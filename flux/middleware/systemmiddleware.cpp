#include "systemmiddleware.h"

QSharedPointer<Action> SystemMiddleware::process(const QSharedPointer<Action> &action)
{
    switch (action->getType<ActionType>())
    {
        case ActionType::LoadProcessFile:
        {
            emit sigDispatchActionToConfig(action);
            break;
        }
        case ActionType::AbortTest:
        case ActionType::UpdatePositionInput:
        case ActionType::UpdateCenterInput:
        case ActionType::SendFileDataToProcessService:
        {
            emit sigDispatchActionToTest(action);
            break;
        }
        default:
        break;
    }
    return action;
}

SystemMiddleware::SystemMiddleware()
{

}

SystemMiddleware::~SystemMiddleware()
{

}
