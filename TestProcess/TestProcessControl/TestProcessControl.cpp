#include "TestProcessControl.h"
#include "utils/math_helper/math_helper.h"

TestProcessControl::TestProcessControl(DEVICE::TYPE device, ControlParamType control, SpecificationParamType spec)
    : TestProcess(device, control, spec)
{
    if(device == DEVICE::TYPE::FMS)
        mMaxAxisCount = 6;
    else
        mMaxAxisCount = 4;
    setPlotData(true);
    mIsFalse = false;
}

TestProcessControl::~TestProcessControl()
{

}

int TestProcessControl::run()
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
            if(mAxisCount < mMaxAxisCount)
            {
                moveAbs(mDevice, mAxisCount, mCtrlParam.mLowerPosition[mAxisCount]);
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
                if(isEqual(position[mAxisCount], mCtrlParam.mLowerPosition[mAxisCount]))
                {
                    mStep = TEST_STEP::TESTSTEP_5;
                    mStepCount = 0;
                }
            }
            else
                mIsFalse = true;
            break;
        }
        case TEST_STEP::TESTSTEP_5:
        {
            moveAbs(mDevice, mAxisCount, mCtrlParam.mUpperPosition[mAxisCount]);
            mStep = TEST_STEP::TESTSTEP_6;
            break;
        }
        case TEST_STEP::TESTSTEP_6:
        {
            if(mStepCount++ < TEST_STEP_MAX_COUNT)
            {
                std::vector<double> position = getPosition(mDevice);
                if(isEqual(position[mAxisCount], mCtrlParam.mUpperPosition[mAxisCount]))
                {
                    mStep = TEST_STEP::TESTSTEP_0;
                    mStepCount = 0;
                    mAxisCount++;
                }
            }
            else
                mIsFalse = true;
            break;
        }
        case TEST_STEP::TESTSTEP_FINISH:
        {
            if(mIsFalse)
                mResult = TEST_PROCESS_FAIL;
            else
                mResult = TEST_PROCESS_PASS;
        }
        default: break;
        }
    }
    return mResult;
}
