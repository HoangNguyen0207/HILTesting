#ifndef CFGLIMACCGETRESPONSEMESSAGE_H
#define CFGLIMACCGETRESPONSEMESSAGE_H

#include "IOMessage.h"

class CfgLimAccGetResponseMessage : public IOMessage
{
public:
    CfgLimAccGetResponseMessage();

    int serialToData(char *dest, int length) override;
    int parseFromData(char *mesData, int mesLen) override;

    short getState() const;
    void setState(const short &value);

    QList<double> getParam() const;
    void setParam(const QList<double> &value);

private:
    short state;
    QList<double> param;
};

#endif // CFGLIMACCGETRESPONSEMESSAGE_H
