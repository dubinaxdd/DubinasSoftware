#ifndef SHELLMODEL_H
#define SHELLMODEL_H

#include <QObject>
#include <qlist.h>
#include <QMyPoint.h>
#include <QTimer>
#include "MyGraphicsView.h"

#include "QPixmap"
#include "QPainter"

enum TGenerateMethod : int
{
    gmRect = 0,
    gmCircle = 1,
    gmNormal = 2
};


enum TGenerateType : int
{
    gtGarvis = 0,
    gtGrecham = 1

};

struct AngleWithIndex
{
    double Angle = 0;
    int Index = 0;
};

class QShellModel : public QObject
{
    Q_OBJECT
public:
    explicit QShellModel(MyGraphicsView *View, QObject *parent = nullptr);
    ~QShellModel();


    MyGraphicsView *View;

    int mousePosX;
    int mousePosY;


    QList<QMyPoint> PointArray;

    QList<QMyPoint> PointArrayForShell;

    QList<QMyPoint> ShellPoints;

    int PointCount;

    QGraphicsScene* pScene;

    QPixmap *pointsPixmap;

    QPainter *pointsPinter;

    QTimer *AnimationTimer;

    bool FirstDraw;

    void TimerTick();

    void Draw();

    void RecRandomizePoints(int pointCount);
    void CircleRandomizePoints(int pointCount);
    void NormalRandomizePoints(int pointCount);

    void GenerateShell(TGenerateType type);

    void GarvisGeneration();
    void GrechamGenegation();


private:
    void Merge(QList<AngleWithIndex> *PointArray, int first, int last);

public slots:

    void RandomizePoints(int pointCount, TGenerateMethod GenerateMethod, TGenerateType GenerateType);

    void receiveFormSizeChanged();


public slots:

signals:

    void SendTime(int time);


};

#endif // SHELLMODEL_H
