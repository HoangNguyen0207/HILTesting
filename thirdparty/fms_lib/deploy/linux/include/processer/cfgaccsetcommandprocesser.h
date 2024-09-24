#ifndef CFGACCSETCOMMANDPROCESSER_H
#define CFGACCSETCOMMANDPROCESSER_H

#include "CommandProcesserInterface.h"

class CfgAccSetCommandProcesser : public CommandProcesserInterface
{
public:
    CfgAccSetCommandProcesser();

public:
    void processCmd(const QString& cmd);
    void processParameter(BaseInfo *baseInfo);
    void sendCommand(BaseInfo *baseInfo);
};

#endif // CFGACCSETCOMMANDPROCESSER_H
