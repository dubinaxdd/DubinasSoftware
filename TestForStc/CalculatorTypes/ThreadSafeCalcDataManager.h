#ifndef TTHREADSAFECALCDATAMANAGER_H
#define TTHREADSAFECALCDATAMANAGER_H

#include <QMutex>
#include <CalculatorRequest.h>
#include <CalculatorResult.h>
#include <QList>

class TThreadSafeCalcDataManager
{
    QMutex	m_RequestsMutex;
    QMutex  m_ResultsMutex;
    QMutex  m_DelayMutex;

    QList<TCalculatorRequest> *m_QueueRequests;
    QList<TCalculatorResult>  *m_QueueResults;

    int m_Delay;

public:
    TThreadSafeCalcDataManager();

    TCalculatorRequest getFirstRequest();
    TCalculatorResult getFirstResult();

    int getRequestsLength();
    int getResultsLength();

    TCalculatorResult getLastResult();


    void appendRequest(TCalculatorRequest ARequest);
    void appendResult(TCalculatorResult AResult);

    int getDelay();
    void setDelay(int Delay);
};

#endif // TTHREADSAFECALCDATAMANAGER_H
