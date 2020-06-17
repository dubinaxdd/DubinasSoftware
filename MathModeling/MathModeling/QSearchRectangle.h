#ifndef QSEARCHRECTANGLE_H
#define QSEARCHRECTANGLE_H

#include <QObject>
#include "QMyPoint.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include "QPixmap"


class QSearchRectangle : public QObject
{
    Q_OBJECT

private:
    int mousePositionX;
    int mousePositionY;


    bool mousePressed;

    bool Drawable;

public:
    QMyPoint *FirstPoint;
    QMyPoint *SecondPoint;


    explicit QSearchRectangle(QObject *parent = nullptr);

    void Draw(QGraphicsScene *pScene , QPixmap *pointsPixmam);

    void setMousePressed();

    void setMouseReleased();

    void setMousePosition(int X, int Y);



};

#endif // QSEARCHRECTANGLE_H
