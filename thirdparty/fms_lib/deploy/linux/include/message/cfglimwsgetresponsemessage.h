#ifndef CFGLIMWSGETRESPONSEMESSAGE_H
#define CFGLIMWSGETRESPONSEMESSAGE_H

#include "IOMessage.h"
#include <QList>

class CfgLimWsGetResponseMessage : public IOMessage
{
public:
    CfgLimWsGetResponseMessage();

    int serialToData(char *dest, int length) override;
    int parseFromData(char *mesData, int mesLen) override;

    uint8 getState() const;
    void setState(const uint8 &value);

    uint32 getP1() const;
    void setP1(const uint32 &value);

    QList<double> getParam() const;
    void setParam(const QList<double> &value);

private:
    uint8 state;
    uint32 p1;
    QList<double> param;
};

#endif // CFGLIMWSGETRESPONSEMESSAGE_H
