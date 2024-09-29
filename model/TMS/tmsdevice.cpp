#include "tmsdevice.h"


TMSDevice::TMSDevice(QObject *parent) : QObject(parent)
{

}

TMSDevice::~TMSDevice()
{

}

int TMSDevice::sendCommand(const QString &cmd)
{

}

int TMSDevice::enable()
{

}

int TMSDevice::disable()
{

}

int TMSDevice::reset()
{

}

int TMSDevice::controllerOn()
{

}

int TMSDevice::controllerOff()
{

}

int TMSDevice::powerOff()
{

}

int TMSDevice::stopMoving()
{

}

int TMSDevice::homing()
{

}

int TMSDevice::moveOff()
{

}

int TMSDevice::moveAbsPosition(double tx, double ty, double rx, double ry)
{

}

int TMSDevice::queryStatus()
{

}

int TMSDevice::queryVelocity()
{

}

int TMSDevice::queryAcc()
{

}

int TMSDevice::queryHomeOffset()
{

}

int TMSDevice::queryLimitWorkSpace()
{

}

int TMSDevice::queryLimitVelocity()
{

}

int TMSDevice::queryLimitAcc()
{

}

int TMSDevice::configVelocity(double tx, double ty, double rx, double ry)
{

}

int TMSDevice::configLimitVelocity(double tx, double ty, double rx, double ry)
{

}

int TMSDevice::configAcc(double tx, double ty, double rx, double ry)
{

}

int TMSDevice::configLimitAcc(double tx, double ty, double rx, double ry)
{

}

int TMSDevice::configHomeOffset(double tx, double ty, double rx, double ry)
{

}

void TMSDevice::onReceiveResponse(QString response)
{

}
