#ifndef AXISCONTROLOFFCOMMANDPROCESSER_H
#define AXISCONTROLOFFCOMMANDPROCESSER_H

#include "CommandProcesserInterface.h"

class AxisHomingInfo;
class AxisControlOffMessage;

class AxisControlOffCommandProcesser : public CommandProcesserInterface
{
public:
    AxisControlOffCommandProcesser();
    ~AxisControlOffCommandProcesser();

public:
    void processCmd(const QString& cmd);
    void processParameter(BaseInfo *baseInfo);
    void sendCommand(BaseInfo *baseInfo);

private:
    AxisHomingInfo *info = nullptr;
    AxisControlOffMessage *message = nullptr;
};

#endif // AXISCONTROLOFFCOMMANDPROCESSER_H
