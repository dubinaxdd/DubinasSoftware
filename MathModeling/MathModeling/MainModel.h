#ifndef MAINMODEL_H
#define MAINMODEL_H

#include <QObject>
#include <qlist.h>
#include <QMyPoint.h>
#include <QGraphicsView>
#include <QTimer>
#include "MyGraphicsView.h"
#include "QSearchRectangle.h"
#include "TreeElement.h"

#include "QPixmap"
#include "QPainter"



struct CoordinateWithIndex
{
    int Coord;
    int Ind;
};


enum Method : int
{
    Trivial = 0,
    Dominating = 1,
    kDTree = 2
};


class MainModel: public QObject
{

    Q_OBJECT


private:
    MyGraphicsView *View;

    int mousePosX;
    int mousePosY;

    QSearchRectangle *searchRectangle;

    QList<QMyPoint> PointArray;

    //Для второго метода
    QList<QMyPoint> DominatingPointArray;


    bool PretreatmentReady;

    int PointCount;

    QGraphicsScene* pScene;

    QPixmap *pointsPixmap;

    QPainter *pointsPinter;

    QTimer *AnimationTimer;

    QList<TreeElement> Tree;



    bool FirstDraw;

    void TimerTick();

    void FastSearch(QMyPoint* point);

    void Merge(QList<CoordinateWithIndex> *coordArray, int first, int last);

    void TreeBuild(QList<CoordinateWithIndex> CoordArray, int IndOfParent, bool isLeftChildren, bool isX, QList<TreeElement> *Tree);

    void TreeCounting(int TreeElementIndex, int* PointCount, int MinX, int MaxX, int MinY, int MaxY);

public:
    MainModel(MyGraphicsView *View);
    ~MainModel();

    void Draw();


public slots:

    void RandomizePoints(int pointCount);
    void Pretreatment(Method method);
    void Counting(Method method);

    void receiveMousePress();
    void receiveMouseRelease();

    void receiveMouseMove(int X, int Y);

    void receiveFormSizeChanged();

signals:
    void sendPretreatmentEnded(int time);

    void sendCountingEnded(int CountFinded, int time , int PointCount, Method method);

};



#endif // MAINMODEL_H
