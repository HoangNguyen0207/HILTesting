#pragma once

#include <QObject>
#include "store.h"
using namespace flux_qt;

class MainStore final : public QObject, public Store
{
        Q_OBJECT

    public:
        ~MainStore() override;
        static MainStore* getInstance()
        {
            static MainStore self;
            return &self;
        }
        void process(const QSharedPointer<Action> &action) override;


    private:
        explicit MainStore(QObject* parent = nullptr);

};

