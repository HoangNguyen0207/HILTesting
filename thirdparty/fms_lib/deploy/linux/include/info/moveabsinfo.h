#ifndef MOVEABSINFO_H
#define MOVEABSINFO_H

#include "baseinfo.h"
#include <QMutex>
#include <QPair>

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
    double* getValues();

    QPair<double, double> getRangeTx() const;
    void setRangeTx(const QPair<double, double> &value);

    QPair<double, double> getRangeTy() const;
    void setRangeTy(const QPair<double, double> &value);

    QPair<double, double> getRangeTz() const;
    void setRangeTz(const QPair<double, double> &value);

    QPair<double, double> getRangeRx() const;
    void setRangeRx(const QPair<double, double> &value);

    QPair<double, double> getRangeRy() const;
    void setRangeRy(const QPair<double, double> &value);

    QPair<double, double> getRangeRz() const;
    void setRangeRz(const QPair<double, double> &value);

    double validateAndApplyInput(double value, QPair<double, double> range);
    void setRangeInput(double txMin, double txMax,
                       double tyMin, double tyMax,
                       double tzMin, double tzMax,
                       double rxMin, double rxMax,
                       double ryMin, double ryMax,
                       double rzMin, double rzMax);
    void setHomeOffset(double value[6]);
    QString toRangeString();
    QString toHomeOffsetString();

private:
    double tx, ty, tz, rx, ry, rz;
    double offsettx, offsetty, offsettz, offsetrx, offsetry, offsetrz;
    QPair<double, double> rangeTx, rangeTy, rangeTz, rangeRx, rangeRy, rangeRz;
    QPair<double, double> defaultrangeTx, defaultrangeTy, defaultrangeTz, defaultrangeRx, defaultrangeRy, defaultrangeRz;
    double *values;
    QMutex lockInfo;
};

#endif // MOVEABSINFO_H
