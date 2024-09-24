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


MainStore::MainStore(QObject* parent) : QObject(parent)
{

}

MainStore::~MainStore()
{

}

