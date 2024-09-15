#ifndef CFGLIMINFO_H
#define CFGLIMINFO_H

#include "constant.h"
#include "baseinfo.h"

class CfgLimInfo : public BaseInfo
{
public:
    CfgLimInfo();

    uint32 getP1() const;
    void setP1(const uint32 &value);

    QList<double> getParam() const;
    void setParam(const QList<double> &value);
    void appendItem(const double& p);

private:
    uint32 p1;
    QList<double> param;
};

#endif // CFGLIMINFO_H
