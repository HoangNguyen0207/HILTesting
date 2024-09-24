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
        void sigLoadSystemConfig(SystemConfig_t config);

    private:
        bool loadProcessFile(int processIndex);
        bool loadProcessFile_1_1_1(const QString& filePath);
        bool loadProcessFile_1_1_2(const QString& filePath);
        bool loadProcessFile_1_1_11(const QString& filePath);
        bool loadProcessFile_1_2_1(const QString& filePath);
        bool loadProcessFile_1_2_2(const QString& filePath);
        bool loadProcessFile_1_2_3(const QString& filePath);
        bool loadProcessFile_1_2_4(const QString& filePath);
        bool loadProcessFile_1_2_5(const QString& filePath);
        bool loadProcessFile_1_2_6_7(const QString& filePath);
        bool loadProcessFile_1_2_8(const QString& filePath);
        bool loadProcessFile_1_2_9(const QString& filePath);
        bool loadProcessFile_1_2_10(const QString& filePath);
        bool loadProcessFile_1_2_11(const QString& filePath);
        bool loadProcessFile_2_1_10(const QString& filePath);
        bool loadProcessFile_2_1_11(const QString& filePath);
        bool loadProcessFile_2_2_1(const QString& filePath);
        bool loadProcessFile_2_2_2(const QString& filePath);
        bool loadProcessFile_2_2_3(const QString& filePath);
        bool loadProcessFile_2_2_4(const QString& filePath);
        bool loadProcessFile_2_2_5(const QString& filePath);
        bool loadProcessFile_2_2_9(const QString& filePath);
        bool loadProcessFile_2_2_10(const QString& filePath);
        bool loadProcessFile_2_2_13_1(const QString& filePath);
        bool loadProcessFile_2_2_13_2(const QString& filePath);

        bool loadSystemConfigFile(const QString& filePath);

    private:
        SystemConfigLoader mSystemConfigLoader;
        ProcessLoader* mProcessLoader {nullptr};

};

