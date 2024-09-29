#ifndef CFGMINAXESGETCOMMANDPROCESSER_H
#define CFGMINAXESGETCOMMANDPROCESSER_H

#include "CommandProcesserInterface.h"
#include <QObject>
#include "info/ResponseInfo.h"


class CfgMinAxesGetCommandProcesser : public QObject, public CommandProcesserInterface
{
    Q_OBJECT
public:
    CfgMinAxesGetCommandProcesser();

public:
    void processCmd(const QString& cmd) override;
    void processParameter(BaseInfo *baseInfo) override;
    void sendCommand(BaseInfo *baseInfo) override;

signals:
    void sigResponseResult(ResponseInfo responseInfo);
};

#endif // CFGMINAXESGETCOMMANDPROCESSER_H
