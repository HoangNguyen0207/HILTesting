#ifndef CFGSPDSETCOMMANDPROCESSER_H
#define CFGSPDSETCOMMANDPROCESSER_H

#include "CommandProcesserInterface.h"

#include <QObject>
#include "info/ResponseInfo.h"

class CfgSpdSetInfo;

class CfgSpdSetCommandProcesser : public QObject, public CommandProcesserInterface
{
    Q_OBJECT
public:
    CfgSpdSetCommandProcesser();

public:
    void processCmd(const QString& cmd);
    void processParameter(BaseInfo *baseInfo);
    void sendCommand(BaseInfo *baseInfo);

signals:
    void sigResponseResult(ResponseInfo responseInfo);

private:
    CfgSpdSetInfo *info = nullptr;
};

#endif // CFGSPDSETCOMMANDPROCESSER_H
