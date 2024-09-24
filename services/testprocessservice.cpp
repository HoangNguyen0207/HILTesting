#include "testprocessservice.h"
#include "flux/action/actiontypes.h"
#include "typedef/globalvar.h"
#include "flux/action/actionprovider.h"

TestProcessService::TestProcessService(const QString& processorName)
    : ProcessorAbstract(processorName)
{
    mTestFactory = new TestProcessFactory();
    mTestConfigGetter = new TestConfigGetter();
    mTestTimer = startTimer(2);
    if(mTestTimer == 0)
    {
        LOG_ERROR("Cannot Start Testing Timer");
    }
}

TestProcessService::~TestProcessService()
{
    mTestFactory->removeTestProcess(mTestProcess);
    delete [] mTestFactory;
    delete [] mTestConfigGetter;
    mTestFactory = nullptr;
    mTestConfigGetter = nullptr;
}

void TestProcessService::onStartProcess()
{

}

void TestProcessService::onStopProcess()
{

}

void TestProcessService::onMessage(QSharedPointer<BaseMessage> msg)
{

}

void TestProcessService::processActionFromMiddleware(const QSharedPointer<Action> &action)
{
    switch(action->getType<ActionType>())
    {
    case ActionType::AbortTest:
    {
        if(mTestProcess)
            mTestProcess->abort();
        //Clear All TestProcess in Queue
        std::queue<TestProcessQueuePart> empty;
        std::swap(mTestQueue, empty);
        break;
    }
    case ActionType::UpdatePositionInput:
    {
        if(mTestProcess)
        {
            QVariantMap data = action->getPayload<QVariantMap>();
            std::vector<double> position;
            position.push_back(data["x"].toDouble());
            position.push_back(data["y"].toDouble());
            position.push_back(data["z"].toDouble());
            mTestProcess->updateCoordinate(position);
            mTestProcess->resume();
        }
        break;
    }
    case ActionType::UpdateCenterInput:
    {
        QVariantMap data = action->getPayload<QVariantMap>();
        int device = data["device"].toInt();
        int axis = data["axis"].toInt();
        std::vector<double> position;
        position.push_back(data["x"].toDouble());
        position.push_back(data["y"].toDouble());
        position.push_back(data["z"].toDouble());
        mCenterCoordinate[device][axis] = position;
        break;
    }
    case ActionType::SendFileDataToProcessService:
    {
        QVariantMap config = action->getPayload<QVariantMap>();
        QVariantMap controlParam, specParam;
        ProcessType testType = static_cast<ProcessType>(config["type"].toInt());
        if(config.contains("param"))
        {
            controlParam = config.value("param").toMap();
        }
        if(config.contains("spec"))
        {
            specParam = config.value("spec").toMap();
        }
        QMap<QString, QVariantMap> dataMap;
        dataMap.insert("param", controlParam);
        dataMap.insert("spec", specParam);

        mTestConfigGetter->updateConfig(testType, dataMap, mTestQueue);
        break;
    }

    default: break;
    }
}

void TestProcessService::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == mTestTimer)
    {
        switch(mState)
        {
        case TEST_DEFINE::STATE::IDLE:
        {
            mIsTestPass = true;
            if(mTestQueue.empty() == false)
            {
                TestProcessQueuePart config = mTestQueue.front();
                mTestQueue.pop();
                mTestProcess = mTestFactory->createTestProcess(config.device, config.axis, config.control, config.spec, config.type);
                if(mTestProcess)
                {
                    LOG_DEBUG("Start Running Test %d on axis %d, device %d",
                              static_cast<int>(config.type), static_cast<int>(config.axis), static_cast<int>(config.device));
                    mTestProcess->setCenterCoordination(mCenterCoordinate[static_cast<int>(config.device)][static_cast<int>(config.axis)]);
                }
                changeTestState(TEST_DEFINE::STATE::RUNNING);
            }
            break;
        }
        case TEST_DEFINE::STATE::PAUSE:
        {
            int ret = mTestProcess->run();
            if(ret == TEST_PROCESS_IDLE)
                changeTestState(TEST_DEFINE::STATE::IDLE);
            break;
        }
        case TEST_DEFINE::STATE::RUNNING:
        {
            int ret = mTestProcess->run();
            if(ret == TEST_PROCESS_IDLE || ret == TEST_PROCESS_ERROR)
            {
                changeTestState(TEST_DEFINE::STATE::IDLE);
                LOG_DEBUG("Stop Test, ret = %d", ret);
            }
            else if(ret == TEST_PROCESS_WAIT_INPUT_0)
                changeTestState(TEST_DEFINE::STATE::PAUSE);
            else if(ret == TEST_PROCESS_RUNNING)
                changeTestState(TEST_DEFINE::STATE::RUNNING);
            else if(ret == TEST_PROCESS_PASS || ret == TEST_PROCESS_FAIL)
            {
                mIsTestPass &= (ret == TEST_PROCESS_PASS) ? true : false;
                mTestFactory->removeTestProcess(mTestProcess);
                if(mTestQueue.empty() == true)
                {
                    changeTestState(TEST_DEFINE::STATE::IDLE);
                    ActionProvider::instance()->finishTest(mIsTestPass);
                }
                else
                {
                    TestProcessQueuePart config = mTestQueue.front();
                    mTestQueue.pop();
                    mTestProcess = mTestFactory->createTestProcess(config.device, config.axis, config.control, config.spec, config.type);
                    if(mTestProcess)
                    {
                        LOG_DEBUG("Start Running Test %d on axis %d, device %d",
                                  static_cast<int>(config.type), static_cast<int>(config.axis), static_cast<int>(config.device));
                        mTestProcess->setCenterCoordination(mCenterCoordinate[static_cast<int>(config.device)][static_cast<int>(config.axis)]);
                    }
                }
            }
            break;
        }
        }
    }
}

void TestProcessService::updateCenterCoordinate(int device, int axis, double x, double y, double z)
{
    mCenterCoordinate[device][axis].clear();
    mCenterCoordinate[device][axis].push_back(x);
    mCenterCoordinate[device][axis].push_back(y);
    mCenterCoordinate[device][axis].push_back(z);
}

void TestProcessService::changeTestState(TEST_DEFINE::STATE state)
{
    if(mState != state)
    {
        mState = state;
        ActionProvider::instance()->updateState(static_cast<int>(mState));
    }
    //Dispatch to UI for displaying
}

void TestProcessService::setSystemConfig(SystemConfig_t config)
{
    mCenterCoordinate[static_cast<int>(DEVICE::TYPE::FMS)][static_cast<int>(DEVICE::FMS_AXIS::ROLL)].push_back(config.fmsRollCenterX);
    mCenterCoordinate[static_cast<int>(DEVICE::TYPE::FMS)][static_cast<int>(DEVICE::FMS_AXIS::ROLL)].push_back(config.fmsRollCenterY);
    mCenterCoordinate[static_cast<int>(DEVICE::TYPE::FMS)][static_cast<int>(DEVICE::FMS_AXIS::ROLL)].push_back(config.fmsRollCenterZ);

    mCenterCoordinate[static_cast<int>(DEVICE::TYPE::FMS)][static_cast<int>(DEVICE::FMS_AXIS::PITCH)].push_back(config.fmsYawPitchCenterX);
    mCenterCoordinate[static_cast<int>(DEVICE::TYPE::FMS)][static_cast<int>(DEVICE::FMS_AXIS::PITCH)].push_back(config.fmsYawPitchCenterY);
    mCenterCoordinate[static_cast<int>(DEVICE::TYPE::FMS)][static_cast<int>(DEVICE::FMS_AXIS::PITCH)].push_back(config.fmsYawPitchCenterZ);

    mCenterCoordinate[static_cast<int>(DEVICE::TYPE::FMS)][static_cast<int>(DEVICE::FMS_AXIS::YAW)].push_back(config.fmsYawPitchCenterX);
    mCenterCoordinate[static_cast<int>(DEVICE::TYPE::FMS)][static_cast<int>(DEVICE::FMS_AXIS::YAW)].push_back(config.fmsYawPitchCenterY);
    mCenterCoordinate[static_cast<int>(DEVICE::TYPE::FMS)][static_cast<int>(DEVICE::FMS_AXIS::YAW)].push_back(config.fmsYawPitchCenterZ);

    mCenterCoordinate[static_cast<int>(DEVICE::TYPE::TMS)][static_cast<int>(DEVICE::TMS_AXIS::GYMBAL_X)].push_back(config.tmsCenterX);
    mCenterCoordinate[static_cast<int>(DEVICE::TYPE::TMS)][static_cast<int>(DEVICE::TMS_AXIS::GYMBAL_X)].push_back(config.tmsCenterY);
    mCenterCoordinate[static_cast<int>(DEVICE::TYPE::TMS)][static_cast<int>(DEVICE::TMS_AXIS::GYMBAL_X)].push_back(config.tmsCenterZ);

    mCenterCoordinate[static_cast<int>(DEVICE::TYPE::TMS)][static_cast<int>(DEVICE::TMS_AXIS::GYMBAL_Y)].push_back(config.tmsCenterX);
    mCenterCoordinate[static_cast<int>(DEVICE::TYPE::TMS)][static_cast<int>(DEVICE::TMS_AXIS::GYMBAL_Y)].push_back(config.tmsCenterY);
    mCenterCoordinate[static_cast<int>(DEVICE::TYPE::TMS)][static_cast<int>(DEVICE::TMS_AXIS::GYMBAL_Y)].push_back(config.tmsCenterZ);

}



