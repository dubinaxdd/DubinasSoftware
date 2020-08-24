#include "CalculatorCore.h"


QCalculatorCore::QCalculatorCore(TThreadSafeCalcDataManager *ADataManager, QObject *parent)
{
    Q_UNUSED(parent);
    m_DataManager = ADataManager;

}

void QCalculatorCore::run()
{
    while (true)
    {
        if (m_DataManager->getRequestsLength() > 0)
        {
            TCalculatorRequest NeedCalcRequest = m_DataManager->getFirstRequest();

            double Result = NeedCalcRequest.FirstOperand() + NeedCalcRequest.SecondOperand();

            TCalculatorResult NewResult(Result, errorType::errNoError);

            m_DataManager->appendResult(NewResult);

            sleep(m_DataManager->getDelay());

            emit sendResultReady();
        }
        //else
           // sleep(m_DataManager->getDelay());

    }
}

