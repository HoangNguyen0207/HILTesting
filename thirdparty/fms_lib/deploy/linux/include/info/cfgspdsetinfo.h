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

    double getP3() const;
    void setP3(double value);

    double getP4() const;
    void setP4(double value);

    double getP5() const;
    void setP5(double value);

    double getP6() const;
    void setP6(double value);

private:
    double p1, p2, p3, p4, p5, p6;
};

#endif // CFGSPDSETINFO_H
