#ifndef VORONOYLINE_H
#define VORONOYLINE_H

#include <QPointF>
#include <QMyPoint.h>

class VoronoyLine
{
public:
    VoronoyLine();

    QPointF First;
    QPointF Second;

    bool IsLeft = true;
    bool IsIntersected = true;

    int IndLeft;
    int IndRight;

};

#endif // VORONOYLINE_H
