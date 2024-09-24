#ifndef AXISHOMINGINFO_H
#define AXISHOMINGINFO_H

#include "constant.h"
#include "baseinfo.h"

class AxisHomingInfo : public BaseInfo
{
public:
    AxisHomingInfo();

    uint32 getP1() const;
    void setP1(const uint32 &value);

private:
    uint32 p1;
};

#endif // AXISHOMINGINFO_H
