﻿#include "actionprovider.h"
#include <QVariant>

void ActionProvider::loadProcessFile(const int& processIndex)
{
    Dispatcher::instance().dispatch(new Action(ActionType::LoadProcessFile,processIndex));
}

void ActionProvider::sendFileDataToProcessService(const QVariantMap &data)
{
    Dispatcher::instance().dispatch(new Action(ActionType::SendFileDataToProcessService,data));
}

void ActionProvider::fmsSendCommand(const QString &cmd)
{
    Dispatcher::instance().dispatch(new Action(ActionType::FMSSendCommand,cmd));
}

void ActionProvider::fmsEnable()
{
    Dispatcher::instance().dispatch(new Action(ActionType::FMSEnable));
}

void ActionProvider::fmsDisable()
{
    Dispatcher::instance().dispatch(new Action(ActionType::FMSDisable));
}

void ActionProvider::fmsReset()
{
    Dispatcher::instance().dispatch(new Action(ActionType::FMSReset));
}

void ActionProvider::fmsControlOn()
{
    Dispatcher::instance().dispatch(new Action(ActionType::FMSControlOn));
}

void ActionProvider::fmsControlOff()
{
    Dispatcher::instance().dispatch(new Action(ActionType::FMSControlOff));
}

void ActionProvider::fmsPowerOff()
{
    Dispatcher::instance().dispatch(new Action(ActionType::FMSPowerOff));
}

void ActionProvider::fmsStopMoving()
{
    Dispatcher::instance().dispatch(new Action(ActionType::FMSStopMoving));
}

void ActionProvider::fmsHoming()
{
    Dispatcher::instance().dispatch(new Action(ActionType::FMSHoming));
}

void ActionProvider::fmsMoveOff()
{
    Dispatcher::instance().dispatch(new Action(ActionType::FMSMoveOff));
}

void ActionProvider::fmsMovePosition(const QVariantMap &data)
{
    Dispatcher::instance().dispatch(new Action(ActionType::FMSMovePosition,data));
}

void ActionProvider::fmsConfigVelocity(const QVariantMap &data)
{
    Dispatcher::instance().dispatch(new Action(ActionType::FMSConfigVelocity,data));
}

void ActionProvider::fmsConfigLimitVelocity(const QVariantMap &data)
{
    Dispatcher::instance().dispatch(new Action(ActionType::FMSConfigLimitVelocity,data));
}

void ActionProvider::fmsConfigAcc(const QVariantMap &data)
{
    Dispatcher::instance().dispatch(new Action(ActionType::FMSConfigAcc,data));
}

void ActionProvider::fmsConfigLimitAcc(const QVariantMap &data)
{
    Dispatcher::instance().dispatch(new Action(ActionType::FMSConfigLimitAcc,data));
}

void ActionProvider::fmsConfigHomeOffset(const QVariantMap &data)
{
    Dispatcher::instance().dispatch(new Action(ActionType::FMSConfigHomeOffset,data));
}

void ActionProvider::fmsQueryStatus()
{
    Dispatcher::instance().dispatch(new Action(ActionType::FMSQueryStatus));
}

void ActionProvider::fmsQueryVelocity()
{
    Dispatcher::instance().dispatch(new Action(ActionType::FMSQueryVelocity));
}

void ActionProvider::fmsQueryAcc()
{
    Dispatcher::instance().dispatch(new Action(ActionType::FMSQueryAcc));
}

void ActionProvider::fmsQueryHomeOffset()
{
    Dispatcher::instance().dispatch(new Action(ActionType::FMSQueryHomeOffset));
}

void ActionProvider::fmsQueryLimitWorkSpace()
{
    Dispatcher::instance().dispatch(new Action(ActionType::FMSQueryLimitWorkSpace));
}

void ActionProvider::fmsQueryLimitVelocity()
{
    Dispatcher::instance().dispatch(new Action(ActionType::FMSQueryLimitVelocity));
}

void ActionProvider::fmsQueryLimitAcc()
{
    Dispatcher::instance().dispatch(new Action(ActionType::FMSQueryLimitAcc));
}

void ActionProvider::fmsTxPosChanged(double value)
{
    Dispatcher::instance().dispatch(new Action(ActionType::FMSTxPosChanged,value));
}

void ActionProvider::fmsTyPosChanged(double value)
{
    Dispatcher::instance().dispatch(new Action(ActionType::FMSTyPosChanged,value));
}

void ActionProvider::fmsTzPosChanged(double value)
{
    Dispatcher::instance().dispatch(new Action(ActionType::FMSTzPosChanged,value));
}

void ActionProvider::fmsRxPosChanged(double value)
{
    Dispatcher::instance().dispatch(new Action(ActionType::FMSRxPosChanged,value));
}

void ActionProvider::fmsRyPosChanged(double value)
{
    Dispatcher::instance().dispatch(new Action(ActionType::FMSRyPosChanged,value));
}

void ActionProvider::fmsRzPosChanged(double value)
{
    Dispatcher::instance().dispatch(new Action(ActionType::FMSRzPosChanged,value));
}

void ActionProvider::fmsTxVelChanged(double value)
{
    Dispatcher::instance().dispatch(new Action(ActionType::FMSTxVelChanged,value));
}

void ActionProvider::fmsTyVelChanged(double value)
{
    Dispatcher::instance().dispatch(new Action(ActionType::FMSTyVelChanged,value));
}

void ActionProvider::fmsTzVelChanged(double value)
{
    Dispatcher::instance().dispatch(new Action(ActionType::FMSTzVelChanged,value));
}

void ActionProvider::fmsRxVelChanged(double value)
{
    Dispatcher::instance().dispatch(new Action(ActionType::FMSRxVelChanged,value));
}

void ActionProvider::fmsRyVelChanged(double value)
{
    Dispatcher::instance().dispatch(new Action(ActionType::FMSRyVelChanged,value));
}

void ActionProvider::fmsRzVelChanged(double value)
{
    Dispatcher::instance().dispatch(new Action(ActionType::FMSRzVelChanged,value));
}

void ActionProvider::fmsTxAccChanged(double value)
{
    Dispatcher::instance().dispatch(new Action(ActionType::FMSTxAccChanged,value));
}

void ActionProvider::fmsTyAccChanged(double value)
{
    Dispatcher::instance().dispatch(new Action(ActionType::FMSTyAccChanged,value));
}

void ActionProvider::fmsTzAccChanged(double value)
{
    Dispatcher::instance().dispatch(new Action(ActionType::FMSTzAccChanged,value));
}

void ActionProvider::fmsRxAccChanged(double value)
{
    Dispatcher::instance().dispatch(new Action(ActionType::FMSRxAccChanged,value));
}

void ActionProvider::fmsRyAccChanged(double value)
{
    Dispatcher::instance().dispatch(new Action(ActionType::FMSRyAccChanged,value));
}

void ActionProvider::fmsRzAccChanged(double value)
{
    Dispatcher::instance().dispatch(new Action(ActionType::FMSRzAccChanged,value));
}

//-----------------------------------------------------------------------------------
void ActionProvider::tmsSendCommand(const QString &cmd)
{
    Dispatcher::instance().dispatch(new Action(ActionType::TMSSendCommand,cmd));
}

void ActionProvider::tmsEnable()
{
    Dispatcher::instance().dispatch(new Action(ActionType::TMSEnable));
}

void ActionProvider::tmsDisable()
{
    Dispatcher::instance().dispatch(new Action(ActionType::TMSDisable));
}

void ActionProvider::tmsReset()
{
    Dispatcher::instance().dispatch(new Action(ActionType::TMSReset));
}

void ActionProvider::tmsControlOn()
{
    Dispatcher::instance().dispatch(new Action(ActionType::TMSControlOn));
}

void ActionProvider::tmsControlOff()
{
    Dispatcher::instance().dispatch(new Action(ActionType::TMSControlOff));
}

void ActionProvider::tmsPowerOff()
{
    Dispatcher::instance().dispatch(new Action(ActionType::TMSPowerOff));
}

void ActionProvider::tmsStopMoving()
{
    Dispatcher::instance().dispatch(new Action(ActionType::TMSStopMoving));
}

void ActionProvider::tmsHoming()
{
    Dispatcher::instance().dispatch(new Action(ActionType::TMSHoming));
}

void ActionProvider::tmsMoveOff()
{
    Dispatcher::instance().dispatch(new Action(ActionType::TMSMoveOff));
}

void ActionProvider::tmsMovePosition(const QVariantMap &data)
{
    Dispatcher::instance().dispatch(new Action(ActionType::TMSMovePosition,data));
}

void ActionProvider::tmsConfigVelocity(const QVariantMap &data)
{
    Dispatcher::instance().dispatch(new Action(ActionType::TMSConfigVelocity,data));
}

void ActionProvider::tmsConfigLimitVelocity(const QVariantMap &data)
{
    Dispatcher::instance().dispatch(new Action(ActionType::TMSConfigLimitVelocity,data));
}

void ActionProvider::tmsConfigAcc(const QVariantMap &data)
{
    Dispatcher::instance().dispatch(new Action(ActionType::TMSConfigAcc,data));
}

void ActionProvider::tmsConfigLimitAcc(const QVariantMap &data)
{
    Dispatcher::instance().dispatch(new Action(ActionType::TMSConfigLimitAcc,data));
}

void ActionProvider::tmsConfigHomeOffset(const QVariantMap &data)
{
    Dispatcher::instance().dispatch(new Action(ActionType::TMSConfigHomeOffset,data));
}

void ActionProvider::tmsQueryStatus()
{
    Dispatcher::instance().dispatch(new Action(ActionType::TMSQueryStatus));
}

void ActionProvider::tmsQueryVelocity()
{
    Dispatcher::instance().dispatch(new Action(ActionType::TMSQueryVelocity));
}

void ActionProvider::tmsQueryAcc()
{
    Dispatcher::instance().dispatch(new Action(ActionType::TMSQueryAcc));
}

void ActionProvider::tmsQueryHomeOffset()
{
    Dispatcher::instance().dispatch(new Action(ActionType::TMSQueryHomeOffset));
}

void ActionProvider::tmsQueryLimitWorkSpace()
{
    Dispatcher::instance().dispatch(new Action(ActionType::TMSQueryLimitWorkSpace));
}

void ActionProvider::tmsQueryLimitVelocity()
{
    Dispatcher::instance().dispatch(new Action(ActionType::TMSQueryLimitVelocity));
}

void ActionProvider::tmsQueryLimitAcc()
{
    Dispatcher::instance().dispatch(new Action(ActionType::TMSQueryLimitAcc));
}

void ActionProvider::tmsTxPosChanged(double value)
{
    Dispatcher::instance().dispatch(new Action(ActionType::TMSTxPosChanged,value));
}

void ActionProvider::tmsTyPosChanged(double value)
{
    Dispatcher::instance().dispatch(new Action(ActionType::TMSTyPosChanged,value));
}

void ActionProvider::tmsRxPosChanged(double value)
{
    Dispatcher::instance().dispatch(new Action(ActionType::TMSRxPosChanged,value));
}

void ActionProvider::tmsRyPosChanged(double value)
{
    Dispatcher::instance().dispatch(new Action(ActionType::TMSRyPosChanged,value));
}

void ActionProvider::tmsTxVelChanged(double value)
{
    Dispatcher::instance().dispatch(new Action(ActionType::TMSTxVelChanged,value));
}

void ActionProvider::tmsTyVelChanged(double value)
{
    Dispatcher::instance().dispatch(new Action(ActionType::TMSTyVelChanged,value));
}

void ActionProvider::tmsRxVelChanged(double value)
{
    Dispatcher::instance().dispatch(new Action(ActionType::TMSRxVelChanged,value));
}

void ActionProvider::tmsRyVelChanged(double value)
{
    Dispatcher::instance().dispatch(new Action(ActionType::TMSRyVelChanged,value));
}

void ActionProvider::tmsTxAccChanged(double value)
{
    Dispatcher::instance().dispatch(new Action(ActionType::TMSTxAccChanged,value));
}

void ActionProvider::tmsTyAccChanged(double value)
{
    Dispatcher::instance().dispatch(new Action(ActionType::TMSTyAccChanged,value));
}

void ActionProvider::tmsRxAccChanged(double value)
{
    Dispatcher::instance().dispatch(new Action(ActionType::TMSRxAccChanged,value));
}

void ActionProvider::tmsRyAccChanged(double value)
{
    Dispatcher::instance().dispatch(new Action(ActionType::TMSRyAccChanged,value));
}

void ActionProvider::laserInputTriggered(const QVariantMap &data)
{
    Dispatcher::instance().dispatch(new Action(ActionType::LaserTrackerInputTriggered,data));
}

void ActionProvider::laserDialogShowFlagChanged(const bool &flag)
{
    Dispatcher::instance().dispatch(new Action(ActionType::LaserTrackerDialogShowFlagChanged,flag));
}

void ActionProvider::plotProcessFlagChanged(bool flag)
{
    Dispatcher::instance().dispatch(new Action(ActionType::PlotProcessFlagChanged,flag));
}

void ActionProvider::plotMapModeChanged(int mode)
{
    Dispatcher::instance().dispatch(new Action(ActionType::PlotMapModeChanged,mode));
}
