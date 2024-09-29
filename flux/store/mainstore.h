#pragma once

#include <QObject>
#include "store.h"
using namespace flux_qt;

class MainStore final : public QObject, public Store
{
        Q_OBJECT
        Q_PROPERTY(QString loadedProcessFilePath READ loadedProcessFilePath WRITE setLoadedProcessFilePath NOTIFY loadedProcessFilePathChanged)
        Q_PROPERTY(bool laserTrackerDialogShowFlag READ laserTrackerDialogShowFlag WRITE setLaserTrackerDialogShowFlag NOTIFY laserTrackerDialogShowFlagChanged)

    public:
        ~MainStore() override;
        static MainStore* getInstance()
        {
            static MainStore self;
            return &self;
        }
        void process(const QSharedPointer<Action> &action) override;
        QString loadedProcessFilePath() const;
        bool laserTrackerDialogShowFlag() const;

    public slots:
        void setLoadedProcessFilePath(QString loadedProcessFilePath);
        void setLaserTrackerDialogShowFlag(bool laserTrackerDialogShowFlag);

    signals:
        void loadedProcessFilePathChanged(QString loadedProcessFilePath);
        void laserTrackerDialogShowFlagChanged(bool laserTrackerDialogShowFlag);

    private:
        explicit MainStore(QObject* parent = nullptr);

        QString mLoadedProcessFilePath;
        bool mLaserTrackerDialogShowFlag;
};

