#-------------------------------------------------
#
# Project created by QtCreator 2019-12-01T18:04:22
#
#-------------------------------------------------

QT       -= gui
QT += quick
QT += sql concurrent
TARGET = commonlib
TEMPLATE = lib
CONFIG += staticlib
CONFIG += c++14 console
CONFIG -= app_bundle
DEFINES += COMMON_LIBRARY

#Check os architect: 32 bit or 64 bit, uncheck shadow build in build setting to use this feature
linux-g++:QMAKE_TARGET.arch = $$QMAKE_HOST.arch
linux-g++-32:QMAKE_TARGET.arch = x86
linux-g++-64:QMAKE_TARGET.arch = x86_64

DESTDIR = ''
contains(QMAKE_TARGET.arch, x86) {
    DESTDIR = ../commonlib_32/

} else {
    DESTDIR = ../commonlib_64/
}

OBJECTS_DIR = $$DESTDIR/obj
MOC_DIR  = $$DESTDIR/moc
RCC_DIR = $$DESTDIR/rc
UI_DIR = $$DESTDIR/ui



# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
#This script part is to execute your shell script before build project
extralib.target = extra
extralib.commands = bash ../sourcecode/create_version.sh # Run your programs here
extralib.depends =
#QMAKE_EXTRA_TARGETS += extralib
#PRE_TARGETDEPS = extra
# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(./commonlib.pri)

unix {
    target.path = /usr/lib
    INSTALLS += target
}

