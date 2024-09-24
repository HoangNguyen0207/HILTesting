#include "testprocessdelay.h"
#include "utils/math_helper/math_helper.h"
#include "utils/reportHandle/reporthandle.h"

TestProcessDelay::TestProcessDelay(DEVICE::TYPE device, int axis, ControlParamType control, SpecificationParamType spec)
    : TestProcess(device, axis, control, spec)
{
    mControlPosition = getSineTrajectory(mCtrlParam.mFrequency[mAxis], mCtrlParam.mAmplitude[mAxis],
                                         1, 5, 1000/TEST_STEP_TIME_INTERVAL);
}

int TestProcessDelay::run()
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
            std::vector<double> position = getPosition(mDevice);
            mFeedbackPosition.push_back(position.at(mAxis));
            if(mIndex < mControlPosition.size())
            {
                moveAbs(mDevice, mAxis, mControlPosition.at(mIndex));
            }
            else
            {
                mStep = TEST_STEP::TESTSTEP_FINISH;
            }
            break;
        }
        case TEST_STEP::TESTSTEP_FINISH:
        {
            double realDelay = getPhaseDelay(mControlPosition, mFeedbackPosition, 1000/TEST_STEP_TIME_INTERVAL);
            if(realDelay < mSpec.mSpecification[mAxis])
                mResult = TEST_PROCESS_PASS;
            else
                mResult = TEST_PROCESS_FAIL;

            QString imgPath = "BandwidthImage";

            InforReport mReportInfo;
            mReportInfo.device = mDevice;
            mReportInfo.axis = mAxis;
            mReportInfo.result = mResult;
            mReportInfo.testType = TEST_DEFINE::TEST_PROCESS::DELAY;
            mReportInfo.specification = mSpec.mSpecification[mAxis];
            ReportHandle::getInstance()->createReportDelay(mReportInfo, realDelay/1000.0f, imgPath);
        }
        default: break;
        }
    }
    return mResult;
}


