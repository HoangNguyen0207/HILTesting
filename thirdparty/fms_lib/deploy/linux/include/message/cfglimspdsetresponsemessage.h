#ifndef CFGLIMSPDSETRESPONSEMESSAGE_H
#define CFGLIMSPDSETRESPONSEMESSAGE_H

#include "IOMessage.h"

class CfgLimSpdSetResponseMessage : public IOMessage
{
public:
    CfgLimSpdSetResponseMessage();

    int serialToData(char *dest, int length) override;
    int parseFromData(char *mesData, int mesLen) override;

    short getState() const;
    void setState(short value);

private:
    short state;

};

#endif // CFGLIMSPDSETRESPONSEMESSAGE_H
