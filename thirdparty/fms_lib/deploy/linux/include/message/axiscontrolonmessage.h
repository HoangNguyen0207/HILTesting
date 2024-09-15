#ifndef AXISCONTROLONMESSAGE_H
#define AXISCONTROLONMESSAGE_H

#include "IOMessage.h"

class AxisControlOnMessage : public IOMessage
{
public:
    AxisControlOnMessage();

    int serialToData(char *dest, int length) override;
    int parseFromData(char *mesData, int mesLen) override;

    uint32 getP1() const;
    void setP1(const uint32 &value);

private:
    uint32 p1 = 0;
};

#endif // AXISCONTROLONMESSAGE_H
