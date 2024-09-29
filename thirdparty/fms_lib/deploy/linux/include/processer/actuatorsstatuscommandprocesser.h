#ifndef ACTUATORSSTATUSCOMMANDPROCESSER_H
#define ACTUATORSSTATUSCOMMANDPROCESSER_H

#include "enablecommandprocesser.h"

class ActuatorsStatusMessage;

class ActuatorsStatusCommandProcesser : public EnableCommandProcesser
{
public:
    ActuatorsStatusCommandProcesser();
    ~ActuatorsStatusCommandProcesser() override;

    // CommandProcesserInterface interface
public:
    void sendCommand(BaseInfo *baseInfo) override;
private:
    ActuatorsStatusMessage *message = nullptr;
};

#endif // ACTUATORSSTATUSCOMMANDPROCESSER_H
