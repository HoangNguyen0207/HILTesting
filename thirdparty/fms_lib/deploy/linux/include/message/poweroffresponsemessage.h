#ifndef POWEROFFRESPONSEMESSAGE_H
#define POWEROFFRESPONSEMESSAGE_H

#include "IOMessage.h"

class PowerOffResponseMessage : public IOMessage
{
public:
    PowerOffResponseMessage();

    int serialToData(char *dest, int length) override;
    int parseFromData(char *mesData, int mesLen) override;

    short getState() const;
    void setState(short value);

private:
    short state;
};

#endif // POWEROFFRESPONSEMESSAGE_H
