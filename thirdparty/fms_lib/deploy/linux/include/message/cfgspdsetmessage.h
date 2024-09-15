#ifndef CFGSPDSETMESSAGE_H
#define CFGSPDSETMESSAGE_H

#include "IOMessage.h"

class CfgSpdSetMessage : public IOMessage
{
public:
    CfgSpdSetMessage();

    int serialToData(char *dest, int length) override;
    int parseFromData(char *mesData, int mesLen) override;

    double getP1() const;
    void setP1(double value);

    double getP2() const;
    void setP2(double value);

private:
    double p1, p2;
};

#endif // CFGSPDSETMESSAGE_H
