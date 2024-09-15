#pragma once
#include "action.h"
#include "processorabs/processorabstract.h"
#include "utils/configLoader/systemconfigloader.h"
#include "utils/bytebuffer.h"
#include "connector/tcpserverconnector.h"
#include "connector/tcpclientconnector.h"
#include "connector/udpunicastconnector.h"
#include <QSharedPointer>
//#include <utils/binarylogger/binarylogger.h>

using namespace flux_qt;

class LogService final : public ProcessorAbstract
{
        Q_OBJECT
    public:
        LogService(const QString& processorName);
        ~LogService() override;
        void onMessage(QSharedPointer<BaseMessage> msg) override;
        void onStartProcess() override;
        void setSystemConfig(const SystemConfig_t& systemConfig);

    public slots:
        void processActionFromMiddleware(const QSharedPointer<Action>& action);

    signals:

    private:

    private:
        SystemConfig_t mSystemConfig;
//        BinaryLogger mLogger;

};

