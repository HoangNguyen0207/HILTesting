#ifndef ACTUATORSSTATUSMESSAGE_H
#define ACTUATORSSTATUSMESSAGE_H

#include "IOMessage.h"

class ActuatorsStatusMessage : public IOMessage
{
public:
    ActuatorsStatusMessage();

    int serialToData(char *dest, int length) override;
    int parseFromData(char *mesData, int mesLen) override;

};

#endif // ACTUATORSSTATUSMESSAGE_H
