#ifndef TESTPROCESSMAXVELOCITY_H
#define TESTPROCESSMAXVELOCITY_H

#include "../testprocess.h"

class TestProcessMaxVelocity : public TestProcess
{
public:
    TestProcessMaxVelocity(DEVICE::TYPE device, int axis, ControlParamType control, SpecificationParamType spec);
    ~TestProcessMaxVelocity();

    virtual int run() override;

private:
    double mMaxVelocity {0};
    double mMaxAccelearation {0};

    std::vector<double> mPosition;
};

#endif // TESTPROCESSMAXVELOCITY_H
