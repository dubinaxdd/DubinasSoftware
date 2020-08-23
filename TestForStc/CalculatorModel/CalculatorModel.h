#ifndef QCALCULATORMODEL_H
#define QCALCULATORMODEL_H

#include <QObject>
#include <QThread>
#include <ThreadSafeCalcDataManager.h>
#include <CalculatorCore.h>



class QCalculatorModel : public QObject
{
    Q_OBJECT

    QCalculatorCore* m_CalcCore;

    TThreadSafeCalcDataManager *m_DataManager;

    int m_ThreadPauseTime = 1;

public:
    explicit QCalculatorModel(QObject *parent = nullptr);


public slots:
    void receiveRequest(requestAction AAction, double AFirstOperand, double ASecondOperand);

signals:

    void sendResult(double AResult, errorType AError);

};

#endif // QCALCULATORMODEL_H
