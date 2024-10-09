#pragma once

#include <QObject>
#include "actiontypes.h"
#include "dispatcher.h"
#include "action.h"
using namespace  flux_qt;

class ActionProvider : public QObject
{
        Q_OBJECT
    public:
        static ActionProvider* instance()
        {
            static ActionProvider self;
            return &self;
        }

        ~ActionProvider() = default;

        Q_INVOKABLE void loadProcessFile(const int& processIndex);
        void sendFileDataToProcessService(const QVariantMap& data);

        // FMS action
        Q_INVOKABLE void fmsSendCommand(const QString& cmd);
        Q_INVOKABLE void fmsEnable();
        Q_INVOKABLE void fmsDisable();
        Q_INVOKABLE void fmsReset();
        Q_INVOKABLE void fmsControlOn();
        Q_INVOKABLE void fmsControlOff();
        Q_INVOKABLE void fmsPowerOff();
        Q_INVOKABLE void fmsStopMoving();
        Q_INVOKABLE void fmsHoming();
        Q_INVOKABLE void fmsMoveOff();
        Q_INVOKABLE void fmsMovePosition(const QVariantMap& data);
        Q_INVOKABLE void fmsConfigVelocity(const QVariantMap& data);
        Q_INVOKABLE void fmsConfigLimitVelocity(const QVariantMap& data);
        Q_INVOKABLE void fmsConfigAcc(const QVariantMap& data);
        Q_INVOKABLE void fmsConfigLimitAcc(const QVariantMap& data);
        Q_INVOKABLE void fmsConfigHomeOffset(const QVariantMap& data);
        Q_INVOKABLE void fmsQueryStatus();
        Q_INVOKABLE void fmsQueryVelocity();
        Q_INVOKABLE void fmsQueryAcc();
        Q_INVOKABLE void fmsQueryHomeOffset();
        Q_INVOKABLE void fmsQueryLimitWorkSpace();
        Q_INVOKABLE void fmsQueryLimitVelocity();
        Q_INVOKABLE void fmsQueryLimitAcc();

        Q_INVOKABLE void fmsTxPosChanged(double value);
        Q_INVOKABLE void fmsTyPosChanged(double value);
        Q_INVOKABLE void fmsTzPosChanged(double value);
        Q_INVOKABLE void fmsRxPosChanged(double value);
        Q_INVOKABLE void fmsRyPosChanged(double value);
        Q_INVOKABLE void fmsRzPosChanged(double value);
        Q_INVOKABLE void fmsTxVelChanged(double value);
        Q_INVOKABLE void fmsTyVelChanged(double value);
        Q_INVOKABLE void fmsTzVelChanged(double value);
        Q_INVOKABLE void fmsRxVelChanged(double value);
        Q_INVOKABLE void fmsRyVelChanged(double value);
        Q_INVOKABLE void fmsRzVelChanged(double value);
        Q_INVOKABLE void fmsTxAccChanged(double value);
        Q_INVOKABLE void fmsTyAccChanged(double value);
        Q_INVOKABLE void fmsTzAccChanged(double value);
        Q_INVOKABLE void fmsRxAccChanged(double value);
        Q_INVOKABLE void fmsRyAccChanged(double value);
        Q_INVOKABLE void fmsRzAccChanged(double value);

        // TMS action
        Q_INVOKABLE void tmsSendCommand(const QString& cmd);
        Q_INVOKABLE void tmsEnable();
        Q_INVOKABLE void tmsDisable();
        Q_INVOKABLE void tmsReset();
        Q_INVOKABLE void tmsControlOn();
        Q_INVOKABLE void tmsControlOff();
        Q_INVOKABLE void tmsPowerOff();
        Q_INVOKABLE void tmsStopMoving();
        Q_INVOKABLE void tmsHoming();
        Q_INVOKABLE void tmsMoveOff();
        Q_INVOKABLE void tmsMovePosition(const QVariantMap& data);
        Q_INVOKABLE void tmsConfigVelocity(const QVariantMap& data);
        Q_INVOKABLE void tmsConfigLimitVelocity(const QVariantMap& data);
        Q_INVOKABLE void tmsConfigAcc(const QVariantMap& data);
        Q_INVOKABLE void tmsConfigLimitAcc(const QVariantMap& data);
        Q_INVOKABLE void tmsConfigHomeOffset(const QVariantMap& data);
        Q_INVOKABLE void tmsQueryStatus();
        Q_INVOKABLE void tmsQueryVelocity();
        Q_INVOKABLE void tmsQueryAcc();
        Q_INVOKABLE void tmsQueryHomeOffset();
        Q_INVOKABLE void tmsQueryLimitWorkSpace();
        Q_INVOKABLE void tmsQueryLimitVelocity();
        Q_INVOKABLE void tmsQueryLimitAcc();

        Q_INVOKABLE void tmsTxPosChanged(double value);
        Q_INVOKABLE void tmsTyPosChanged(double value);
        Q_INVOKABLE void tmsRxPosChanged(double value);
        Q_INVOKABLE void tmsRyPosChanged(double value);
        Q_INVOKABLE void tmsTxVelChanged(double value);
        Q_INVOKABLE void tmsTyVelChanged(double value);
        Q_INVOKABLE void tmsRxVelChanged(double value);
        Q_INVOKABLE void tmsRyVelChanged(double value);
        Q_INVOKABLE void tmsTxAccChanged(double value);
        Q_INVOKABLE void tmsTyAccChanged(double value);
        Q_INVOKABLE void tmsRxAccChanged(double value);
        Q_INVOKABLE void tmsRyAccChanged(double value);

        // Laser tracker
        Q_INVOKABLE void laserInputTriggered(const QVariantMap& data);
        Q_INVOKABLE void laserDialogShowFlagChanged(const bool& flag);

        // Process plot flag
        Q_INVOKABLE void plotProcessFlagChanged(bool flag);

        // Plot map mode
        Q_INVOKABLE void plotMapModeChanged(int mode);

    signals:

    public slots:

    private:
        ActionProvider() = default;
        ActionProvider(const ActionProvider&) = delete;
        ActionProvider(ActionProvider&&) = delete;
        ActionProvider& operator=(const ActionProvider&) = delete;
        ActionProvider& operator=(ActionProvider &&) = delete;
};

