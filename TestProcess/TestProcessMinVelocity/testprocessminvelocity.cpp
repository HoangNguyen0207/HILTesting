#include "testprocessminvelocity.h"
#include "utils/math_helper/math_helper.h"
#include "utils/reportHandle/reporthandle.h"

TestProcessMinVelocity::TestProcessMinVelocity(DEVICE::TYPE device, int axis, ControlParamType control, SpecificationParamType spec)
    : TestProcess(device, axis, control, spec)
{
    mMaxVelocity = mCtrlParam.mAmplitude[mAxis] * mCtrlParam.mFrequency[mAxis] * 2 * PI;
    mMaxAcceleration = mCtrlParam.mAmplitude[mAxis] * mCtrlParam.mFrequency[mAxis]
                        * mCtrlParam.mFrequency[mAxis] * 4 * PI * PI;
}

int TestProcessMinVelocity::run()
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
                        mStep = TEST_STEP::TESTSTEP_1;
                        mStepCount = 0;
                    }
                }
                else
                    error();
                break;
            }
            case TEST_STEP::TESTSTEP_2:
            {
                //Wait for 2 sec
                if(mStepCount++ > getCount(2))
                {
                    configDeviceSpec(mDevice, mMaxVelocity, mMaxAcceleration);
                    mStep = TEST_STEP::TESTSTEP_3;
                }
                break;
            }
            case TEST_STEP::TESTSTEP_3:
            {
                moveSine(mDevice, mAxis, mCtrlParam.mAmplitude[mAxis], mCtrlParam.mFrequency[mAxis]);
                mStep = TEST_STEP::TESTSTEP_4;
                break;
            }
            case TEST_STEP::TESTSTEP_4:
            {
                if(mStepCount++ < getCount(2/mCtrlParam.mFrequency[mAxis]))
                {
                    mPosition.push_back(getPosition(mDevice).at(mAxis));
                }
                else
                {
                    homing(mDevice);
                    mStep = TEST_STEP::TESTSTEP_FINISH;
                    mStepCount = 0;
                }
                break;
            }
            case TEST_STEP::TESTSTEP_FINISH:
            {
                double realAmp = peak_amplitude_detect(mPosition);
                double realFreq = frequency_detect(mPosition, 1000/TEST_STEP_TIME_INTERVAL);

                double maxVel = realAmp * 2 * PI * realFreq;

                if(maxVel < mSpec.mSpecification[mAxis])
                {
                    mResult = TEST_PROCESS_PASS;
                }
                else
                {
                    mResult = TEST_PROCESS_FAIL;
                }
                QString imgPath = "BandwidthImage";

                InforReport mReportInfo;
                mReportInfo.device = mDevice;
                mReportInfo.axis = mAxis;
                mReportInfo.result = mResult;
                mReportInfo.testType = TEST_DEFINE::TEST_PROCESS::MIN_VEL;
                mReportInfo.specification = mSpec.mSpecification[mAxis];
                ReportHandle::getInstance()->createReportMinVelocity(mReportInfo, mCtrlParam.mAmplitude[mAxis], mCtrlParam.mFrequency[mAxis], imgPath);

                break;
            }
            default: break;
        }
    }
    return mResult;
}
