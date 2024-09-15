#ifndef CFGLIMWSSETCOMMANDPROCESSER_H
#define CFGLIMWSSETCOMMANDPROCESSER_H

#include "CommandProcesserInterface.h"

class CfgLimWsSetCommandProcesser : public CommandProcesserInterface
{
public:
    CfgLimWsSetCommandProcesser();

public:
    void processCmd(const QString& cmd);
    void processParameter(BaseInfo *baseInfo);
    void sendCommand(BaseInfo *baseInfo);
};

#endif // CFGLIMWSSETCOMMANDPROCESSER_H
