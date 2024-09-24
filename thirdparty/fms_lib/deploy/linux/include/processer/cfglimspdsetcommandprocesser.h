#ifndef CFGLIMSPDSETCOMMANDPROCESSER_H
#define CFGLIMSPDSETCOMMANDPROCESSER_H

#include "CommandProcesserInterface.h"

class CfgLimSpdSetCommandProcesser : public CommandProcesserInterface
{
public:
    CfgLimSpdSetCommandProcesser();

public:
    void processCmd(const QString& cmd);
    void processParameter(BaseInfo *baseInfo);
    void sendCommand(BaseInfo *baseInfo);
};

#endif // CFGLIMSPDSETCOMMANDPROCESSER_H
