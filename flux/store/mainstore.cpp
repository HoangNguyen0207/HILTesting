#include "mainstore.h"
#include "flux/action/actiontypes.h"
#include "action.h"

void MainStore::process(const QSharedPointer<Action> &action)
{
    switch(action->getType<ActionType>())
    {

        default: break;
    }
}

QString MainStore::loadedProcessFilePath() const
{
    return mLoadedProcessFilePath;
}

bool MainStore::laserTrackerDialogShowFlag() const
{
    return mLaserTrackerDialogShowFlag;
}

void MainStore::setLoadedProcessFilePath(QString loadedProcessFilePath)
{
    if (mLoadedProcessFilePath == loadedProcessFilePath)
        return;

    mLoadedProcessFilePath = loadedProcessFilePath;
    emit loadedProcessFilePathChanged(mLoadedProcessFilePath);
}

void MainStore::setLaserTrackerDialogShowFlag(bool laserTrackerDialogShowFlag)
{
    if (mLaserTrackerDialogShowFlag == laserTrackerDialogShowFlag)
        return;

    mLaserTrackerDialogShowFlag = laserTrackerDialogShowFlag;
    emit laserTrackerDialogShowFlagChanged(mLaserTrackerDialogShowFlag);
}


MainStore::MainStore(QObject* parent) : QObject(parent)
{

}

MainStore::~MainStore()
{

}

