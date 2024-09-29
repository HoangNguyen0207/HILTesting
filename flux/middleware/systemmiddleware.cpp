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
        case ActionType::SendFileDataToProcessService:
        {
            // emit sigToProcessService
            break;
        }
        case ActionType::FMSSendCommand:
        case ActionType::FMSEnable:
        case ActionType::FMSDisable:
        case ActionType::FMSReset:
        case ActionType::FMSControlOn:
        case ActionType::FMSControlOff:
        case ActionType::FMSPowerOff:
        case ActionType::FMSStopMoving:
        case ActionType::FMSHoming:
        case ActionType::FMSMoveOff:
        case ActionType::FMSMovePosition:
        case ActionType::FMSQueryStatus:
        case ActionType::FMSQueryVelocity:
        case ActionType::FMSQueryAcc:
        case ActionType::FMSQueryHomeOffset:
        case ActionType::FMSQueryLimitWorkSpace:
        case ActionType::FMSQueryLimitVelocity:
        case ActionType::FMSQueryLimitAcc:
        case ActionType::FMSConfigVelocity:
        case ActionType::FMSConfigLimitVelocity:
        case ActionType::FMSConfigAcc:
        case ActionType::FMSConfigLimitAcc:
        case ActionType::FMSConfigHomeOffset:
        {
            emit sigDispatchActionToFMS(action);
            break;
        }
        case ActionType::TMSSendCommand:
        case ActionType::TMSEnable:
        case ActionType::TMSDisable:
        case ActionType::TMSReset:
        case ActionType::TMSControlOn:
        case ActionType::TMSControlOff:
        case ActionType::TMSPowerOff:
        case ActionType::TMSStopMoving:
        case ActionType::TMSHoming:
        case ActionType::TMSMoveOff:
        case ActionType::TMSMovePosition:
        case ActionType::TMSQueryStatus:
        case ActionType::TMSQueryVelocity:
        case ActionType::TMSQueryAcc:
        case ActionType::TMSQueryHomeOffset:
        case ActionType::TMSQueryLimitWorkSpace:
        case ActionType::TMSQueryLimitVelocity:
        case ActionType::TMSQueryLimitAcc:
        case ActionType::TMSConfigVelocity:
        case ActionType::TMSConfigLimitVelocity:
        case ActionType::TMSConfigAcc:
        case ActionType::TMSConfigLimitAcc:
        case ActionType::TMSConfigHomeOffset:
        {
            emit sigDispatchActionToTMS(action);
            break;
        }
        case ActionType::LaserTrackerInputTriggered:
        {
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
