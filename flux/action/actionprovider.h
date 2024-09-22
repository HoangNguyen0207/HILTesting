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
        Q_INVOKABLE void abortTest();
        Q_INVOKABLE void requestPositionInput();
        Q_INVOKABLE void updatePositionInput(double x, double y, double z);
        Q_INVOKABLE void updateCenterInput(int device, int axis, double x, double y, double z);
        Q_INVOKABLE void updateState(int state);
        Q_INVOKABLE void finishTest(bool result);
        void sendFileDataToProcessService(const QVariantMap& data);

    signals:

    public slots:

    private:
        ActionProvider() = default;
        ActionProvider(const ActionProvider&) = delete;
        ActionProvider(ActionProvider&&) = delete;
        ActionProvider& operator=(const ActionProvider&) = delete;
        ActionProvider& operator=(ActionProvider &&) = delete;
};

