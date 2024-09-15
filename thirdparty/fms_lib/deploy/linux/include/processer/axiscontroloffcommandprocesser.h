#ifndef AXISCONTROLOFFCOMMANDPROCESSER_H
#define AXISCONTROLOFFCOMMANDPROCESSER_H

#include "CommandProcesserInterface.h"

class AxisControlOffCommandProcesser : public CommandProcesserInterface
{
public:
    AxisControlOffCommandProcesser();

public:
    void processCmd(const QString& cmd);
    void processParameter(BaseInfo *baseInfo);
    void sendCommand(BaseInfo *baseInfo);
};

#endif // AXISCONTROLOFFCOMMANDPROCESSER_H
