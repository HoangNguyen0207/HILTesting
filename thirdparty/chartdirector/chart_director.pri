INCLUDEPATH += $$PWD/include \
    $$PWD

HEADERS += \
    $$PWD/include/FinanceChart.h \
    $$PWD/include/bchartdir.h \
    $$PWD/include/chartdir.h \
    $$PWD/include/memblock.h

LIBS += -L$$PWD/lib -lchartdir

