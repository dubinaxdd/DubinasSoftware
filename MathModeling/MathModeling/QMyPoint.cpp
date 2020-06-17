#include "QMyPoint.h"

QMyPoint::QMyPoint()
{
    this->X = 0;
    this->Y = 0;

    this->Dominating = 0;

    this->Angle = 0.0;
    this->index = 0;

}


QMyPoint::QMyPoint(int X, int Y)
{
    this->X = X;
    this->Y = Y;

    this->Dominating = 0;

    this->Angle = 0.0;
    this->index = 0;
}
