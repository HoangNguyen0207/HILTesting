#include "TestProcessRealtimeControl.h"
#include "utils/math_helper/math_helper.h"

TestProcessRealtimeControl::TestProcessRealtimeControl(DEVICE::TYPE device, ControlParamType control, SpecificationParamType spec)
    : TestProcess(device, control, spec)
{
    mMaxAxis = (device == DEVICE::TYPE::FMS) ? 3 : 2;
    mSendCount = 0;
    for(int i = 0; i < mMaxAxis; i++)
    {
        mCtrlPosition[i] = getSineTrajectory(mCtrlParam.mAmplitude[i],
                                             mCtrlParam.mFrequency[i],
                                             1, 3, TEST_STEP_TIME_INTERVAL/1000);
    }
}

TestProcessRealtimeControl::~TestProcessRealtimeControl()
{

}

int TestProcessRealtimeControl::run()
{
    if(mPause == false)
    {
        switch(mStep)
        {
        case TEST_STEP::TESTSTEP_0:
        {
            homing(mDevice);
            mStepCount = 0;
            mStep = TEST_STEP::TESTSTEP_1;
            break;
        }
        case TEST_STEP::TESTSTEP_1:
        {
            if(mStepCount++ < TEST_STEP_MAX_COUNT)
            {
                if(isHoming(mDevice))
                {
                    mStep = TEST_STEP::TESTSTEP_2;
                    mStepCount = 0;
                }
            }
            else
                error();
            break;
        }
        case TEST_STEP::TESTSTEP_2:
        {
            //Wait for 2 sec for stablizing
            if(mStepCount++ > getCount(2))
            {
                mStep = TEST_STEP::TESTSTEP_3;
                mStepCount = 0;
                setPlotData(true);
            }
            break;
        }
        case TEST_STEP::TESTSTEP_3:
        {
            std::vector<double> position = getPosition(mDevice);
            for(int i = 0; i < mMaxAxis; i++)
            {
                mPosition[i].push_back(position.at(i));
            }
            if(mSendCount < mCtrlPosition[0].size())
            {
                for(int i = 0; i < mMaxAxis; i++)
                {
                    moveAbs(mDevice, i, mCtrlPosition[i].at(mSendCount));
                }
                mSendCount++;
            }
            else
            {
                setPlotData(false);
                mStep = TEST_STEP::TESTSTEP_FINISH;
            }
            break;
        }
        case TEST_STEP::TESTSTEP_FINISH:
        {
            bool isPass = true;
            for(int i = 0; i < mMaxAxis; i++)
            {
                double amp = peak_amplitude_detect(mPosition[i]);
                double freq = frequency_detect(mPosition[i], 1000/TEST_STEP_TIME_INTERVAL);
                if(getPercentage(amp, mCtrlParam.mAmplitude[i]) < 70 ||
                    getPercentage(freq, mCtrlParam.mFrequency[i]) < 70)
                {
                    isPass = false;
                }
            }
            if(isPass)
                mResult = TEST_PROCESS_PASS;
            else
                mResult = TEST_PROCESS_FAIL;
        }
        default: break;
        }
    }
    return mResult;
}
