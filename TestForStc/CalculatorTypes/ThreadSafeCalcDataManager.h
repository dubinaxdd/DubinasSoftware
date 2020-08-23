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

    QList<TCalculatorRequest> *m_QueueRequests;
    QList<TCalculatorResult>  *m_QueueResults;
public:
    TThreadSafeCalcDataManager();

    TCalculatorRequest getFirstRequest();
    TCalculatorResult getFirstResult();

    int getRequestsLength();
    int getResultsLength();

    void appendRequest(TCalculatorRequest ARequest);
    void appendResult(TCalculatorResult AResult);
};

#endif // TTHREADSAFECALCDATAMANAGER_H
