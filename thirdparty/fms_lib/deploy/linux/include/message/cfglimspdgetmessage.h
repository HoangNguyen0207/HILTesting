#ifndef CFGLIMSPDGETMESSAGE_H
#define CFGLIMSPDGETMESSAGE_H

#include "IOMessage.h"

class CfgLimSpdGetMessage : public IOMessage
{
public:
    CfgLimSpdGetMessage();

    int serialToData(char *dest, int length) override;
    int parseFromData(char *mesData, int mesLen) override;

    uint32 getP1() const;
    void setP1(const uint32 &value);

private:
    uint32 p1 = 0;
};

#endif // CFGLIMSPDGETMESSAGE_H
