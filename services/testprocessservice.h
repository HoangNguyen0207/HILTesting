#ifndef TESTPROCESSSERVICE_H
#define TESTPROCESSSERVICE_H

#include "processorabs/processorabstract.h"
#include "TestProcess/TestProcessFactory.h"
#include "action.h"
#include <QTimer>
#include <QTimerEvent>

using namespace flux_qt;

typedef struct {
    DEVICE::TYPE device;
    int axis;
    TEST_DEFINE::TEST_PROCESS type;
} TestProcessQueuePart;

class TestProcessService : public ProcessorAbstract
{
    Q_OBJECT
public:
    TestProcessService(const QString& processorName);
    ~TestProcessService() override;

    void timerEvent(QTimerEvent *event) override;

public slots:
    void onStopProcess() override;
    void onStartProcess() override;
    void onMessage(QSharedPointer<BaseMessage> msg) override;
    void processActionFromMiddleware(const QSharedPointer<Action> &action);

private:
    void updateCenterCoordinate(int device, int axis, double x, double y, double z);
    void changeTestState(TEST_DEFINE::STATE state);

private:
    TestProcessFactory* mTestFactory {nullptr};
    TestProcess* mTestProcess {nullptr};

    std::vector<double> mCenterCoordinate[2][3];

    TEST_DEFINE::STATE mState {TEST_DEFINE::STATE::IDLE};
    std::queue<TestProcessQueuePart> mTestQueue;

    int mTestTimer {0};
};

#endif // TESTPROCESSSERVICE_H
