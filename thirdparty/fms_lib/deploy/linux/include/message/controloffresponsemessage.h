#ifndef CONTROLOFFRESPONSEMESSAGE_H
#define CONTROLOFFRESPONSEMESSAGE_H

#include "IOMessage.h"

class ControlOffResponseMessage : public IOMessage
{
public:
    ControlOffResponseMessage();

    int serialToData(char *dest, int length) override;
    int parseFromData(char *mesData, int mesLen) override;

    short getState() const;
    void setState(short value);

private:
    short state;
};

#endif // CONTROLOFFRESPONSEMESSAGE_H
