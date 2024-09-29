#ifndef CFGLIMACCGETCOMMANDPROCESSER_H
#define CFGLIMACCGETCOMMANDPROCESSER_H

#include "CommandProcesserInterface.h"
#include <QObject>
#include "info/ResponseInfo.h"

class AxisHomingInfo;
class CfgLimAccGetMessage;

class CfgLimAccGetCommandProcesser : public QObject, public CommandProcesserInterface
{
    Q_OBJECT
public:
    CfgLimAccGetCommandProcesser();

public:
    void processCmd(const QString& cmd);
    void processParameter(BaseInfo *baseInfo);
    void sendCommand(BaseInfo *baseInfo);

signals:
    void sigResponseResult(ResponseInfo responseInfo);

private:
    AxisHomingInfo *info = nullptr;
    CfgLimAccGetMessage *message = nullptr;
};

#endif // CFGLIMACCGETCOMMANDPROCESSER_H
