#include "CalculatorRequest.h"

TCalculatorRequest::TCalculatorRequest(requestAction AAction, double AFirstOperand, double ASecondOperand)
{
    m_Action = AAction;
    m_FirstOperand = AFirstOperand;
    m_SecondOperand = ASecondOperand;
}


requestAction TCalculatorRequest::Action() const
{
    return m_Action;
}

double TCalculatorRequest::FirstOperand() const
{
    return m_FirstOperand;
}

double TCalculatorRequest::SecondOperand() const
{
    return m_SecondOperand;
}
