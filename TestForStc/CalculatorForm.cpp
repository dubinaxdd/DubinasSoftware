#include "CalculatorForm.h"
#include "QDebug"


#include <QObject>


void QCalculatorForm::buttonC_onClick()
{
    qDebug() << "Baneblade";
    emit sendTextToView();

}

void QCalculatorForm::buttonCE_onClick()
{

}

void QCalculatorForm::buttonBackspace_onClick()
{

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
}

void QCalculatorForm::buttonMinus_onClick()
{
    m_MainText.append("\n-\n");
    emit sendTextToView();
}

void QCalculatorForm::buttonMultiplication_onClick()
{
    m_MainText.append("\n*\n");
    emit sendTextToView();
}

void QCalculatorForm::buttonDivision_onClick()
{
    m_MainText.append("\n/\n");
    emit sendTextToView();
}

void QCalculatorForm::buttonEqualy_onClick()
{
    m_MainText.append("\n=\n");
    emit sendTextToView();
}

QString QCalculatorForm::mainText() const
{
    return m_MainText;
}
