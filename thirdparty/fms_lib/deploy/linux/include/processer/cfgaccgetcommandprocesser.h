#ifndef CFGACCGETCOMMANDPROCESSER_H
#define CFGACCGETCOMMANDPROCESSER_H

#include "enablecommandprocesser.h"

class CfgAccGetCommandProcesser : public EnableCommandProcesser
{
public:
    CfgAccGetCommandProcesser();
public:
    void sendCommand(BaseInfo *baseInfo) override;
};

#endif // CFGACCGETCOMMANDPROCESSER_H
