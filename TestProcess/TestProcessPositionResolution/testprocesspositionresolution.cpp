#include "testprocesspositionresolution.h"
#include "utils/math_helper/math_helper.h"
#include "utils/reportHandle/reporthandle.h"

TestProcessPositionResolution::TestProcessPositionResolution(DEVICE::TYPE device, int axis, ControlParamType control, SpecificationParamType spec)
    : TestProcess(device, axis, control, spec)
{
    mData.resize(10);
    mData[0].cmdPosition = 0;
    for(int i = 1; i < mData.size(); i++)
    {
        mData[i].cmdPosition = mData[i-1].cmdPosition + mCtrlParam.mPositionStep[mAxis];
    }
}

int TestProcessPositionResolution::run()
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
                    mResult = TEST_PROCESS_WAIT_INPUT_0;
                    pause();
                }
            }
            else
            {
                error();
            }
            break;
        }
        case TEST_STEP::TESTSTEP_2:
        {
            mRefCoordinate = mSmrCoordinate;
            mStep = TEST_STEP::TESTSTEP_3;
        }
        case TEST_STEP::TESTSTEP_3:
        {
            if(mIndex < mData.size())
            {
                moveAbs(mDevice, mAxis, mData.at(mIndex).cmdPosition);
                mStep = TEST_STEP::TESTSTEP_4;
            }
            else
            {
                mStep = TEST_STEP::TESTSTEP_FINISH;
            }
            break;
        }
        case TEST_STEP::TESTSTEP_4:
        {
            if(mStepCount++ < TEST_STEP_MAX_COUNT)
            {
                std::vector<double> position = getPosition(mDevice);
                if(isEqual(mData.at(mIndex).cmdPosition, position.at(mAxis)))
                {
                    mStep = TEST_STEP::TESTSTEP_5;
                    mStepCount = 0;
                    mResult = TEST_PROCESS_WAIT_INPUT_0;
                    pause();
                }
            }
            else
            {
                error();
            }
            break;
        }
        case TEST_STEP::TESTSTEP_5:
        {
            mData[mIndex].x = mSmrCoordinate.at(0);
            mData[mIndex].y = mSmrCoordinate.at(1);
            mData[mIndex].z = mSmrCoordinate.at(2);

            if(mCtrlParam.mIsLinear)
            {
                mData[mIndex].measurePosition = getDistance(mRefCoordinate, mSmrCoordinate);
            }
            else
            {
                mData[mIndex].measurePosition = getAngle(mCenterCoordinate, mRefCoordinate, mSmrCoordinate);
            }
            mIndex++;
            mStep = TEST_STEP::TESTSTEP_3;
            break;
        }
        case TEST_STEP::TESTSTEP_FINISH:
        {
            mResult = TEST_PROCESS_PASS;
            mData[0].measurePosition = 0;
            for(int index = 1; index < mData.size(); index++)
            {
                double error = mData[mIndex].measurePosition - mData[mIndex-1].measurePosition;
                if(error < (mSpec.mSpecification[mAxis] - 0.005) ||
                    error > (mSpec.mSpecification[mAxis] + 0.005))
                {
                    mResult = TEST_PROCESS_FAIL;
                }
            }
            QString imgPath = "BandwidthImage";

            InforReport mReportInfo;
            mReportInfo.device = mDevice;
            mReportInfo.axis = mAxis;
            mReportInfo.result = mResult;
            mReportInfo.testType = TEST_DEFINE::TEST_PROCESS::RESOLUTION;
            mReportInfo.specification = mSpec.mSpecification[mAxis];
            ReportHandle::getInstance()->createReportResolution(mReportInfo, mData, mRefCoordinate, mCenterCoordinate, mCtrlParam.mIsLinear);
            break;
        }
        default: break;
        }
    }
    return mResult;
}
