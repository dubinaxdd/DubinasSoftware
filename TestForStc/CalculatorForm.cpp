#include "CalculatorForm.h"
#include "QDebug"


#include <QObject>


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
    return m_MainText;
}
