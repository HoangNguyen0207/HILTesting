#include "testprocessbandwidth.h"
#include "utils/math_helper/math_helper.h"
#include "utils/reportHandle/reporthandle.h"

TestProcessBandwidth::TestProcessBandwidth(DEVICE::TYPE device, int axis, ControlParamType control, SpecificationParamType spec)
    : TestProcess(device, axis, control, spec)
{
    mMaxVelocity = mCtrlParam.mAmplitude[mAxis] * mCtrlParam.mFrequency[mAxis] * 2 * PI;
    mMaxAcceleration = mCtrlParam.mAmplitude[mAxis] * mCtrlParam.mFrequency[mAxis]
                        * mCtrlParam.mFrequency[mAxis] * 4 * PI * PI;

    int dataSize = mCtrlParam.mFrequency[mAxis]/mCtrlParam.mPositionStep[mAxis];
    mData.resize(dataSize);
    mData[0].frequency = mCtrlParam.mPositionStep[mAxis];
    mData[0].amplitude = mCtrlParam.mAmplitude[mAxis];
    for(int i = 1; i < mData.size(); i++)
    {
        mData[i].amplitude = mCtrlParam.mAmplitude[mAxis];
        mData[i].frequency = mData[i-1].frequency + mCtrlParam.mPositionStep[mAxis];
    }
}

int TestProcessBandwidth::run()
{
    if(mPause == false)
    {
        switch(mStep)
        {
        case TEST_STEP::TESTSTEP_0:
        {
            homing(mDevice);
            mStep = TEST_STEP::TESTSTEP_1;
            break;
        }
        case TEST_STEP::TESTSTEP_1:
        {
            if(mStepCount++ < TEST_STEP_MAX_COUNT)
            {
                if(isHoming(mDevice))
                {
                    mStepCount = 0;
                    mStep = TEST_STEP::TESTSTEP_2;
                }
            }
            else
                error();
            break;
        }
        case TEST_STEP::TESTSTEP_3:
        {
            if(mStepCount++ > getCount(2))
            {
                mStepCount = 0;
                mStep = TEST_STEP::TESTSTEP_4;
            }
            break;
        }
        case TEST_STEP::TESTSTEP_4:
        {
            if(mIndex < mData.size())
            {
                moveSine(mDevice, mAxis, mData.at(mIndex).amplitude, mData[mIndex].frequency);
                mStep = TEST_STEP::TESTSTEP_5;
            }
            else
            {
                homing(mDevice);
                mStep = TEST_STEP::TESTSTEP_FINISH;
            }
            break;
        }
        case TEST_STEP::TESTSTEP_5:
        {
            //Wait for 2 period for system transient to other frequency
            double mPeriodWait;
            if(mData[mIndex].frequency < 0.5)
            {
                //Wait for half period
                mPeriodWait = 1/(2*mData[mIndex].frequency);
            }
            else if(mData[mIndex].frequency < 1)
            {
                mPeriodWait = 1/mData[mIndex].frequency;
            }
            else
            {
                mPeriodWait = 2/mData[mIndex].frequency;
            }
            if(mStepCount++ > getCount(mPeriodWait))
            {
                mStep = TEST_STEP::TESTSTEP_6;
                mStepCount = 0;
            }
            break;
        }
        case TEST_STEP::TESTSTEP_6:
        {
            if(mStepCount++ < getCount(1/mData[mIndex].frequency))
            {
                mData[mIndex].position.push_back(getPosition(mDevice).at(mAxis));
            }
            else
            {
                mIndex++;
                mStep = TEST_STEP::TESTSTEP_4;
                mStepCount = 0;
            }
            break;
        }
        case TEST_STEP::TESTSTEP_FINISH:
        {
            mResult = TEST_PROCESS_PASS;
            for(std::vector<TestProcessBandwidthData>::iterator it = mData.begin();
                 it != mData.end(); it++)
            {
                double peakAmp = peak_amplitude_detect(it->position);
                double dB = getdBGain(peakAmp, it->amplitude);
                it->gain = dB;
                if(dB < -3)
                    mResult = TEST_PROCESS_FAIL;
            }

            //Draw Bode Diagram and Save Image
            QString imgPath = "BandwidthImage";

            InforReport mReportInfo;
            mReportInfo.device = mDevice;
            mReportInfo.axis = mAxis;
            mReportInfo.result = mResult;
            mReportInfo.testType = TEST_DEFINE::TEST_PROCESS::BANDWIDTH;
            mReportInfo.specification = mSpec.mSpecification[mAxis];
            ReportHandle::getInstance()->createReportBandwidth(mReportInfo,
                        mData, mCtrlParam.mAmplitude[mAxis], imgPath);
            break;
        }
        default: break;
        }
    }
    return mResult;
}
