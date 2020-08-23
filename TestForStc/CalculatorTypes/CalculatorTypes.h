#ifndef CALCULATORTYPES_H
#define CALCULATORTYPES_H

#pragma once
#include <QObject>
enum requestAction : quint8
{
    reqPlus             = 0,
    reqMinus            = 1,
    reqMultiplication   = 2,
    reqDivision         = 3
};

enum errorType : quint8
{
    errNoError = 0,
    errNullDivision = 1
};

#endif // CALCULATORTYPES_H
