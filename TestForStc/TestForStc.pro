QT += quick \
    widgets \
    core

CONFIG += c++11\
            quickcontrols2

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
#QT 5.12.0, MinGW 7.3.0 x64

include(CalculatorForm/CalculatorForm.pri)
include(CalculatorModel/CalculatorModel.pri)
include(CalculatorTypes/CalculatorTypes.pri)


SOURCES += \
        main.cpp

RESOURCES += qml.qrc

TRANSLATIONS += \
    TestForStc_ru_RU.ts

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH = C:/Qt/5.12.0/mingw73_64/qml

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/CalculatorLibrary/build/release/ -llibcalculator
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/CalculatorLibrary/build/debug/ -llibcalculator

INCLUDEPATH += $$PWD/CalculatorLibrary/libcalculator
DEPENDPATH += $$PWD/CalculatorLibrary/libcalculator
