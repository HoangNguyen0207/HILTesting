#ifndef CFGLIMACCSETCOMMANDPROCESSER_H
#define CFGLIMACCSETCOMMANDPROCESSER_H

#include "CommandProcesserInterface.h"
#include <QObject>
#include "info/ResponseInfo.h"

class CfgLimInfo;
class CfgLimAccSetMessage;

class CfgLimAccSetCommandProcesser : public QObject, public CommandProcesserInterface
{
    Q_OBJECT
public:
    CfgLimAccSetCommandProcesser();

signals:
    void sigResponseResult(ResponseInfo responseInfo);

public:
    void processCmd(const QString& cmd);
    void processParameter(BaseInfo *baseInfo);
    void sendCommand(BaseInfo *baseInfo);

private:
    CfgLimInfo *info = nullptr;
    CfgLimAccSetMessage *message = nullptr;
};

#endif // CFGLIMACCSETCOMMANDPROCESSER_H
