#ifndef CFGLIMWSGETCOMMANDPROCESSER_H
#define CFGLIMWSGETCOMMANDPROCESSER_H

#include "CommandProcesserInterface.h"

class CfgLimWsGetCommandProcesser : public CommandProcesserInterface
{
public:
    CfgLimWsGetCommandProcesser();

public:
    void processCmd(const QString& cmd);
    void processParameter(BaseInfo *baseInfo);
    void sendCommand(BaseInfo *baseInfo);
};

#endif // CFGLIMWSGETCOMMANDPROCESSER_H
