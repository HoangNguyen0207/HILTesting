#include "systemmanager.h"
#include <functional>
#include <memory>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "logger/logger.h"
#include "typedef/globalvar.h"
#include "utils/plot/qmlchartviewer.h"
#include "utils/plot/trajectorymap.h"
#include "utils/plot/bodemap.h"

SystemManager::~SystemManager()
{
    DELETE(mLogService)
    DELETE(mConfigService)
}

void SystemManager::initSoftware()
{
    registerMetaType();
    initMiddlewareAndStoreRegistration();
    initObjectForQmlAccession();
    initThreads();
    initSignalSlotConnection();
}

void SystemManager::slotCreateLogService()
{
    mLogService = new LogService(ProcessorName::BUS_ADDR_LOGGER);
    QObject::connect(mSystemMiddleware.get(),&SystemMiddleware::sigDispatchActionToLogger,mLogService,&LogService::processActionFromMiddleware,Qt::QueuedConnection);
    mLogService->setSystemConfig(mConfigService->getSystemConfig());
    emit mLogService->startProcess();
}

void SystemManager::slotCreateFMSCommService()
{
    mFMSCommService = new FMSCommService(ProcessorName::BUS_ADDR_FMS);
    QObject::connect(mSystemMiddleware.get(),&SystemMiddleware::sigDispatchActionToFMS,mFMSCommService,&FMSCommService::processActionFromMiddleware,Qt::QueuedConnection);
    mFMSCommService->setSystemConfig(mConfigService->getSystemConfig());
    emit mFMSCommService->startProcess();
}

void SystemManager::slotCreateTMSCommService()
{
    mTMSCommService = new TMSCommService(ProcessorName::BUS_ADDR_TMS);
    QObject::connect(mSystemMiddleware.get(),&SystemMiddleware::sigDispatchActionToTMS,mTMSCommService,&TMSCommService::processActionFromMiddleware,Qt::QueuedConnection);
    mTMSCommService->setSystemConfig(mConfigService->getSystemConfig());
    emit mTMSCommService->startProcess();
}

void SystemManager::registerMetaType()
{
    qRegisterMetaType<QSharedPointer<Action>>("QSharedPointer<Action>");
    qmlRegisterType<TrajectoryMap>("Chart",1,0,"TrajectoryMap");
    qmlRegisterType<BodeMap>("Chart",1,0,"BodeMap");
    qRegisterMetaType<QmlChartViewer::Direction>("Direction");
    qmlRegisterUncreatableMetaObject(QmlChartViewer::staticMetaObject,
                                     "Chart",
                                     1, 0,
                                     "Chart",
                                     "Error: only enums");
}

void SystemManager::initThreads()
{
    LOG_DEBUG("Init ConfigService thread");
    mConfigService = new ConfigService(ProcessorName::BUS_ADDR_CONFIG);
    QObject::connect(mSystemMiddleware.get(),&SystemMiddleware::sigDispatchActionToConfig,mConfigService,&ConfigService::processActionFromMiddleware, Qt::QueuedConnection);
    QObject::connect(mConfigService,&ConfigService::sigCreateLogService,this,&SystemManager::slotCreateLogService);
    QObject::connect(mConfigService,&ConfigService::sigCreateFMSCommService,this,&SystemManager::slotCreateFMSCommService);
    QObject::connect(mConfigService,&ConfigService::sigCreateTMSCommService,this,&SystemManager::slotCreateTMSCommService);
    emit mConfigService->startProcess();
}

void SystemManager::initMiddlewareAndStoreRegistration()
{
    LOG_DEBUG("Register Middleware and Store");
    mSystemMiddleware = QSharedPointer<SystemMiddleware>(new SystemMiddleware(),&QObject::deleteLater);
    Dispatcher::instance().registerMiddleware(mSystemMiddleware);
    Dispatcher::instance().registerStore(MainStore::getInstance(),[](Store*){});
}

void SystemManager::initObjectForQmlAccession()
{
    LOG_DEBUG("Init QML Component");

    qmlRegisterSingletonType<ActionProvider>("Flux",1,0,"ActionProvider",
                               [](QQmlEngine* engine,QJSEngine* scriptEngine)->QObject*
    {
        Q_UNUSED(engine)
        Q_UNUSED(scriptEngine)
        QQmlEngine::setObjectOwnership(ActionProvider::instance(),QQmlEngine::CppOwnership);
        return ActionProvider::instance();
    });

    qmlRegisterSingletonType<MainStore>("Flux",1,0,"MainStore",
                               [](QQmlEngine* engine,QJSEngine* scriptEngine)->QObject*
    {
        Q_UNUSED(engine)
        Q_UNUSED(scriptEngine)
        QQmlEngine::setObjectOwnership(MainStore::getInstance(),QQmlEngine::CppOwnership);
        return MainStore::getInstance();
    });
}

void SystemManager::initSignalSlotConnection()
{
    LOG_DEBUG("Init connect signal and slot");
}
