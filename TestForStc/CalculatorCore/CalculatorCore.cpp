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
            Libcalculator::ErrorType *NewErrorType = new Libcalculator::ErrorType();

            Libcalculator::TypeWorkEnum NeedType = Libcalculator::TypeWorkEnum::twPlus;

            switch (NeedCalcRequest.Action())
            {
                case reqPlus:{
                    NeedType = Libcalculator::TypeWorkEnum::twPlus;
                    break;
                }
                case reqMinus:{
                    NeedType = Libcalculator::TypeWorkEnum::twMinus;
                    break;
                }
                case reqMultiplication:{
                    NeedType = Libcalculator::TypeWorkEnum::twMultiplication;
                    break;
                }
                case reqDivision:{
                    NeedType = Libcalculator::TypeWorkEnum::twDivision;
                    break;
                }
            }

            double Result = Libcalculator::DoIt(NeedType, NeedCalcRequest.FirstOperand(), NeedCalcRequest.SecondOperand(), NewErrorType);

            errorType NewError = errNoError;

            switch (*NewErrorType)
            {
                case Libcalculator::etNoError :{

                    NewError = errorType::errNoError;
                    break;
                }
                case Libcalculator::etNullDivision :{

                    NewError = errorType::errNullDivision;
                    break;
                }

            }

            TCalculatorResult NewResult(Result, NewError);

            sleep(m_DataManager->getDelay());

            m_DataManager->appendResult(NewResult);

            emit sendResultReady();
        }
        //else
           // sleep(m_DataManager->getDelay());

    }
}

