#include "TestProcessClosedLoop.h"
#include "utils/math_helper/math_helper.h"

TestProcessClosedLoop::TestProcessClosedLoop(DEVICE::TYPE device, ControlParamType control, SpecificationParamType spec)
    : TestProcess(device, control, spec)
{

}

TestProcessClosedLoop::~TestProcessClosedLoop()
{

}

int TestProcessClosedLoop::run()
{
    if(mPause == false)
    {
        switch(mStep)
        {
        case TEST_STEP::TESTSTEP_0:
        {
            homing(DEVICE::TYPE::FMS);
            homing(DEVICE::TYPE::FMS);
            mStepCount = 0;
            mStep = TEST_STEP::TESTSTEP_1;
            break;
        }
        case TEST_STEP::TESTSTEP_1:
        {
            if(mStepCount++ < TEST_STEP_MAX_COUNT)
            {
                if(isHoming(DEVICE::TYPE::FMS) && isHoming(DEVICE::TYPE::TMS))
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
            }
            break;
        }
        case TEST_STEP::TESTSTEP_3:
        {
            moveSine(DEVICE::TYPE::FMS, static_cast<int>(DEVICE::FMS_AXIS::ROLL),
                     mCtrlParam.mAmplitude[static_cast<int>(DEVICE::TYPE::FMS)],
                     mCtrlParam.mFrequency[static_cast<int>(DEVICE::TYPE::FMS)]);
            moveSine(DEVICE::TYPE::FMS, static_cast<int>(DEVICE::FMS_AXIS::PITCH),
                     mCtrlParam.mAmplitude[static_cast<int>(DEVICE::TYPE::FMS)],
                     mCtrlParam.mFrequency[static_cast<int>(DEVICE::TYPE::FMS)]);
            moveSine(DEVICE::TYPE::FMS, static_cast<int>(DEVICE::FMS_AXIS::YAW),
                     mCtrlParam.mAmplitude[static_cast<int>(DEVICE::TYPE::FMS)],
                     mCtrlParam.mFrequency[static_cast<int>(DEVICE::TYPE::FMS)]);
            moveSine(DEVICE::TYPE::TMS, static_cast<int>(DEVICE::TMS_AXIS::X),
                     mCtrlParam.mAmplitude[static_cast<int>(DEVICE::TYPE::TMS)],
                     mCtrlParam.mFrequency[static_cast<int>(DEVICE::TYPE::TMS)]);
            moveSine(DEVICE::TYPE::TMS, static_cast<int>(DEVICE::TMS_AXIS::Y),
                     mCtrlParam.mAmplitude[static_cast<int>(DEVICE::TYPE::TMS)],
                     mCtrlParam.mFrequency[static_cast<int>(DEVICE::TYPE::TMS)]);
            mStep = TEST_STEP::TESTSTEP_4;
            setPlotData(true);
            break;
        }
        case TEST_STEP::TESTSTEP_4:
        {
            if(mStepCount++ < getCount(5))
            {
                std::vector<double> fmsPos = getPosition(DEVICE::TYPE::FMS);
                std::vector<double> tmsPos = getPosition(DEVICE::TYPE::FMS);
                mFmsPosition[0].push_back(fmsPos[static_cast<int>(DEVICE::FMS_AXIS::ROLL)]);
                mFmsPosition[1].push_back(fmsPos[static_cast<int>(DEVICE::FMS_AXIS::PITCH)]);
                mFmsPosition[2].push_back(fmsPos[static_cast<int>(DEVICE::FMS_AXIS::YAW)]);

                mTmsPosition[0].push_back(fmsPos[static_cast<int>(DEVICE::TMS_AXIS::X)]);
                mTmsPosition[1].push_back(fmsPos[static_cast<int>(DEVICE::TMS_AXIS::Y)]);
                mStep = TEST_STEP::TESTSTEP_5;
                homing(DEVICE::TYPE::FMS);
                homing(DEVICE::TYPE::TMS);
                mStepCount = 0;
            }
            break;
        }
        case TEST_STEP::TESTSTEP_5:
        {
            if(mStepCount++ < TEST_STEP_MAX_COUNT)
            {
                if(isHoming(DEVICE::TYPE::FMS) && isHoming(DEVICE::TYPE::TMS))
                {
                    mStep = TEST_STEP::TESTSTEP_FINISH;
                    mStepCount = 0;
                    setPlotData(false);
                }
            }
            else
                error();
            break;
        }
        case TEST_STEP::TESTSTEP_FINISH:
        {
            bool isPass = true;
            for(int i = 0; i < 3; i++)
            {
                double amp = peak_amplitude_detect(mFmsPosition[i]);
                double freq = frequency_detect(mFmsPosition[i], 1000/TEST_STEP_TIME_INTERVAL);

                if(getPercentage(amp, mCtrlParam.mAmplitude[static_cast<int>(DEVICE::TYPE::FMS)]) < 90 ||
                    getPercentage(freq, mCtrlParam.mFrequency[static_cast<int>(DEVICE::TYPE::FMS)]) < 90)
                {
                    isPass = 0;
                }
            }

            for(int i = 0; i < 2; i++)
            {
                double amp = peak_amplitude_detect(mTmsPosition[i]);
                double freq = frequency_detect(mTmsPosition[i], 1000/TEST_STEP_TIME_INTERVAL);

                if(getPercentage(amp, mCtrlParam.mAmplitude[static_cast<int>(DEVICE::TYPE::TMS)]) < 90 ||
                    getPercentage(freq, mCtrlParam.mFrequency[static_cast<int>(DEVICE::TYPE::TMS)]) < 90)
                {
                    isPass = 0;
                }
            }
            if(isPass)
                mResult = TEST_PROCESS_PASS;
            else
                mResult = TEST_PROCESS_FAIL;
            break;
        }
        default: break;
        }
    }
    return mResult;
}
