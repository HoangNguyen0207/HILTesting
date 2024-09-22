#ifndef _TESTPROCESSCLOSEDLOOP_H_
#define _TESTPROCESSCLOSEDLOOP_H_

#include "../testprocess.h"

class TestProcessClosedLoop : public TestProcess
{
public:
    TestProcessClosedLoop(DEVICE::TYPE device, ControlParamType control, SpecificationParamType spec);
    ~TestProcessClosedLoop();

    virtual int run() override;

private:
    std::vector<double> mFmsPosition[3];
    std::vector<double> mTmsPosition[2];
};

#endif
