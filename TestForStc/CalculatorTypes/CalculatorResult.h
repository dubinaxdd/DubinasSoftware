#ifndef TCALCULATORRESULT_H
#define TCALCULATORRESULT_H

#include <CalculatorTypes.h>

class TCalculatorResult
{
    double m_Result;
    errorType m_Error;

public:
    TCalculatorResult(double AResult, errorType AError);
    double Result() const;
    errorType Error() const;
};

#endif // TCALCULATORRESULT_H
