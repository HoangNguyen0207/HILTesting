#ifndef TESTPROCESSLOAD_H
#define TESTPROCESSLOAD_H

#include "../testprocess.h"

class TestProcessLoad : public TestProcess
{
public:
    TestProcessLoad(DEVICE::TYPE device, int axis, ControlParamType control, SpecificationParamType spec);
    ~TestProcessLoad();

    virtual int run() override;

private:
    double mMaxVelocity {0};
    double mMaxAccelearation {0};

    std::vector<double> mPosition;
};

#endif // TESTPROCESSMAXVELOCITY_H
