#ifndef _TESTCONFIGGETTER_H_
#define _TESTCONFIGGETTER_H_

#include "typedef/globalvar.h"
#include "typedef/system_def.h"
#include <QMap>
#include "queue"

typedef struct {
    DEVICE::TYPE device;
    int axis;
    TEST_DEFINE::TEST_PROCESS type;
    ControlParamType control;
    SpecificationParamType spec;
} TestProcessQueuePart;

class TestConfigGetter
{
public:
    TestConfigGetter();
    ~TestConfigGetter();

    ControlParamType getControlParam();
    SpecificationParamType getSpecParam();

    void updateConfig(ProcessType type, QMap<QString, QVariantMap>& config, std::queue<TestProcessQueuePart>& mQueue);

private:
    ControlParamType mCtrlParam;
    SpecificationParamType mSpecParam;
};

#endif
