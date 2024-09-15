#ifndef CFGLIMACCSETRESPONSEMESSAGE_H
#define CFGLIMACCSETRESPONSEMESSAGE_H

#include "IOMessage.h"

class CfgLimAccSetResponseMessage : public IOMessage
{
public:
    CfgLimAccSetResponseMessage();

    int serialToData(char *dest, int length) override;
    int parseFromData(char *mesData, int mesLen) override;

    short getState() const;
    void setState(short value);

private:
    short state;
};

#endif // CFGLIMACCSETRESPONSEMESSAGE_H
