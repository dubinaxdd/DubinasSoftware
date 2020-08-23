contains(DEFINES, CALCULATORCORE_PRI){
} else {

DEFINES += CALCULATORCORE_PRI

QT += core

INCLUDEPATH += $$PWD

}

HEADERS += \
    $$PWD/CalculatorCore.h

SOURCES += \
    $$PWD/CalculatorCore.cpp
