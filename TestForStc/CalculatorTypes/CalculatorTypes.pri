contains(DEFINES, CALCULATORTYPES_PRI){
} else {

DEFINES += CALCULATORTYPES_PRI

QT += core

INCLUDEPATH += $$PWD

}

HEADERS += \
    $$PWD/CalculatorResult.h \
    $$PWD/CalculatorTypes.h\
    $$PWD/CalculatorRequest.h \
    $$PWD/ThreadSafeCalcDataManager.h

SOURCES += \
    $$PWD/CalculatorRequest.cpp \
    $$PWD/CalculatorResult.cpp \
    $$PWD/ThreadSafeCalcDataManager.cpp
