#include "fmscommservice.h"
#include "logger/logger.h"
#include <bits/stdc++.h>
#include <time.h>

FMSCommService::FMSCommService(const QString &processorName)
    : ProcessorAbstract(processorName)
{

}

FMSCommService::~FMSCommService()
{

}

void FMSCommService::onMessage(QSharedPointer<BaseMessage> msg)
{

}

void FMSCommService::onStartProcess()
{
    LOG_DEBUG("Created FMSCommService");

    // Init FMS device
    if(!mFMSDevice)
    {
        mFMSDevice.reset(new FMSDevice);
        QObject::connect(mFMSDevice.get(),&FMSDevice::sigReceiveResponse,this,&FMSCommService::onReceiveResponse);
    }
}

void FMSCommService::setSystemConfig(const SystemConfig_t &systemConfig)
{
    mSystemConfig = systemConfig;
}

void FMSCommService::processActionFromMiddleware(const QSharedPointer<Action> &action)
{
    switch (action->getType<ActionType>())
    {
        case ActionType::FMSSendCommand:
        {
            sendCommand(action->getPayload<QString>());
            break;
        }
        case ActionType::FMSEnable:
        {
            enable();
            break;
        }
        case ActionType::FMSDisable:
        {
            disable();
            break;
        }
        case ActionType::FMSReset:
        {
            reset();
            break;
        }
        case ActionType::FMSControlOn:
        {
            controlOn();
            break;
        }
        case ActionType::FMSControlOff:
        {
            controlOff();
            break;
        }
        case ActionType::FMSPowerOff:
        {
            powerOff();
            break;
        }
        case ActionType::FMSStopMoving:
        {
            stopMoving();
            break;
        }
        case ActionType::FMSHoming:
        {
            homing();
            break;
        }
        case ActionType::FMSMoveOff:
        {
            moveOff();
            break;
        }
        case ActionType::FMSMovePosition:
        {
            moveAbsPosition(action->getPayload<QVariantMap>());
            break;
        }
        case ActionType::FMSQueryStatus:
        {
            queryStatus();
            break;
        }
        case ActionType::FMSQueryVelocity:
        {
            queryVelocity();
            break;
        }
        case ActionType::FMSQueryAcc:
        {
            queryAcc();
            break;
        }
        case ActionType::FMSQueryHomeOffset:
        {
            queryHomeOffset();
            break;
        }
        case ActionType::FMSQueryLimitWorkSpace:
        {
            queryLimitWorkSpace();
            break;
        }
        case ActionType::FMSQueryLimitVelocity:
        {
            queryLimitVelocity();
            break;
        }
        case ActionType::FMSQueryLimitAcc:
        {
            queryLimitAcc();
            break;
        }
        case ActionType::FMSConfigVelocity:
        {
            configVelocity(action->getPayload<QVariantMap>());
            break;
        }
        case ActionType::FMSConfigLimitVelocity:
        {
            configLimitVelocity(action->getPayload<QVariantMap>());
            break;
        }
        case ActionType::FMSConfigAcc:
        {
            configAcc(action->getPayload<QVariantMap>());
            break;
        }
        case ActionType::FMSConfigLimitAcc:
        {
            configLimitAcc(action->getPayload<QVariantMap>());
            break;
        }
        case ActionType::FMSConfigHomeOffset:
        {
            configHomeOffset(action->getPayload<QVariantMap>());
            break;
        }
        default:
        break;
    }
}

void FMSCommService::onReceiveResponse(QString response)
{

}

int FMSCommService::sendCommand(const QString &cmd)
{
    return mFMSDevice->sendCommand(cmd);
}

int FMSCommService::enable()
{
    return mFMSDevice->enable();
}

int FMSCommService::disable()
{
    return mFMSDevice->disable();
}

int FMSCommService::reset()
{
    return mFMSDevice->reset();
}

int FMSCommService::controlOn()
{
    return mFMSDevice->controllerOn();
}

int FMSCommService::controlOff()
{
    return mFMSDevice->controllerOff();
}

int FMSCommService::powerOff()
{
    return mFMSDevice->powerOff();
}

int FMSCommService::stopMoving()
{
    return mFMSDevice->stopMoving();
}

int FMSCommService::homing()
{
    return mFMSDevice->homing();
}

int FMSCommService::moveOff()
{
    return mFMSDevice->moveOff();
}

int FMSCommService::moveAbsPosition(const QVariantMap &data)
{
    double tx = data["tx"].toDouble();
    double ty = data["ty"].toDouble();
    double tz = data["tz"].toDouble();
    double rx = data["rx"].toDouble();
    double ry = data["ry"].toDouble();
    double rz = data["rz"].toDouble();

    return mFMSDevice->moveAbsPosition(tx,ty,tz,rx,ry,rz);
}

int FMSCommService::queryStatus()
{
    return mFMSDevice->queryStatus();
}

int FMSCommService::queryVelocity()
{
    return mFMSDevice->queryVelocity();
}

int FMSCommService::queryAcc()
{
    return mFMSDevice->queryAcc();
}

int FMSCommService::queryHomeOffset()
{
    return mFMSDevice->queryHomeOffset();
}

int FMSCommService::queryLimitWorkSpace()
{
    return mFMSDevice->queryLimitWorkSpace();
}

int FMSCommService::queryLimitVelocity()
{
    return mFMSDevice->queryLimitVelocity();
}

int FMSCommService::queryLimitAcc()
{
    return mFMSDevice->queryLimitAcc();
}

int FMSCommService::configVelocity(const QVariantMap &data)
{
    double tx = data["tx"].toDouble();
    double ty = data["ty"].toDouble();
    double tz = data["tz"].toDouble();
    double rx = data["rx"].toDouble();
    double ry = data["ry"].toDouble();
    double rz = data["rz"].toDouble();

    return mFMSDevice->configVelocity(tx,ty,tz,rx,ry,rz);
}

int FMSCommService::configLimitVelocity(const QVariantMap &data)
{
    double tx = data["tx"].toDouble();
    double ty = data["ty"].toDouble();
    double tz = data["tz"].toDouble();
    double rx = data["rx"].toDouble();
    double ry = data["ry"].toDouble();
    double rz = data["rz"].toDouble();

    return mFMSDevice->configLimitVelocity(tx,ty,tz,rx,ry,rz);
}

int FMSCommService::configAcc(const QVariantMap &data)
{
    double tx = data["tx"].toDouble();
    double ty = data["ty"].toDouble();
    double tz = data["tz"].toDouble();
    double rx = data["rx"].toDouble();
    double ry = data["ry"].toDouble();
    double rz = data["rz"].toDouble();

    return mFMSDevice->configAcc(tx,ty,tz,rx,ry,rz);
}

int FMSCommService::configLimitAcc(const QVariantMap &data)
{
    double tx = data["tx"].toDouble();
    double ty = data["ty"].toDouble();
    double tz = data["tz"].toDouble();
    double rx = data["rx"].toDouble();
    double ry = data["ry"].toDouble();
    double rz = data["rz"].toDouble();

    return mFMSDevice->configLimitAcc(tx,ty,tz,rx,ry,rz);
}

int FMSCommService::configHomeOffset(const QVariantMap &data)
{
    double tx = data["tx"].toDouble();
    double ty = data["ty"].toDouble();
    double tz = data["tz"].toDouble();
    double rx = data["rx"].toDouble();
    double ry = data["ry"].toDouble();
    double rz = data["rz"].toDouble();

    return mFMSDevice->configHomeOffset(tx,ty,tz,rx,ry,rz);
}
