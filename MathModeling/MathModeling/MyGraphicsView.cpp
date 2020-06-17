#include "MyGraphicsView.h"
#include <QMouseEvent>

MyGraphicsView::MyGraphicsView(QWidget *parent) : QGraphicsView(parent)
{
    this->setMouseTracking(true);
}


void MyGraphicsView::mousePressEvent ( QMouseEvent * event )
{
    emit this->mousePress();
}

void MyGraphicsView::mouseReleaseEvent (QMouseEvent *event)
{
    emit this->mouseRelease();
}

void MyGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    int X = event->pos().x();
    int Y = event->pos().y();

    emit this->mouseMove(X, Y);
}
