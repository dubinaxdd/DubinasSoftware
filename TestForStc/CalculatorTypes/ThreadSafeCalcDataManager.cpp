#include "ThreadSafeCalcDataManager.h"

TThreadSafeCalcDataManager::TThreadSafeCalcDataManager()
{
    m_QueueRequests = new QList<TCalculatorRequest>();
    m_QueueResults = new  QList<TCalculatorResult>();
}

TCalculatorRequest TThreadSafeCalcDataManager::getFirstRequest()
{
    m_RequestsMutex.lock();
    TCalculatorRequest NeedRequest = m_QueueRequests->first();
    m_QueueRequests->removeFirst();
    m_RequestsMutex.unlock();
    return NeedRequest;
}

TCalculatorResult TThreadSafeCalcDataManager::getFirstResult()
{
    m_ResultsMutex.lock();
    TCalculatorResult NeedResult = m_QueueResults->first();
    m_QueueResults->removeFirst();
    m_ResultsMutex.unlock();
    return NeedResult;
}

int TThreadSafeCalcDataManager::getRequestsLength()
{
    QMutexLocker locker (&m_RequestsMutex);
    return m_QueueRequests->length();
}

int TThreadSafeCalcDataManager::getResultsLength()
{
    QMutexLocker locker (&m_ResultsMutex);
    return m_QueueResults->length();
}

void TThreadSafeCalcDataManager::appendRequest(TCalculatorRequest ARequest)
{
    m_RequestsMutex.lock();
    m_QueueRequests->append(ARequest);
    m_RequestsMutex.unlock();
}

void TThreadSafeCalcDataManager::appendResult(TCalculatorResult AResult)
{
    m_ResultsMutex.lock();
    m_QueueResults->append(AResult);
    m_ResultsMutex.unlock();
}
