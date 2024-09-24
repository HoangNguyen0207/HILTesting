#ifndef CFGLIMACCSETMESSAGE_H
#define CFGLIMACCSETMESSAGE_H

#include "IOMessage.h"
#include <QList>

class CfgLimAccSetMessage : public IOMessage
{
public:
    CfgLimAccSetMessage();

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

#endif // CFGLIMACCSETMESSAGE_H
