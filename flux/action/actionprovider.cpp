#include "actionprovider.h"
#include <QVariant>

void ActionProvider::loadProcessFile(const int& processIndex)
{
    Dispatcher::instance().dispatch(new Action(ActionType::LoadProcessFile,processIndex));
}

void ActionProvider::abortTest()
{
    Dispatcher::instance().dispatch(new Action(ActionType::AbortTest));
}

void ActionProvider::requestPositionInput()
{
    Dispatcher::instance().dispatch(new Action(ActionType::RequestPositionInput));
}

void ActionProvider::updatePositionInput(double x, double y, double z)
{
    QVariantMap data;
    data["x"] = QVariant::fromValue(x);
    data["y"] = QVariant::fromValue(y);
    data["z"] = QVariant::fromValue(z);
    Dispatcher::instance().dispatch(new Action(ActionType::UpdatePositionInput, data));
}

void ActionProvider::updateState(int state)
{
    Dispatcher::instance().dispatch(new Action(ActionType::UpdateState, state));
}

void ActionProvider::finishTest(bool result)
{
    Dispatcher::instance().dispatch(new Action(ActionType::FinishTest, result));
}

void ActionProvider::updateCenterInput(int device, int axis, double x, double y, double z)
{
    QVariantMap data;
    data["device"] = QVariant::fromValue(device);
    data["axis"] = QVariant::fromValue(axis);
    data["x"] = QVariant::fromValue(x);
    data["y"] = QVariant::fromValue(y);
    data["z"] = QVariant::fromValue(z);
    Dispatcher::instance().dispatch(new Action(ActionType::UpdateCenterInput, data));
void ActionProvider::sendFileDataToProcessService(const QVariantMap &data)
{
    Dispatcher::instance().dispatch(new Action(ActionType::SendFileDataToProcessService,data));
}
