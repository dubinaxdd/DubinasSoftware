#ifndef CALCULATORFORM_H
#define CALCULATORFORM_H

#include <QObject>
#include <QDebug>

class QCalculatorForm : public QObject
{
    Q_OBJECT
public:
    explicit QCalculatorForm(QObject *parent = nullptr) : QObject(parent) {};

private:
    void clearBlock();
    bool m_Doted = false;

    void NoolCheck();
    void ActionCheck();


signals:

    void sendTextToView();

    void sendLockActions();
    void sendUnlockActions();

    void sendLockDotButton();
    void sendUnlockDotButton();

    void sendLockMinusButton();
    void sendUnlockMinusButton();



 public slots:
     void buttonC_onClick();
     void buttonCE_onClick();
     void buttonBackspace_onClick();
     void button1_onClick();
     void button2_onClick();
     void button3_onClick();
     void button4_onClick();
     void button5_onClick();
     void button6_onClick();
     void button7_onClick();
     void button8_onClick();
     void button9_onClick();
     void button0_onClick();
     void buttonDot_onClick();
     void buttonPlus_onClick();
     void buttonMinus_onClick();
     void buttonMultiplication_onClick();
     void buttonDivision_onClick();
     void buttonEqualy_onClick();
 protected:
     //QObject *m_Form;
     QObject *TextBox;

     QString m_MainText;

public slots:
    QString mainText() const;

};

#endif // CALCULATORFORM_H
