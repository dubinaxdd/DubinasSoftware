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

public:
    explicit QCalculatorModel(QObject *parent = nullptr);
    ~QCalculatorModel();


public slots:
    void receiveRequest(requestAction AAction, double AFirstOperand, double ASecondOperand);

    void receiveResultReady();

    void receiveDelay(int ADelay);

signals:
    void sendResult(double AResult, errorType AErrType, int resultArrayLength);

    void sendRequestDataLength(int ALength);



};

#endif // QCALCULATORMODEL_H
