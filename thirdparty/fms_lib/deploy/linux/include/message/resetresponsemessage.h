#ifndef RESETRESPONSEMESSAGE_H
#define RESETRESPONSEMESSAGE_H

#include "IOMessage.h"

class ResetResponseMessage : public IOMessage
{
public:
    ResetResponseMessage();

    int serialToData(char *dest, int length) override;
    int parseFromData(char *mesData, int mesLen) override;

    short getState() const;
    void setState(short value);

private:
    short state;
};

#endif // RESETRESPONSEMESSAGE_H
