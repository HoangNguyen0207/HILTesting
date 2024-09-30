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
        $$PWD/model/FMS/fmsdevice.cpp \
        $$PWD/model/TMS/tmsdevice.cpp \
        $$PWD/services/configservice.cpp \
        $$PWD/services/fmscommservice.cpp \
        $$PWD/services/logservice.cpp \
        $$PWD/services/tmscommservice.cpp \
        $$PWD/systemmanager.cpp \
        $$PWD/utils/bytebuffer.cpp \
        $$PWD/utils/configLoader/fileloader.cpp \
        $$PWD/utils/configLoader/systemconfigloader.cpp \
        $$PWD/utils/plot/gencolor.cpp \
        $$PWD/utils/plot/outputchart.cpp \
        $$PWD/utils/plot/qmlchartviewer.cpp \
        $$PWD/utils/plot/trajectorymap.cpp \
        $$PWD/utils/processLoader/processloader.cpp \
        main.cpp

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
    $$PWD/model/FMS/FMSCommand.h \
    $$PWD/model/FMS/fmsdevice.h \
    $$PWD/model/TMS/tmsdevice.h \
    $$PWD/services/configservice.h \
    $$PWD/services/fmscommservice.h \
    $$PWD/services/logservice.h \
    $$PWD/services/tmscommservice.h \
    $$PWD/systemmanager.h \
    $$PWD/typedef/globalvar.h \
    $$PWD/utils/bytebuffer.h \
    $$PWD/utils/calculatehelper/calculatehelper.h \
    $$PWD/utils/configLoader/fileloader.h \
    $$PWD/utils/configLoader/systemconfigloader.h \
    $$PWD/utils/plot/gencolor.h \
    $$PWD/utils/plot/graphdata.h \
    $$PWD/utils/plot/outputchart.h \
    $$PWD/utils/plot/qmlchartviewer.h \
    $$PWD/utils/plot/trajectorymap.h \
    $$PWD/utils/processLoader/processloader.h











