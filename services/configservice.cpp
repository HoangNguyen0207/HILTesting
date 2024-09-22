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

const std::map<ProcessType, QString> mConfigFilePath =
{
    {ProcessType::Process_1_1_1,     ProcessFilePath::Process_1_1_1     },
    {ProcessType::Process_1_1_2,     ProcessFilePath::Process_1_1_2     },
    {ProcessType::Process_1_1_11,    ProcessFilePath::Process_1_1_11    },
    {ProcessType::Process_1_2_1,     ProcessFilePath::Process_1_2_1     },
    {ProcessType::Process_1_2_2,     ProcessFilePath::Process_1_2_2     },
    {ProcessType::Process_1_2_3,     ProcessFilePath::Process_1_2_3     },
    {ProcessType::Process_1_2_4,     ProcessFilePath::Process_1_2_4     },
    {ProcessType::Process_1_2_5,     ProcessFilePath::Process_1_2_5     },
    {ProcessType::Process_1_2_6_7,   ProcessFilePath::Process_1_2_6_7   },
    {ProcessType::Process_1_2_8,     ProcessFilePath::Process_1_2_8     },
    {ProcessType::Process_1_2_9,     ProcessFilePath::Process_1_2_9     },
    {ProcessType::Process_1_2_10,    ProcessFilePath::Process_1_2_10    },
    {ProcessType::Process_1_2_11,    ProcessFilePath::Process_1_2_11    },
    {ProcessType::Process_2_1_10,    ProcessFilePath::Process_2_1_10    },
    {ProcessType::Process_2_1_11,    ProcessFilePath::Process_2_1_11    },
    {ProcessType::Process_2_2_1,     ProcessFilePath::Process_2_2_1     },
    {ProcessType::Process_2_2_2,     ProcessFilePath::Process_2_2_2     },
    {ProcessType::Process_2_2_3,     ProcessFilePath::Process_2_2_3     },
    {ProcessType::Process_2_2_4,     ProcessFilePath::Process_2_2_4     },
    {ProcessType::Process_2_2_5,     ProcessFilePath::Process_2_2_5     },
    {ProcessType::Process_2_2_9,     ProcessFilePath::Process_2_2_9     },
    {ProcessType::Process_2_2_10,    ProcessFilePath::Process_2_2_10    },
    {ProcessType::Process_2_2_13_1,  ProcessFilePath::Process_2_2_13_1  },
    {ProcessType::Process_2_2_13_2,  ProcessFilePath::Process_2_2_13_2  }
};

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
}
