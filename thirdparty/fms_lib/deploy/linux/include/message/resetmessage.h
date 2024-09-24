#ifndef RESETMESSAGE_H
#define RESETMESSAGE_H

#include "IOMessage.h"

class ResetMessage : public IOMessage
{
public:
    ResetMessage();
    ~ResetMessage();

    int serialToData(char *dest, int length) override;
    int parseFromData(char *mesData, int mesLen) override;

};

#endif // RESETMESSAGE_H
