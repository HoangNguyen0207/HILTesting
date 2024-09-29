#ifndef CFGLIMSPDGETCOMMANDPROCESSER_H
#define CFGLIMSPDGETCOMMANDPROCESSER_H

#include "CommandProcesserInterface.h"
#include <QObject>
#include "info/ResponseInfo.h"

class AxisHomingInfo;
class CfgLimSpdGetMessage;

class CfgLimSpdGetCommandProcesser : public QObject, public CommandProcesserInterface
{
    Q_OBJECT
public:
    CfgLimSpdGetCommandProcesser();

public:
    void processCmd(const QString& cmd);
    void processParameter(BaseInfo *baseInfo);
    void sendCommand(BaseInfo *baseInfo);

signals:
    void sigResponseResult(ResponseInfo responseInfo);

private:
    AxisHomingInfo *info = nullptr;
    CfgLimSpdGetMessage *message = nullptr;
};

#endif // CFGLIMSPDGETCOMMANDPROCESSER_H
