#include "configservice.h"
#include <QFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QDebug>
#include <QVariantMap>
#include <QVector>
#include "typedef/globalvar.h"
#include "flux/action/actionprovider.h"

ConfigService::ConfigService(const QString &processorName)
    : ProcessorAbstract(processorName)
{

}

ConfigService::~ConfigService()
{

}

void ConfigService::onMessage(QSharedPointer<BaseMessage> msg)
{

}

void ConfigService::onStartProcess()
{
    LOG_DEBUG("Created ConfigService");
    if(mSystemConfigLoader.loadSystemConfig(FilePath::SystemConfigFilePath.toStdString()))
    {
        LOG_DEBUG("Load file Config Successfully");
        emit sigCreateLogService();
    }
    else
    {
        LOG_DEBUG("Cannot load file config");
    }

}

SystemConfig_t ConfigService::getSystemConfig() const
{
    return mSystemConfigLoader.getSystemConfig();
}

void ConfigService::processActionFromMiddleware(const QSharedPointer<Action> &action)
{
    switch (action->getType<ActionType>())
    {
        case ActionType::LoadProcessFile:
        {
            loadProcessFile(action->getPayload<int>());
            break;
        }
        default:
        break;
    }
}

bool ConfigService::loadProcessFile(int processIndex)
{
    ProcessType processType = static_cast<ProcessType>(processIndex);
    switch (processType)
    {
        case ProcessType::Process_1_1_1:
        {
            break;
        }
        case ProcessType::Process_1_1_2:
        {
            break;
        }
        case ProcessType::Process_1_1_11:
        {
            break;
        }
        case ProcessType::Process_1_2_1:
        {
            break;
        }
        case ProcessType::Process_1_2_2:
        {
            break;
        }
        case ProcessType::Process_1_2_3:
        {
            break;
        }
        case ProcessType::Process_1_2_4:
        {
            break;
        }
        case ProcessType::Process_1_2_5:
        {
            break;
        }
        case ProcessType::Process_1_2_6_7:
        {
            break;
        }
        case ProcessType::Process_1_2_8:
        {
            break;
        }
        case ProcessType::Process_1_2_9:
        {
            break;
        }
        case ProcessType::Process_1_2_10:
        {
            break;
        }
        case ProcessType::Process_1_2_11:
        {
            break;
        }
        case ProcessType::Process_2_1_10:
        {
            break;
        }
        case ProcessType::Process_2_1_11:
        {
            break;
        }
        case ProcessType::Process_2_2_1:
        {
            break;
        }
        case ProcessType::Process_2_2_2:
        {
            break;
        }
        case ProcessType::Process_2_2_3:
        {
            break;
        }
        case ProcessType::Process_2_2_4:
        {
            break;
        }
        case ProcessType::Process_2_2_5:
        {
            break;
        }
        case ProcessType::Process_2_2_9:
        {
            break;
        }
        case ProcessType::Process_2_2_10:
        {
            break;
        }
        case ProcessType::Process_2_2_13_1:
        {
            break;
        }
        case ProcessType::Process_2_2_13_2:
        {
            break;
        }
        default: break;
    }
}
