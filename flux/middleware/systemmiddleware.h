#pragma once

#include <QObject>
#include "middleware.h"
#include "action.h"
#include <QSharedPointer>
#include "flux/action/actionprovider.h"
#include "flux/action/actiontypes.h"

using namespace flux_qt;

class SystemMiddleware final : public QObject, public Middleware
{
        Q_OBJECT
    public:
        SystemMiddleware();
        ~SystemMiddleware() override;
        QSharedPointer<Action> process(const QSharedPointer<Action> &action) override;

    signals:
        void sigDispatchActionToConfig(QSharedPointer<Action> actionFromMiddle);
        void sigDispatchActionToLogger(QSharedPointer<Action> actionFromMiddle);
        void sigDispatchActionToFMS(QSharedPointer<Action> actionFromMiddle);
        void sigDispatchActionToTMS(QSharedPointer<Action> actionFromMiddle);

    private:
        SystemMiddleware(const SystemMiddleware&) = delete;
        SystemMiddleware(SystemMiddleware&&) = delete;
        SystemMiddleware& operator=(const SystemMiddleware&) = delete;
        SystemMiddleware& operator=(SystemMiddleware&&) = delete;
};

