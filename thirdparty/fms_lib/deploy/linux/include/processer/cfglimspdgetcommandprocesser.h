#ifndef CFGLIMSPDGETCOMMANDPROCESSER_H
#define CFGLIMSPDGETCOMMANDPROCESSER_H

#include "CommandProcesserInterface.h"

class CfgLimSpdGetCommandProcesser : public CommandProcesserInterface
{
public:
    CfgLimSpdGetCommandProcesser();

public:
    void processCmd(const QString& cmd);
    void processParameter(BaseInfo *baseInfo);
    void sendCommand(BaseInfo *baseInfo);
};

#endif // CFGLIMSPDGETCOMMANDPROCESSER_H
