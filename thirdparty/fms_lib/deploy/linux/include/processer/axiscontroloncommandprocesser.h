#ifndef AXISCONTROLONCOMMANDPROCESSER_H
#define AXISCONTROLONCOMMANDPROCESSER_H

#include "CommandProcesserInterface.h"

class AxisHomingInfo;
class AxisControlOnMessage;

class AxisControlOnCommandProcesser : public CommandProcesserInterface
{
public:
    AxisControlOnCommandProcesser();

public:
    void processCmd(const QString& cmd);
    void processParameter(BaseInfo *baseInfo);
    void sendCommand(BaseInfo *baseInfo);

private:
    AxisHomingInfo *info = nullptr;
    AxisControlOnMessage *message = nullptr;
};

#endif // AXISCONTROLONCOMMANDPROCESSER_H
