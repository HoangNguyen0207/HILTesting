#include "TestProcessMaxPosition.h"
#include "utils/math_helper/math_helper.h"
#include "utils/reportHandle/reporthandle.h"

TestProcessMaxPosition::TestProcessMaxPosition(DEVICE::TYPE device, int axis, ControlParamType control, SpecificationParamType spec)
    : TestProcess(device, axis, control, spec)
{
    setPlotData(true);
    mData.resize(2);
    mData[0].cmdPosition = -mSpec.mSpecification[mAxis];
    mData[1].cmdPosition = mSpec.mSpecification[mAxis];
    mIndex = 0;
}

TestProcessMaxPosition::~TestProcessMaxPosition()
{

}

int TestProcessMaxPosition::run()
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
            if(mIndex < 2)
            {
                moveAbs(mDevice, mAxis, mData.at(mIndex).cmdPosition);
                mStep = TEST_STEP::TESTSTEP_6;
            }
            else
            {
                mStep = TEST_STEP::TESTSTEP_FINISH;
                homing(mDevice);
            }

            break;
        }
        case TEST_STEP::TESTSTEP_6:
        {
            std::vector<double> position = getPosition(mDevice);
            if(mStepCount++ < TEST_STEP_MAX_COUNT)
            {
                if(isEqual(position[mAxis],  mData.at(mIndex).cmdPosition))
                {
                    mStep = TEST_STEP::TESTSTEP_7;
                    mResult = TEST_PROCESS_WAIT_INPUT_0;
                    pause();
                }
            }
            else
                error();
            break;
        }
        case TEST_STEP::TESTSTEP_7:
        {
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
            mIndex++;
            mStep = TEST_STEP::TESTSTEP_5;
            break;
        }
        case TEST_STEP::TESTSTEP_FINISH:
        {
            mResult = TEST_PROCESS_PASS;
            if(mData.at(0).measurePosition > -mSpec.mSpecification[mAxis] ||
                mData.at(1).measurePosition < mSpec.mSpecification[mAxis])
            {
                mResult = TEST_PROCESS_FAIL;
            }
            QString imgPath = "BandwidthImage";

            InforReport mReportInfo;
            mReportInfo.device = mDevice;
            mReportInfo.axis = mAxis;
            mReportInfo.result = mResult;
            mReportInfo.testType = TEST_DEFINE::TEST_PROCESS::MAX_POS;
            mReportInfo.specification = mSpec.mSpecification[mAxis];
            ReportHandle::getInstance()->createReportMaxPosition(mReportInfo, mData, mRefCoordinate,
                                                                 mCenterCoordinate, mCtrlParam.mIsLinear);
            break;
        }
        default: break;
        }
    }
    return mResult;
}
