#ifndef CFGLIMSPDGETRESPONSEMESSAGE_H
#define CFGLIMSPDGETRESPONSEMESSAGE_H

#include "IOMessage.h"
#include <QList>

class CfgLimSpdGetResponseMessage : public IOMessage
{
public:
    CfgLimSpdGetResponseMessage();

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

#endif // CFGLIMSPDGETRESPONSEMESSAGE_H
