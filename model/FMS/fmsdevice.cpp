#include "fmsdevice.h"
#include <QDebug>
#include <QThread>

FMSDevice::FMSDevice(QObject *parent)
    : QObject(parent)
{
//    QThread::currentThread()->setObjectName("FMS");
    FmsManager::Instance()->initialize();
    QObject::connect(FmsManager::Instance(),&FmsManager::sigResponseResult,this,&FMSDevice::onReceiveResponse,
                     Qt::QueuedConnection);
}

FMSDevice::~FMSDevice()
{

}

int FMSDevice::sendCommand(const QString &cmd)
{
    return FmsManager::Instance()->processCommand(cmd);
}

int FMSDevice::enable()
{
    return FmsManager::Instance()->processCommand(CMD_ENABLE);
}

int FMSDevice::disable()
{
    return FmsManager::Instance()->processCommand(CMD_DISABLE);
}

int FMSDevice::reset()
{
    return FmsManager::Instance()->processCommand(CMD_RESET);
}

int FMSDevice::controllerOn()
{
    return FmsManager::Instance()->processCommand(CMD_CONTROL_ON);
}

int FMSDevice::controllerOff()
{
    return FmsManager::Instance()->processCommand(CMD_CONTROL_OFF);
}

int FMSDevice::powerOff()
{
    return FmsManager::Instance()->processCommand(CMD_POWER_OFF);
}

int FMSDevice::stopMoving()
{
    return FmsManager::Instance()->processCommand(CMD_STOP);
}

int FMSDevice::homing()
{
    return FmsManager::Instance()->processCommand(CMD_HOMING);
}

int FMSDevice::moveOff()
{
    return FmsManager::Instance()->processCommand(CMD_MOVE_OFF);
}

int FMSDevice::moveAbsPosition(double tx, double ty,
                               double tz, double rx,
                               double ry, double rz)
{
    return FmsManager::Instance()->processCommand(CMD_MOVE_ABS(tx,ty,tz,rx,ry,rz));
}

int FMSDevice::queryStatus()
{
    return FmsManager::Instance()->processCommand(QRY_HEXAPOD);
}

int FMSDevice::queryVelocity()
{
    return FmsManager::Instance()->processCommand(QRY_VELOCITY);
}

int FMSDevice::queryAcc()
{
    return FmsManager::Instance()->processCommand(QRY_ACC);
}

int FMSDevice::queryHomeOffset()
{
    return FmsManager::Instance()->processCommand(QRY_HOME_OFFSET);
}

int FMSDevice::queryLimitWorkSpace()
{
    return FmsManager::Instance()->processCommand(QRY_LIM_WS);
}

int FMSDevice::queryLimitVelocity()
{
    return FmsManager::Instance()->processCommand(QRY_LIM_VELOCITY);
}

int FMSDevice::queryLimitAcc()
{
    return FmsManager::Instance()->processCommand(QRY_LIM_ACC);
}

int FMSDevice::configVelocity(double tx, double ty, double tz, double rx, double ry, double rz)
{
    return FmsManager::Instance()->processCommand(CFG_VELOCITY(tx,ty,tz,rx,ry,rz));
}

int FMSDevice::configLimitVelocity(double tx, double ty, double tz, double rx, double ry, double rz)
{
    return FmsManager::Instance()->processCommand(CFG_LIM_VELOCITY(tx,ty,tz,rx,ry,rz));
}

int FMSDevice::configAcc(double tx, double ty, double tz, double rx, double ry, double rz)
{
    return FmsManager::Instance()->processCommand(CFG_ACC(tx,ty,tz,rx,ry,rz));
}

int FMSDevice::configLimitAcc(double tx, double ty, double tz, double rx, double ry, double rz)
{
    return FmsManager::Instance()->processCommand(CFG_LIM_ACC(tx,ty,tz,rx,ry,rz));
}

int FMSDevice::configHomeOffset(double tx, double ty, double tz, double rx, double ry, double rz)
{
    return FmsManager::Instance()->processCommand(CFG_HOME_OFFSET(tx,ty,tz,rx,ry,rz));
}

void FMSDevice::setDemandData(const FMSDemandData &data)
{
    mDemandData = data;
}

FMSDemandData FMSDevice::getFMSDemandData() const
{
    return mDemandData;
}

void FMSDevice::onReceiveResponse(QString response)
{
    qDebug() << response;
    emit sigReceiveResponse(response);
}
