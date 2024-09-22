#ifndef _TESTPROCESSFACTORY_H_
#define _TESTPROCESSFACTORY_H_

#include "testprocess.h"

class TestProcessFactory {
public:
    TestProcessFactory();
    ~TestProcessFactory();
    TestProcess* createTestProcess(DEVICE::TYPE device, ControlParamType control, SpecificationParamType spec, TEST_DEFINE::TEST_PROCESS type);
    TestProcess* createTestProcess(DEVICE::TYPE device, int axis, ControlParamType control, SpecificationParamType spec, TEST_DEFINE::TEST_PROCESS type);
    void removeTestProcess(TestProcess* process);
};

#endif
