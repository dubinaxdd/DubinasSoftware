#include "CalculatorForm.h"
#include "QDebug"

#define DEFAULT_CONFIG_FILE_NAME "/config.ini"
#define DEFAULT_NUMBER_STRING_MAX_LENGTH 15


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
    if (m_CalcStringVector.last().String == "-")
        m_CalcStringVector.last().String = "";

    if (m_CalcStringVector.last().String.isEmpty()
        || m_CalcStringVector.last().String.at(m_CalcStringVector.last().String.length() - 1) == ".")

        m_CalcStringVector.last().String.append("0");

    if (m_CalcStringVector.last().String == "0.0")
        m_CalcStringVector.last().String = "0";

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
        newCalcString.String = "Ожидание результата";

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

void QCalculatorForm::AppendNumSybol(QString AString)
{
    if (m_CalcStringVector.last().String.length() < DEFAULT_NUMBER_STRING_MAX_LENGTH +
            (m_CalcStringVector.last().String.left(1) == "-") ? 1 : 0)
        m_CalcStringVector.last().String.append(AString);
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
    AppendNumSybol("1");
    emit sendTextToView();
}

void QCalculatorForm::button2_onClick()
{
    MinusCheck();
    AppendNumSybol("2");
    emit sendTextToView();
}

void QCalculatorForm::button3_onClick()
{
    MinusCheck();
    AppendNumSybol("3");
    emit sendTextToView();
}

void QCalculatorForm::button4_onClick()
{
    MinusCheck();
    AppendNumSybol("4");
    emit sendTextToView();
}

void QCalculatorForm::button5_onClick()
{
    MinusCheck();
    AppendNumSybol("5");
    emit sendTextToView();
}

void QCalculatorForm::button6_onClick()
{
    MinusCheck();
    AppendNumSybol("6");
    emit sendTextToView();
}

void QCalculatorForm::button7_onClick()
{
    MinusCheck();
    AppendNumSybol("7");
    emit sendTextToView();
}

void QCalculatorForm::button8_onClick()
{
    MinusCheck();
    AppendNumSybol("8");
    emit sendTextToView();
}

void QCalculatorForm::button9_onClick()
{
    MinusCheck();
    AppendNumSybol("9");
    emit sendTextToView();
}

void QCalculatorForm::button0_onClick()
{
    MinusCheck();
    AppendNumSybol("0");

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

void QCalculatorForm::buttonDelayPlus_onClick()
{
    if (m_Delay < 999)
        m_Delay++;

    emit sendDelay(m_Delay);
}

void QCalculatorForm::buttonDelayMinus_onClick()
{
    if (m_Delay > 0 )
        m_Delay--;

    emit sendDelay(m_Delay);
}

void QCalculatorForm::setDelay(QString ADelayString)
{
    m_Delay = ADelayString.toInt();

    emit sendDelay(m_Delay);
}

QString QCalculatorForm::mainText() const
{
    QString ReturnedText;

    for( int i = 0; i < m_CalcStringVector.length(); i++)
    {
        if (m_CalcStringVector.at(i).Type == calcResult)
        {
            if (m_CalcStringVector.at(i).String.left(2) == "Ож")
                ReturnedText.append("<font color=\"Yellow\">");
            else if (m_CalcStringVector.at(i).String.left(2) == "Ош")
                ReturnedText.append("<font color=\"Red\">");
            else
                ReturnedText.append("<font color=\"Blue\">");
        }
        else
            ReturnedText.append("<font color=\"LimeGreen\">");

        ReturnedText.append(m_CalcStringVector.at(i).String);
        ReturnedText.append("<\font><br>");
    }

    return ReturnedText;

}

QString QCalculatorForm::getDelayNumber()
{
    return QString::number(m_Delay);
}

QString QCalculatorForm::getDataStatisticString()
{
    return "Очередь на вход: " + QString::number(m_RequestCount) + "\nКоличество результатов: " + QString::number(m_ResultCount);
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

void QCalculatorForm::receiveResult(double AResult, errorType AErrType, int resultArrayLength)
{

    m_ResultCount = resultArrayLength;

    emit sendUpdateDataStatistic();

    for (int i = 0; i < m_CalcStringVector.length(); i++)
    {
        if (m_CalcStringVector.at(i).Type == calcResult && m_CalcStringVector.at(i).String.left(2) == "Ож")
        {
            switch (AErrType)
            {
                case errNoError:
                {
                    m_CalcStringVector[i].String = QString::number(AResult, 'f', 10);
                    if (m_CalcStringVector[i].String.contains("."))
                    {
                        while (m_CalcStringVector[i].String.right(1) == "0")
                            m_CalcStringVector[i].String.remove(m_CalcStringVector[i].String.length() -1, 1);
                        if(m_CalcStringVector[i].String.right(1) == ".")
                            m_CalcStringVector[i].String.remove(m_CalcStringVector[i].String.length() -1, 1);
                    }


                    break;
                }

                case errNullDivision:
                {
                    m_CalcStringVector[i].String = "Ошибка: Деление на ноль";
                    break;
                }
            }

            emit sendTextToView();

            break;
        }
    }

}

void QCalculatorForm::receiveRequestDataLength(int ARequestsLength)
{
    m_RequestCount = ARequestsLength;

    emit sendUpdateDataStatistic();
}

