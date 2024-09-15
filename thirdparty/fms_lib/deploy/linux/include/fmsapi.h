#ifndef FMSAPI_H
#define FMSAPI_H

#include "FmsApi_global.h"

#include <string>
#include "constant.h"

#include "controller/fmsmanager.h"


//inline int fmsEnableCommand(const QString& cmd)
//{
//    return FmsManager::Instance()->processCommand(ENABLE, cmd);
//}

//inline int fmsDisableCommand(const QString& cmd)
//{
//    return FmsManager::Instance()->processCommand(DISABLE, cmd);
//}

//inline int fmsResetCommand(const QString& cmd)
//{
//    return FmsManager::Instance()->processCommand(RESET, cmd);
//}

//inline int fmsControlOnCommand(const QString& cmd)
//{
//    return FmsManager::Instance()->processCommand(CONTROLON, cmd);
//}

//inline int fmsControlOffCommand(const QString& cmd)
//{
//    return FmsManager::Instance()->processCommand(CONTROLOFF, cmd);
//}

//inline int fmsPowerOffCommand(const QString& cmd)
//{
//    return FmsManager::Instance()->processCommand(POWEROFF, cmd);
//}

//inline int fmsStopCommand(const QString& cmd)
//{
//    return FmsManager::Instance()->processCommand(STOP, cmd);
//}

//inline int fmsHomingCommand(const QString& cmd)
//{
//    return FmsManager::Instance()->processCommand(HOMING, cmd);
//}

//inline int fmsMoveAbsCommand(const QString& cmd)
//{
//    return FmsManager::Instance()->processCommand(MOVE_ABS, cmd);
//}

//inline int fmsAxisControlOnCommand(const QString& cmd)
//{
//    return FmsManager::Instance()->processCommand(AXIS_CONTROLON, cmd);
//}

//inline int fmsAxisHomingCommand(const QString& cmd)
//{
//    return FmsManager::Instance()->processCommand(AXIS_HOMING, cmd);
//}

//inline int fmsAxisControlOffCommand(const QString& cmd)
//{
//    return FmsManager::Instance()->processCommand(AXIS_CONTROLOFF, cmd);
//}

//inline int fmsHexapodStatusCommand(const QString& cmd)
//{
//    return FmsManager::Instance()->processCommand(HEXAPOD_STATUS, cmd);
//}

//inline int fmsActuatorsStatusCommand(const QString& cmd)
//{
//    return FmsManager::Instance()->processCommand(ACTUATORS_STATUS, cmd);
//}

//inline int fmsCfgSpeedSetCommand(const QString& cmd)
//{
//    return FmsManager::Instance()->processCommand(CFG_SPD_SET, cmd);
//}

//inline int fmsCfgSpeedGetCommand(const QString& cmd)
//{
//    return FmsManager::Instance()->processCommand(CFG_SPD_GET, cmd);
//}

//inline int fmsCfgAccGetCommand(const QString& cmd)
//{
//    return FmsManager::Instance()->processCommand(CFG_ACC_GET, cmd);
//}

//inline int fmsCfgAccSetCommand(const QString& cmd)
//{
//    return FmsManager::Instance()->processCommand(CFG_ACC_SET, cmd);
//}

//inline int fmsCfgLimWsSetCommand(const QString& cmd)
//{
//    return FmsManager::Instance()->processCommand(CFG_LIM_WS_SET, cmd);
//}

//inline int fmsCfgLimWsGetCommand(const QString& cmd)
//{
//    return FmsManager::Instance()->processCommand(CFG_LIM_WS_GET, cmd);
//}

//inline int fmsCfgSimSpdSetCommand(const QString& cmd)
//{
//    return FmsManager::Instance()->processCommand(CFG_LIM_SPD_SET, cmd);
//}

//inline int fmsCfgSimSpdGetCommand(const QString& cmd)
//{
//    return FmsManager::Instance()->processCommand(CFG_LIM_SPD_GET, cmd);
//}

//inline int fmsCfgSimAccSetCommand(const QString& cmd)
//{
//    return FmsManager::Instance()->processCommand(CFG_LIM_ACC_SET, cmd);
//}

//inline int fmsCfgSimAccGetCommand(const QString& cmd)
//{
//    return FmsManager::Instance()->processCommand(CFG_LIM_ACC_GET, cmd);
//}

inline int processCommand(const QString& cmd)
{
    return FmsManager::Instance()->processCommand(cmd);
}

#endif // FMSAPI_H
