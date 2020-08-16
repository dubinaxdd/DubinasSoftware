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

void QCalculatorForm::buttonC_onClick()
{
    m_MainText.clear();
    emit sendTextToView();
}

void QCalculatorForm::buttonCE_onClick()
{
    if (m_MainText.length() > 0)
    {
        //Если удаляем знак действия
        if(m_MainText.at(m_MainText.length() - 1) == "\n")
        {
            QChar sign = m_MainText.at(m_MainText.length() - 2);

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
    }
}

void QCalculatorForm::buttonBackspace_onClick()
{
    if (m_MainText.length() > 0)
    {
        if(m_MainText.at(m_MainText.length() - 1) == "\n")
        {
            //m_MainText.remove(m_MainText.length() - 1, 1);

            int i = 1;
            while (m_MainText.length() - i - 1 >= 0 && m_MainText.at(m_MainText.length() - i - 1) != "\n")
            {
                i++;
            }

            //qDebug() << "asd" << i;

            if (m_MainText.length() >= i + 2 && m_MainText.at(m_MainText.length() - i - 2) == "=")
            {
                buttonCE_onClick();
            }
            else
                m_MainText.remove(m_MainText.length() - 3, 3);
            emit sendUnlockActions();
        }
        else
            m_MainText.remove(m_MainText.length() - 1, 1);

        emit sendTextToView();
    }
}

void QCalculatorForm::button1_onClick()
{
    m_MainText.append("1");
    emit sendTextToView();
}

void QCalculatorForm::button2_onClick()
{
    m_MainText.append("2");
    emit sendTextToView();
}

void QCalculatorForm::button3_onClick()
{
    m_MainText.append("3");
    emit sendTextToView();
}

void QCalculatorForm::button4_onClick()
{
    m_MainText.append("4");
    emit sendTextToView();
}

void QCalculatorForm::button5_onClick()
{
    m_MainText.append("5");
    emit sendTextToView();
}

void QCalculatorForm::button6_onClick()
{
    m_MainText.append("6");
    emit sendTextToView();
}

void QCalculatorForm::button7_onClick()
{
    m_MainText.append("7");
    emit sendTextToView();
}

void QCalculatorForm::button8_onClick()
{
    m_MainText.append("8");
    emit sendTextToView();
}

void QCalculatorForm::button9_onClick()
{
    m_MainText.append("9");
    emit sendTextToView();
}

void QCalculatorForm::button0_onClick()
{
    m_MainText.append("0");
    emit sendTextToView();
}

void QCalculatorForm::buttonDot_onClick()
{
    m_MainText.append(".");
    emit sendTextToView();
}

void QCalculatorForm::buttonPlus_onClick()
{
    m_MainText.append("\n+\n");
    emit sendTextToView();
    emit sendLockActions();
}

void QCalculatorForm::buttonMinus_onClick()
{
    m_MainText.append("\n-\n");
    emit sendTextToView();
    emit sendLockActions();
}

void QCalculatorForm::buttonMultiplication_onClick()
{
    m_MainText.append("\n*\n");
    emit sendTextToView();
    emit sendLockActions();
}

void QCalculatorForm::buttonDivision_onClick()
{
    m_MainText.append("\n/\n");
    emit sendTextToView();
    emit sendLockActions();
}

void QCalculatorForm::buttonEqualy_onClick()
{
    m_MainText.append("\n=\nОжидание результата\n");
    emit sendTextToView();
    emit sendUnlockActions();
}

QString QCalculatorForm::mainText() const
{
    return m_MainText;
}
