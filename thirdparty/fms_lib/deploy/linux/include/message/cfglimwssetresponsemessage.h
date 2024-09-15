#ifndef CFGLIMWSSETRESPONSEMESSAGE_H
#define CFGLIMWSSETRESPONSEMESSAGE_H

#include "IOMessage.h"

class CfgLimWsSetResponseMessage : public IOMessage
{
public:
    CfgLimWsSetResponseMessage();

    int serialToData(char *dest, int length) override;
    int parseFromData(char *mesData, int mesLen) override;

    short getState() const;
    void setState(short value);

private:
    short state;
};

#endif // CFGLIMWSSETRESPONSEMESSAGE_H
