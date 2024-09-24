#ifndef MOVEABSINFO_H
#define MOVEABSINFO_H

#include "baseinfo.h"

class MoveAbsInfo : public BaseInfo
{
public:
    MoveAbsInfo();

    double getTx() const;
    void setTx(double value);

    double getTy() const;
    void setTy(double value);

    double getTz() const;
    void setTz(double value);

    double getRx() const;
    void setRx(double value);

    double getRy() const;
    void setRy(double value);

    double getRz() const;
    void setRz(double value);

    void updateValue(double value[6]);

private:
    double tx, ty, tz, rx, ry, rz;
};

#endif // MOVEABSINFO_H
