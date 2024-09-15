#ifndef CFGLIMACCGETMESSAGE_H
#define CFGLIMACCGETMESSAGE_H

#include "IOMessage.h"

class CfgLimAccGetMessage : public IOMessage
{
public:
    CfgLimAccGetMessage();

    int serialToData(char *dest, int length) override;
    int parseFromData(char *mesData, int mesLen) override;

    uint32 getP1() const;
    void setP1(const uint32 &value);

private:
    uint32 p1 = 0;
};

#endif // CFGLIMACCGETMESSAGE_H
