#ifndef QCALCULATORCORE_H
#define QCALCULATORCORE_H

#include <QObject>
#include <ThreadSafeCalcDataManager.h>
#include <QThread>
#include "CalculatorLibrary/libcalculator/Libcalculator.h"


class QCalculatorCore : public QThread
{
    Q_OBJECT

private:

    TThreadSafeCalcDataManager *m_DataManager;

public:
    explicit QCalculatorCore(TThreadSafeCalcDataManager *ADataManager, QObject *parent = nullptr);

    void run() override;

public slots:

signals:
    void sendResultReady();

};

#endif // QCALCULATORCORE_H
