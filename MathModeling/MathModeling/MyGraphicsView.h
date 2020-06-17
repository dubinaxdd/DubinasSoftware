#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H

#include <QWidget>
#include <QtWidgets/QGraphicsView>

class MyGraphicsView : public QGraphicsView //QWidget
{
    Q_OBJECT
public:
    explicit MyGraphicsView(QWidget *parent = nullptr);

private:
    virtual void mousePressEvent (QMouseEvent *event);
    virtual void mouseReleaseEvent (QMouseEvent *event);

    virtual void mouseMoveEvent(QMouseEvent *event);

signals:
    void mousePress();
    void mouseRelease();

    void mouseMove(int X, int Y);

public slots:
};

#endif // MYGRAPHICSVIEW_H
