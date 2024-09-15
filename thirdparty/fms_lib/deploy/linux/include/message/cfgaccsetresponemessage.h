#ifndef CFGACCSETRESPONEMESSAGE_H
#define CFGACCSETRESPONEMESSAGE_H

#include "IOMessage.h"

class CfgAccSetResponeMessage : public IOMessage
{
public:
    CfgAccSetResponeMessage();

    int serialToData(char *dest, int length) override;
    int parseFromData(char *mesData, int mesLen) override;

    short getState() const;
    void setState(short value);

private:
    short state;
};

#endif // CFGACCSETRESPONEMESSAGE_H
