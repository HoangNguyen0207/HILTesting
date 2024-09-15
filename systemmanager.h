#pragma once

#include <QObject>
#include <QSharedPointer>
#include <sys/resource.h>
#include "services/configservice.h"
#include "services/logservice.h"
#include "flux/action/actionprovider.h"
#include "flux/middleware/systemmiddleware.h"
#include "flux/store/mainstore.h"

class SystemManager : public QObject
{
        Q_OBJECT
    public:
        static SystemManager& getInstance()
        {
            static SystemManager self;
            return self;
        }
        ~SystemManager();
        void initSoftware();

    signals:

    private slots:
        void slotCreateLogService();

    private:
        SystemManager() = default;
        void registerMetaType();
        void initThreads();
        void initMiddlewareAndStoreRegistration();
        void initObjectForQmlAccession();
        void initSignalSlotConnection();

    private:
        QSharedPointer<SystemMiddleware> mSystemMiddleware{nullptr};
        LogService* mLogService{nullptr};
        ConfigService* mConfigService{nullptr};

};

