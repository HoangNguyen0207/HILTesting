#ifndef AXISCONTROLONCOMMANDPROCESSER_H
#define AXISCONTROLONCOMMANDPROCESSER_H

#include "CommandProcesserInterface.h"

class AxisControlOnCommandProcesser : public CommandProcesserInterface
{
public:
    AxisControlOnCommandProcesser();

public:
    void processCmd(const QString& cmd);
    void processParameter(BaseInfo *baseInfo);
    void sendCommand(BaseInfo *baseInfo);
};

#endif // AXISCONTROLONCOMMANDPROCESSER_H
