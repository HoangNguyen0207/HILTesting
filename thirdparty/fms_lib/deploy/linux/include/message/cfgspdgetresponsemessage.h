#ifndef CFGSPDGETRESPONSEMESSAGE_H
#define CFGSPDGETRESPONSEMESSAGE_H

#include "IOMessage.h"

class CfgSpdGetResponseMessage : public IOMessage
{
public:
    CfgSpdGetResponseMessage();

    int serialToData(char *dest, int length) override;
    int parseFromData(char *mesData, int mesLen) override;

    short getState() const;
    void setState(short value);

private:
    short state;
    double o1, o2, o3, o4;
};

#endif // CFGSPDGETRESPONSEMESSAGE_H
