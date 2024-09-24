#ifndef _TESTPROCESSCONTROL_H_
#define _TESTPROCESSCONTROL_H_

#include "../testprocess.h"

class TestProcessControl : public TestProcess
{
public:
    TestProcessControl(DEVICE::TYPE device, ControlParamType control, SpecificationParamType spec);
    ~TestProcessControl();

    virtual int run() override;

private:
    std::vector<double> mPosition[6];
    int mAxisCount;
    int mMaxAxisCount;

    bool mIsFalse;
};

#endif
