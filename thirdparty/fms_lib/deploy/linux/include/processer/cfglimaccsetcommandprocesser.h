#ifndef CFGLIMACCSETCOMMANDPROCESSER_H
#define CFGLIMACCSETCOMMANDPROCESSER_H

#include "CommandProcesserInterface.h"

class CfgLimAccSetCommandProcesser : public CommandProcesserInterface
{
public:
    CfgLimAccSetCommandProcesser();

public:
    void processCmd(const QString& cmd);
    void processParameter(BaseInfo *baseInfo);
    void sendCommand(BaseInfo *baseInfo);
};

#endif // CFGLIMACCSETCOMMANDPROCESSER_H
