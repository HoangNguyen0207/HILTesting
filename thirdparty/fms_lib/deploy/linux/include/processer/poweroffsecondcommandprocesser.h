#ifndef POWEROFFSECONDCOMMANDPROCESSER_H
#define POWEROFFSECONDCOMMANDPROCESSER_H

#include "enablecommandprocesser.h"

class PowerOffSecondMessage;

class PowerOffSecondCommandProcesser : public EnableCommandProcesser
{
public:
    PowerOffSecondCommandProcesser();

public:
    void sendCommand(BaseInfo *baseInfo) override;
private:
    PowerOffSecondMessage *message = nullptr;
};

#endif // POWEROFFSECONDCOMMANDPROCESSER_H
