#ifndef CFGSPDSETRESPONSEMESSAGE_H
#define CFGSPDSETRESPONSEMESSAGE_H

#include "IOMessage.h"

class CfgSpdSetResponseMessage : public IOMessage
{
public:
    CfgSpdSetResponseMessage();

    int serialToData(char *dest, int length) override;
    int parseFromData(char *mesData, int mesLen) override;

    short getState() const;
    void setState(short value);

private:
    short state;
};

#endif // CFGSPDSETRESPONSEMESSAGE_H
