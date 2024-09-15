#ifndef STOPMESSAGE_H
#define STOPMESSAGE_H

#include "IOMessage.h"

class StopMessage : public IOMessage
{
public:
    StopMessage();

    int serialToData(char *dest, int length) override;
    int parseFromData(char *mesData, int mesLen) override;
};

#endif // STOPMESSAGE_H
