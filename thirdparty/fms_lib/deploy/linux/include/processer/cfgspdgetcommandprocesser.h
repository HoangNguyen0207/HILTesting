#ifndef CFGSPDGETCOMMANDPROCESSER_H
#define CFGSPDGETCOMMANDPROCESSER_H

#include "enablecommandprocesser.h"

class CfgSpdGetCommandProcesser : public EnableCommandProcesser
{
public:
    CfgSpdGetCommandProcesser();

public:
    void sendCommand(BaseInfo *baseInfo) override;
};

#endif // CFGSPDGETCOMMANDPROCESSER_H
