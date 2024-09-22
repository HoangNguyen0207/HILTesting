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

void MainStore::setLoadedProcessFilePath(QString loadedProcessFilePath)
{
    if (mLoadedProcessFilePath == loadedProcessFilePath)
        return;

    mLoadedProcessFilePath = loadedProcessFilePath;
    emit loadedProcessFilePathChanged(mLoadedProcessFilePath);
}


MainStore::MainStore(QObject* parent) : QObject(parent)
{

}

MainStore::~MainStore()
{

}

