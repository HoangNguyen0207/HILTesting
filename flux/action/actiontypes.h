#ifndef ACTIONTYPES_H
#define ACTIONTYPES_H

enum class ActionType
{
    LoadProcessFile,
    SendFileDataToProcessService,

    // FMS Actions
    FMSSendCommand,
    FMSEnable,
    FMSDisable,
    FMSReset,
    FMSControlOn,
    FMSControlOff,
    FMSPowerOff,
    FMSStopMoving,
    FMSHoming,
    FMSMoveOff,
    FMSMovePosition,
    FMSStartMovingLoop,
    FMSStopMovingLoop,
    FMSConfigVelocity,
    FMSConfigLimitVelocity,
    FMSConfigAcc,
    FMSConfigLimitAcc,
    FMSConfigHomeOffset,
    FMSQueryStatus,
    FMSQueryVelocity,
    FMSQueryAcc,
    FMSQueryHomeOffset,
    FMSQueryLimitWorkSpace,
    FMSQueryLimitVelocity,
    FMSQueryLimitAcc,

    // TMS Actions
    TMSSendCommand,
    TMSEnable,
    TMSDisable,
    TMSReset,
    TMSControlOn,
    TMSControlOff,
    TMSPowerOff,
    TMSStopMoving,
    TMSHoming,
    TMSMoveOff,
    TMSMovePosition,
    TMSStartMovingLoop,
    TMSStopMovingLoop,
    TMSConfigVelocity,
    TMSConfigLimitVelocity,
    TMSConfigAcc,
    TMSConfigLimitAcc,
    TMSConfigHomeOffset,
    TMSQueryStatus,
    TMSQueryVelocity,
    TMSQueryAcc,
    TMSQueryHomeOffset,
    TMSQueryLimitWorkSpace,
    TMSQueryLimitVelocity,
    TMSQueryLimitAcc,

    // Laser tracker
    LaserTrackerInputTriggered,
    LaserTrackerDialogShowFlagChanged,

    // Plot process flag
    PlotProcessFlagChanged,

    // Plot map mode
    PlotMapModeChanged,
};

#endif
