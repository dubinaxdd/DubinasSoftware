#ifndef VORONOYMODEL_H
#define VORONOYMODEL_H

#include <QObject>

#include <QMyPoint.h>
#include <QTimer>
#include "MyGraphicsView.h"

#include "QPixmap"
#include "QPainter"

#include "VoronoyLine.h"


class QVoronoyModel : public QObject
{
    Q_OBJECT
private:



    MyGraphicsView *View;

    QList<QMyPoint> PointArray;

    QList<QMyPoint> ShellPoints;

    QList<VoronoyLine> VoronoyLineArray;

    int PointCount;

    QGraphicsScene* pScene;

    QPixmap *pointsPixmap;

    QPainter *pointsPinter;

    QPointF CircleCenter;

    double CircleRadius;

    void Draw();

    QList<VoronoyLine> VoronoyDiagramBuild(QList<QMyPoint> *coordArray, int first, int last);

    void GarvisGeneration(QList<QMyPoint> *ShellPoints, QList<QMyPoint> PointArray);

    void Merge(QList<QMyPoint> *coordArray, int first, int last);

    void GenerateCircle();

public:
    explicit QVoronoyModel(MyGraphicsView *View, QObject *parent = nullptr);
    ~QVoronoyModel();





public slots:

    void RandomizePoints(int pointCount);

    void receiveFormSizeChanged();


public slots:

signals:

    void SendTime(int time);


};

#endif // VORONOYMODEL_H
