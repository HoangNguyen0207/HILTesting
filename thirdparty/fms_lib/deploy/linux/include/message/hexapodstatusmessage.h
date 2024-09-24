#ifndef HEXAPODSTATUSMESSAGE_H
#define HEXAPODSTATUSMESSAGE_H

#include "IOMessage.h"

class HexapodStatusMessage : public IOMessage
{
public:
    HexapodStatusMessage();

    int serialToData(char *dest, int length) override;
    int parseFromData(char *mesData, int mesLen) override;
};

#endif // HEXAPODSTATUSMESSAGE_H
