#pragma once

#include <QObject>
#include "store.h"
using namespace flux_qt;

class MainStore final : public QObject, public Store
{
        Q_OBJECT
        Q_PROPERTY(QString loadedProcessFilePath READ loadedProcessFilePath WRITE setLoadedProcessFilePath NOTIFY loadedProcessFilePathChanged)

    public:
        ~MainStore() override;
        static MainStore* getInstance()
        {
            static MainStore self;
            return &self;
        }
        void process(const QSharedPointer<Action> &action) override;
        QString loadedProcessFilePath() const;

    public slots:
        void setLoadedProcessFilePath(QString loadedProcessFilePath);

    signals:
        void loadedProcessFilePathChanged(QString loadedProcessFilePath);

    private:
        explicit MainStore(QObject* parent = nullptr);
        QString mLoadedProcessFilePath;
};

