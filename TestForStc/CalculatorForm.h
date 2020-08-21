#ifndef CALCULATORFORM_H
#define CALCULATORFORM_H

#include <QObject>
#include <QDebug>
#include <QSettings>
#include <QApplication>
#include <QDir>


class QCalculatorForm : public QObject
{
    Q_OBJECT
public:
    explicit QCalculatorForm(QObject *parent = nullptr);
    ~QCalculatorForm();


    void readSettings();
    void writeSettings();

private:
    void clearBlock();
    bool m_Doted = false;

    QSize m_FormSize;
    QPoint m_FormPosition;
    bool m_FormMaximized = false;

        //QMap m_ActionsMap;

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

    void sendSettingsReaded();



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

     QString mainText() const;

     int getFormWidth(){return m_FormSize.width(); };
     int getFormHeight(){return m_FormSize.height(); };

     int getFormXPosition(){return m_FormPosition.x(); };
     int getFormYPosition(){return m_FormPosition.y(); };
     int getFormMaximized(){return m_FormMaximized; };

     void formXChanged(int AXPosition);
     void formYChanged(int AYPosition);

     void formWidthChanged(int AWidth);
     void formHeightChanged(int AHight);

     void formMaximized(bool AMaximased){m_FormMaximized = AMaximased;};

 protected:
     //QObject *m_Form;
     QObject *TextBox;

     QString m_MainText;

};

#endif // CALCULATORFORM_H
