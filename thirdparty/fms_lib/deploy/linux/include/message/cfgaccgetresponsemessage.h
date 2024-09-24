#ifndef CFGACCGETRESPONSEMESSAGE_H
#define CFGACCGETRESPONSEMESSAGE_H

#include "IOMessage.h"

class CfgAccGetResponseMessage : public IOMessage
{
public:
    CfgAccGetResponseMessage();

    int serialToData(char *dest, int length) override;
    int parseFromData(char *mesData, int mesLen) override;

    double getO1() const;
    void setO1(double value);

    double getO2() const;
    void setO2(double value);

    double getO3() const;
    void setO3(double value);

    double getO4() const;
    void setO4(double value);

    short getState() const;
    void setState(short value);

private:
    short state;
    double o1, o2, o3, o4;
};

#endif // CFGACCGETRESPONSEMESSAGE_H
