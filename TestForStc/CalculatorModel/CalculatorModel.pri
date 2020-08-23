contains(DEFINES, CALCULATORMODEL_PRI){
} else {

DEFINES += CALCULATORMODEL_PRI

QT += core

INCLUDEPATH += $$PWD

include(../CalculatorCore/CalculatorCore.pri)

}

HEADERS += \
    $$PWD/CalculatorModel.h\

SOURCES += \
    $$PWD/CalculatorModel.cpp\
