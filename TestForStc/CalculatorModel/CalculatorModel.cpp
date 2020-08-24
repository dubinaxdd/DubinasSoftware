#include "CalculatorModel.h"
#include "QtDebug"

QCalculatorModel::QCalculatorModel(QObject *parent) : QObject(parent)
{
    m_DataManager = new TThreadSafeCalcDataManager();

    m_CalcCore = new QCalculatorCore(m_DataManager, this);

    QObject::connect(m_CalcCore, &QCalculatorCore::sendResultReady, this, &QCalculatorModel::receiveResultReady, Qt::QueuedConnection);

    m_CalcCore->start(QThread::NormalPriority);
}

void QCalculatorModel::receiveRequest(requestAction AAction, double AFirstOperand, double ASecondOperand)
{
    TCalculatorRequest NewRequest(AAction, AFirstOperand, ASecondOperand);

    m_DataManager->appendRequest(NewRequest);
    emit sendRequestDataLength(m_DataManager->getRequestsLength());
}

void QCalculatorModel::receiveResultReady()
{
    TCalculatorResult Result = m_DataManager->getLastResult();
    emit sendResult(Result.Result(), Result.Error(), m_DataManager->getResultsLength());
    emit sendRequestDataLength(m_DataManager->getRequestsLength());
}

void QCalculatorModel::receiveDelay(int ADelay)
{
    m_DataManager->setDelay(ADelay);
}


