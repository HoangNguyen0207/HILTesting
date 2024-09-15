#ifndef CONTROLONCOMMANDPROCESSER_H
#define CONTROLONCOMMANDPROCESSER_H

#include "enablecommandprocesser.h"

class ControlOnCommandProcesser : public EnableCommandProcesser
{
public:
    ControlOnCommandProcesser();

public:
    void sendCommand(BaseInfo *baseInfo) override;
};

#endif // CONTROLONCOMMANDPROCESSER_H
