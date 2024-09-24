#ifndef DISABLERESPONSEMESSAGE_H
#define DISABLERESPONSEMESSAGE_H

#include "IOMessage.h"

class DisableResponseMessage : public IOMessage
{
public:
    DisableResponseMessage();

    int serialToData(char *dest, int length) override;
    int parseFromData(char *mesData, int mesLen) override;

    short getState() const;
    void setState(short value);

private:
    short state;
};

#endif // DISABLERESPONSEMESSAGE_H
