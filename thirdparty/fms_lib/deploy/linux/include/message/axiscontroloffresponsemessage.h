#ifndef AXISCONTROLOFFRESPONSEMESSAGE_H
#define AXISCONTROLOFFRESPONSEMESSAGE_H

#include "IOMessage.h"

class AxisControlOffResponseMessage : public IOMessage
{
public:
    AxisControlOffResponseMessage();

    int serialToData(char *dest, int length) override;
    int parseFromData(char *mesData, int mesLen) override;

    short getState() const;
    void setState(short value);

private:
    short state;
};

#endif // AXISCONTROLOFFRESPONSEMESSAGE_H
