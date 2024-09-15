#include "actionprovider.h"
#include <QVariant>

void ActionProvider::loadProcessFile(const int& processIndex)
{
    Dispatcher::instance().dispatch(new Action(ActionType::LoadProcessFile,processIndex));
}
