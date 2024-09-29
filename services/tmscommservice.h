#pragma once
#include "action.h"
#include "processorabs/processorabstract.h"
#include "utils/configLoader/systemconfigloader.h"
#include "utils/bytebuffer.h"
#include "connector/tcpserverconnector.h"
#include "connector/tcpclientconnector.h"
#include "connector/udpunicastconnector.h"
#include "flux/action/actiontypes.h"
#include "flux/action/actionprovider.h"
#include <QScopedPointer>

using namespace flux_qt;

class TMSCommService : public ProcessorAbstract
{
        Q_OBJECT
    public:
        TMSCommService(const QString& processorName);
        ~TMSCommService() override;
        void onMessage(QSharedPointer<BaseMessage> msg) override;
        void onStartProcess() override;
        void setSystemConfig(const SystemConfig_t& systemConfig);

    public slots:
        void processActionFromMiddleware(const QSharedPointer<Action>& action);

    private slots:
        void onReceiveResponse(QString response);

    private:
        int sendCommand(const QString& cmd);
        int enable();
        int disable();
        int reset();
        int controlOn();
        int controlOff();
        int powerOff();
        int stopMoving();
        int homing();
        int moveOff();
        int moveAbsPosition(const QVariantMap& data);

        int queryStatus();
        int queryVelocity();
        int queryAcc();
        int queryHomeOffset();
        int queryLimitWorkSpace();
        int queryLimitVelocity();
        int queryLimitAcc();

        int configVelocity(const QVariantMap& data);
        int configLimitVelocity(const QVariantMap& data);
        int configAcc(const QVariantMap& data);
        int configLimitAcc(const QVariantMap& data);
        int configHomeOffset(const QVariantMap& data);

    private:
        SystemConfig_t mSystemConfig;
        ByteBuffer mByteBuffer;

};

