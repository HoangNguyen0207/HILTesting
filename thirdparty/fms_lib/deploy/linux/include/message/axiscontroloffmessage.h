#ifndef AXISCONTROLOFFMESSAGE_H
#define AXISCONTROLOFFMESSAGE_H

#include "IOMessage.h"

class AxisControlOffMessage : public IOMessage
{
public:
    AxisControlOffMessage();

    int serialToData(char *dest, int length) override;
    int parseFromData(char *mesData, int mesLen) override;

    uint32 getP1() const;
    void setP1(const uint32 &value);

private:
    uint32 p1 = 0;
};

#endif // AXISCONTROLOFFMESSAGE_H
