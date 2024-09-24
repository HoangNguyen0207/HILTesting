QT += core gui serialport quick qml widgets quickcontrols2 network location opengl
greaterThan(QT_MAJOR_VERSION, 4): QT += printsupport

CONFIG += c++11

#Build dir config
BuildDir = $$PWD/build
CONFIG(debug, debug|release) {
    DESTDIR = $$BuildDir/debug
    BUILD_MODE = debug
} else {
    DESTDIR = $$BuildDir/release
    BUILD_MODE = release
}

OBJECTS_DIR = $$DESTDIR/obj
MOC_DIR     = $$DESTDIR/moc
RCC_DIR     = $$DESTDIR/qrc
UI_DIR      = $$DESTDIR/ui

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

RESOURCES += qml.qrc

LIBS += -lpng

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

include(source.pri)
