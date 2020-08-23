#include "CalculatorResult.h"

double TCalculatorResult::Result() const
{
    return m_Result;
}

errorType TCalculatorResult::Error() const
{
    return m_Error;
}

TCalculatorResult::TCalculatorResult(double AResult, errorType AError)
{
    m_Result = AResult;
    m_Error = AError;
}
