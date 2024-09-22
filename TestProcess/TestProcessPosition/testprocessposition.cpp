#include "testprocessposition.h"
#include "utils/math_helper/math_helper.h"
#include "utils/reportHandle/reporthandle.h"

TestProcessPosition::TestProcessPosition(DEVICE::TYPE device, int axis, ControlParamType control, SpecificationParamType spec)
    : TestProcess(device, axis, control, spec)
{
    int dataSize = static_cast<int>((mCtrlParam.mUpperPosition[mAxis] - mCtrlParam.mLowerPosition[mAxis])/mCtrlParam.mPositionStep[mAxis]);
    mData.resize(dataSize);
    for(int i = 0; i < dataSize; i++)
    {
        mData[i].cmdPosition = mCtrlParam.mLowerPosition[mAxis] + mCtrlParam.mPositionStep[mAxis] * i;
    }
}

int TestProcessPosition::run()
{
    if(mPause == false)
    {
        switch(mStep)
        {
        case TEST_STEP::TESTSTEP_0:
        {
            //Get Device back to homing position
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
        case TEST_STEP::TESTSTEP_3:
        {
            //Wait for 2 sec for stablizing
            if(mStepCount++ > getCount(2))
            {
                mStep = TEST_STEP::TESTSTEP_4;
                mResult = TEST_PROCESS_WAIT_INPUT_0;
                pause();
            }
            break;
        }

        case TEST_STEP::TESTSTEP_4:
        {
            //Get Ref Coordinate
            mRefCoordinate = mSmrCoordinate;
            mStep = TEST_STEP::TESTSTEP_5;
            break;
        }

        case TEST_STEP::TESTSTEP_5:
        {
            //Start Moving Device
            if(mIndex < mData.size())
            {
                moveAbs(mDevice, mAxis, mData.at(mIndex).cmdPosition);
                mStepCount = 0;
                mStep = TEST_STEP::TESTSTEP_6;
            }
            else
            {
                mStep = TEST_STEP::TESTSTEP_FINISH;
            }
            break;
        }
        case TEST_STEP::TESTSTEP_6:
        {
            //Wait until Device move and then pause for recording
            if(mStepCount++ < TEST_STEP_MAX_COUNT)
            {
                std::vector<double> position = getPosition(mDevice);
                if(isEqual(mData.at(mIndex).cmdPosition, position.at(mAxis)))
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
        case TEST_STEP::TESTSTEP_10:
        {
            //get Data, store and update Index
            mData[mIndex].x = mSmrCoordinate.at(0);
            mData[mIndex].y = mSmrCoordinate.at(1);
            mData[mIndex].z = mSmrCoordinate.at(2);

            double measure = 0;
            if(mCtrlParam.mIsLinear)
            {
                measure = getDistance(mRefCoordinate, mSmrCoordinate);
                if(mData[mIndex].cmdPosition < 0)
                    measure *= -1;
            }
            else
            {
                measure = getAngle(mCenterCoordinate, mRefCoordinate, mSmrCoordinate);
            }
            mData[mIndex].measurePosition = measure;
            mData[mIndex].err = measure - mData.at(mIndex).cmdPosition;
            mIndex++;
            mStep = TEST_STEP::TESTSTEP_5;
            break;
        }
        case TEST_STEP::TESTSTEP_FINISH:
        {
            //Start create report and calculate
            mResult = TEST_PROCESS_PASS;
            for(std::vector<TestProcessPositionData>::iterator it = mData.begin();
                 it != mData.end(); it++)
            {
                //update data to report
                if(ABS(it->err) > mSpec.mSpecification[mAxis])
                {
                    mResult = TEST_PROCESS_FAIL;
                }
            }

            QString imgPath = "BandwidthImage";

            InforReport mReportInfo;
            mReportInfo.device = mDevice;
            mReportInfo.axis = mAxis;
            mReportInfo.result = mResult;
            mReportInfo.testType = TEST_DEFINE::TEST_PROCESS::POSITION;
            mReportInfo.specification = mSpec.mSpecification[mAxis];
            ReportHandle::getInstance()->createReportPositionError(mReportInfo, mData,
                                                                   mRefCoordinate, mCenterCoordinate, mCtrlParam.mIsLinear);
            break;
        }
        default: break;
        }
    }
    return mResult;
}




