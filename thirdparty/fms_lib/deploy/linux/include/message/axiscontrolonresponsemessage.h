#ifndef AXISCONTROLONRESPONSEMESSAGE_H
#define AXISCONTROLONRESPONSEMESSAGE_H

#include "IOMessage.h"

class AxisControlOnResponseMessage : public IOMessage
{
public:
    AxisControlOnResponseMessage();

    int serialToData(char *dest, int length) override;
    int parseFromData(char *mesData, int mesLen) override;

    short getState() const;
    void setState(short value);

private:
    short state;
};

#endif // AXISCONTROLONRESPONSEMESSAGE_H
