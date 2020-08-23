#ifndef TCALCULATORREQUEST_H
#define TCALCULATORREQUEST_H

#pragma once

#include <CalculatorTypes.h>

class TCalculatorRequest
{

private:
    requestAction m_Action;
    double m_FirstOperand;
    double m_SecondOperand;

public:
    explicit TCalculatorRequest(requestAction AAction, double AFirstOperand, double ASecondOperand);

    requestAction Action() const;
    double FirstOperand() const;
    double SecondOperand() const;
};

#endif // TCALCULATORREQUEST_H
