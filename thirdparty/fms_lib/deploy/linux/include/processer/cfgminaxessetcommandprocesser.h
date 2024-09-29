#ifndef CFGMINAXESSETCOMMANDPROCESSER_H
#define CFGMINAXESSETCOMMANDPROCESSER_H

#include "CommandProcesserInterface.h"

#include <QObject>
#include "info/ResponseInfo.h"

class CfgSpdSetInfo;

class CfgMinAxesSetCommandProcesser : public QObject, public CommandProcesserInterface
{
    Q_OBJECT
public:
    CfgMinAxesSetCommandProcesser();

public:
    void processCmd(const QString& cmd);
    void processParameter(BaseInfo *baseInfo);
    void sendCommand(BaseInfo *baseInfo);

signals:
    void sigResponseResult(ResponseInfo responseInfo);

private:
    CfgSpdSetInfo *info = nullptr;
};

#endif // CFGMINAXESSETCOMMANDPROCESSER_H
