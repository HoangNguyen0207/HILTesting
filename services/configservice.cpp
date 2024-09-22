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
#include "flux/store/mainstore.h"

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
    bool rs = true;

    ProcessType processType = static_cast<ProcessType>(processIndex);
    switch (processType)
    {
        case ProcessType::Process_1_1_1:
        {
            rs = loadProcessFile_1_1_1(ProcessFilePath::Process_1_1_1);
            if(rs == true)
            {
                MainStore::getInstance()->setLoadedProcessFilePath("Loaded " + QString(ProcessFilePath::Process_1_1_1).remove("../../config/ProcessFiles/"));
            }else
            {
                MainStore::getInstance()->setLoadedProcessFilePath("Error");
            }
            break;
        }
        case ProcessType::Process_1_1_2:
        {
            rs = loadProcessFile_1_1_2(ProcessFilePath::Process_1_1_2);
            if(rs == true)
            {
                MainStore::getInstance()->setLoadedProcessFilePath("Loaded " + QString(ProcessFilePath::Process_1_1_2).remove("../../config/ProcessFiles/"));
            }else
            {
                MainStore::getInstance()->setLoadedProcessFilePath("Error");
            }
            break;
        }
        case ProcessType::Process_1_1_11:
        {
            rs = loadProcessFile_1_1_11(ProcessFilePath::Process_1_1_11);
            if(rs == true)
            {
                MainStore::getInstance()->setLoadedProcessFilePath("Loaded " + QString(ProcessFilePath::Process_1_1_11).remove("../../config/ProcessFiles/"));
            }else
            {
                MainStore::getInstance()->setLoadedProcessFilePath("Error");
            }
            break;
        }
        case ProcessType::Process_1_2_1:
        {
            rs = loadProcessFile_1_2_1(ProcessFilePath::Process_1_2_1);
            if(rs == true)
            {
                MainStore::getInstance()->setLoadedProcessFilePath("Loaded " + QString(ProcessFilePath::Process_1_2_1).remove("../../config/ProcessFiles/"));
            }else
            {
                MainStore::getInstance()->setLoadedProcessFilePath("Error");
            }
            break;
        }
        case ProcessType::Process_1_2_2:
        {
            rs = loadProcessFile_1_2_2(ProcessFilePath::Process_1_2_2);
            if(rs == true)
            {
                MainStore::getInstance()->setLoadedProcessFilePath("Loaded " + QString(ProcessFilePath::Process_1_2_2).remove("../../config/ProcessFiles/"));
            }else
            {
                MainStore::getInstance()->setLoadedProcessFilePath("Error");
            }
            break;
        }
        case ProcessType::Process_1_2_3:
        {
            rs = loadProcessFile_1_2_3(ProcessFilePath::Process_1_2_3);
            if(rs == true)
            {
                MainStore::getInstance()->setLoadedProcessFilePath("Loaded " + QString(ProcessFilePath::Process_1_2_3).remove("../../config/ProcessFiles/"));
            }else
            {
                MainStore::getInstance()->setLoadedProcessFilePath("Error");
            }
            break;
        }
        case ProcessType::Process_1_2_4:
        {
            rs = loadProcessFile_1_2_4(ProcessFilePath::Process_1_2_4);
            if(rs == true)
            {
                MainStore::getInstance()->setLoadedProcessFilePath("Loaded " + QString(ProcessFilePath::Process_1_2_4).remove("../../config/ProcessFiles/"));
            }else
            {
                MainStore::getInstance()->setLoadedProcessFilePath("Error");
            }
            break;
        }
        case ProcessType::Process_1_2_5:
        {
            rs = loadProcessFile_1_2_5(ProcessFilePath::Process_1_2_5);
            if(rs == true)
            {
                MainStore::getInstance()->setLoadedProcessFilePath("Loaded " + QString(ProcessFilePath::Process_1_2_5).remove("../../config/ProcessFiles/"));
            }else
            {
                MainStore::getInstance()->setLoadedProcessFilePath("Error");
            }
            break;
        }
        case ProcessType::Process_1_2_6_7:
        {
            rs = loadProcessFile_1_2_6_7(ProcessFilePath::Process_1_2_6_7);
            if(rs == true)
            {
                MainStore::getInstance()->setLoadedProcessFilePath("Loaded " + QString(ProcessFilePath::Process_1_2_6_7).remove("../../config/ProcessFiles/"));
            }else
            {
                MainStore::getInstance()->setLoadedProcessFilePath("Error");
            }
            break;
        }
        case ProcessType::Process_1_2_8:
        {
            rs = loadProcessFile_1_2_8(ProcessFilePath::Process_1_2_8);
            if(rs == true)
            {
                MainStore::getInstance()->setLoadedProcessFilePath("Loaded " + QString(ProcessFilePath::Process_1_2_8).remove("../../config/ProcessFiles/"));
            }else
            {
                MainStore::getInstance()->setLoadedProcessFilePath("Error");
            }
            break;
        }
        case ProcessType::Process_1_2_9:
        {
            rs = loadProcessFile_1_2_9(ProcessFilePath::Process_1_2_9);
            if(rs == true)
            {
                MainStore::getInstance()->setLoadedProcessFilePath("Loaded " + QString(ProcessFilePath::Process_1_2_9).remove("../../config/ProcessFiles/"));
            }else
            {
                MainStore::getInstance()->setLoadedProcessFilePath("Error");
            }
            break;
        }
        case ProcessType::Process_1_2_10:
        {
            rs = loadProcessFile_1_2_10(ProcessFilePath::Process_1_2_10);
            if(rs == true)
            {
                MainStore::getInstance()->setLoadedProcessFilePath("Loaded " + QString(ProcessFilePath::Process_1_2_10).remove("../../config/ProcessFiles/"));
            }else
            {
                MainStore::getInstance()->setLoadedProcessFilePath("Error");
            }
            break;
        }
        case ProcessType::Process_1_2_11:
        {
            rs = loadProcessFile_1_2_11(ProcessFilePath::Process_1_2_11);
            if(rs == true)
            {
                MainStore::getInstance()->setLoadedProcessFilePath("Loaded " + QString(ProcessFilePath::Process_1_2_11).remove("../../config/ProcessFiles/"));
            }else
            {
                MainStore::getInstance()->setLoadedProcessFilePath("Error");
            }
            break;
        }
        case ProcessType::Process_2_1_10:
        {
            rs = loadProcessFile_2_1_10(ProcessFilePath::Process_2_1_10);
            if(rs == true)
            {
                MainStore::getInstance()->setLoadedProcessFilePath("Loaded " + QString(ProcessFilePath::Process_2_1_10).remove("../../config/ProcessFiles/"));
            }else
            {
                MainStore::getInstance()->setLoadedProcessFilePath("Error");
            }
            break;
        }
        case ProcessType::Process_2_1_11:
        {
            rs = loadProcessFile_2_1_11(ProcessFilePath::Process_2_1_11);
            if(rs == true)
            {
                MainStore::getInstance()->setLoadedProcessFilePath("Loaded " + QString(ProcessFilePath::Process_2_1_11).remove("../../config/ProcessFiles/"));
            }else
            {
                MainStore::getInstance()->setLoadedProcessFilePath("Error");
            }
            break;
        }
        case ProcessType::Process_2_2_1:
        {
            rs = loadProcessFile_2_2_1(ProcessFilePath::Process_2_2_1);
            if(rs == true)
            {
                MainStore::getInstance()->setLoadedProcessFilePath("Loaded " + QString(ProcessFilePath::Process_2_2_1).remove("../../config/ProcessFiles/"));
            }else
            {
                MainStore::getInstance()->setLoadedProcessFilePath("Error");
            }
            break;
        }
        case ProcessType::Process_2_2_2:
        {
            rs = loadProcessFile_2_2_2(ProcessFilePath::Process_2_2_2);
            if(rs == true)
            {
                MainStore::getInstance()->setLoadedProcessFilePath("Loaded " + QString(ProcessFilePath::Process_2_2_2).remove("../../config/ProcessFiles/"));
            }else
            {
                MainStore::getInstance()->setLoadedProcessFilePath("Error");
            }
            break;
        }
        case ProcessType::Process_2_2_3:
        {
            rs = loadProcessFile_2_2_3(ProcessFilePath::Process_2_2_3);
            if(rs == true)
            {
                MainStore::getInstance()->setLoadedProcessFilePath("Loaded " + QString(ProcessFilePath::Process_2_2_3).remove("../../config/ProcessFiles/"));
            }else
            {
                MainStore::getInstance()->setLoadedProcessFilePath("Error");
            }
            break;
        }
        case ProcessType::Process_2_2_4:
        {
            rs = loadProcessFile_2_2_4(ProcessFilePath::Process_2_2_4);
            if(rs == true)
            {
                MainStore::getInstance()->setLoadedProcessFilePath("Loaded " + QString(ProcessFilePath::Process_2_2_4).remove("../../config/ProcessFiles/"));
            }else
            {
                MainStore::getInstance()->setLoadedProcessFilePath("Error");
            }
            break;
        }
        case ProcessType::Process_2_2_5:
        {
            rs = loadProcessFile_2_2_5(ProcessFilePath::Process_2_2_5);
            if(rs == true)
            {
                MainStore::getInstance()->setLoadedProcessFilePath("Loaded " + QString(ProcessFilePath::Process_2_2_5).remove("../../config/ProcessFiles/"));
            }else
            {
                MainStore::getInstance()->setLoadedProcessFilePath("Error");
            }
            break;
        }
        case ProcessType::Process_2_2_9:
        {
            rs = loadProcessFile_2_2_9(ProcessFilePath::Process_2_2_9);
            if(rs == true)
            {
                MainStore::getInstance()->setLoadedProcessFilePath("Loaded " + QString(ProcessFilePath::Process_2_2_9).remove("../../config/ProcessFiles/"));
            }else
            {
                MainStore::getInstance()->setLoadedProcessFilePath("Error");
            }
            break;
        }
        case ProcessType::Process_2_2_10:
        {
            rs = loadProcessFile_2_2_10(ProcessFilePath::Process_2_2_10);
            if(rs == true)
            {
                MainStore::getInstance()->setLoadedProcessFilePath("Loaded " + QString(ProcessFilePath::Process_2_2_10).remove("../../config/ProcessFiles/"));
            }else
            {
                MainStore::getInstance()->setLoadedProcessFilePath("Error");
            }
            break;
        }
        case ProcessType::Process_2_2_13_1:
        {
            rs = loadProcessFile_2_2_13_1(ProcessFilePath::Process_2_2_13_1);
            if(rs == true)
            {
                MainStore::getInstance()->setLoadedProcessFilePath("Loaded " + QString(ProcessFilePath::Process_2_2_13_1).remove("../../config/ProcessFiles/"));
            }else
            {
                MainStore::getInstance()->setLoadedProcessFilePath("Error");
            }
            break;
        }
        case ProcessType::Process_2_2_13_2:
        {
            rs = loadProcessFile_2_2_13_2(ProcessFilePath::Process_2_2_13_2);
            if(rs == true)
            {
                MainStore::getInstance()->setLoadedProcessFilePath("Loaded " + QString(ProcessFilePath::Process_2_2_13_2).remove("../../config/ProcessFiles/"));
            }else
            {
                MainStore::getInstance()->setLoadedProcessFilePath("Error");
            }
            break;
        }
        default: break;
    }

    return rs;
}

bool ConfigService::loadProcessFile_1_1_1(const QString &filePath)
{
    QString path = filePath;
    path = path.remove("file://");

    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
    {
        LOG_ERROR("Could not read process file!, %s", file.errorString().toStdString());
        return false;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject mainObj = doc.object();

    QVariantMap dataMap;
    if(mainObj.value("type").toInt() == static_cast<int>(ProcessType::Process_1_1_1))
    {
        dataMap.insert("type",mainObj.value("type").toInt());
        dataMap.insert("name",mainObj.value("name").toString());

        QVariantMap paramMap;
        paramMap.insert("fmsRxApm",mainObj.value("param").toObject().value("fmsRxApm").toDouble());
        paramMap.insert("fmsRxFreq",mainObj.value("param").toObject().value("fmsRxFreq").toDouble());
        paramMap.insert("fmsRyAmp",mainObj.value("param").toObject().value("fmsRyAmp").toDouble());
        paramMap.insert("fmsRyFreq",mainObj.value("param").toObject().value("fmsRyFreq").toDouble());
        paramMap.insert("fmsRzAmp",mainObj.value("param").toObject().value("fmsRzAmp").toDouble());
        paramMap.insert("fmsRzFreq",mainObj.value("param").toObject().value("fmsRzFreq").toDouble());
        paramMap.insert("tmsTxAmp",mainObj.value("param").toObject().value("tmsTxAmp").toDouble());
        paramMap.insert("tmsTxFreq",mainObj.value("param").toObject().value("tmsTxFreq").toDouble());
        paramMap.insert("tmsTyAmp",mainObj.value("param").toObject().value("tmsTyAmp").toDouble());
        paramMap.insert("tmsTyFreq",mainObj.value("param").toObject().value("tmsTyFreq").toDouble());

        dataMap.insert("param",paramMap);
        ActionProvider::instance()->sendFileDataToProcessService(dataMap);
        return true;
    }else
    {
        return false;
    }
}

bool ConfigService::loadProcessFile_1_1_2(const QString &filePath)
{
    QString path = filePath;
    path = path.remove("file://");

    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
    {
        LOG_ERROR("Could not read process file!, %s", file.errorString().toStdString());
        return false;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject mainObj = doc.object();

    QVariantMap dataMap;
    if(mainObj.value("type").toInt() == static_cast<int>(ProcessType::Process_1_1_2))
    {
        dataMap.insert("type",mainObj.value("type").toInt());
        dataMap.insert("name",mainObj.value("name").toString());

        QVariantMap paramMap;
        paramMap.insert("fmsRxPos1",mainObj.value("param").toObject().value("fmsRxPos1").toDouble());
        paramMap.insert("fmsRxPos2",mainObj.value("param").toObject().value("fmsRxPos2").toDouble());
        paramMap.insert("fmsRyPos1",mainObj.value("param").toObject().value("fmsRyPos1").toDouble());
        paramMap.insert("fmsRyPos2",mainObj.value("param").toObject().value("fmsRyPos2").toDouble());
        paramMap.insert("fmsRzPos1",mainObj.value("param").toObject().value("fmsRzPos1").toDouble());
        paramMap.insert("fmsRzPos2",mainObj.value("param").toObject().value("fmsRzPos2").toDouble());
        paramMap.insert("fmsTxPos1",mainObj.value("param").toObject().value("fmsTxPos1").toDouble());
        paramMap.insert("fmsTxPos2",mainObj.value("param").toObject().value("fmsTxPos2").toDouble());
        paramMap.insert("fmsTyPos1",mainObj.value("param").toObject().value("fmsTyPos1").toDouble());
        paramMap.insert("fmsTyPos2",mainObj.value("param").toObject().value("fmsTyPos2").toDouble());
        paramMap.insert("fmsTzPos1",mainObj.value("param").toObject().value("fmsTzPos1").toDouble());
        paramMap.insert("fmsTzPos2",mainObj.value("param").toObject().value("fmsTzPos2").toDouble());

        dataMap.insert("param",paramMap);
        ActionProvider::instance()->sendFileDataToProcessService(dataMap);
        return true;
    }else
    {
        return false;
    }
}

bool ConfigService::loadProcessFile_1_1_11(const QString &filePath)
{
    QString path = filePath;
    path = path.remove("file://");

    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
    {
        LOG_ERROR("Could not read process file!, %s", file.errorString().toStdString());
        return false;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject mainObj = doc.object();

    QVariantMap dataMap;
    if(mainObj.value("type").toInt() == static_cast<int>(ProcessType::Process_1_1_11))
    {
        dataMap.insert("type",mainObj.value("type").toInt());
        dataMap.insert("name",mainObj.value("name").toString());

        QVariantMap paramMap;
        paramMap.insert("fmsRxStartPos",mainObj.value("param").toObject().value("fmsRxStartPos").toDouble());
        paramMap.insert("fmsRxStopPos",mainObj.value("param").toObject().value("fmsRxStopPos").toDouble());
        paramMap.insert("fmsRxStepPos",mainObj.value("param").toObject().value("fmsRxStepPos").toDouble());
        paramMap.insert("fmsRyStartPos",mainObj.value("param").toObject().value("fmsRyStartPos").toDouble());
        paramMap.insert("fmsRyStopPos",mainObj.value("param").toObject().value("fmsRyStopPos").toDouble());
        paramMap.insert("fmsRyStepPos",mainObj.value("param").toObject().value("fmsRyStepPos").toDouble());
        paramMap.insert("fmsRzStartPos",mainObj.value("param").toObject().value("fmsRzStartPos").toDouble());
        paramMap.insert("fmsRzStopPos",mainObj.value("param").toObject().value("fmsRzStopPos").toDouble());
        paramMap.insert("fmsRzStepPos",mainObj.value("param").toObject().value("fmsRzStepPos").toDouble());
        paramMap.insert("fmsRxAmp",mainObj.value("param").toObject().value("fmsRxAmp").toDouble());
        paramMap.insert("fmsRxFreq",mainObj.value("param").toObject().value("fmsRxFreq").toDouble());
        paramMap.insert("fmsRyAmp",mainObj.value("param").toObject().value("fmsRyAmp").toDouble());
        paramMap.insert("fmsRyFreq",mainObj.value("param").toObject().value("fmsRyFreq").toDouble());
        paramMap.insert("fmsRzAmp",mainObj.value("param").toObject().value("fmsRzAmp").toDouble());
        paramMap.insert("fmsRzFreq",mainObj.value("param").toObject().value("fmsRzFreq").toDouble());

        dataMap.insert("param",paramMap);
        ActionProvider::instance()->sendFileDataToProcessService(dataMap);
        return true;
    }else
    {
        return false;
    }
}

bool ConfigService::loadProcessFile_1_2_1(const QString &filePath)
{
    QString path = filePath;
    path = path.remove("file://");

    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
    {
        LOG_ERROR("Could not read process file!, %s", file.errorString().toStdString());
        return false;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject mainObj = doc.object();

    QVariantMap dataMap;
    if(mainObj.value("type").toInt() == static_cast<int>(ProcessType::Process_1_2_1))
    {
        dataMap.insert("type",mainObj.value("type").toInt());
        dataMap.insert("name",mainObj.value("name").toString());

        QVariantMap paramMap;
        paramMap.insert("fmsRxLowerLimitedPos",mainObj.value("param").toObject().value("fmsRxLowerLimitedPos").toDouble());
        paramMap.insert("fmsRxUpperLimitedPos",mainObj.value("param").toObject().value("fmsRxUpperLimitedPos").toDouble());
        paramMap.insert("fmsRyLowerLimitedPos",mainObj.value("param").toObject().value("fmsRyLowerLimitedPos").toDouble());
        paramMap.insert("fmsRyUpperLimitedPos",mainObj.value("param").toObject().value("fmsRyUpperLimitedPos").toDouble());
        paramMap.insert("fmsRzLowerLimitedPos",mainObj.value("param").toObject().value("fmsRzLowerLimitedPos").toDouble());
        paramMap.insert("fmsRzUpperLimitedPos",mainObj.value("param").toObject().value("fmsRzUpperLimitedPos").toDouble());

        QVariantMap specMap;
        specMap.insert("fmsRxLowerLimitedPos",mainObj.value("spec").toObject().value("fmsRxLowerLimitedPos").toDouble());
        specMap.insert("fmsRxUpperLimitedPos",mainObj.value("spec").toObject().value("fmsRxUpperLimitedPos").toDouble());
        specMap.insert("fmsRyLowerLimitedPos",mainObj.value("spec").toObject().value("fmsRyLowerLimitedPos").toDouble());
        specMap.insert("fmsRyUpperLimitedPos",mainObj.value("spec").toObject().value("fmsRyUpperLimitedPos").toDouble());
        specMap.insert("fmsRzLowerLimitedPos",mainObj.value("spec").toObject().value("fmsRzLowerLimitedPos").toDouble());
        specMap.insert("fmsRzUpperLimitedPos",mainObj.value("spec").toObject().value("fmsRzUpperLimitedPos").toDouble());

        dataMap.insert("param",paramMap);
        dataMap.insert("spec",specMap);
        ActionProvider::instance()->sendFileDataToProcessService(dataMap);
        return true;
    }else
    {
        return false;
    }
}

bool ConfigService::loadProcessFile_1_2_2(const QString &filePath)
{
    QString path = filePath;
    path = path.remove("file://");

    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
    {
        LOG_ERROR("Could not read process file!, %s", file.errorString().toStdString());
        return false;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject mainObj = doc.object();

    QVariantMap dataMap;
    if(mainObj.value("type").toInt() == static_cast<int>(ProcessType::Process_1_2_2))
    {
        dataMap.insert("type",mainObj.value("type").toInt());
        dataMap.insert("name",mainObj.value("name").toString());

        QVariantMap paramMap;
        paramMap.insert("fmsRxAmp",mainObj.value("param").toObject().value("fmsRxAmp").toDouble());
        paramMap.insert("fmsRxFreq",mainObj.value("param").toObject().value("fmsRxFreq").toDouble());
        paramMap.insert("fmsRxMaxVelocity",mainObj.value("param").toObject().value("fmsRxMaxVelocity").toDouble());
        paramMap.insert("fmsRyAmp",mainObj.value("param").toObject().value("fmsRyAmp").toDouble());
        paramMap.insert("fmsRyFreq",mainObj.value("param").toObject().value("fmsRyFreq").toDouble());
        paramMap.insert("fmsRyMaxVelocity",mainObj.value("param").toObject().value("fmsRyMaxVelocity").toDouble());
        paramMap.insert("fmsRzAmp",mainObj.value("param").toObject().value("fmsRzAmp").toDouble());
        paramMap.insert("fmsRzFreq",mainObj.value("param").toObject().value("fmsRzFreq").toDouble());
        paramMap.insert("fmsRzMaxVelocity",mainObj.value("param").toObject().value("fmsRzMaxVelocity").toDouble());

        QVariantMap specMap;
        specMap.insert("fmsRxMaxVelocity",mainObj.value("spec").toObject().value("fmsRxMaxVelocity").toDouble());
        specMap.insert("fmsRyMaxVelocity",mainObj.value("spec").toObject().value("fmsRyMaxVelocity").toDouble());
        specMap.insert("fmsRzMaxVelocity",mainObj.value("spec").toObject().value("fmsRzMaxVelocity").toDouble());

        dataMap.insert("param",paramMap);
        dataMap.insert("spec",specMap);
        ActionProvider::instance()->sendFileDataToProcessService(dataMap);
        return true;
    }else
    {
        return false;
    }
}

bool ConfigService::loadProcessFile_1_2_3(const QString &filePath)
{
    QString path = filePath;
    path = path.remove("file://");

    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
    {
        LOG_ERROR("Could not read process file!, %s", file.errorString().toStdString());
        return false;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject mainObj = doc.object();

    QVariantMap dataMap;
    if(mainObj.value("type").toInt() == static_cast<int>(ProcessType::Process_1_2_3))
    {
        dataMap.insert("type",mainObj.value("type").toInt());
        dataMap.insert("name",mainObj.value("name").toString());

        QVariantMap paramMap;
        paramMap.insert("fmsRxAmp",mainObj.value("param").toObject().value("fmsRxAmp").toDouble());
        paramMap.insert("fmsRxFreq",mainObj.value("param").toObject().value("fmsRxFreq").toDouble());
        paramMap.insert("fmsRxMinVelocity",mainObj.value("param").toObject().value("fmsRxMinVelocity").toDouble());
        paramMap.insert("fmsRyAmp",mainObj.value("param").toObject().value("fmsRyAmp").toDouble());
        paramMap.insert("fmsRyFreq",mainObj.value("param").toObject().value("fmsRyFreq").toDouble());
        paramMap.insert("fmsRyMinVelocity",mainObj.value("param").toObject().value("fmsRyMinVelocity").toDouble());
        paramMap.insert("fmsRzAmp",mainObj.value("param").toObject().value("fmsRzAmp").toDouble());
        paramMap.insert("fmsRzFreq",mainObj.value("param").toObject().value("fmsRzFreq").toDouble());
        paramMap.insert("fmsRzMinVelocity",mainObj.value("param").toObject().value("fmsRzMinVelocity").toDouble());

        QVariantMap specMap;
        specMap.insert("fmsRxMinVelocity",mainObj.value("spec").toObject().value("fmsRxMinVelocity").toDouble());
        specMap.insert("fmsRyMinVelocity",mainObj.value("spec").toObject().value("fmsRyMinVelocity").toDouble());
        specMap.insert("fmsRzMinVelocity",mainObj.value("spec").toObject().value("fmsRzMinVelocity").toDouble());

        dataMap.insert("param",paramMap);
        dataMap.insert("spec",specMap);
        ActionProvider::instance()->sendFileDataToProcessService(dataMap);
        return true;
    }else
    {
        return false;
    }
}

bool ConfigService::loadProcessFile_1_2_4(const QString &filePath)
{
    QString path = filePath;
    path = path.remove("file://");

    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
    {
        LOG_ERROR("Could not read process file!, %s", file.errorString().toStdString());
        return false;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject mainObj = doc.object();

    QVariantMap dataMap;
    if(mainObj.value("type").toInt() == static_cast<int>(ProcessType::Process_1_2_4))
    {
        dataMap.insert("type",mainObj.value("type").toInt());
        dataMap.insert("name",mainObj.value("name").toString());

        QVariantMap paramMap;
        paramMap.insert("fmsRxStep",mainObj.value("param").toObject().value("fmsRxStep").toDouble());
        paramMap.insert("fmsRyStep",mainObj.value("param").toObject().value("fmsRyStep").toDouble());
        paramMap.insert("fmsRzStep",mainObj.value("param").toObject().value("fmsRzStep").toDouble());

        QVariantMap specMap;
        specMap.insert("fmsRxAngleResolution",mainObj.value("spec").toObject().value("fmsRxAngleResolution").toDouble());
        specMap.insert("fmsRyAngleResolution",mainObj.value("spec").toObject().value("fmsRyAngleResolution").toDouble());
        specMap.insert("fmsRzAngleResolution",mainObj.value("spec").toObject().value("fmsRzAngleResolution").toDouble());

        dataMap.insert("param",paramMap);
        dataMap.insert("spec",specMap);
        ActionProvider::instance()->sendFileDataToProcessService(dataMap);
        return true;
    }else
    {
        return false;
    }
}

bool ConfigService::loadProcessFile_1_2_5(const QString &filePath)
{
    QString path = filePath;
    path = path.remove("file://");

    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
    {
        LOG_ERROR("Could not read process file!, %s", file.errorString().toStdString());
        return false;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject mainObj = doc.object();

    QVariantMap dataMap;
    if(mainObj.value("type").toInt() == static_cast<int>(ProcessType::Process_1_2_5))
    {
        dataMap.insert("type",mainObj.value("type").toInt());
        dataMap.insert("name",mainObj.value("name").toString());

        QVariantMap paramMap;
        paramMap.insert("fmsRxAmp",mainObj.value("param").toObject().value("fmsRxAmp").toDouble());
        paramMap.insert("fmsRxFreq",mainObj.value("param").toObject().value("fmsRxFreq").toDouble());
        paramMap.insert("fmsRxMaxAcc",mainObj.value("param").toObject().value("fmsRxMaxAcc").toDouble());
        paramMap.insert("fmsRyAmp",mainObj.value("param").toObject().value("fmsRyAmp").toDouble());
        paramMap.insert("fmsRyFreq",mainObj.value("param").toObject().value("fmsRyFreq").toDouble());
        paramMap.insert("fmsRyMaxAcc",mainObj.value("param").toObject().value("fmsRyMaxAcc").toDouble());
        paramMap.insert("fmsRzAmp",mainObj.value("param").toObject().value("fmsRzAmp").toDouble());
        paramMap.insert("fmsRzFreq",mainObj.value("param").toObject().value("fmsRzFreq").toDouble());
        paramMap.insert("fmsRzMaxAcc",mainObj.value("param").toObject().value("fmsRzMaxAcc").toDouble());

        QVariantMap specMap;
        specMap.insert("fmsRxMaxAcc",mainObj.value("spec").toObject().value("fmsRxMaxAcc").toDouble());
        specMap.insert("fmsRyMaxAcc",mainObj.value("spec").toObject().value("fmsRyMaxAcc").toDouble());
        specMap.insert("fmsRzMaxAcc",mainObj.value("spec").toObject().value("fmsRzMaxAcc").toDouble());

        dataMap.insert("param",paramMap);
        dataMap.insert("spec",specMap);
        ActionProvider::instance()->sendFileDataToProcessService(dataMap);
        return true;
    }else
    {
        return false;
    }
}

bool ConfigService::loadProcessFile_1_2_6_7(const QString &filePath)
{
    QString path = filePath;
    path = path.remove("file://");

    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
    {
        LOG_ERROR("Could not read process file!, %s", file.errorString().toStdString());
        return false;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject mainObj = doc.object();

    QVariantMap dataMap;
    if(mainObj.value("type").toInt() == static_cast<int>(ProcessType::Process_1_2_6_7))
    {
        dataMap.insert("type",mainObj.value("type").toInt());
        dataMap.insert("name",mainObj.value("name").toString());

        QVariantMap paramMap;
        paramMap.insert("fmsTxUpperLimitedPos",mainObj.value("param").toObject().value("fmsTxUpperLimitedPos").toDouble());
        paramMap.insert("fmsTyUpperLimitedPos",mainObj.value("param").toObject().value("fmsTyUpperLimitedPos").toDouble());
        paramMap.insert("fmsTzUpperLimitedPos",mainObj.value("param").toObject().value("fmsTzUpperLimitedPos").toDouble());
        paramMap.insert("fmsTxLowerLimitedPos",mainObj.value("param").toObject().value("fmsTxLowerLimitedPos").toDouble());
        paramMap.insert("fmsTyLowerLimitedPos",mainObj.value("param").toObject().value("fmsTyLowerLimitedPos").toDouble());
        paramMap.insert("fmsTzLowerLimitedPos",mainObj.value("param").toObject().value("fmsTzLowerLimitedPos").toDouble());

        QVariantMap specMap;
        specMap.insert("fmsTxUpperLimitedPos",mainObj.value("spec").toObject().value("fmsTxUpperLimitedPos").toDouble());
        specMap.insert("fmsTyUpperLimitedPos",mainObj.value("spec").toObject().value("fmsTyUpperLimitedPos").toDouble());
        specMap.insert("fmsTzUpperLimitedPos",mainObj.value("spec").toObject().value("fmsTzUpperLimitedPos").toDouble());
        specMap.insert("fmsTxLowerLimitedPos",mainObj.value("spec").toObject().value("fmsTxLowerLimitedPos").toDouble());
        specMap.insert("fmsTyLowerLimitedPos",mainObj.value("spec").toObject().value("fmsTyLowerLimitedPos").toDouble());
        specMap.insert("fmsTzLowerLimitedPos",mainObj.value("spec").toObject().value("fmsTzLowerLimitedPos").toDouble());

        dataMap.insert("param",paramMap);
        dataMap.insert("spec",specMap);
        ActionProvider::instance()->sendFileDataToProcessService(dataMap);
        return true;
    }else
    {
        return false;
    }
}

bool ConfigService::loadProcessFile_1_2_8(const QString &filePath)
{
    QString path = filePath;
    path = path.remove("file://");

    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
    {
        LOG_ERROR("Could not read process file!, %s", file.errorString().toStdString());
        return false;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject mainObj = doc.object();

    QVariantMap dataMap;
    if(mainObj.value("type").toInt() == static_cast<int>(ProcessType::Process_1_2_8))
    {
        dataMap.insert("type",mainObj.value("type").toInt());
        dataMap.insert("name",mainObj.value("name").toString());

        QVariantMap paramMap;
        paramMap.insert("fmsTxAmp",mainObj.value("param").toObject().value("fmsTxAmp").toDouble());
        paramMap.insert("fmsTxFreq",mainObj.value("param").toObject().value("fmsTxFreq").toDouble());
        paramMap.insert("fmsTxMaxVelocity",mainObj.value("param").toObject().value("fmsTxMaxVelocity").toDouble());
        paramMap.insert("fmsTyAmp",mainObj.value("param").toObject().value("fmsTyAmp").toDouble());
        paramMap.insert("fmsTyFreq",mainObj.value("param").toObject().value("fmsTyFreq").toDouble());
        paramMap.insert("fmsTyMaxVelocity",mainObj.value("param").toObject().value("fmsTyMaxVelocity").toDouble());
        paramMap.insert("fmsTzAmp",mainObj.value("param").toObject().value("fmsTzAmp").toDouble());
        paramMap.insert("fmsTzFreq",mainObj.value("param").toObject().value("fmsTzFreq").toDouble());
        paramMap.insert("fmsTzMaxVelocity",mainObj.value("param").toObject().value("fmsTzMaxVelocity").toDouble());

        QVariantMap specMap;
        specMap.insert("fmsTxMaxVelocity",mainObj.value("spec").toObject().value("fmsTxMaxVelocity").toDouble());
        specMap.insert("fmsTyMaxVelocity",mainObj.value("spec").toObject().value("fmsTyMaxVelocity").toDouble());
        specMap.insert("fmsTzMaxVelocity",mainObj.value("spec").toObject().value("fmsTzMaxVelocity").toDouble());

        dataMap.insert("param",paramMap);
        dataMap.insert("spec",specMap);
        ActionProvider::instance()->sendFileDataToProcessService(dataMap);
        return true;
    }else
    {
        return false;
    }
}

bool ConfigService::loadProcessFile_1_2_9(const QString &filePath)
{
    QString path = filePath;
    path = path.remove("file://");

    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
    {
        LOG_ERROR("Could not read process file!, %s", file.errorString().toStdString());
        return false;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject mainObj = doc.object();

    QVariantMap dataMap;
    if(mainObj.value("type").toInt() == static_cast<int>(ProcessType::Process_1_2_9))
    {
        dataMap.insert("type",mainObj.value("type").toInt());
        dataMap.insert("name",mainObj.value("name").toString());

        QVariantMap paramMap;
        paramMap.insert("fmsTxAmp",mainObj.value("param").toObject().value("fmsTxAmp").toDouble());
        paramMap.insert("fmsTxFreq",mainObj.value("param").toObject().value("fmsTxFreq").toDouble());
        paramMap.insert("fmsTxMaxAcc",mainObj.value("param").toObject().value("fmsTxMaxAcc").toDouble());
        paramMap.insert("fmsTyAmp",mainObj.value("param").toObject().value("fmsTyAmp").toDouble());
        paramMap.insert("fmsTyFreq",mainObj.value("param").toObject().value("fmsTyFreq").toDouble());
        paramMap.insert("fmsTyMaxAcc",mainObj.value("param").toObject().value("fmsTyMaxAcc").toDouble());
        paramMap.insert("fmsTzAmp",mainObj.value("param").toObject().value("fmsTzAmp").toDouble());
        paramMap.insert("fmsTzFreq",mainObj.value("param").toObject().value("fmsTzFreq").toDouble());
        paramMap.insert("fmsTzMaxAcc",mainObj.value("param").toObject().value("fmsTzMaxAcc").toDouble());

        QVariantMap specMap;
        specMap.insert("fmsTxMaxAcc",mainObj.value("spec").toObject().value("fmsTxMaxAcc").toDouble());
        specMap.insert("fmsTyMaxAcc",mainObj.value("spec").toObject().value("fmsTyMaxAcc").toDouble());
        specMap.insert("fmsTzMaxAcc",mainObj.value("spec").toObject().value("fmsTzMaxAcc").toDouble());

        dataMap.insert("param",paramMap);
        dataMap.insert("spec",specMap);
        ActionProvider::instance()->sendFileDataToProcessService(dataMap);
        return true;
    }else
    {
        return false;
    }
}

bool ConfigService::loadProcessFile_1_2_10(const QString &filePath)
{
    QString path = filePath;
    path = path.remove("file://");

    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
    {
        LOG_ERROR("Could not read process file!, %s", file.errorString().toStdString());
        return false;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject mainObj = doc.object();

    QVariantMap dataMap;
    if(mainObj.value("type").toInt() == static_cast<int>(ProcessType::Process_1_2_10))
    {
        dataMap.insert("type",mainObj.value("type").toInt());
        dataMap.insert("name",mainObj.value("name").toString());

        QVariantMap paramMap;
        paramMap.insert("fmsRxStartPos",mainObj.value("param").toObject().value("fmsRxStartPos").toDouble());
        paramMap.insert("fmsRxStopPos",mainObj.value("param").toObject().value("fmsRxStopPos").toDouble());
        paramMap.insert("fmsRxStepPos",mainObj.value("param").toObject().value("fmsRxStepPos").toDouble());
        paramMap.insert("fmsRyStartPos",mainObj.value("param").toObject().value("fmsRyStartPos").toDouble());
        paramMap.insert("fmsRyStopPos",mainObj.value("param").toObject().value("fmsRyStopPos").toDouble());
        paramMap.insert("fmsRyStepPos",mainObj.value("param").toObject().value("fmsRyStepPos").toDouble());
        paramMap.insert("fmsRzStartPos",mainObj.value("param").toObject().value("fmsRzStartPos").toDouble());
        paramMap.insert("fmsRzStopPos",mainObj.value("param").toObject().value("fmsRzStopPos").toDouble());
        paramMap.insert("fmsRzStepPos",mainObj.value("param").toObject().value("fmsRzStepPos").toDouble());

        QVariantMap specMap;
        specMap.insert("fmsRxMaxAngleAccuracy",mainObj.value("spec").toObject().value("fmsRxMaxAngleAccuracy").toDouble());
        specMap.insert("fmsRyMaxAngleAccuracy",mainObj.value("spec").toObject().value("fmsRyMaxAngleAccuracy").toDouble());
        specMap.insert("fmsRzMaxAngleAccuracy",mainObj.value("spec").toObject().value("fmsRzMaxAngleAccuracy").toDouble());

        dataMap.insert("param",paramMap);
        dataMap.insert("spec",specMap);
        ActionProvider::instance()->sendFileDataToProcessService(dataMap);
        return true;
    }else
    {
        return false;
    }
}

bool ConfigService::loadProcessFile_1_2_11(const QString &filePath)
{
    QString path = filePath;
    path = path.remove("file://");

    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
    {
        LOG_ERROR("Could not read process file!, %s", file.errorString().toStdString());
        return false;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject mainObj = doc.object();

    QVariantMap dataMap;
    if(mainObj.value("type").toInt() == static_cast<int>(ProcessType::Process_1_2_11))
    {
        dataMap.insert("type",mainObj.value("type").toInt());
        dataMap.insert("name",mainObj.value("name").toString());

        QVariantMap paramMap;
        paramMap.insert("fmsRxPos1",mainObj.value("param").toObject().value("fmsRxPos1").toDouble());
        paramMap.insert("fmsRxPos2",mainObj.value("param").toObject().value("fmsRxPos2").toDouble());
        paramMap.insert("fmsRyPos1",mainObj.value("param").toObject().value("fmsRyPos1").toDouble());
        paramMap.insert("fmsRyPos2",mainObj.value("param").toObject().value("fmsRyPos2").toDouble());
        paramMap.insert("fmsRzPos1",mainObj.value("param").toObject().value("fmsRzPos1").toDouble());
        paramMap.insert("fmsRzPos2",mainObj.value("param").toObject().value("fmsRzPos2").toDouble());
        paramMap.insert("fmsRepeatedMotionNumber",mainObj.value("param").toObject().value("fmsRepeatedMotionNumber").toDouble());

        QVariantMap specMap;
        specMap.insert("fmsRxMaxRepeatedAngleAccuracy",mainObj.value("spec").toObject().value("fmsRxMaxRepeatedAngleAccuracy").toDouble());
        specMap.insert("fmsRyMaxRepeatedAngleAccuracy",mainObj.value("spec").toObject().value("fmsRyMaxRepeatedAngleAccuracy").toDouble());
        specMap.insert("fmsRzMaxRepeatedAngleAccuracy",mainObj.value("spec").toObject().value("fmsRzMaxRepeatedAngleAccuracy").toDouble());

        dataMap.insert("param",paramMap);
        dataMap.insert("spec",specMap);
        ActionProvider::instance()->sendFileDataToProcessService(dataMap);
        return true;
    }else
    {
        return false;
    }
}

bool ConfigService::loadProcessFile_2_1_10(const QString &filePath)
{
    QString path = filePath;
    path = path.remove("file://");

    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
    {
        LOG_ERROR("Could not read process file!, %s", file.errorString().toStdString());
        return false;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject mainObj = doc.object();

    QVariantMap dataMap;
    if(mainObj.value("type").toInt() == static_cast<int>(ProcessType::Process_2_1_10))
    {
        dataMap.insert("type",mainObj.value("type").toInt());
        dataMap.insert("name",mainObj.value("name").toString());

        QVariantMap paramMap;
        paramMap.insert("tmsTxPos1",mainObj.value("param").toObject().value("tmsTxPos1").toDouble());
        paramMap.insert("tmsTxPos2",mainObj.value("param").toObject().value("tmsTxPos2").toDouble());
        paramMap.insert("tmsTyPos1",mainObj.value("param").toObject().value("tmsTyPos1").toDouble());
        paramMap.insert("tmsTyPos2",mainObj.value("param").toObject().value("tmsTyPos2").toDouble());

        dataMap.insert("param",paramMap);
        ActionProvider::instance()->sendFileDataToProcessService(dataMap);
        return true;
    }else
    {
        return false;
    }
}

bool ConfigService::loadProcessFile_2_1_11(const QString &filePath)
{
    QString path = filePath;
    path = path.remove("file://");

    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
    {
        LOG_ERROR("Could not read process file!, %s", file.errorString().toStdString());
        return false;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject mainObj = doc.object();

    QVariantMap dataMap;
    if(mainObj.value("type").toInt() == static_cast<int>(ProcessType::Process_2_1_11))
    {
        dataMap.insert("type",mainObj.value("type").toInt());
        dataMap.insert("name",mainObj.value("name").toString());

        QVariantMap paramMap;
        paramMap.insert("fmsRxAmp",mainObj.value("param").toObject().value("fmsRxAmp").toDouble());
        paramMap.insert("fmsRxFreq",mainObj.value("param").toObject().value("fmsRxFreq").toDouble());
        paramMap.insert("fmsRyAmp",mainObj.value("param").toObject().value("fmsRyAmp").toDouble());
        paramMap.insert("fmsRyFreq",mainObj.value("param").toObject().value("fmsRyFreq").toDouble());
        paramMap.insert("fmsRzAmp",mainObj.value("param").toObject().value("fmsRzAmp").toDouble());
        paramMap.insert("fmsRzFreq",mainObj.value("param").toObject().value("fmsRzFreq").toDouble());
        paramMap.insert("tmsTxAmp",mainObj.value("param").toObject().value("tmsTxAmp").toDouble());
        paramMap.insert("tmsTxFreq",mainObj.value("param").toObject().value("tmsTxFreq").toDouble());
        paramMap.insert("tmsTyAmp",mainObj.value("param").toObject().value("tmsTyAmp").toDouble());
        paramMap.insert("tmsTyFreq",mainObj.value("param").toObject().value("tmsTyFreq").toDouble());

        dataMap.insert("param",paramMap);
        ActionProvider::instance()->sendFileDataToProcessService(dataMap);
        return true;
    }else
    {
        return false;
    }
}

bool ConfigService::loadProcessFile_2_2_1(const QString &filePath)
{
    QString path = filePath;
    path = path.remove("file://");

    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
    {
        LOG_ERROR("Could not read process file!, %s", file.errorString().toStdString());
        return false;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject mainObj = doc.object();

    QVariantMap dataMap;
    if(mainObj.value("type").toInt() == static_cast<int>(ProcessType::Process_2_2_1))
    {
        dataMap.insert("type",mainObj.value("type").toInt());
        dataMap.insert("name",mainObj.value("name").toString());

        QVariantMap paramMap;
        paramMap.insert("tmsTxLowerLimitedPos",mainObj.value("param").toObject().value("tmsTxLowerLimitedPos").toDouble());
        paramMap.insert("tmsTxUpperLimitedPos",mainObj.value("param").toObject().value("tmsTxUpperLimitedPos").toDouble());
        paramMap.insert("tmsTyLowerLimitedPos",mainObj.value("param").toObject().value("tmsTyLowerLimitedPos").toDouble());
        paramMap.insert("tmsTyUpperLimitedPos",mainObj.value("param").toObject().value("tmsTyUpperLimitedPos").toDouble());

        QVariantMap specMap;
        specMap.insert("tmsTxMaxRange",mainObj.value("spec").toObject().value("tmsTxMaxRange").toDouble());
        specMap.insert("tmsTxOffsetRange",mainObj.value("spec").toObject().value("tmsTxOffsetRange").toDouble());
        specMap.insert("tmsTyMaxRange",mainObj.value("spec").toObject().value("tmsTyMaxRange").toDouble());
        specMap.insert("tmsTyOffsetRange",mainObj.value("spec").toObject().value("tmsTyOffsetRange").toDouble());

        dataMap.insert("param",paramMap);
        dataMap.insert("spec",specMap);
        ActionProvider::instance()->sendFileDataToProcessService(dataMap);
        return true;
    }else
    {
        return false;
    }
}

bool ConfigService::loadProcessFile_2_2_2(const QString &filePath)
{
    QString path = filePath;
    path = path.remove("file://");

    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
    {
        LOG_ERROR("Could not read process file!, %s", file.errorString().toStdString());
        return false;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject mainObj = doc.object();

    QVariantMap dataMap;
    if(mainObj.value("type").toInt() == static_cast<int>(ProcessType::Process_2_2_2))
    {
        dataMap.insert("type",mainObj.value("type").toInt());
        dataMap.insert("name",mainObj.value("name").toString());

        QVariantMap paramMap;
        paramMap.insert("tmsTxLowerLimitedPos",mainObj.value("param").toObject().value("tmsTxLowerLimitedPos").toDouble());
        paramMap.insert("tmsTxUpperLimitedPos",mainObj.value("param").toObject().value("tmsTxUpperLimitedPos").toDouble());
        paramMap.insert("tmsTxMaxVelocity",mainObj.value("param").toObject().value("tmsTxMaxVelocity").toDouble());
        paramMap.insert("tmsTyLowerLimitedPos",mainObj.value("param").toObject().value("tmsTyLowerLimitedPos").toDouble());
        paramMap.insert("tmsTyUpperLimitedPos",mainObj.value("param").toObject().value("tmsTyUpperLimitedPos").toDouble());
        paramMap.insert("tmsTyMaxVelocity",mainObj.value("param").toObject().value("tmsTyMaxVelocity").toDouble());

        QVariantMap specMap;
        specMap.insert("tmsTxMaxVelocity",mainObj.value("spec").toObject().value("tmsTxMaxVelocity").toDouble());
        specMap.insert("tmsTyMaxVelocity",mainObj.value("spec").toObject().value("tmsTyMaxVelocity").toDouble());

        dataMap.insert("param",paramMap);
        dataMap.insert("spec",specMap);
        ActionProvider::instance()->sendFileDataToProcessService(dataMap);
        return true;
    }else
    {
        return false;
    }
}

bool ConfigService::loadProcessFile_2_2_3(const QString &filePath)
{
    QString path = filePath;
    path = path.remove("file://");

    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
    {
        LOG_ERROR("Could not read process file!, %s", file.errorString().toStdString());
        return false;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject mainObj = doc.object();

    QVariantMap dataMap;
    if(mainObj.value("type").toInt() == static_cast<int>(ProcessType::Process_2_2_3))
    {
        dataMap.insert("type",mainObj.value("type").toInt());
        dataMap.insert("name",mainObj.value("name").toString());

        QVariantMap paramMap;
        paramMap.insert("tmsTxLowerLimitedPos",mainObj.value("param").toObject().value("tmsTxLowerLimitedPos").toDouble());
        paramMap.insert("tmsTxUpperLimitedPos",mainObj.value("param").toObject().value("tmsTxUpperLimitedPos").toDouble());
        paramMap.insert("tmsTxMinVelocity",mainObj.value("param").toObject().value("tmsTxMinVelocity").toDouble());
        paramMap.insert("tmsTyLowerLimitedPos",mainObj.value("param").toObject().value("tmsTyLowerLimitedPos").toDouble());
        paramMap.insert("tmsTyUpperLimitedPos",mainObj.value("param").toObject().value("tmsTyUpperLimitedPos").toDouble());
        paramMap.insert("tmsTyMinVelocity",mainObj.value("param").toObject().value("tmsTyMinVelocity").toDouble());

        QVariantMap specMap;
        specMap.insert("tmsTxMinVelocity",mainObj.value("spec").toObject().value("tmsTxMinVelocity").toDouble());
        specMap.insert("tmsTyMinVelocity",mainObj.value("spec").toObject().value("tmsTyMinVelocity").toDouble());

        dataMap.insert("param",paramMap);
        dataMap.insert("spec",specMap);
        ActionProvider::instance()->sendFileDataToProcessService(dataMap);
        return true;
    }else
    {
        return false;
    }
}

bool ConfigService::loadProcessFile_2_2_4(const QString &filePath)
{
    QString path = filePath;
    path = path.remove("file://");

    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
    {
        LOG_ERROR("Could not read process file!, %s", file.errorString().toStdString());
        return false;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject mainObj = doc.object();

    QVariantMap dataMap;
    if(mainObj.value("type").toInt() == static_cast<int>(ProcessType::Process_2_2_4))
    {
        dataMap.insert("type",mainObj.value("type").toInt());
        dataMap.insert("name",mainObj.value("name").toString());

        QVariantMap paramMap;
        paramMap.insert("tmsTxAmp",mainObj.value("param").toObject().value("tmsTxAmp").toDouble());
        paramMap.insert("tmsTxFreq",mainObj.value("param").toObject().value("tmsTxFreq").toDouble());
        paramMap.insert("tmsTxMaxAcc",mainObj.value("param").toObject().value("tmsTxMaxAcc").toDouble());
        paramMap.insert("tmsTyAmp",mainObj.value("param").toObject().value("tmsTyAmp").toDouble());
        paramMap.insert("tmsTyFreq",mainObj.value("param").toObject().value("tmsTyFreq").toDouble());
        paramMap.insert("tmsTyMaxAcc",mainObj.value("param").toObject().value("tmsTyMaxAcc").toDouble());

        QVariantMap specMap;
        specMap.insert("tmsTxMaxAcc",mainObj.value("spec").toObject().value("tmsTxMaxAcc").toDouble());
        specMap.insert("tmsTyMaxAcc",mainObj.value("spec").toObject().value("tmsTyMaxAcc").toDouble());

        dataMap.insert("param",paramMap);
        dataMap.insert("spec",specMap);
        ActionProvider::instance()->sendFileDataToProcessService(dataMap);
        return true;
    }else
    {
        return false;
    }
}

bool ConfigService::loadProcessFile_2_2_5(const QString &filePath)
{
    QString path = filePath;
    path = path.remove("file://");

    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
    {
        LOG_ERROR("Could not read process file!, %s", file.errorString().toStdString());
        return false;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject mainObj = doc.object();

    QVariantMap dataMap;
    if(mainObj.value("type").toInt() == static_cast<int>(ProcessType::Process_2_2_5))
    {
        dataMap.insert("type",mainObj.value("type").toInt());
        dataMap.insert("name",mainObj.value("name").toString());

        QVariantMap paramMap;
        paramMap.insert("tmsTxStepPos",mainObj.value("param").toObject().value("tmsTxStepPos").toDouble());
        paramMap.insert("tmsTyStepPos",mainObj.value("param").toObject().value("tmsTyStepPos").toDouble());

        QVariantMap specMap;
        specMap.insert("tmsTxMaxAccuracy",mainObj.value("spec").toObject().value("tmsTxMaxAccuracy").toDouble());
        specMap.insert("tmsTyMaxAccuracy",mainObj.value("spec").toObject().value("tmsTyMaxAccuracy").toDouble());

        dataMap.insert("param",paramMap);
        dataMap.insert("spec",specMap);
        ActionProvider::instance()->sendFileDataToProcessService(dataMap);
        return true;
    }else
    {
        return false;
    }
}

bool ConfigService::loadProcessFile_2_2_9(const QString &filePath)
{
    QString path = filePath;
    path = path.remove("file://");

    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
    {
        LOG_ERROR("Could not read process file!, %s", file.errorString().toStdString());
        return false;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject mainObj = doc.object();

    QVariantMap dataMap;
    if(mainObj.value("type").toInt() == static_cast<int>(ProcessType::Process_2_2_9))
    {
        dataMap.insert("type",mainObj.value("type").toInt());
        dataMap.insert("name",mainObj.value("name").toString());

        QVariantMap paramMap;
        paramMap.insert("tmsTxPos1",mainObj.value("param").toObject().value("tmsTxPos1").toDouble());
        paramMap.insert("tmsTxPos2",mainObj.value("param").toObject().value("tmsTxPos2").toDouble());
        paramMap.insert("tmsTyPos1",mainObj.value("param").toObject().value("tmsTyPos1").toDouble());
        paramMap.insert("tmsTyPos2",mainObj.value("param").toObject().value("tmsTyPos2").toDouble());
        paramMap.insert("tmsRepeatedMotionNumber",mainObj.value("param").toObject().value("tmsRepeatedMotionNumber").toDouble());

        QVariantMap specMap;
        specMap.insert("tmsTxMaxRepeatedAccuracy",mainObj.value("spec").toObject().value("tmsTxMaxRepeatedAccuracy").toDouble());
        specMap.insert("tmsTyMaxRepeatedAccuracy",mainObj.value("spec").toObject().value("tmsTyMaxRepeatedAccuracy").toDouble());

        dataMap.insert("param",paramMap);
        dataMap.insert("spec",specMap);
        ActionProvider::instance()->sendFileDataToProcessService(dataMap);
        return true;
    }else
    {
        return false;
    }
}

bool ConfigService::loadProcessFile_2_2_10(const QString &filePath)
{
    QString path = filePath;
    path = path.remove("file://");

    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
    {
        LOG_ERROR("Could not read process file!, %s", file.errorString().toStdString());
        return false;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject mainObj = doc.object();

    QVariantMap dataMap;
    if(mainObj.value("type").toInt() == static_cast<int>(ProcessType::Process_2_2_10))
    {
        dataMap.insert("type",mainObj.value("type").toInt());
        dataMap.insert("name",mainObj.value("name").toString());

        QVariantMap paramMap;
        paramMap.insert("tmsTxStartPos",mainObj.value("param").toObject().value("tmsTxStartPos").toDouble());
        paramMap.insert("tmsTxStopPos",mainObj.value("param").toObject().value("tmsTxStopPos").toDouble());
        paramMap.insert("tmsTxStepPos",mainObj.value("param").toObject().value("tmsTxStepPos").toDouble());
        paramMap.insert("tmsTyStartPos",mainObj.value("param").toObject().value("tmsTyStartPos").toDouble());
        paramMap.insert("tmsTyStopPos",mainObj.value("param").toObject().value("tmsTyStopPos").toDouble());
        paramMap.insert("tmsTyStepPos",mainObj.value("param").toObject().value("tmsTyStepPos").toDouble());
        paramMap.insert("tmsTxAmp",mainObj.value("param").toObject().value("tmsTxAmp").toDouble());
        paramMap.insert("tmsTxFreq",mainObj.value("param").toObject().value("tmsTxFreq").toDouble());
        paramMap.insert("tmsTyAmp",mainObj.value("param").toObject().value("tmsTyAmp").toDouble());
        paramMap.insert("tmsTyFreq",mainObj.value("param").toObject().value("tmsTyFreq").toDouble());

        dataMap.insert("param",paramMap);
        ActionProvider::instance()->sendFileDataToProcessService(dataMap);
        return true;
    }else
    {
        return false;
    }
}

bool ConfigService::loadProcessFile_2_2_13_1(const QString &filePath)
{
    QString path = filePath;
    path = path.remove("file://");

    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
    {
        LOG_ERROR("Could not read process file!, %s", file.errorString().toStdString());
        return false;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject mainObj = doc.object();

    QVariantMap dataMap;
    if(mainObj.value("type").toInt() == static_cast<int>(ProcessType::Process_2_2_13_1))
    {
        dataMap.insert("type",mainObj.value("type").toInt());
        dataMap.insert("name",mainObj.value("name").toString());

        QVariantMap paramMap;
        paramMap.insert("tmsRxLowerLimitedPos",mainObj.value("param").toObject().value("tmsRxLowerLimitedPos").toDouble());
        paramMap.insert("tmsRxUpperLimitedPos",mainObj.value("param").toObject().value("tmsRxUpperLimitedPos").toDouble());
        paramMap.insert("tmsRyLowerLimitedPos",mainObj.value("param").toObject().value("tmsRyLowerLimitedPos").toDouble());
        paramMap.insert("tmsRyUpperLimitedPos",mainObj.value("param").toObject().value("tmsRyUpperLimitedPos").toDouble());

        QVariantMap specMap;
        specMap.insert("tmsRxLowerLimitedPos",mainObj.value("spec").toObject().value("tmsRxLowerLimitedPos").toDouble());
        specMap.insert("tmsRxUpperLimitedPos",mainObj.value("spec").toObject().value("tmsRxUpperLimitedPos").toDouble());
        specMap.insert("tmsRyLowerLimitedPos",mainObj.value("spec").toObject().value("tmsRyLowerLimitedPos").toDouble());
        specMap.insert("tmsRyUpperLimitedPos",mainObj.value("spec").toObject().value("tmsRyUpperLimitedPos").toDouble());

        dataMap.insert("param",paramMap);
        dataMap.insert("spec",specMap);
        ActionProvider::instance()->sendFileDataToProcessService(dataMap);
        return true;
    }else
    {
        return false;
    }
}

bool ConfigService::loadProcessFile_2_2_13_2(const QString &filePath)
{
    QString path = filePath;
    path = path.remove("file://");

    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
    {
        LOG_ERROR("Could not read process file!, %s", file.errorString().toStdString());
        return false;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject mainObj = doc.object();

    QVariantMap dataMap;
    if(mainObj.value("type").toInt() == static_cast<int>(ProcessType::Process_2_2_13_2))
    {
        dataMap.insert("type",mainObj.value("type").toInt());
        dataMap.insert("name",mainObj.value("name").toString());

        QVariantMap paramMap;
        paramMap.insert("tmsRxAmp",mainObj.value("param").toObject().value("tmsRxAmp").toDouble());
        paramMap.insert("tmsRxFreq",mainObj.value("param").toObject().value("tmsRxFreq").toDouble());
        paramMap.insert("tmsRxMaxVelocity",mainObj.value("param").toObject().value("tmsRxMaxVelocity").toDouble());
        paramMap.insert("tmsRyAmp",mainObj.value("param").toObject().value("tmsRyAmp").toDouble());
        paramMap.insert("tmsRyFreq",mainObj.value("param").toObject().value("tmsRyFreq").toDouble());
        paramMap.insert("tmsRyMaxVelocity",mainObj.value("param").toObject().value("tmsRyMaxVelocity").toDouble());

        QVariantMap specMap;
        specMap.insert("tmsRxMaxVelocity",mainObj.value("spec").toObject().value("tmsRxMaxVelocity").toDouble());
        specMap.insert("tmsRyMaxVelocity",mainObj.value("spec").toObject().value("tmsRyMaxVelocity").toDouble());

        dataMap.insert("param",paramMap);
        dataMap.insert("spec",specMap);
        ActionProvider::instance()->sendFileDataToProcessService(dataMap);
        return true;
    }else
    {
        return false;
    }
}
