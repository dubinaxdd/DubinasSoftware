#include "CalculatorForm.h"
#include "QDebug"

#define DEFAULT_CONFIG_FILE_NAME "/config.ini"


#include <QObject>


QCalculatorForm::QCalculatorForm(QObject *parent) : QObject(parent)
{       
    m_FormSize = QSize(500, 400);
    m_FormPosition = QPoint(0, 0);
}

QCalculatorForm::~QCalculatorForm()
{
    writeSettings();
}

void QCalculatorForm::clearBlock()
{
    while (m_MainText.length() > 0 && m_MainText.at(m_MainText.length() - 1) != "\n")
        m_MainText.remove(m_MainText.length() - 1, 1);

    if (m_MainText.length() > 1 && m_MainText.at(m_MainText.length() - 2) == "=")
    {
        for (int i = 0; i < 4; i++)
        {
            if(m_MainText.at(m_MainText.length() - 1) == "\n")
                m_MainText.remove(m_MainText.length() - 3, 3);
            else
            {
                while (m_MainText.length() > 0 && m_MainText.at(m_MainText.length() - 1) != "\n")
                    m_MainText.remove(m_MainText.length() - 1, 1);
            }
        }
    }
}

void QCalculatorForm::NoolCheck()
{
    if (m_MainText.length() > 1 && m_MainText.at(m_MainText.length() - 1) == "0" && m_MainText.at(m_MainText.length() - 2) == "\n")
    {
       m_MainText.append(".");
       emit sendLockDotButton();
    }
    else if (m_MainText.length() == 1 && m_MainText.at(m_MainText.length() - 1) == "0")
    {
        m_MainText.append(".");
        emit sendLockDotButton();
    }


    if (m_MainText.length() > 3 && m_MainText.at(m_MainText.length() - 3) == "\n" && m_MainText.at(m_MainText.length() - 1) == "\n")
        emit sendLockMinusButton();
}

void QCalculatorForm::ActionCheck()
{
    if (m_MainText.length() == 0)
        m_MainText.append("0");
    else if (m_MainText.at(m_MainText.length() - 1) == "." || m_MainText.at(m_MainText.length() - 1) == "\n" || m_MainText.at(m_MainText.length() - 1) == "-")
    {
        if (m_MainText.at(m_MainText.length() - 1) == "-")
             m_MainText.remove(m_MainText.length() - 1, 1);

        m_MainText.append("0");
    }
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
    if (!m_MainText.isEmpty())
    {
        m_MainText.clear();
        emit sendTextToView();
        emit sendUnlockActions();
        emit sendUnlockDotButton();
    }
}

///Удаляет строку, если последняя строка - результат, то удаляет весь блок
void QCalculatorForm::buttonCE_onClick()
{
    if (m_MainText.length() > 0)
    {

        if(m_MainText.at(m_MainText.length() - 1) == "\n")
        {
            QChar sign = m_MainText.at(m_MainText.length() - 2);

            //Если удаляем знак действия
            if (sign == "+" || sign == "-" || sign == "*" || sign == "/")
            {
                m_MainText.remove(m_MainText.length() - 3, 3);
                emit sendUnlockActions();
            }
            else
            {
                m_MainText.remove(m_MainText.length() - 1, 1);
                clearBlock();
            }
        }
        else
        {
            clearBlock();
        }

        emit sendTextToView();
        emit sendUnlockDotButton();
    }
}


void QCalculatorForm::buttonBackspace_onClick()
{
    if (m_MainText.length() > 0)
    {
        if(m_MainText.at(m_MainText.length() - 1) == "\n")
        {
            int i = 1;
            while (m_MainText.length() - i - 1 >= 0 && m_MainText.at(m_MainText.length() - i - 1) != "\n")
            {
                i++;
            }

            if (m_MainText.length() >= i + 2 && m_MainText.at(m_MainText.length() - i - 2) == "=")
            {
                buttonCE_onClick();
            }
            else
                m_MainText.remove(m_MainText.length() - 3, 3);
            emit sendUnlockActions();
        }
        else
        {
            if (m_MainText.at(m_MainText.length() - 1) == ".")
                emit sendUnlockDotButton();

            if (m_MainText.at(m_MainText.length() - 1) == "-")
                emit sendUnlockMinusButton();

            m_MainText.remove(m_MainText.length() - 1, 1);

            if (m_MainText.length() > 2 && m_MainText.at(m_MainText.length() - 3) == "\n" && m_MainText.at(m_MainText.length() - 1) == "\n")
            {
                if (m_MainText.at(m_MainText.length() - 2) == "+" || m_MainText.at(m_MainText.length() - 2) == "-" ||m_MainText.at(m_MainText.length() - 2) == "*" || m_MainText.at(m_MainText.length() - 2) == "/")
                emit sendUnlockMinusButton();
            }
        }

        emit sendTextToView();
    }
}

void QCalculatorForm::button1_onClick()
{
    NoolCheck();
    m_MainText.append("1");
    emit sendTextToView();
}

void QCalculatorForm::button2_onClick()
{
    NoolCheck();
    m_MainText.append("2");
    emit sendTextToView();
}

void QCalculatorForm::button3_onClick()
{
    NoolCheck();
    m_MainText.append("3");
    emit sendTextToView();
}

void QCalculatorForm::button4_onClick()
{
    NoolCheck();
    m_MainText.append("4");
    emit sendTextToView();
}

void QCalculatorForm::button5_onClick()
{
    NoolCheck();
    m_MainText.append("5");
    emit sendTextToView();
}

void QCalculatorForm::button6_onClick()
{
    NoolCheck();
    m_MainText.append("6");
    emit sendTextToView();
}

void QCalculatorForm::button7_onClick()
{
    NoolCheck();
    m_MainText.append("7");
    emit sendTextToView();
}

void QCalculatorForm::button8_onClick()
{
    NoolCheck();
    m_MainText.append("8");
    emit sendTextToView();
}

void QCalculatorForm::button9_onClick()
{
    NoolCheck();
    m_MainText.append("9");
    emit sendTextToView();
}

void QCalculatorForm::button0_onClick()
{
    NoolCheck();
    m_MainText.append("0");
    emit sendTextToView();
}

void QCalculatorForm::buttonDot_onClick()
{
    if (m_MainText.isEmpty() || m_MainText.at(m_MainText.length() - 1) == "\n")
        m_MainText.append("0");
    m_MainText.append(".");
    emit sendTextToView();
    emit sendLockDotButton();

}

void QCalculatorForm::buttonPlus_onClick()
{
    ActionCheck();
    m_MainText.append("\n+\n");
    emit sendTextToView();
    emit sendLockActions();
}

void QCalculatorForm::buttonMinus_onClick()
{
    if(m_MainText.isEmpty() || m_MainText.at(m_MainText.length() - 1) == "\n")
    {
        m_MainText.append("-");

        if (m_MainText.length() > 4 && m_MainText.at(m_MainText.length() - 4) == "\n")
            emit sendLockMinusButton();
    }
    else
    {
        ActionCheck();
        m_MainText.append("\n-\n");
        emit sendLockActions();
    }
    emit sendTextToView();
}

void QCalculatorForm::buttonMultiplication_onClick()
{
    ActionCheck();
    m_MainText.append("\n*\n");
    emit sendTextToView();
    emit sendLockActions();
}

void QCalculatorForm::buttonDivision_onClick()
{
    ActionCheck();
    m_MainText.append("\n/\n");
    emit sendTextToView();
    emit sendLockActions();
}

void QCalculatorForm::buttonEqualy_onClick()
{
    ActionCheck();
    m_MainText.append("\n=\nОжидание результата\n");
    emit sendTextToView();
    emit sendUnlockActions();
}

QString QCalculatorForm::mainText() const
{
    QString ReturnedText;

    ReturnedText.append("<font color=\"LimeGreen\">");

    ReturnedText.append(m_MainText);

    for (int i = 0; i < ReturnedText.length(); i++)
    {
        if (ReturnedText.at(i) == "\n")
        {
            if (ReturnedText.length() > i + 1 && ReturnedText.at(i + 1) == "О")
                ReturnedText.replace(i,1, "</font><br><font color=\"Yellow\">");
            else
                ReturnedText.replace(i,1, "</font><br><font color=\"Lime\">");
        }
    }

    ReturnedText.append("</font>");

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
