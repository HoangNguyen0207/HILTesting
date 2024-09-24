#ifndef CFGACCSETMESSAGE_H
#define CFGACCSETMESSAGE_H

#include "IOMessage.h"

class CfgAccSetMessage : public IOMessage
{
public:
    CfgAccSetMessage();

    int serialToData(char *dest, int length) override;
    int parseFromData(char *mesData, int mesLen) override;

    double getP1() const;
    void setP1(double value);

    double getP2() const;
    void setP2(double value);

private:
    double p1, p2;
};

#endif // CFGACCSETMESSAGE_H
