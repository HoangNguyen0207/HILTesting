#ifndef AXISHOMINGCOMMANDPROCESSER_H
#define AXISHOMINGCOMMANDPROCESSER_H

#include "CommandProcesserInterface.h"

class AxisHomingCommandProcesser : public CommandProcesserInterface
{
public:
    AxisHomingCommandProcesser();
    // CommandProcesserInterface interface
public:
    void processCmd(const QString& cmd);
    void processParameter(BaseInfo *baseInfo);
    void sendCommand(BaseInfo *baseInfo);
};

#endif // AXISHOMINGCOMMANDPROCESSER_H
