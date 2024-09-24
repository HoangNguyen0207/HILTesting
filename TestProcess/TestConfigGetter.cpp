#include "TestConfigGetter.h"
#include <QVariant>

TestConfigGetter::TestConfigGetter()
{

}

TestConfigGetter::~TestConfigGetter()
{

}

ControlParamType TestConfigGetter::getControlParam()
{
    return mCtrlParam;
}

SpecificationParamType TestConfigGetter::getSpecParam()
{
    return mSpecParam;
}

void TestConfigGetter::updateConfig(ProcessType type, QMap<QString, QVariantMap>& config, std::queue<TestProcessQueuePart>& mQueue)
{
    TestProcessQueuePart queue;
    switch(type)
    {
    case ProcessType::Process_1_1_1:
    {
        mCtrlParam.mAmplitude[static_cast<int>(DEVICE::TYPE::FMS)] = config["param"]["fmsApp"].toDouble();
        mCtrlParam.mAmplitude[static_cast<int>(DEVICE::TYPE::FMS)] = config["param"]["fmsFreq"].toDouble();
        mCtrlParam.mAmplitude[static_cast<int>(DEVICE::TYPE::TMS)] = config["param"]["tmsApp"].toDouble();
        mCtrlParam.mAmplitude[static_cast<int>(DEVICE::TYPE::TMS)] = config["param"]["tmsFreq"].toDouble();
        queue.device = DEVICE::TYPE::FMS;
        queue.type = TEST_DEFINE::TEST_PROCESS::CLOSED_LOOP;
        queue.control = mCtrlParam;
        queue.spec = mSpecParam;
        mQueue.push(queue);
        return;
    }
    case ProcessType::Process_1_1_2:
    {
        mCtrlParam.mLowerPosition[static_cast<int>(DEVICE::FMS_AXIS::ROLL)] = config["param"]["fmsRollPos1"].toDouble();
        mCtrlParam.mUpperPosition[static_cast<int>(DEVICE::FMS_AXIS::ROLL)] = config["param"]["fmsRollPos2"].toDouble();
        mCtrlParam.mLowerPosition[static_cast<int>(DEVICE::FMS_AXIS::PITCH)] = config["param"]["fmsPitchPos1"].toDouble();
        mCtrlParam.mUpperPosition[static_cast<int>(DEVICE::FMS_AXIS::PITCH)] = config["param"]["fmsPitchPos2"].toDouble();
        mCtrlParam.mLowerPosition[static_cast<int>(DEVICE::FMS_AXIS::YAW)] = config["param"]["fmsYawPos1"].toDouble();
        mCtrlParam.mUpperPosition[static_cast<int>(DEVICE::FMS_AXIS::YAW)] = config["param"]["fmsYawPos2"].toDouble();
        mCtrlParam.mLowerPosition[static_cast<int>(DEVICE::FMS_AXIS::X)] = config["param"]["fmsTxPos1"].toDouble();
        mCtrlParam.mUpperPosition[static_cast<int>(DEVICE::FMS_AXIS::X)] = config["param"]["fmsTxPos2"].toDouble();
        mCtrlParam.mLowerPosition[static_cast<int>(DEVICE::FMS_AXIS::Y)] = config["param"]["fmsTyPos1"].toDouble();
        mCtrlParam.mUpperPosition[static_cast<int>(DEVICE::FMS_AXIS::Y)] = config["param"]["fmsTyPos2"].toDouble();
        mCtrlParam.mLowerPosition[static_cast<int>(DEVICE::FMS_AXIS::Z)] = config["param"]["fmsTzPos1"].toDouble();
        mCtrlParam.mUpperPosition[static_cast<int>(DEVICE::FMS_AXIS::Z)] = config["param"]["fmsTzPos2"].toDouble();
        queue.device = DEVICE::TYPE::FMS;
        queue.type = TEST_DEFINE::TEST_PROCESS::CONTROL;
        queue.control = mCtrlParam;
        queue.spec = mSpecParam;
        for(int i = static_cast<int>(DEVICE::FMS_AXIS::ROLL); i <= static_cast<int>(DEVICE::FMS_AXIS::YAW); i++)
        {
            queue.axis = i;
            mQueue.push(queue);
        }
        return;
    }
    case ProcessType::Process_1_1_11:
    case ProcessType::Process_2_1_11:
    {
        mCtrlParam.mAmplitude[static_cast<int>(DEVICE::FMS_AXIS::ROLL)] = config["param"]["fmsRollAmp"].toDouble();
        mCtrlParam.mFrequency[static_cast<int>(DEVICE::FMS_AXIS::ROLL)] = config["param"]["fmsRollFreq"].toDouble();
        mCtrlParam.mAmplitude[static_cast<int>(DEVICE::FMS_AXIS::PITCH)] = config["param"]["fmsPitchAmp"].toDouble();
        mCtrlParam.mFrequency[static_cast<int>(DEVICE::FMS_AXIS::PITCH)] = config["param"]["fmsPitchFreq"].toDouble();
        mCtrlParam.mAmplitude[static_cast<int>(DEVICE::FMS_AXIS::YAW)] = config["param"]["fmsYawAmp"].toDouble();
        mCtrlParam.mFrequency[static_cast<int>(DEVICE::FMS_AXIS::YAW)] = config["param"]["fmsYawFreq"].toDouble();
        queue.device = DEVICE::TYPE::FMS;
        queue.type = TEST_DEFINE::TEST_PROCESS::REALTIME_CONTROL;
        queue.control = mCtrlParam;
        queue.spec = mSpecParam;
        mQueue.push(queue);
        return;
    }
    case ProcessType::Process_1_2_1:
    {
        mCtrlParam.mLowerPosition[static_cast<int>(DEVICE::FMS_AXIS::ROLL)] = config["param"]["fmsRollLowerLimitedPos"].toDouble();
        mCtrlParam.mUpperPosition[static_cast<int>(DEVICE::FMS_AXIS::ROLL)] = config["param"]["fmsRollUpperLimitedPos"].toDouble();
        mCtrlParam.mLowerPosition[static_cast<int>(DEVICE::FMS_AXIS::PITCH)] = config["param"]["fmsPitchLowerLimitedPos"].toDouble();
        mCtrlParam.mUpperPosition[static_cast<int>(DEVICE::FMS_AXIS::PITCH)] = config["param"]["fmsPitchUpperLimitedPos"].toDouble();
        mCtrlParam.mLowerPosition[static_cast<int>(DEVICE::FMS_AXIS::YAW)] = config["param"]["fmsYawLowerLimitedPos"].toDouble();
        mCtrlParam.mUpperPosition[static_cast<int>(DEVICE::FMS_AXIS::YAW)] = config["param"]["fmsYawUpperLimitedPos"].toDouble();

        mSpecParam.mSpecification[static_cast<int>(DEVICE::FMS_AXIS::ROLL)] = config["spec"]["fmsRollUpperLimitedPos"].toDouble();
        mSpecParam.mSpecification[static_cast<int>(DEVICE::FMS_AXIS::PITCH)] = config["spec"]["fmsPitchUpperLimitedPos"].toDouble();
        mSpecParam.mSpecification[static_cast<int>(DEVICE::FMS_AXIS::YAW)] = config["spec"]["fmsYawUpperLimitedPos"].toDouble();

        mCtrlParam.mIsLinear = false;
        queue.device = DEVICE::TYPE::FMS;
        queue.type = TEST_DEFINE::TEST_PROCESS::MAX_POS;
        queue.control = mCtrlParam;
        queue.spec = mSpecParam;
        for(int i = static_cast<int>(DEVICE::FMS_AXIS::ROLL); i <= static_cast<int>(DEVICE::FMS_AXIS::YAW); i++)
        {
            queue.axis = i;
            mQueue.push(queue);
        }
        return;
    }
    case ProcessType::Process_1_2_2:
    {
        mCtrlParam.mAmplitude[static_cast<int>(DEVICE::FMS_AXIS::ROLL)] = config["param"]["fmsRollAmp"].toDouble();
        mCtrlParam.mFrequency[static_cast<int>(DEVICE::FMS_AXIS::ROLL)] = config["param"]["fmsRollFreq"].toDouble();
        mCtrlParam.mAmplitude[static_cast<int>(DEVICE::FMS_AXIS::PITCH)] = config["param"]["fmsPitchAmp"].toDouble();
        mCtrlParam.mFrequency[static_cast<int>(DEVICE::FMS_AXIS::PITCH)] = config["param"]["fmsPitchFreq"].toDouble();
        mCtrlParam.mAmplitude[static_cast<int>(DEVICE::FMS_AXIS::YAW)] = config["param"]["fmsYawAmp"].toDouble();
        mCtrlParam.mFrequency[static_cast<int>(DEVICE::FMS_AXIS::YAW)] = config["param"]["fmsYawFreq"].toDouble();

        mSpecParam.mSpecification[static_cast<int>(DEVICE::FMS_AXIS::ROLL)] = config["spec"]["fmsRollMaxVelocity"].toDouble();
        mSpecParam.mSpecification[static_cast<int>(DEVICE::FMS_AXIS::PITCH)] = config["spec"]["fmsPitchMaxVelocity"].toDouble();
        mSpecParam.mSpecification[static_cast<int>(DEVICE::FMS_AXIS::YAW)] = config["spec"]["fmsYawMaxVelocity"].toDouble();

        queue.device = DEVICE::TYPE::FMS;
        queue.type = TEST_DEFINE::TEST_PROCESS::MAX_VEL;
        queue.control = mCtrlParam;
        queue.spec = mSpecParam;
        for(int i = static_cast<int>(DEVICE::FMS_AXIS::ROLL); i <= static_cast<int>(DEVICE::FMS_AXIS::YAW); i++)
        {
            queue.axis = i;
            mQueue.push(queue);
        }
        return;
    }
    case ProcessType::Process_1_2_3:
    {
        mCtrlParam.mAmplitude[static_cast<int>(DEVICE::FMS_AXIS::ROLL)] = config["param"]["fmsRollAmp"].toDouble();
        mCtrlParam.mFrequency[static_cast<int>(DEVICE::FMS_AXIS::ROLL)] = config["param"]["fmsRollFreq"].toDouble();
        mCtrlParam.mAmplitude[static_cast<int>(DEVICE::FMS_AXIS::PITCH)] = config["param"]["fmsPitchAmp"].toDouble();
        mCtrlParam.mFrequency[static_cast<int>(DEVICE::FMS_AXIS::PITCH)] = config["param"]["fmsPitchFreq"].toDouble();
        mCtrlParam.mAmplitude[static_cast<int>(DEVICE::FMS_AXIS::YAW)] = config["param"]["fmsYawAmp"].toDouble();
        mCtrlParam.mFrequency[static_cast<int>(DEVICE::FMS_AXIS::YAW)] = config["param"]["fmsYawFreq"].toDouble();

        mSpecParam.mSpecification[static_cast<int>(DEVICE::FMS_AXIS::ROLL)] = config["spec"]["fmsRollMinVelocity"].toDouble();
        mSpecParam.mSpecification[static_cast<int>(DEVICE::FMS_AXIS::PITCH)] = config["spec"]["fmsPitchMinVelocity"].toDouble();
        mSpecParam.mSpecification[static_cast<int>(DEVICE::FMS_AXIS::YAW)] = config["spec"]["fmsYawMinVelocity"].toDouble();

        queue.device = DEVICE::TYPE::FMS;
        queue.type = TEST_DEFINE::TEST_PROCESS::MIN_VEL;
        queue.control = mCtrlParam;
        queue.spec = mSpecParam;
        for(int i = static_cast<int>(DEVICE::FMS_AXIS::ROLL); i <= static_cast<int>(DEVICE::FMS_AXIS::YAW); i++)
        {
            queue.axis = i;
            mQueue.push(queue);
        }
        return;
    }
    case ProcessType::Process_1_2_4:
    {
        mCtrlParam.mPositionStep[static_cast<int>(DEVICE::FMS_AXIS::ROLL)] = config["param"]["fmsRollStep"].toDouble();
        mCtrlParam.mPositionStep[static_cast<int>(DEVICE::FMS_AXIS::PITCH)] = config["param"]["fmsPitchStep"].toDouble();
        mCtrlParam.mPositionStep[static_cast<int>(DEVICE::FMS_AXIS::YAW)] = config["param"]["fmsYawStep"].toDouble();

        mSpecParam.mSpecification[static_cast<int>(DEVICE::FMS_AXIS::ROLL)] = config["spec"]["fmsRollAngleResolution"].toDouble();
        mSpecParam.mSpecification[static_cast<int>(DEVICE::FMS_AXIS::PITCH)] = config["spec"]["fmsPitchAngleResolution"].toDouble();
        mSpecParam.mSpecification[static_cast<int>(DEVICE::FMS_AXIS::YAW)] = config["spec"]["fmsYawAngleResolution"].toDouble();

        mCtrlParam.mIsLinear = false;
        queue.device = DEVICE::TYPE::FMS;
        queue.type = TEST_DEFINE::TEST_PROCESS::RESOLUTION;
        queue.control = mCtrlParam;
        queue.spec = mSpecParam;
        for(int i = static_cast<int>(DEVICE::FMS_AXIS::ROLL); i <= static_cast<int>(DEVICE::FMS_AXIS::YAW); i++)
        {
            queue.axis = i;
            mQueue.push(queue);
        }
        return;
    }
    case ProcessType::Process_1_2_5:
    {
        mCtrlParam.mAmplitude[static_cast<int>(DEVICE::FMS_AXIS::ROLL)] = config["param"]["fmsRollAmp"].toDouble();
        mCtrlParam.mFrequency[static_cast<int>(DEVICE::FMS_AXIS::ROLL)] = config["param"]["fmsRollFreq"].toDouble();
        mCtrlParam.mAmplitude[static_cast<int>(DEVICE::FMS_AXIS::PITCH)] = config["param"]["fmsPitchAmp"].toDouble();
        mCtrlParam.mFrequency[static_cast<int>(DEVICE::FMS_AXIS::PITCH)] = config["param"]["fmsPitchFreq"].toDouble();
        mCtrlParam.mAmplitude[static_cast<int>(DEVICE::FMS_AXIS::YAW)] = config["param"]["fmsYawAmp"].toDouble();
        mCtrlParam.mFrequency[static_cast<int>(DEVICE::FMS_AXIS::YAW)] = config["param"]["fmsYawFreq"].toDouble();

        mSpecParam.mSpecification[static_cast<int>(DEVICE::FMS_AXIS::ROLL)] = config["spec"]["fmsRollMaxAcc"].toDouble();
        mSpecParam.mSpecification[static_cast<int>(DEVICE::FMS_AXIS::PITCH)] = config["spec"]["fmsPitchMaxAcc"].toDouble();
        mSpecParam.mSpecification[static_cast<int>(DEVICE::FMS_AXIS::YAW)] = config["spec"]["fmsYawMaxAcc"].toDouble();

        queue.device = DEVICE::TYPE::FMS;
        queue.type = TEST_DEFINE::TEST_PROCESS::MAX_ACC;
        queue.control = mCtrlParam;
        queue.spec = mSpecParam;
        for(int i = static_cast<int>(DEVICE::FMS_AXIS::ROLL); i <= static_cast<int>(DEVICE::FMS_AXIS::YAW); i++)
        {
            queue.axis = i;
            mQueue.push(queue);
        }
        return;
    }
    case ProcessType::Process_1_2_6_7:
    {
        mCtrlParam.mLowerPosition[static_cast<int>(DEVICE::FMS_AXIS::X)] = config["param"]["fmsTxLowerLimitedPos"].toDouble();
        mCtrlParam.mUpperPosition[static_cast<int>(DEVICE::FMS_AXIS::X)] = config["param"]["fmsTxUpperLimitedPos"].toDouble();
        mCtrlParam.mLowerPosition[static_cast<int>(DEVICE::FMS_AXIS::Y)] = config["param"]["fmsTyLowerLimitedPos"].toDouble();
        mCtrlParam.mUpperPosition[static_cast<int>(DEVICE::FMS_AXIS::Y)] = config["param"]["fmsTyUpperLimitedPos"].toDouble();
        mCtrlParam.mLowerPosition[static_cast<int>(DEVICE::FMS_AXIS::Z)] = config["param"]["fmsTzLowerLimitedPos"].toDouble();
        mCtrlParam.mUpperPosition[static_cast<int>(DEVICE::FMS_AXIS::Z)] = config["param"]["fmsTzUpperLimitedPos"].toDouble();

        mSpecParam.mSpecification[static_cast<int>(DEVICE::FMS_AXIS::X)] = config["spec"]["fmsTxUpperLimitedPos"].toDouble();
        mSpecParam.mSpecification[static_cast<int>(DEVICE::FMS_AXIS::Y)] = config["spec"]["fmsTyUpperLimitedPos"].toDouble();
        mSpecParam.mSpecification[static_cast<int>(DEVICE::FMS_AXIS::Z)] = config["spec"]["fmsTzUpperLimitedPos"].toDouble();

        mCtrlParam.mIsLinear = true;
        queue.device = DEVICE::TYPE::FMS;
        queue.type = TEST_DEFINE::TEST_PROCESS::MAX_POS;
        queue.control = mCtrlParam;
        queue.spec = mSpecParam;
        for(int i = static_cast<int>(DEVICE::FMS_AXIS::X); i <= static_cast<int>(DEVICE::FMS_AXIS::Z); i++)
        {
            queue.axis = i;
            mQueue.push(queue);
        }
        return;
    }
    case ProcessType::Process_1_2_8:
    {
        mCtrlParam.mAmplitude[static_cast<int>(DEVICE::FMS_AXIS::X)] = config["param"]["fmsTxAmp"].toDouble();
        mCtrlParam.mFrequency[static_cast<int>(DEVICE::FMS_AXIS::X)] = config["param"]["fmsTxFreq"].toDouble();
        mCtrlParam.mAmplitude[static_cast<int>(DEVICE::FMS_AXIS::Y)] = config["param"]["fmsTyAmp"].toDouble();
        mCtrlParam.mFrequency[static_cast<int>(DEVICE::FMS_AXIS::Y)] = config["param"]["fmsTyFreq"].toDouble();
        mCtrlParam.mAmplitude[static_cast<int>(DEVICE::FMS_AXIS::Z)] = config["param"]["fmsTzAmp"].toDouble();
        mCtrlParam.mFrequency[static_cast<int>(DEVICE::FMS_AXIS::Z)] = config["param"]["fmsTzFreq"].toDouble();

        mSpecParam.mSpecification[static_cast<int>(DEVICE::FMS_AXIS::X)] = config["spec"]["fmsTxMaxVelocity"].toDouble();
        mSpecParam.mSpecification[static_cast<int>(DEVICE::FMS_AXIS::Y)] = config["spec"]["fmsTyMaxVelocity"].toDouble();
        mSpecParam.mSpecification[static_cast<int>(DEVICE::FMS_AXIS::Z)] = config["spec"]["fmsTzMaxVelocity"].toDouble();

        queue.device = DEVICE::TYPE::FMS;
        queue.type = TEST_DEFINE::TEST_PROCESS::MAX_VEL;
        queue.control = mCtrlParam;
        queue.spec = mSpecParam;
        for(int i = static_cast<int>(DEVICE::FMS_AXIS::X); i <= static_cast<int>(DEVICE::FMS_AXIS::Z); i++)
        {
            queue.axis = i;
            mQueue.push(queue);
        }
        return;
    }
    case ProcessType::Process_1_2_9:
    {
        mCtrlParam.mAmplitude[static_cast<int>(DEVICE::FMS_AXIS::X)] = config["param"]["fmsTxAmp"].toDouble();
        mCtrlParam.mFrequency[static_cast<int>(DEVICE::FMS_AXIS::X)] = config["param"]["fmsTxFreq"].toDouble();
        mCtrlParam.mAmplitude[static_cast<int>(DEVICE::FMS_AXIS::Y)] = config["param"]["fmsTyAmp"].toDouble();
        mCtrlParam.mFrequency[static_cast<int>(DEVICE::FMS_AXIS::Y)] = config["param"]["fmsTyFreq"].toDouble();
        mCtrlParam.mAmplitude[static_cast<int>(DEVICE::FMS_AXIS::Z)] = config["param"]["fmsTzAmp"].toDouble();
        mCtrlParam.mFrequency[static_cast<int>(DEVICE::FMS_AXIS::Z)] = config["param"]["fmsTzFreq"].toDouble();

        mSpecParam.mSpecification[static_cast<int>(DEVICE::FMS_AXIS::X)] = config["spec"]["fmsTxMaxAcc"].toDouble();
        mSpecParam.mSpecification[static_cast<int>(DEVICE::FMS_AXIS::Y)] = config["spec"]["fmsTyMaxAcc"].toDouble();
        mSpecParam.mSpecification[static_cast<int>(DEVICE::FMS_AXIS::Z)] = config["spec"]["fmsTzMaxAcc"].toDouble();

        queue.device = DEVICE::TYPE::FMS;
        queue.type = TEST_DEFINE::TEST_PROCESS::MAX_ACC;
        queue.control = mCtrlParam;
        queue.spec = mSpecParam;
        for(int i = static_cast<int>(DEVICE::FMS_AXIS::X); i <= static_cast<int>(DEVICE::FMS_AXIS::Z); i++)
        {
            queue.axis = i;
            mQueue.push(queue);
        }
        return;
    }
    case ProcessType::Process_1_2_10:
    {
        mCtrlParam.mLowerPosition[static_cast<int>(DEVICE::FMS_AXIS::ROLL)] = config["param"]["fmsRxStartPos"].toDouble();
        mCtrlParam.mUpperPosition[static_cast<int>(DEVICE::FMS_AXIS::ROLL)] = config["param"]["fmsRxStopPos"].toDouble();
        mCtrlParam.mPositionStep[static_cast<int>(DEVICE::FMS_AXIS::ROLL)] = config["param"]["fmsRxStepPos"].toDouble();

        mCtrlParam.mLowerPosition[static_cast<int>(DEVICE::FMS_AXIS::PITCH)] = config["param"]["fmsRyStartPos"].toDouble();
        mCtrlParam.mUpperPosition[static_cast<int>(DEVICE::FMS_AXIS::PITCH)] = config["param"]["fmsRyStopPos"].toDouble();
        mCtrlParam.mPositionStep[static_cast<int>(DEVICE::FMS_AXIS::PITCH)] = config["param"]["fmsRyStepPos"].toDouble();

        mCtrlParam.mLowerPosition[static_cast<int>(DEVICE::FMS_AXIS::YAW)] = config["param"]["fmsRzStartPos"].toDouble();
        mCtrlParam.mUpperPosition[static_cast<int>(DEVICE::FMS_AXIS::YAW)] = config["param"]["fmsRzStopPos"].toDouble();
        mCtrlParam.mPositionStep[static_cast<int>(DEVICE::FMS_AXIS::YAW)] = config["param"]["fmsRzStepPos"].toDouble();

        mSpecParam.mSpecification[static_cast<int>(DEVICE::FMS_AXIS::ROLL)] = config["spec"]["fmsRxMaxAngleAccuracy"].toDouble();
        mSpecParam.mSpecification[static_cast<int>(DEVICE::FMS_AXIS::PITCH)] = config["spec"]["fmsRyMaxAngleAccuracy"].toDouble();
        mSpecParam.mSpecification[static_cast<int>(DEVICE::FMS_AXIS::YAW)] = config["spec"]["fmsRzMaxAngleAccuracy"].toDouble();

        queue.device = DEVICE::TYPE::FMS;
        queue.type = TEST_DEFINE::TEST_PROCESS::POSITION;
        queue.control = mCtrlParam;
        queue.spec = mSpecParam;
        for(int i = static_cast<int>(DEVICE::FMS_AXIS::ROLL); i <= static_cast<int>(DEVICE::FMS_AXIS::YAW); i++)
        {
            queue.axis = i;
            mQueue.push(queue);
        }
        return;
    }
    case ProcessType::Process_1_2_11:
    {
        mCtrlParam.mLowerPosition[static_cast<int>(DEVICE::FMS_AXIS::ROLL)] = config["param"]["fmsRxPos1"].toDouble();
        mCtrlParam.mUpperPosition[static_cast<int>(DEVICE::FMS_AXIS::ROLL)] = config["param"]["fmsRxPos2"].toDouble();

        mCtrlParam.mLowerPosition[static_cast<int>(DEVICE::FMS_AXIS::PITCH)] = config["param"]["fmsRyPos1"].toDouble();
        mCtrlParam.mUpperPosition[static_cast<int>(DEVICE::FMS_AXIS::PITCH)] = config["param"]["fmsRyPos2"].toDouble();

        mCtrlParam.mLowerPosition[static_cast<int>(DEVICE::FMS_AXIS::YAW)] = config["param"]["fmsRzPos1"].toDouble();
        mCtrlParam.mUpperPosition[static_cast<int>(DEVICE::FMS_AXIS::YAW)] = config["param"]["fmsRzPos2"].toDouble();

        mCtrlParam.mPositionRepeat = config["param"]["fmsRepeatedMotionNumber"].toInt();

        mSpecParam.mSpecification[static_cast<int>(DEVICE::FMS_AXIS::ROLL)] = config["spec"]["fmsRxMaxRepeatedAngleAccuracy"].toDouble();
        mSpecParam.mSpecification[static_cast<int>(DEVICE::FMS_AXIS::PITCH)] = config["spec"]["fmsRyMaxRepeatedAngleAccuracy"].toDouble();
        mSpecParam.mSpecification[static_cast<int>(DEVICE::FMS_AXIS::YAW)] = config["spec"]["fmsRzMaxRepeatedAngleAccuracy"].toDouble();

        queue.device = DEVICE::TYPE::FMS;
        queue.type = TEST_DEFINE::TEST_PROCESS::POSITION;
        queue.control = mCtrlParam;
        queue.spec = mSpecParam;
        for(int i = static_cast<int>(DEVICE::FMS_AXIS::ROLL); i <= static_cast<int>(DEVICE::FMS_AXIS::YAW); i++)
        {
            queue.axis = i;
            mQueue.push(queue);
        }
        return;
    }
    case ProcessType::Process_2_1_10:
    {
        mCtrlParam.mLowerPosition[static_cast<int>(DEVICE::TMS_AXIS::X)] = config["param"]["tmsAziPos1"].toDouble();
        mCtrlParam.mUpperPosition[static_cast<int>(DEVICE::TMS_AXIS::X)] = config["param"]["tmsAziPos2"].toDouble();
        mCtrlParam.mLowerPosition[static_cast<int>(DEVICE::TMS_AXIS::Y)] = config["param"]["tmsElvPos1"].toDouble();
        mCtrlParam.mUpperPosition[static_cast<int>(DEVICE::TMS_AXIS::Y)] = config["param"]["tmsElvPos2"].toDouble();

        queue.device = DEVICE::TYPE::TMS;
        queue.type = TEST_DEFINE::TEST_PROCESS::CONTROL;
        queue.control = mCtrlParam;
        queue.spec = mSpecParam;
        mQueue.push(queue);
        return;
    }
    case ProcessType::Process_2_2_1:
    {
        mCtrlParam.mLowerPosition[static_cast<int>(DEVICE::TMS_AXIS::X)] = config["param"]["tmsAziLowerLimitedPos"].toDouble();
        mCtrlParam.mUpperPosition[static_cast<int>(DEVICE::TMS_AXIS::X)] = config["param"]["tmsAziUpperLimitedPos"].toDouble();
        mCtrlParam.mLowerPosition[static_cast<int>(DEVICE::TMS_AXIS::Y)] = config["param"]["tmsElvLowerLimitedPos"].toDouble();
        mCtrlParam.mUpperPosition[static_cast<int>(DEVICE::TMS_AXIS::Y)] = config["param"]["tmsElvUpperLimitedPos"].toDouble();

        mSpecParam.mSpecification[static_cast<int>(DEVICE::TMS_AXIS::X)] = config["spec"]["tmsAziMaxRange"].toDouble();
        mSpecParam.mSpecification[static_cast<int>(DEVICE::TMS_AXIS::Y)] = config["spec"]["tmsElvMaxRange"].toDouble();

        mCtrlParam.mIsLinear = false;
        queue.device = DEVICE::TYPE::TMS;
        queue.type = TEST_DEFINE::TEST_PROCESS::MAX_POS;
        queue.control = mCtrlParam;
        queue.spec = mSpecParam;
        for(int i = static_cast<int>(DEVICE::TMS_AXIS::X); i <= static_cast<int>(DEVICE::TMS_AXIS::Y); i++)
        {
            queue.axis = i;
            mQueue.push(queue);
        }
        return;
    }
    case ProcessType::Process_2_2_2:
    {
        mCtrlParam.mAmplitude[static_cast<int>(DEVICE::TMS_AXIS::X)] = config["param"]["fmsTxAmp"].toDouble();
        mCtrlParam.mFrequency[static_cast<int>(DEVICE::TMS_AXIS::X)] = config["param"]["fmsTxFreq"].toDouble();
        mCtrlParam.mAmplitude[static_cast<int>(DEVICE::TMS_AXIS::Y)] = config["param"]["fmsTyAmp"].toDouble();
        mCtrlParam.mFrequency[static_cast<int>(DEVICE::TMS_AXIS::Y)] = config["param"]["fmsTyFreq"].toDouble();

        mSpecParam.mSpecification[static_cast<int>(DEVICE::TMS_AXIS::X)] = config["spec"]["tmsAziMaxVelocity"].toDouble();
        mSpecParam.mSpecification[static_cast<int>(DEVICE::TMS_AXIS::Y)] = config["spec"]["tmsElvMaxVelocity"].toDouble();

        queue.device = DEVICE::TYPE::TMS;
        queue.type = TEST_DEFINE::TEST_PROCESS::MAX_VEL;
        queue.control = mCtrlParam;
        queue.spec = mSpecParam;
        for(int i = static_cast<int>(DEVICE::TMS_AXIS::X); i <= static_cast<int>(DEVICE::TMS_AXIS::Y); i++)
        {
            queue.axis = i;
            mQueue.push(queue);
        }
        return;
    }
    default: return;
    }
}
