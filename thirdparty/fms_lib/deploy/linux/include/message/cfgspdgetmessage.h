#ifndef CFGSPDGETMESSAGE_H
#define CFGSPDGETMESSAGE_H

#include "IOMessage.h"

class CfgSpdGetMessage : public IOMessage
{
public:
    CfgSpdGetMessage();

    int serialToData(char *dest, int length) override;
    int parseFromData(char *mesData, int mesLen) override;
};

#endif // CFGSPDGETMESSAGE_H
