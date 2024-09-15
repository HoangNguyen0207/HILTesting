#ifndef DISABLEMESSAGE_H
#define DISABLEMESSAGE_H

#include "IOMessage.h"

class DisableMessage : public IOMessage
{
public:
    DisableMessage();
    ~DisableMessage() override;

    int serialToData(char *dest, int length) override;
    int parseFromData(char *mesData, int mesLen) override;
};

#endif // DISABLEMESSAGE_H
