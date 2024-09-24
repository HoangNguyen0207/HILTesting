#ifndef POWEROFFMESSAGE_H
#define POWEROFFMESSAGE_H

#include "IOMessage.h"

class PowerOffMessage : public IOMessage
{
public:
    PowerOffMessage();
    ~PowerOffMessage();

    int serialToData(char *dest, int length) override;
    int parseFromData(char *mesData, int mesLen) override;
};

#endif // POWEROFFMESSAGE_H
