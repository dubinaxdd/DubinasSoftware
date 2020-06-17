#ifndef QMYPOINT_H
#define QMYPOINT_H

#include <QObject>

class QMyPoint
{

private:



public:
    int X;
    int Y;

    int Dominating;

    bool LeftShell;

    int index;

    double Angle;

    QMyPoint();

    QMyPoint(int X, int Y);

    void set_X(int X){this->X = X;}
    void set_Y(int Y){this->Y = Y;}

    int get_X(){return this->X;}
    int get_Y(){return this->Y;}

    QList<int> CellVoronoyLines;

};

#endif // QMYPOINT_H
