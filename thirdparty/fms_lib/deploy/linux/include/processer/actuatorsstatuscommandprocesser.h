#ifndef ACTUATORSSTATUSCOMMANDPROCESSER_H
#define ACTUATORSSTATUSCOMMANDPROCESSER_H

#include "enablecommandprocesser.h"

class ActuatorsStatusCommandProcesser : public EnableCommandProcesser
{
public:
    ActuatorsStatusCommandProcesser();

    // CommandProcesserInterface interface
public:
    void sendCommand(BaseInfo *baseInfo) override;
};

#endif // ACTUATORSSTATUSCOMMANDPROCESSER_H
