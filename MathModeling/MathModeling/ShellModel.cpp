#include "ShellModel.h"
#include "QtMath"
#include <QDebug>
#include "QTime"
#include "QMap"

QShellModel::QShellModel(MyGraphicsView *View, QObject *parent) : QObject(parent)
{
    this->View = View;

    FirstDraw = true;

    PointCount = 0;

    this->AnimationTimer = new QTimer();

    this->AnimationTimer->setInterval(100);

    QObject::connect(this->AnimationTimer, &QTimer::timeout, this, &QShellModel::TimerTick, Qt::QueuedConnection);

    pointsPixmap = new QPixmap();

    this->AnimationTimer->start();
}


QShellModel::~QShellModel()
{
}


//Рисование
void QShellModel::Draw()
{
    if (FirstDraw)
    {
        RandomizePoints(0,TGenerateMethod::gmRect, TGenerateType::gtGarvis);
        FirstDraw = false;
    }

    this->pScene->clear();


    this->pScene->addPixmap(*this->pointsPixmap);

    this->View->setScene(this->pScene);
}

void QShellModel::TimerTick()
{
    this->Draw();
}

//Рандомайз точек
void QShellModel::RandomizePoints(int pointCount, TGenerateMethod GenerateMethod, TGenerateType GenerateType)
{
    switch (GenerateMethod) {

    case TGenerateMethod::gmRect :
    {
        RecRandomizePoints(pointCount);
        break;
    }
    case TGenerateMethod::gmCircle :
    {
        CircleRandomizePoints(pointCount);
        break;
    }
    case TGenerateMethod::gmNormal :
    {
        NormalRandomizePoints(pointCount);
        break;
    }

    }

    if (PointArray.length() > 0)
        GenerateShell(GenerateType);


    this->pScene = new QGraphicsScene(QRectF(5,5,View->width()-15,View->height()-15));

    pointsPixmap = new QPixmap(View->width(), View->height());
    pointsPixmap->fill();

    QPen *DrawingPen = new QPen(Qt::darkGreen, 1, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin);
    QBrush *DrawingBrush = new QBrush(Qt::green);

    pointsPinter = new QPainter(pointsPixmap);

    pointsPinter->setRenderHint(QPainter::Antialiasing);

    pointsPinter->setBrush(*DrawingBrush);
    pointsPinter->setPen(*DrawingPen);



    for(int i = 0; i < this->PointArray.length(); i++)
    {
        int X = PointArray[i].get_X();
        int Y = PointArray[i].get_Y();

        pointsPinter->drawEllipse(X,Y,5,5);

    }

    if (this->ShellPoints.length() < 1)
        return;

    DrawingPen = new QPen(Qt::blue, 1, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin);
    DrawingBrush = new QBrush(Qt::blue);

    pointsPinter->setBrush(*DrawingBrush);
    pointsPinter->setPen(*DrawingPen);

    for(int i = 0; i < this->ShellPoints.length() - 1; i++)
        pointsPinter->drawLine(ShellPoints.at(i).X + 2, ShellPoints.at(i).Y + 2, ShellPoints.at(i + 1).X + 2, ShellPoints.at(i +1).Y + 2);

}


//При изменении размеров окна стираем все точки
void QShellModel::receiveFormSizeChanged()
{
    this->RandomizePoints(0,TGenerateMethod::gmRect, TGenerateType::gtGarvis);
}

void QShellModel::RecRandomizePoints(int pointCount)
{
    this->PointCount = pointCount;

    int X;
    int Y;

    this->PointArray.clear();

    for(int i=0; i< pointCount; i++)
    {
        X =  rand() % (this->View->width()-20);
        Y =  rand() % (this->View->height()-20);

        this->PointArray.append(QMyPoint(X+5,Y+5));
    }



}

void QShellModel::CircleRandomizePoints(int pointCount)
{

    int Radius;

    if (this->View->width() > this->View->height())
        Radius = this->View->height()/2 - 20;
    else
        Radius = this->View->width()/2 - 20;

    int Xcentre = static_cast<int>(this->View->width()/2.0);
    int Ycentre = static_cast<int>(this->View->height()/2.0);


    this->PointCount = pointCount;

    int X;
    int Y;

    this->PointArray.clear();

    for(int i=0; i < pointCount; i++)
    {
        X =  rand() % (this->View->width()-20);
        Y =  rand() % (this->View->height()-20);

        if (qSqrt((X - Xcentre)*(X - Xcentre) + (Y - Ycentre)*(Y - Ycentre)) <= Radius)
            this->PointArray.append(QMyPoint(X+5,Y+5));
        else
            i--;

    }
}

void QShellModel::NormalRandomizePoints(int pointCount)
{

    int power = 10;

    this->PointArray.clear();

    for(int i=0; i < pointCount; i++)
    {
        int X = 0;
        int Y = 0;


        for (int j = 0; j < power; j++)
        {
            X +=  (rand() % (this->View->width()-20));
            Y +=  (rand() % (this->View->height()-20));
        }

        this->PointArray.append(QMyPoint(static_cast<int>(X/power)+5, static_cast<int>(Y/power)+5));
    }
}

void QShellModel::GenerateShell(TGenerateType type)
{
    this->ShellPoints.clear();

    QTime timeSpent = QTime();
    timeSpent.start();

    switch (type)
    {
    case gtGarvis:
        {
            GarvisGeneration();
            break;
        }

    case gtGrecham:
        {
            GrechamGenegation();
            break;
        }
    }

    int time = timeSpent.elapsed();

    emit SendTime(time);
}

void QShellModel::GarvisGeneration()
{
    //Ищем самую нижнюю, самую левую точку
    if (PointArray.length() < 1)
        return;


    QMyPoint MinPoint = PointArray.at(0);
    int MinPointIndex = 0;

    for (int i = 0; i < this->PointArray.length(); i++)
    {
        if (this->PointArray[i].get_Y() < MinPoint.get_Y())
        {
                MinPoint = this->PointArray[i];
                MinPointIndex = i;
        }
        else if (this->PointArray[i].get_Y() == MinPoint.get_Y())
        {
               if( this->PointArray[i].get_X() < MinPoint.get_X())
               {
                   MinPoint = this->PointArray[i];
                   MinPointIndex = i;
               }
        }
    }


    this->ShellPoints.append(this->PointArray[MinPointIndex]);

    int X1 = -1;
    int Y1 = 0;
    int X2 = 0;
    int Y2 = 0;
    int NeedX2 = 0;
    int NeedY2 = 0;

    //Генерация массива точек оболочки
    for (int j = 0; j < this->PointArray.length(); j++)
    {
        double Angle = 360;
        int NextPointIndex = 0;

        for (int i = 0; i< this->PointArray.length(); i++)
        {
            double NextAngle;

            X2 = PointArray[i].get_X() - ShellPoints.last().get_X();
            Y2 = PointArray[i].get_Y() - ShellPoints.last().get_Y();


            NextAngle = (((X1 * X2) + (Y1*Y2)))/(sqrt((X1 * X1) + (Y1 * Y1)) * sqrt((X2 * X2) + (Y2 * Y2)));


            NextAngle = qAcos(NextAngle) * 180 / 3.14159265;

            if (NextAngle < Angle)
            {
                Angle = NextAngle;
                NextPointIndex = i;
                NeedX2 = X2;
                NeedY2 = Y2;
            }
        }

        ShellPoints.append(this->PointArray[NextPointIndex]);

        X1 = NeedX2;
        Y1 = NeedY2;

        if (NextPointIndex == MinPointIndex)
            break;
    }
}

void QShellModel::GrechamGenegation()
{
    //Ищем самую нижнюю, самую левую точку
    if (PointArray.length() < 1)
        return;


    QMyPoint MinPoint = PointArray.at(0);
    int MinPointIndex = 0;

    for (int i = 0; i < this->PointArray.length(); i++)
    {
        if (this->PointArray[i].get_Y() < MinPoint.get_Y())
        {
                MinPoint = this->PointArray[i];
                MinPointIndex = i;
        }
        else if (this->PointArray[i].get_Y() == MinPoint.get_Y())
        {
               if( this->PointArray[i].get_X() < MinPoint.get_X())
               {
                   MinPoint = this->PointArray[i];
                   MinPointIndex = i;
               }
        }
    }

    QList<AngleWithIndex> AngleArray;

    ShellPoints.append(PointArray.at(MinPointIndex));

    PointArrayForShell.clear();

    PointArrayForShell = PointArray;

    PointArrayForShell.removeAt(MinPointIndex);

    int ind = 0;

    //Находим углы до всех точек
    foreach (QMyPoint NeedPoint, this->PointArrayForShell)
    {
        double Angle;


        int X1 = -1;
        int Y1 = 0;
        int X2 = NeedPoint.get_X() - MinPoint.get_X();
        int Y2 = NeedPoint.get_Y() - MinPoint.get_Y();


        Angle = (((X1 * X2) + (Y1*Y2)))/(sqrt((X1 * X1) + (Y1 * Y1)) * sqrt((X2 * X2) + (Y2 * Y2)));

        Angle = qAcos(Angle) * 180 / 3.14159265;

        NeedPoint.Angle = Angle;

        AngleWithIndex NeedElement;

        NeedElement.Angle = Angle;
        NeedElement.Index = ind;

        AngleArray.append(NeedElement);

        ind++;

    }



    //Сортировка по углу
    this->Merge(&AngleArray, 0, AngleArray.length() - 1);


    for(int i = 0; i < AngleArray.length(); i++)
    {
        ShellPoints.append(PointArrayForShell.at(AngleArray[i].Index));
    }

    //Удаление лишних точек из массива
    for (int i = 0; i < ShellPoints.length(); i++)
    {
        if (i > 1)
        {
            int X1 = ShellPoints.at(i).X;
            int Y1 = ShellPoints.at(i).Y;
            int X2 = ShellPoints.at(i-1).X;
            int Y2 = ShellPoints.at(i-1).Y;
            int X3 = ShellPoints.at(i-2).X;
            int Y3 = ShellPoints.at(i-2).Y;

            double Angle = (X1 - X3)*(Y2 - Y3) - (X2 - X3)*(Y1 - Y3);

            if (Angle >= 0)
            {
                ShellPoints.removeAt(i-1);
                i = i - 2;
            }
        }
    }

    ShellPoints.append(ShellPoints.first());
}

//Сортировка слиянием
void QShellModel::Merge(QList<AngleWithIndex> *PointArray, int first, int last)
{
    if (last <= first)
       return;
    int mid = first + (last - first) / 2;

    Merge(PointArray, first, mid);
    Merge(PointArray, mid + 1, last);

    QList<AngleWithIndex> bufferList = *PointArray;

    for (int k = first; k <= last; k++)
       bufferList.replace(k, PointArray->at(k));

    int i = first, j = mid + 1;

    for (int k = first; k <= last; k++)
    {

       if (i > mid)
       {
           PointArray->replace(k , bufferList.at(j));
           j++;
       }
       else if (j > last)
       {
           PointArray->replace(k , bufferList.at(i));
           i++;
       }
       else if ((bufferList.at(j).Angle > bufferList.at(i).Angle))
       {
           PointArray->replace(k, bufferList.at(j));
           j++;
       }
       else
       {
           PointArray->replace(k, bufferList.at(i));
           i++;
       }
    }
}
