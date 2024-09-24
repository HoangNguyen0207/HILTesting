#ifndef CFGLIMACCGETCOMMANDPROCESSER_H
#define CFGLIMACCGETCOMMANDPROCESSER_H

#include "CommandProcesserInterface.h"

class CfgLimAccGetCommandProcesser : public CommandProcesserInterface
{
public:
    CfgLimAccGetCommandProcesser();

public:
    void processCmd(const QString& cmd);
    void processParameter(BaseInfo *baseInfo);
    void sendCommand(BaseInfo *baseInfo);
};

#endif // CFGLIMACCGETCOMMANDPROCESSER_H
