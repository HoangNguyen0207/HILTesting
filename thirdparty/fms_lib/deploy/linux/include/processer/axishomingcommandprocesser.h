#ifndef AXISHOMINGCOMMANDPROCESSER_H
#define AXISHOMINGCOMMANDPROCESSER_H

#include "CommandProcesserInterface.h"

class AxisHomingInfo;
class AxisHomingMessage;

class AxisHomingCommandProcesser : public CommandProcesserInterface
{
public:
    AxisHomingCommandProcesser();
    // CommandProcesserInterface interface
public:
    void processCmd(const QString& cmd);
    void processParameter(BaseInfo *baseInfo);
    void sendCommand(BaseInfo *baseInfo);

private:
    AxisHomingInfo *info = nullptr;
    AxisHomingMessage *message = nullptr;
};

#endif // AXISHOMINGCOMMANDPROCESSER_H
