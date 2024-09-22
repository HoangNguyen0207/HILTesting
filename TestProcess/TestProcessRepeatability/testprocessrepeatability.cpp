#include "testprocessrepeatability.h"
#include "utils/math_helper/math_helper.h"
#include "utils/reportHandle/reporthandle.h"

TestProcessRepeatability::TestProcessRepeatability(DEVICE::TYPE device, int axis, ControlParamType control_param, SpecificationParamType spec)
    : TestProcess(device, axis,control_param, spec)
{
    mData.resize(mCtrlParam.mPositionRepeat);
    for(int i = 0; i < mData.size(); i++)
    {
        if(i % 2 == 0)
            mData[i].cmdPosition = mCtrlParam.mUpperPosition[mAxis];
        else
            mData[i].cmdPosition = mCtrlParam.mLowerPosition[mAxis];
    }
}

int TestProcessRepeatability::run()
{
    if(mPause == false)
    {
        switch(mStep)
        {
        case TEST_STEP::TESTSTEP_0:
        {
            //Get Device back to homing Position;
            homing(mDevice);
            mStepCount = 0;
            mStep = TEST_STEP::TESTSTEP_1;
            break;
        }
        case TEST_STEP::TESTSTEP_1:
        {
            //Wait until Device homing
            if(mStepCount++ < TEST_STEP_MAX_COUNT)
            {
                if(isHoming(mDevice))
                {
                    mStep = TEST_STEP::TESTSTEP_2;
                    mStepCount = 0;
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
            //Wait for 2 sec for stablizing
            if(mStepCount++ > getCount(2))
            {
                mStep = TEST_STEP::TESTSTEP_3;
                mResult = TEST_PROCESS_WAIT_INPUT_0;
                mStepCount = 0;
                pause();
            }
            break;
        }
        case TEST_STEP::TESTSTEP_3:
        {
            mRefCoordinate = mSmrCoordinate;
            mStep = TEST_STEP::TESTSTEP_4;
            break;
        }
        case TEST_STEP::TESTSTEP_4:
        {
            if(mIndex < mData.size())
            {
                moveAbs(mDevice, mAxis, mData.at(mIndex).cmdPosition);
                mStep = TEST_STEP::TESTSTEP_5;
            }
            else
            {
                mStep = TEST_STEP::TESTSTEP_FINISH;
            }
            break;
        }
        case TEST_STEP::TESTSTEP_5:
        {
            if(mStepCount++ < TEST_STEP_MAX_COUNT)
            {
                std::vector<double> position = getPosition(mDevice);
                if(isEqual(mData.at(mIndex).cmdPosition, position.at(mAxis)))
                {
                    moveAbs(mDevice, mAxis, 0);
                    mStepCount = 0;
                    mStep = TEST_STEP::TESTSTEP_6;
                }
            }
            else
                error();
            break;
        }
        case TEST_STEP::TESTSTEP_6:
        {
            if(mStepCount++ < TEST_STEP_MAX_COUNT)
            {
                std::vector<double> position = getPosition(mDevice);
                if(isEqual(0, position.at(mAxis)))
                {
                    mStep = TEST_STEP::TESTSTEP_7;
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
        case TEST_STEP::TESTSTEP_7:
        {
            mData[mIndex].x = mSmrCoordinate.at(0);
            mData[mIndex].y = mSmrCoordinate.at(1);
            mData[mIndex].z = mSmrCoordinate.at(2);
            double measure;
            if(mCtrlParam.mIsLinear)
            {
                measure = getDistance(mRefCoordinate, mSmrCoordinate);
            }
            else
            {
                measure = getAngle(mCenterCoordinate, mRefCoordinate, mSmrCoordinate);
            }
            mData[mIndex].measurePosition = measure;
            mIndex++;
            mStep = TEST_STEP::TESTSTEP_4;
            break;
        }
        case TEST_STEP::TESTSTEP_FINISH:
        {
            mResult = TEST_PROCESS_PASS;
            for(std::vector<TestProcessPositionData>::iterator it = mData.begin();
                 it != mData.end(); it++)
            {
                if(it->measurePosition > mSpec.mSpecification[mAxis])
                    mResult = TEST_PROCESS_FAIL;
            }
            InforReport mReportInfo;
            mReportInfo.device = mDevice;
            mReportInfo.axis = mAxis;
            mReportInfo.result = mResult;
            mReportInfo.testType = TEST_DEFINE::TEST_PROCESS::REPEATABILITY;
            mReportInfo.specification = mSpec.mSpecification[mAxis];
            ReportHandle::getInstance()->createReportRepeatability(mReportInfo, mData, mRefCoordinate, mCenterCoordinate, mCtrlParam.mIsLinear);

            break;
        }
        default: break;
        }
    }
    return mResult;
}
