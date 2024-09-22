#ifndef TESTPROCESSMAXACCELERATION_H
#define TESTPROCESSMAXACCELERATION_H

#include "../testprocess.h"

class TestProcessMaxAcceleration : public TestProcess
{
public:
    TestProcessMaxAcceleration(DEVICE::TYPE device, int axis, ControlParamType control, SpecificationParamType spec);
    ~TestProcessMaxAcceleration();

    virtual int run() override;

private:
    double mMaxVelocity {0};
    double mMaxAccelearation {0};

    std::vector<double> mPosition;
};

#endif // TESTPROCESSMAXVELOCITY_H
