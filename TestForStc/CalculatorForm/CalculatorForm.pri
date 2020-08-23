contains(DEFINES, CALCULATORFORM_PRI){
} else {

DEFINES += CALCULATORFORM_PRI

QT += core

INCLUDEPATH += $$PWD

}

HEADERS += \
    $$PWD/CalculatorForm.h

SOURCES += \
    $$PWD/CalculatorForm.cpp
