#ifndef AXISHOMINGMESSAGE_H
#define AXISHOMINGMESSAGE_H

#include "IOMessage.h"

class AxisHomingMessage : public IOMessage
{
public:
    AxisHomingMessage();

    int serialToData(char *dest, int length) override;
    int parseFromData(char *mesData, int mesLen) override;

    uint32 getP1() const;
    void setP1(const uint32 &value);

private:
    uint32 p1 = 0;
};

#endif // AXISHOMINGMESSAGE_H
