#ifndef CFGSPDSETINFO_H
#define CFGSPDSETINFO_H

#include "baseinfo.h"

class CfgSpdSetInfo : public BaseInfo
{
public:
    CfgSpdSetInfo();

    double getP1() const;
    void setP1(double value);

    double getP2() const;
    void setP2(double value);

private:
    double p1, p2;
};

#endif // CFGSPDSETINFO_H
