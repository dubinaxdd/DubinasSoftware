#ifndef LIBCALCULATOR_H
#define LIBCALCULATOR_H

#include "libcalculator_global.h"

class LIBCALCULATOR_EXPORT Libcalculator
{

public:
    Libcalculator();

    enum TypeWorkEnum{
        twPlus,
        twMinus,
        twMultiplication,
        twDivision
    };

    enum ErrorType{
        etNoError,
        etNullDivision
    };

    static double DoIt (TypeWorkEnum ATypeWork, double AFirstOperand, double ASecondOperand, ErrorType *AError);
};


#endif // LIBCALCULATOR_H
