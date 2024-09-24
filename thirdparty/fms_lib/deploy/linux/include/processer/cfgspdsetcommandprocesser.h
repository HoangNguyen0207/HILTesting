#ifndef CFGSPDSETCOMMANDPROCESSER_H
#define CFGSPDSETCOMMANDPROCESSER_H

#include "CommandProcesserInterface.h"

class CfgSpdSetCommandProcesser : public CommandProcesserInterface
{
public:
    CfgSpdSetCommandProcesser();

public:
    void processCmd(const QString& cmd);
    void processParameter(BaseInfo *baseInfo);
    void sendCommand(BaseInfo *baseInfo);
};

#endif // CFGSPDSETCOMMANDPROCESSER_H
