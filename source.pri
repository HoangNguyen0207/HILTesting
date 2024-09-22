INCLUDEPATH += $$PWD
INCLUDEPATH += $$PWD/thirdparty/flux_qt/flux_qt
INCLUDEPATH += $$PWD/commonlib

include(thirdparty/lib_thirdparty.pri)
include(commonlib/commonlib.pri)


SOURCES += \
        $$PWD/connector/serialconnector.cpp \
        $$PWD/connector/tcpclientconnector.cpp \
        $$PWD/connector/tcpserverconnector.cpp \
        $$PWD/connector/udpmulticastconnector.cpp \
        $$PWD/connector/udpunicastconnector.cpp \
        $$PWD/flux/action/actionprovider.cpp \
        $$PWD/flux/middleware/systemmiddleware.cpp \
        $$PWD/flux/store/mainstore.cpp \
        $$PWD/services/configservice.cpp \
        $$PWD/services/logservice.cpp \
        $$PWD/systemmanager.cpp \
        $$PWD/utils/bytebuffer.cpp \
        $$PWD/utils/configLoader/fileloader.cpp \
        $$PWD/utils/configLoader/systemconfigloader.cpp \
        $$PWD/utils/plot/gencolor.cpp \
        $$PWD/utils/plot/inputchart.cpp \
        $$PWD/utils/plot/outputchart.cpp \
        $$PWD/utils/plot/qmlchartviewer.cpp \
        $$PWD/utils/plot/trajectorymap.cpp \
        $$PWD/utils/processLoader/processloader.cpp \
        $$PWD/main.cpp \
        $$PWD/TestProcess/TestProcessBandwidth/testprocessbandwidth.cpp \
        $$PWD/TestProcess/TestProcessDelay/testprocessdelay.cpp \
        $$PWD/TestProcess/TestProcessFactory.cpp \
        $$PWD/TestProcess/TestProcessMaxVelocity/testprocessmaxvelocity.cpp \
        $$PWD/TestProcess/TestProcessMinVelocity/testprocessminvelocity.cpp \
        $$PWD/TestProcess/TestProcessPosition/testprocessposition.cpp \
        $$PWD/TestProcess/TestProcessPositionResolution/testprocesspositionresolution.cpp \
        $$PWD/TestProcess/TestProcessRepeatability/testprocessrepeatability.cpp \
        $$PWD/TestProcess/testprocess.cpp \
        $$PWD/utils/math_helper/math_helper.cpp \
        $$PWD/utils/reportHandle/reporthandle.cpp \
        $$PWD/services/testprocessservice.cpp \
        $$PWD/TestProcess/TestConfigGetter.cpp \
        $$PWD/TestProcess/TestProcessClosedLoop/TestProcessClosedLoop.cpp \
        $$PWD/TestProcess/TestProcessControl/TestProcessControl.cpp \
        $$PWD/TestProcess/TestProcessRealtimeControl/TestProcessRealtimeControl.cpp \
        $$PWD/TestProcess/TestProcessMaxPosition/TestProcessMaxPosition.cpp \
        $$PWD/TestProcess/TestProcessMaxAcceleration/testprocessmaxacceleration.cpp \
        $$PWD/TestProcess/TestProcessLoad/testprocessload.cpp \
        $$PWD/TestProcess/TestConfigGetter.cpp \
        $$PWD/TestProcess/TestProcessMaxVelocityLinear/TestProcessMaxVelocityLinear.cpp \
        $$PWD/TestProcess/TestProcessMinVelocityLinear/TestProcessMinVelocityLinear.cpp

HEADERS += \
    $$PWD/connector/serialconnector.h \
    $$PWD/connector/tcpclientconnector.h \
    $$PWD/connector/tcpserverconnector.h \
    $$PWD/connector/udpmulticastconnector.h \
    $$PWD/connector/udpunicastconnector.h \
    $$PWD/flux/action/actionprovider.h \
    $$PWD/flux/action/actiontypes.h \
    $$PWD/flux/middleware/systemmiddleware.h \
    $$PWD/flux/store/mainstore.h \
    $$PWD/message/messagetype.h \
    $$PWD/services/configservice.h \
    $$PWD/services/logservice.h \
    $$PWD/systemmanager.h \
    $$PWD/typedef/globalvar.h \
    $$PWD/typedef/system_def.h \
    $$PWD/utils/bytebuffer.h \
    $$PWD/utils/calculatehelper/calculatehelper.h \
    $$PWD/utils/configLoader/fileloader.h \
    $$PWD/utils/configLoader/systemconfigloader.h \
    $$PWD/utils/plot/gencolor.h \
    $$PWD/utils/plot/graphdata.h \
    $$PWD/utils/plot/inputchart.h \
    $$PWD/utils/plot/outputchart.h \
    $$PWD/utils/plot/qmlchartviewer.h \
    $$PWD/utils/plot/trajectorymap.h \
    $$PWD/utils/processLoader/processloader.h \
    $$PWD/TestProcess/TestProcessBandwidth/testprocessbandwidth.h \
    $$PWD/TestProcess/TestProcessDelay/testprocessdelay.h \
    $$PWD/TestProcess/TestProcessFactory.h \
    $$PWD/TestProcess/TestProcessMaxVelocity/testprocessmaxvelocity.h \
    $$PWD/TestProcess/TestProcessMinVelocity/testprocessminvelocity.h \
    $$PWD/TestProcess/TestProcessPosition/testprocessposition.h \
    $$PWD/TestProcess/TestProcessPositionResolution/testprocesspositionresolution.h \
    $$PWD/TestProcess/TestProcessRepeatability/testprocessrepeatability.h \
    $$PWD/TestProcess/testprocess.h \
    $$PWD/utils/math_helper/math_helper.h \
    $$PWD/utils/reportHandle/reporthandle.h \
    $$PWD/services/testprocessservice.h \
    $$PWD/TestProcess/TestConfigGetter.h \
    $$PWD/TestProcess/TestProcessClosedLoop/TestProcessClosedLoop.h \
    $$PWD/TestProcess/TestProcessControl/TestProcessControl.h \
    $$PWD/TestProcess/TestProcessRealtimeControl/TestProcessRealtimeControl.h \
    $$PWD/TestProcess/TestProcessMaxPosition/TestProcessMaxPosition.h \
    $$PWD/TestProcess/TestProcessMaxAcceleration/testprocessmaxacceleration.h \
    $$PWD/TestProcess/TestProcessLoad/testprocessload.h \
    $$PWD/TestProcess/TestConfigGetter.h \
    $$PWD/TestProcess/TestProcessMaxVelocityLinear/TestProcessMaxVelocityLinear.h \
    $$PWD/TestProcess/TestProcessMinVelocityLinear/TestProcessMinVelocityLinear.h













