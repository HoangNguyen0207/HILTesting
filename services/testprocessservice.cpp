#include "testprocessservice.h"
#include "flux/action/actiontypes.h"
#include "typedef/globalvar.h"

TestProcessService::TestProcessService(const QString& processorName)
    : ProcessorAbstract(processorName)
{
    mTestFactory = new TestProcessFactory();
}

TestProcessService::~TestProcessService()
{
    mTestFactory->removeTestProcess(mTestProcess);
    delete [] mTestFactory;
    mTestFactory = nullptr;
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
    default: break;
    }
}

void TestProcessService::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == mTestTimer)
    {
        if(mTestProcess)
        {
            int ret = mTestProcess->run();
            if(ret == TEST_PROCESS_PAUSE ||
                    ret == TEST_PROCESS_WAIT_INPUT_0)
            {
                changeTestState(TEST_DEFINE::STATE::PAUSE);
                if(ret == TEST_PROCESS_WAIT_INPUT_0)
                {
                    //Send action
                }
            }
            else if(ret != TEST_PROCESS_RUNNING)
            {
                //process Test result here
                if(ret == TEST_PROCESS_ERROR)
                {
                    //Process Error
                }
                else if(ret == TEST_PROCESS_PASS)
                {
                    //Test is pass
                }
                else if(ret == TEST_PROCESS_FAIL)
                {
                    //Test is fail
                }
                changeTestState(TEST_DEFINE::STATE::IDLE);
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
    mState = state;
    //Dispatch to UI for displaying
}





