#pragma once
#include "action.h"
#include "processorabs/processorabstract.h"
#include "utils/configLoader/systemconfigloader.h"
#include "typedef/globalvar.h"
#include <QString>
#include "utils/processLoader/processloader.h"

using namespace flux_qt;

class ConfigService final : public ProcessorAbstract
{
        Q_OBJECT
    public:
        ConfigService(const QString& processorName);
        ~ConfigService() override;
        void onMessage(QSharedPointer<BaseMessage> msg) override;
        void onStartProcess() override;
        SystemConfig_t getSystemConfig() const;

    public slots:
        void processActionFromMiddleware(const QSharedPointer<Action>& action);

    signals:
        void sigCreateLogService();

    private:
        bool loadProcessFile(int processIndex);

    private:
        SystemConfigLoader mSystemConfigLoader;
        ProcessLoader* mProcessLoader {nullptr};

};

