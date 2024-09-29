#include "tmscommservice.h"


TMSCommService::TMSCommService(const QString &processorName)
    : ProcessorAbstract(processorName)
{

}

TMSCommService::~TMSCommService()
{

}

void TMSCommService::onMessage(QSharedPointer<BaseMessage> msg)
{

}

void TMSCommService::onStartProcess()
{
    LOG_DEBUG("Created TMSCommService");
}

void TMSCommService::setSystemConfig(const SystemConfig_t &systemConfig)
{

}

void TMSCommService::processActionFromMiddleware(const QSharedPointer<Action> &action)
{

}

void TMSCommService::onReceiveResponse(QString response)
{

}

int TMSCommService::sendCommand(const QString &cmd)
{

}

int TMSCommService::enable()
{

}

int TMSCommService::disable()
{

}

int TMSCommService::reset()
{

}

int TMSCommService::controlOn()
{

}

int TMSCommService::controlOff()
{

}

int TMSCommService::powerOff()
{

}

int TMSCommService::stopMoving()
{

}

int TMSCommService::homing()
{

}

int TMSCommService::moveOff()
{

}

int TMSCommService::moveAbsPosition(const QVariantMap &data)
{

}

int TMSCommService::queryStatus()
{

}

int TMSCommService::queryVelocity()
{

}

int TMSCommService::queryAcc()
{

}

int TMSCommService::queryHomeOffset()
{

}

int TMSCommService::queryLimitWorkSpace()
{

}

int TMSCommService::queryLimitVelocity()
{

}

int TMSCommService::queryLimitAcc()
{

}

int TMSCommService::configVelocity(const QVariantMap &data)
{

}

int TMSCommService::configLimitVelocity(const QVariantMap &data)
{

}

int TMSCommService::configAcc(const QVariantMap &data)
{

}

int TMSCommService::configLimitAcc(const QVariantMap &data)
{

}

int TMSCommService::configHomeOffset(const QVariantMap &data)
{

}
