#ifndef CFGLIMWSSETMESSAGE_H
#define CFGLIMWSSETMESSAGE_H

#include "IOMessage.h"
#include <QList>

class CfgLimWsSetMessage : public IOMessage
{
public:
    CfgLimWsSetMessage();

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

#endif // CFGLIMWSSETMESSAGE_H
