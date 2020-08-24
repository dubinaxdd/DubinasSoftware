#include "Libcalculator.h"

Libcalculator::Libcalculator()
{
}

double Libcalculator::DoIt(Libcalculator::TypeWorkEnum ATypeWork, double AFirstOperand, double ASecondOperand, Libcalculator::ErrorType *AError)
{
    switch(ATypeWork)
    {
        case twPlus:
        {
            *AError = etNoError;
            return  AFirstOperand + ASecondOperand;
        }
        case twMinus:
        {

            *AError = etNoError;
            return AFirstOperand - ASecondOperand;
        }
        case twMultiplication:
        {
            *AError = etNoError;
            return AFirstOperand  * ASecondOperand;
        }
        case twDivision:
        {
            if (ASecondOperand == 0.0)
            {
                *AError = etNullDivision;
                return 0.0;
            }
            else
            {
                *AError = etNoError;
                return AFirstOperand / ASecondOperand;
            }
        }
    }

    return 0.0;
}



