QT += serialport network

#spdlog
INCLUDEPATH += $$PWD/logger/spdlog
DEPENDPATH += $$PWD/logger/spdlog

INCLUDEPATH += $$PWD
INCLUDEPATH += $$PWD/logger

SOURCES += \
    $$PWD/logger/logger.cpp \
    $$PWD/messageabs/basemessage.cpp \
    $$PWD/processorabs/processorabstract.cpp \
    $$PWD/processorabs/processormanager.cpp \
    $$PWD/processorabs/workerthread.cpp

HEADERS += \
    $$PWD/logger/logger.h \
    $$PWD/messageabs/basemessage.h \
    $$PWD/processorabs/processorabstract.h \
    $$PWD/processorabs/processormanager.h \
    $$PWD/processorabs/workerthread.h

