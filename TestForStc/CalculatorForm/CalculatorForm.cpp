#include "CalculatorForm.h"
#include "QDebug"

#define DEFAULT_CONFIG_FILE_NAME "/config.ini"


#include <QObject>


QCalculatorForm::QCalculatorForm(QObject *parent) : QObject(parent)
{       
    m_FormSize = QSize(500, 400);
    m_FormPosition = QPoint(0, 0);

    NewNumber();
}

QCalculatorForm::~QCalculatorForm()
{
    writeSettings();
}

void QCalculatorForm::MinusCheck()
{
    if (m_CalcStringVector.length() > 2
        && m_CalcStringVector.at(m_CalcStringVector.length() - 2).Type == calcAction
        && m_CalcStringVector.last().String.isEmpty())
        emit sendLockMinusButton();
}

void QCalculatorForm::NewAction(CalcActionType AActionType)
{
    if (m_CalcStringVector.last().String.length() == 1
        && m_CalcStringVector.last().String.at(m_CalcStringVector.last().String.length() - 1) == "-")

        m_CalcStringVector.last().String.remove(m_CalcStringVector.last().String.length() - 1, 1);

    if (m_CalcStringVector.last().String.isEmpty()
        || m_CalcStringVector.last().String.at(m_CalcStringVector.last().String.length() - 1) == ".")

        m_CalcStringVector.last().String.append("0");

    TCalcString newCalcString;

    newCalcString.Type = calcAction;

    switch (AActionType) {
    case actPlus :
        newCalcString.String = "+";
        break;

    case actMinus :
        newCalcString.String = "-";
        break;

    case actMultiplication :
        newCalcString.String = "*";
        break;

    case actDivision :
        newCalcString.String = "/";
        break;

    case actEqualy :
        newCalcString.String = "=";
        break;

    }

    m_CalcStringVector.append(newCalcString);


    if (AActionType == actEqualy)
    {
        newCalcString.Type = calcResult;
        newCalcString.String = "Ожидание результата [_]";

        m_CalcStringVector.append(newCalcString);

        emit sendUnlockActions();
    }
    else
        emit sendLockActions();

    NewNumber();

    emit sendTextToView();

}

void QCalculatorForm::NewNumber()
{
    TCalcString newCalcString;

    newCalcString.Type = calcNumber;
    newCalcString.String = "";

    m_CalcStringVector.append(newCalcString);
}

void QCalculatorForm::readSettings()
{
    QString configFilePath = QApplication::applicationDirPath() + DEFAULT_CONFIG_FILE_NAME;

    QSettings FormSettings(configFilePath, QSettings::IniFormat);

    FormSettings.beginGroup("Calculator");
    m_FormSize = FormSettings.value("size", QSize(500, 400)).toSize();
    m_FormPosition = FormSettings.value("pos", QPoint(0,0)).toPoint();
    m_FormMaximized = FormSettings.value("maximized", false).toBool();
    FormSettings.endGroup();

    emit sendSettingsReaded();
}

void QCalculatorForm::writeSettings()
{
    QString configFilePath = QApplication::applicationDirPath() + DEFAULT_CONFIG_FILE_NAME;

    QSettings FormSettings(configFilePath, QSettings::IniFormat);

    FormSettings.beginGroup("Calculator");
    FormSettings.setValue("size", m_FormSize);
    FormSettings.setValue("pos", m_FormPosition);
    FormSettings.setValue("maximized", m_FormMaximized);
    FormSettings.endGroup();
}



void QCalculatorForm::buttonC_onClick()
{
    m_CalcStringVector.clear();

    NewNumber();

    emit sendTextToView();
    emit sendUnlockActions();
    emit sendUnlockDotButton();
}

///Удаляет строку, если последняя строка - результат, то удаляет весь блок
void QCalculatorForm::buttonCE_onClick()
{
    if (m_CalcStringVector.last().String.isEmpty() && m_CalcStringVector.at(m_CalcStringVector.length() - 1).Type == calcNumber)
    {
        if (m_CalcStringVector.length() > 5 && m_CalcStringVector.at(m_CalcStringVector.length() - 2).Type == calcResult)
        {
            m_CalcStringVector.remove(m_CalcStringVector.length() - 6, 6);
            NewNumber();
            emit sendUnlockActions();
        }
        else if (m_CalcStringVector.length() > 2 && m_CalcStringVector.at(m_CalcStringVector.length() - 2).Type == calcAction)
        {
            m_CalcStringVector.remove(m_CalcStringVector.length() - 2, 2);
            emit sendUnlockActions();
        }
    }
    else
        m_CalcStringVector.last().String = "";


    emit sendTextToView();
    emit sendUnlockDotButton();
}


void QCalculatorForm::buttonBackspace_onClick()
{
    if (m_CalcStringVector.last().String.isEmpty())
        buttonCE_onClick();
    else
    {
        if (m_CalcStringVector.last().String.at(m_CalcStringVector.last().String.length() - 1) == ".")
        {
            emit sendUnlockDotButton();

            if (m_CalcStringVector.last().String.length() == 3
                && m_CalcStringVector.last().String.at(m_CalcStringVector.last().String.length() - 3) == "-"
                && m_CalcStringVector.last().String.at(m_CalcStringVector.last().String.length() - 2) == "0")
            {
                m_CalcStringVector.last().String.remove(m_CalcStringVector.last().String.length() - 1, 1);
            }

            if (m_CalcStringVector.last().String.length() == 2
                && m_CalcStringVector.last().String.at(m_CalcStringVector.last().String.length() - 2) == "0")
            {
                m_CalcStringVector.last().String.remove(m_CalcStringVector.last().String.length() - 1, 1);
            }
        }

        m_CalcStringVector.last().String.remove(m_CalcStringVector.last().String.length() - 1, 1);

        if (m_CalcStringVector.last().String.isEmpty())
            emit sendUnlockMinusButton();
    }

    emit sendTextToView();
}

void QCalculatorForm::button1_onClick()
{
    MinusCheck();
    m_CalcStringVector.last().String.append("1");
    emit sendTextToView();
}

void QCalculatorForm::button2_onClick()
{
    MinusCheck();
    m_CalcStringVector.last().String.append("2");
    emit sendTextToView();
}

void QCalculatorForm::button3_onClick()
{
    MinusCheck();
    m_CalcStringVector.last().String.append("3");
    emit sendTextToView();
}

void QCalculatorForm::button4_onClick()
{
    MinusCheck();
    m_CalcStringVector.last().String.append("4");
    emit sendTextToView();
}

void QCalculatorForm::button5_onClick()
{
    MinusCheck();
    m_CalcStringVector.last().String.append("5");
    emit sendTextToView();
}

void QCalculatorForm::button6_onClick()
{
    MinusCheck();
    m_CalcStringVector.last().String.append("6");
    emit sendTextToView();
}

void QCalculatorForm::button7_onClick()
{
    MinusCheck();
    m_CalcStringVector.last().String.append("7");
    emit sendTextToView();
}

void QCalculatorForm::button8_onClick()
{
    MinusCheck();
    m_CalcStringVector.last().String.append("8");
    emit sendTextToView();
}

void QCalculatorForm::button9_onClick()
{
    MinusCheck();
    m_CalcStringVector.last().String.append("9");
    emit sendTextToView();
}

void QCalculatorForm::button0_onClick()
{
    MinusCheck();
    m_CalcStringVector.last().String.append("0");

    if ((m_CalcStringVector.last().String.length() == 1)
        || (m_CalcStringVector.last().String.length() == 2
            && m_CalcStringVector.last().String.at(m_CalcStringVector.last().String.length() - 2) == "-"))
    {
        m_CalcStringVector.last().String.append(".");
        emit sendLockDotButton();
    }

    emit sendTextToView();
}

void QCalculatorForm::buttonDot_onClick()
{
    if(m_CalcStringVector.last().String.isEmpty()
       || (m_CalcStringVector.last().String.at(0) == "-"
       && m_CalcStringVector.last().String.length() == 1))

        m_CalcStringVector.last().String.append("0");

    m_CalcStringVector.last().String.append(".");
    emit sendTextToView();
    emit sendLockDotButton();

}

void QCalculatorForm::buttonPlus_onClick()
{
    NewAction(actPlus);
}

void QCalculatorForm::buttonMinus_onClick()
{
    if (m_CalcStringVector.last().String.isEmpty())
    {
        m_CalcStringVector.last().String.append("-");

        if (m_CalcStringVector.length() > 2 && m_CalcStringVector.at(m_CalcStringVector.length()-2).Type == calcAction)
            emit sendLockMinusButton();

        emit sendTextToView();
    }
    else
        NewAction(actMinus);
}

void QCalculatorForm::buttonMultiplication_onClick()
{
    NewAction(actMultiplication);
}

void QCalculatorForm::buttonDivision_onClick()
{
    NewAction(actDivision);
}

void QCalculatorForm::buttonEqualy_onClick()
{

    requestAction reqAction = reqPlus;

    QString NeedString = m_CalcStringVector.at(m_CalcStringVector.length() - 2).String;

    if (NeedString == "+")
        reqAction = reqPlus;
    else if (NeedString == "-")
        reqAction = reqMinus;
    else if (NeedString == "*")
        reqAction = reqMultiplication;
    else if (NeedString == "/")
        reqAction = reqDivision;


    double NeedFirstOperand = m_CalcStringVector.at(m_CalcStringVector.length() - 3).String.toDouble();
    double NeedSecondOperand = m_CalcStringVector.at(m_CalcStringVector.length() - 1).String.toDouble();

    emit sendRequest(reqAction, NeedFirstOperand, NeedSecondOperand);

    NewAction(actEqualy);
}

QString QCalculatorForm::mainText() const
{
    QString ReturnedText;

    for( int i = 0; i < m_CalcStringVector.length(); i++)
    {
        if (m_CalcStringVector.at(i).Type == calcResult)
            ReturnedText.append("<font color=\"Yellow\">");
        else
            ReturnedText.append("<font color=\"LimeGreen\">");

        ReturnedText.append(m_CalcStringVector.at(i).String);
        ReturnedText.append("<\font><br>");
    }

    return ReturnedText;

}

void QCalculatorForm::formXChanged(int AXPosition)
{
    m_FormPosition.setX(AXPosition);
}

void QCalculatorForm::formYChanged(int AYPosition)
{
    m_FormPosition.setY(AYPosition);
}

void QCalculatorForm::formWidthChanged(int AWidth)
{
    m_FormSize.setWidth(AWidth);
}

void QCalculatorForm::formHeightChanged(int AHight)
{
    m_FormSize.setHeight(AHight);
}

