#ifndef CALCULATORFORM_H
#define CALCULATORFORM_H

#include <QObject>
#include <QDebug>
#include <QSettings>
#include <QApplication>
#include <CalculatorTypes.h>

enum CalcActionType{
    actPlus,
    actMinus,
    actMultiplication,
    actDivision,
    actEqualy
};

enum CalcStringType{
    calcAction,
    calcNumber,
    calcResult
};

struct TCalcString{
    CalcStringType Type;
    QString String;
};


class QCalculatorForm : public QObject
{
    Q_OBJECT

    QVector<TCalcString> m_CalcStringVector;

    QString m_DataStatisticString;

    int m_RequestCount = 0;
    int m_ResultCount = 0;

public:
    explicit QCalculatorForm(QObject *parent = nullptr);
    ~QCalculatorForm();


    void readSettings();
    void writeSettings();

private:
    QSize m_FormSize;
    QPoint m_FormPosition;
    bool m_FormMaximized = false;  

    int m_Delay = 0;

    void MinusCheck();

    void NewAction(CalcActionType AActionType);
    void NewNumber();


signals:

    void sendTextToView();

    void sendLockActions();
    void sendUnlockActions();

    void sendLockDotButton();
    void sendUnlockDotButton();

    void sendLockMinusButton();
    void sendUnlockMinusButton();

    void sendSettingsReaded();

    void sendRequest(requestAction AAction, double AFirstOperand, double ASecondOperand);

    void sendDelay(int ADelay);

    void sendUpdateDataStatistic();



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
     void buttonDelayPlus_onClick();
     void buttonDelayMinus_onClick();
     void setDelay(QString ADelayString);

     QString mainText() const;

     int getFormWidth(){return m_FormSize.width(); };
     int getFormHeight(){return m_FormSize.height(); };

     int getFormXPosition(){return m_FormPosition.x(); };
     int getFormYPosition(){return m_FormPosition.y(); };
     int getFormMaximized(){return m_FormMaximized; };

     QString getDelayNumber();
     QString getDataStatisticString();

     void formXChanged(int AXPosition);
     void formYChanged(int AYPosition);

     void formWidthChanged(int AWidth);
     void formHeightChanged(int AHight);

     void formMaximized(bool AMaximased){m_FormMaximized = AMaximased;};

     void receiveResult(double AResult, errorType AErrType, int resultArrayLength);
     void receiveRequestDataLength(int ARequestsLength);
};

#endif // CALCULATORFORM_H
