#ifndef CFGLIMWSGETCOMMANDPROCESSER_H
#define CFGLIMWSGETCOMMANDPROCESSER_H

#include "CommandProcesserInterface.h"
#include <QObject>
#include "info/ResponseInfo.h"
#include "info/moveabsinfo.h"

//class AxisHomingInfo;
class CfgLimWsGetMessage;

class CfgLimWsGetCommandProcesser : public QObject, public CommandProcesserInterface
{
    Q_OBJECT
public:
    CfgLimWsGetCommandProcesser();

public:
    void processCmd(const QString& cmd);
    void processParameter(BaseInfo *baseInfo);
    void sendCommand(BaseInfo *baseInfo);

    MoveAbsInfo *getInfo() const;
    void setInfo(MoveAbsInfo *value);

signals:
    void sigResponseResult(ResponseInfo responseInfo);

private:
//    AxisHomingInfo *info = nullptr;
    CfgLimWsGetMessage *message = nullptr;
    MoveAbsInfo *info = nullptr;
};

#endif // CFGLIMWSGETCOMMANDPROCESSER_H
