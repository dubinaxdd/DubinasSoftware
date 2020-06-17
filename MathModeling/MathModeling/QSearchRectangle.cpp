#include "QSearchRectangle.h"
#include "QDebug"

QSearchRectangle::QSearchRectangle(QObject *parent) : QObject(parent)
{
    this->mousePressed = false;
    this->Drawable = false;

    this->mousePositionX = 0;
    this->mousePositionY = 0;

    this->FirstPoint = new QMyPoint(0,0);
    this->SecondPoint = new QMyPoint(0,0);
}


void QSearchRectangle::Draw(QGraphicsScene *pScene, QPixmap *pointsPixmam)
{

    if(this->Drawable)
    {
        QPen *DrawingPen = new QPen(Qt::darkBlue, 1, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin);
        QBrush *DrawingBrush = new QBrush(Qt::blue);

        DrawingBrush->setColor(QColor(0,0,255,80));

        if(this->mousePressed)
        {
            int width = this->mousePositionX - this->FirstPoint->get_X();

            int height = this->mousePositionY - this->FirstPoint->get_Y();

            pScene->addRect(this->FirstPoint->get_X(), this->FirstPoint->get_Y(), width, height, *DrawingPen, *DrawingBrush);

        }
        else
        {
            int width = this->SecondPoint->get_X() - this->FirstPoint->get_X();

            int height = this->SecondPoint->get_Y() - this->FirstPoint->get_Y();

            pScene->addRect(this->FirstPoint->get_X(), this->FirstPoint->get_Y(), width, height, *DrawingPen, *DrawingBrush);
        }
    }
}

void QSearchRectangle::setMousePressed()
{


    FirstPoint->set_X(this->mousePositionX);
    FirstPoint->set_Y(this->mousePositionY);

    this->mousePressed = true;

    this->Drawable = true;
}

void QSearchRectangle::setMouseReleased()
{

    SecondPoint->set_X(this->mousePositionX);
    SecondPoint->set_Y(this->mousePositionY);

    this->mousePressed = false;
}

void QSearchRectangle::setMousePosition(int X, int Y)
{
    this->mousePositionX = X;
    this->mousePositionY = Y;
}
