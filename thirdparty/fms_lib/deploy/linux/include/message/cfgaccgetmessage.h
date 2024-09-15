#ifndef CFGACCGETMESSAGE_H
#define CFGACCGETMESSAGE_H

#include "IOMessage.h"

class CfgAccGetMessage : public IOMessage
{
public:
    CfgAccGetMessage();

    int serialToData(char *dest, int length) override;
    int parseFromData(char *mesData, int mesLen) override;
};

#endif // CFGACCGETMESSAGE_H
