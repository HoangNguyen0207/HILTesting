#ifndef CFGLIMSPDSETMESSAGE_H
#define CFGLIMSPDSETMESSAGE_H

#include "IOMessage.h"
#include <QList>

class CfgLimSpdSetMessage : public IOMessage
{
public:
    CfgLimSpdSetMessage();
    int serialToData(char *dest, int length) override;
    int parseFromData(char *mesData, int mesLen) override;

    uint32 getP1() const;
    void setP1(const uint32 &value);

    QList<double> getParam() const;
    void setParam(const QList<double> &value);

private:
    uint32 p1;
    QList<double> param;
};

#endif // CFGLIMSPDSETMESSAGE_H
