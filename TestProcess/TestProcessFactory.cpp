#include "TestProcessFactory.h"
#include "TestProcessBandwidth/testprocessbandwidth.h"
#include "TestProcessDelay/testprocessdelay.h"
#include "TestProcessMaxVelocity/testprocessmaxvelocity.h"
#include "TestProcessMinVelocity/testprocessminvelocity.h"
#include "TestProcessPosition/testprocessposition.h"
#include "TestProcessRepeatability/testprocessrepeatability.h"
#include "TestProcessPositionResolution/testprocesspositionresolution.h"
#include "TestProcessClosedLoop/TestProcessClosedLoop.h"
#include "TestProcessControl/TestProcessControl.h"
#include "TestProcessLoad/testprocessload.h"
#include "TestProcessMaxPosition/TestProcessMaxPosition.h"
#include "TestProcessMaxAcceleration/testprocessmaxacceleration.h"
#include "TestProcessRealtimeControl/TestProcessRealtimeControl.h"

TestProcessFactory::TestProcessFactory() {

}

TestProcessFactory::~TestProcessFactory() {

}

TestProcess* TestProcessFactory::createTestProcess(DEVICE::TYPE device, ControlParamType control, SpecificationParamType spec, TEST_DEFINE::TEST_PROCESS type)
{
    switch(type)
    {
    case TEST_DEFINE::TEST_PROCESS::CONTROL:
        return new TestProcessControl(device, control, spec);
    case TEST_DEFINE::TEST_PROCESS::CLOSED_LOOP:
        return new TestProcessClosedLoop(device, control, spec);
    case TEST_DEFINE::TEST_PROCESS::REALTIME_CONTROL:
        return new TestProcessRealtimeControl(device, control, spec);
    default: return nullptr;
    }
}

TestProcess* TestProcessFactory::createTestProcess(DEVICE::TYPE device, int axis, ControlParamType control, SpecificationParamType spec, TEST_DEFINE::TEST_PROCESS type)
{
    switch(type)
    {
    case TEST_DEFINE::TEST_PROCESS::POSITION:
        return new TestProcessPosition(device, axis, control, spec);
    case TEST_DEFINE::TEST_PROCESS::BANDWIDTH:
        return new TestProcessBandwidth(device, axis, control, spec);
    case TEST_DEFINE::TEST_PROCESS::DELAY:
        return new TestProcessDelay(device, axis, control, spec);
    case TEST_DEFINE::TEST_PROCESS::LOAD:
        return new TestProcessLoad(device, axis, control, spec);
    case TEST_DEFINE::TEST_PROCESS::MAX_ACC:
        return new TestProcessMaxAcceleration(device, axis, control, spec);
    case TEST_DEFINE::TEST_PROCESS::MAX_POS:
        return new TestProcessMaxPosition(device, axis, control, spec);
    case TEST_DEFINE::TEST_PROCESS::MAX_VEL:
        return new TestProcessMaxVelocity(device, axis, control, spec);
    case TEST_DEFINE::TEST_PROCESS::MIN_VEL:
        return new TestProcessMinVelocity(device, axis, control, spec);
    case TEST_DEFINE::TEST_PROCESS::REPEATABILITY:
        return new TestProcessRepeatability(device, axis, control, spec);
    case TEST_DEFINE::TEST_PROCESS::RESOLUTION:
        return new TestProcessPositionResolution(device, axis, control, spec);
    default: return nullptr;
    }
}

void TestProcessFactory::removeTestProcess(TestProcess* process)
{
    delete[] process;
    process = nullptr;
}
