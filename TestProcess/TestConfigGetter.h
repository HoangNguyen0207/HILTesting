#ifndef _TESTCONFIGGETTER_H_
#define _TESTCONFIGGETTER_H_

#include "typedef/globalvar.h"
#include "typedef/system_def.h"
#include <QMap>
#include <QList>

class TestConfigGetter
{
public:
    TestConfigGetter();
    ~TestConfigGetter();

    ControlParamType getControlParam();
    SpecificationParamType getSpecParam();

    TEST_DEFINE::TEST_PROCESS updateConfig(ProcessType type, QMap<QString, QVariantMap>& config, DEVICE::TYPE& device);

private:
    ControlParamType mCtrlParam;
    SpecificationParamType mSpecParam;
};

#endif
