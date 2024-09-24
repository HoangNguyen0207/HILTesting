#ifndef AXISHOMINGRESPONSEMESSAGE_H
#define AXISHOMINGRESPONSEMESSAGE_H

#include "IOMessage.h"

class AxisHomingResponseMessage : public IOMessage
{
public:
    AxisHomingResponseMessage();
    int serialToData(char *dest, int length) override;
    int parseFromData(char *mesData, int mesLen) override;

    short getState() const;
    void setState(short value);

private:
    short state;
};

#endif // AXISHOMINGRESPONSEMESSAGE_H
