#include "CalculatorModel.h"

QCalculatorModel::QCalculatorModel(QObject *parent) : QObject(parent)
{
    m_DataManager = new TThreadSafeCalcDataManager();

    m_CalcCore = new QCalculatorCore(m_DataManager, this);

    m_CalcCore->start(QThread::NormalPriority);
}

void QCalculatorModel::receiveRequest(requestAction AAction, double AFirstOperand, double ASecondOperand)
{
    TCalculatorRequest NewRequest(AAction, AFirstOperand, ASecondOperand);

    m_DataManager->appendRequest(NewRequest);
}
