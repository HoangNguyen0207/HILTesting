#ifndef STOPRESPONSEMESSAGE_H
#define STOPRESPONSEMESSAGE_H

#include "IOMessage.h"

class StopResponseMessage : public IOMessage
{
public:
    StopResponseMessage();

    int serialToData(char *dest, int length) override;
    int parseFromData(char *mesData, int mesLen) override;

    short getState() const;
    void setState(short value);

private:
    short state;
};

#endif // STOPRESPONSEMESSAGE_H
