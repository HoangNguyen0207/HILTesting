#ifndef TESTPROCESSMINVELOCITY_H
#define TESTPROCESSMINVELOCITY_H

#include "../testprocess.h"

class TestProcessMinVelocity : public TestProcess
{
public:
    TestProcessMinVelocity(DEVICE::TYPE device, int axis, ControlParamType control, SpecificationParamType spec);

    virtual int run() override;

private:
    double mMaxVelocity;
    double mMaxAcceleration;

    std::vector<double> mPosition;
};

#endif // TESTPROCESSMINVELOCITY_H
