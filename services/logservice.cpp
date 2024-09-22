#include "logservice.h"
#include "flux/action/actiontypes.h"
#include "message/messagetype.h"
#include "logger/logger.h"

LogService::LogService(const QString &processorName)
    : ProcessorAbstract(processorName)
{

}

LogService::~LogService()
{

}

void LogService::onMessage(QSharedPointer<BaseMessage> msg)
{

}

void LogService::onStartProcess()
{
    LOG_DEBUG("Created LogService");
}

void LogService::setSystemConfig(const SystemConfig_t &systemConfig)
{
    mSystemConfig = systemConfig;
}

void LogService::processActionFromMiddleware(const QSharedPointer<Action> &action)
{
    switch (action->getType<ActionType>())
    {
//        case ActionType::SendFileDataToProcessService:
//        {
//            QVariantMap dataMap = action->getPayload<QVariantMap>();
//            QVariantMap paramMap = dataMap.value("param").toMap();
//            break;
//        }
        default:
        break;
    }
}
