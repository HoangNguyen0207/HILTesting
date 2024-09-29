#ifndef CFGHOMEOFFSETGETCOMMANDPROCESSER_H
#define CFGHOMEOFFSETGETCOMMANDPROCESSER_H

#include "CommandProcesserInterface.h"
#include <QObject>
#include "info/ResponseInfo.h"
#include "info/moveabsinfo.h"

class CfgHomeOffsetGetCommandProcesser : public QObject, public CommandProcesserInterface
{
    Q_OBJECT
public:
    CfgHomeOffsetGetCommandProcesser();

public:
    void processCmd(const QString& cmd);
    void processParameter(BaseInfo *baseInfo);
    void sendCommand(BaseInfo *baseInfo);

    MoveAbsInfo *getInfo() const;
    void setInfo(MoveAbsInfo *value);

signals:
    void sigResponseResult(ResponseInfo responseInfo);

private:
    MoveAbsInfo *info = nullptr;
};

#endif // CFGHOMEOFFSETGETCOMMANDPROCESSER_H
