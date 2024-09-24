INCLUDEPATH += $$PWD/deploy/linux/include \
               $$PWD/deploy/linux/include/controller \
               $$PWD/deploy/linux/include/handler \
               $$PWD/deploy/linux/include/info \
               $$PWD/deploy/linux/include/kinematic \
               $$PWD/deploy/linux/include/message \
               $$PWD/deploy/linux/include/network \
               $$PWD/deploy/linux/include/processer \
               $$PWD

HEADERS += \
    $$PWD/deploy/linux/include/fmsapi.h

LIBS += -L$$PWD/deploy/linux/lib/release -lFmsApi
#LIBS += -L$$PWD/deploy/linux/bin

