#include "VoronoyModel.h"
#include "QtMath"
#include <QDebug>
#include "QTime"
#include "QMap"

QVoronoyModel::QVoronoyModel(MyGraphicsView *View, QObject *parent) : QObject(parent)
{
    this->View = View;

    PointCount = 0;

    pointsPixmap = new QPixmap();
}


QVoronoyModel::~QVoronoyModel()
{

}


//Рисование
void QVoronoyModel::Draw()
{
    this->pScene->clear();

    this->pScene->addPixmap(*this->pointsPixmap);

    this->View->setScene(this->pScene);
}

QList<VoronoyLine> QVoronoyModel::VoronoyDiagramBuild(QList<QMyPoint> *coordArray, int first, int last)
{
    if (last <= first)
       return QList<VoronoyLine>();
    int mid = first + (last - first) / 2;

    QList<VoronoyLine> LeftLines = VoronoyDiagramBuild(coordArray, first, mid);
    QList<VoronoyLine> RightLines = VoronoyDiagramBuild(coordArray, mid + 1, last);

    //Определяем к какому множеству пренадлежат линии (правое или левое)
    for (int i = 0; i < LeftLines.length(); i++)
    {
        LeftLines[i].IsLeft = true;
        LeftLines[i].IsIntersected = false;
    }

    for (int i = 0; i < RightLines.length(); i++)
    {
        RightLines[i].IsLeft = false;
        RightLines[i].IsIntersected = false;
    }


    //Запихиваем обе диаграммы в один массив
    QList<VoronoyLine> AllLines;

    for (int i = 0; i < LeftLines.length(); i++)
        AllLines.append(LeftLines.at(i));


    for (int i = 0; i < RightLines.length(); i++)
        AllLines.append(RightLines.at(i));

    //Наращиваем индаксы правого подмножества
    for (int i = mid + 1; i < last + 1; i++)
    {
        QMyPoint asd = coordArray->at(i);

        for(int j = 0; j < asd.CellVoronoyLines.length(); j++)
            asd.CellVoronoyLines[j] += LeftLines.length();

        coordArray->replace(i, asd);
    }


   // if (coordArray->length() == (last + 1 - first))
      //  return AllLines;

    //распихиваем по массивам точки множества
    QList<QMyPoint> PointsArrayLeft;
    for (int i = first; i < mid + 1; i++)
        PointsArrayLeft.append(coordArray->at(i));

    QList<QMyPoint> PointsArrayRight;
    for (int i = mid + 1; i < last + 1; i++)
        PointsArrayRight.append(coordArray->at(i));

    //Определяем для них к какому множеству они изначально принадлежат
    for (int i = 0; i < PointsArrayLeft.length(); i++)
        PointsArrayLeft[i].LeftShell = true;

    for (int i = 0; i < PointsArrayRight.length(); i++)
        PointsArrayRight[i].LeftShell = false;


    //Объединение выпуклых оболочек
    QList<QMyPoint> PointsArray;
    PointsArray.append(PointsArrayLeft);
    PointsArray.append(PointsArrayRight);

    QList<QMyPoint> ShellPointsUnited;


    //Построение выпуклой оболочек
    GarvisGeneration(&ShellPointsUnited, PointsArray);

    //Инициализация точек опорных прямых
    QMyPoint LeftBottom;
    QMyPoint RightBottom;
    QMyPoint LeftTop;
    QMyPoint RightTop;

    for (int i = 0; i < ShellPointsUnited.length()-1; i++)
    {
        if (ShellPointsUnited.at(i).LeftShell == true && ShellPointsUnited.at(i + 1).LeftShell == false)
        {
            LeftTop = ShellPointsUnited.at(i);
            RightTop = ShellPointsUnited.at(i + 1);
        }

        if (ShellPointsUnited.at(i).LeftShell == false && ShellPointsUnited.at(i + 1).LeftShell == true)
        {
            RightBottom = ShellPointsUnited.at(i);
            LeftBottom = ShellPointsUnited.at(i + 1);
        }
    }


    //Перестроение диаграммы Вороного
    int SuperIndex = AllLines.length()-1;


    //Для первого вхождения
    {
        QPointF MinBottomPoint1 = QPointF(0.0, -9999.0);
        QPointF MinBottomPoint2 = QPointF(1.0, -9999.0);

        QLineF MinBottomLine = QLineF(MinBottomPoint1, MinBottomPoint2);

        //Получаем опорную прямую
        QPointF LeftBottomPoint = QPointF(LeftBottom.X, LeftBottom.Y);
        QPointF RightBottomPoint = QPointF(RightBottom.X, RightBottom.Y);

        QLineF Line  = QLineF(LeftBottomPoint, RightBottomPoint);

        //Получаем центр опорной прямой
        QPointF LineCenter = Line.center();

        //Получаем вектор нормали опорной прямой
        QLineF LineForNormal = QLineF(LineCenter, RightBottomPoint);

        QLineF NormalLine = LineForNormal.normalVector();

        QPointF IntersectPoint;

        NormalLine.intersect(MinBottomLine, &IntersectPoint);

        VoronoyLine NewVoronoyLine  = VoronoyLine();

        NewVoronoyLine.First = IntersectPoint;

        NewVoronoyLine.IndLeft = LeftBottom.index;
        NewVoronoyLine.IndRight = RightBottom.index;

        AllLines.append(NewVoronoyLine);
    }



    //Фланг нужный для включения условии о том что EntryPoint должна быть выше last.first
    bool FirstLineInIntersection = true;

   // bool FirstLineInIntersection = false;

    while(!(LeftTop.index == LeftBottom.index && RightTop.index == RightBottom.index) && PointsArray.length() != 2)
    {
        qDebug() << "new";
        //Получаем опорную прямую
        QPointF LeftBottomPoint = QPointF(LeftBottom.X, LeftBottom.Y);
        QPointF RightBottomPoint = QPointF(RightBottom.X, RightBottom.Y);

        QLineF Line  = QLineF(LeftBottomPoint, RightBottomPoint);

        //Получаем центр опорной прямой
        QPointF LineCenter = Line.center();

        //Получаем вектор нормали опорной прямой
        QLineF LineForNormal = QLineF(LineCenter, RightBottomPoint);

        QLineF NormalLine = LineForNormal.normalVector();

        QPointF EntryPoint;

        QPointF MinBottomPoint1 = QPointF(0.0, 9999.0);
        QPointF MinBottomPoint2 = QPointF(1.0, 9999.0);

        QLineF MinBottomLine = QLineF(MinBottomPoint1, MinBottomPoint2);


        NormalLine.intersect(MinBottomLine, &EntryPoint);

        QLineF NewLine = QLineF(AllLines.last().First, EntryPoint);

        int IntersectLineIndex = -1;

        //Ищем все пересечения текущей линии с  линиями  диаграммы вороного

         //Для ЛЕВОГО мнжества
         for(int j = 0; j < LeftBottom.CellVoronoyLines.length(); j++)
         {

             QLineF VoronoyLine = QLineF(AllLines.at(LeftBottom.CellVoronoyLines.at(j)).First, AllLines.at(LeftBottom.CellVoronoyLines.at(j)).Second);



             QPointF IntersectPoint;
            if(LeftBottom.CellVoronoyLines.at(j) <= SuperIndex)
            {
                 //Если пересечение удалось, то запоминаем точку пересечения
                 if (NewLine.intersect(VoronoyLine, &IntersectPoint)== QLineF::BoundedIntersection)
                 {
                     qDebug() << "left intersected" << j;
                     //Если EntryPoint еще не определен

                     if(FirstLineInIntersection)
                     {
                         if (IntersectPoint.y() < EntryPoint.y())
                         {
                             EntryPoint = IntersectPoint;
                             IntersectLineIndex = LeftBottom.CellVoronoyLines.at(j);
                         }
                     }
                     else
                     {
                         if (IntersectPoint.y() < EntryPoint.y() && IntersectPoint.y() > AllLines.last().First.y())
                         {
                             EntryPoint = IntersectPoint;
                             IntersectLineIndex = LeftBottom.CellVoronoyLines.at(j);
                         }
                     }
                 }
                 else {
                     qDebug() << "left no intersected";
                 }
            }

         }

         //flag2 = false;

        //Для ПРАВОГО мнжества
         for(int j = 0; j < RightBottom.CellVoronoyLines.length(); j++)
         {

             QLineF VoronoyLine = QLineF(AllLines.at(RightBottom.CellVoronoyLines.at(j)).First, AllLines.at(RightBottom.CellVoronoyLines.at(j)).Second);

             QPointF IntersectPoint;
             if(RightBottom.CellVoronoyLines.at(j) <= SuperIndex)
             {
                 //Если пересечение удалось, то запоминаем точку пересечения
                 if (NewLine.intersect(VoronoyLine, &IntersectPoint)== QLineF::BoundedIntersection)
                 {
                     qDebug() << "right intersected" << j;

                     if(FirstLineInIntersection)
                     {
                         if (IntersectPoint.y() < EntryPoint.y())
                         {
                             EntryPoint = IntersectPoint;
                             IntersectLineIndex = RightBottom.CellVoronoyLines.at(j);
                         }
                     }
                     else
                     {
                         if (IntersectPoint.y() < EntryPoint.y() && IntersectPoint.y() > AllLines.last().First.y())
                         {
                             EntryPoint = IntersectPoint;
                             IntersectLineIndex = RightBottom.CellVoronoyLines.at(j);
                         }
                     }

                 }
                 else {
                     qDebug() << "right no intersected";
                 }
             }

         }


        FirstLineInIntersection = false;



        if (IntersectLineIndex == -1)
        {
            qDebug() << "break";

            break;
        }



        //Добавляем Ребро диаграммы Вороного в массив
        AllLines.last().Second = EntryPoint;

        //добавляем точке основного массива индекс пренадлежащей ей диаграммы воронова

        LeftBottom.CellVoronoyLines.append(AllLines.length()-1);

        coordArray->replace(LeftBottom.index, LeftBottom);

        RightBottom.CellVoronoyLines.append(AllLines.length()-1);

        coordArray->replace(RightBottom.index, RightBottom);


        //Перемещаем опорную прямую
       if (AllLines.at(IntersectLineIndex).IsLeft)
       {
            if (AllLines.at(IntersectLineIndex).IndLeft == LeftBottom.index)
                LeftBottom = coordArray->at(AllLines.at(IntersectLineIndex).IndRight);
            else
                LeftBottom = coordArray->at(AllLines.at(IntersectLineIndex).IndLeft);
       }
       else
       {
           if (AllLines.at(IntersectLineIndex).IndLeft == RightBottom.index)
               RightBottom = coordArray->at(AllLines.at(IntersectLineIndex).IndRight);
           else
               RightBottom = coordArray->at(AllLines.at(IntersectLineIndex).IndLeft);
       }


        // Определяется так. Предположим, у нас есть 3 точки: А(х1,у1), Б(х2,у2), С(х3,у3). Через точки А и Б проведена прямая. И нам надо определить, как расположена точка С относительно прямой АБ. Для этого вычисляем значение:
         //D = (х3 - х1) * (у2 - у1) - (у3 - у1) * (х2 - х1)

        // D = (х3 - х1) * (у2 - у1) - (у3 - у1) * (х2 - х1)
        // - Если D = 0 - значит, точка С лежит на прямой АБ.
        // - Если D < 0 - значит, точка С лежит слева от прямой.
         //- Если D > 0 - значит, точка С лежит справа от прямой.


       qreal x3 = 0;
       qreal y3 = 0;
       qreal x1 = 0;
       qreal y1 = 0;
       qreal x2 = 0;
       qreal y2 = 0;



        if (AllLines.at(IntersectLineIndex).Second.y() > AllLines.at(IntersectLineIndex).First.y())
        {
            x3 = AllLines.at(IntersectLineIndex).Second.x();
            y3 = AllLines.at(IntersectLineIndex).Second.y();

            x1 = AllLines.last().Second.x();
            y1 = AllLines.last().Second.y();

            x2 = AllLines.last().First.x();
            y2 = AllLines.last().First.y();
        }
        else
        {
            x3 = AllLines.at(IntersectLineIndex).First.x();
            y3 = AllLines.at(IntersectLineIndex).First.y();

            x1 = AllLines.last().Second.x();
            y1 = AllLines.last().Second.y();

            x2 = AllLines.last().First.x();
            y2 = AllLines.last().First.y();
        }

        double D = ((x3 - x1) * (y2 - y1)) - ((y3 - y1) * (x2 - x1));


        QPointF NeedDellPoint;

        if (AllLines.at(IntersectLineIndex).IsLeft)
        {
            if (D < 0)
            {

                NeedDellPoint = AllLines[IntersectLineIndex].Second;
                AllLines[IntersectLineIndex].Second = EntryPoint;
            }
            else
            {
                NeedDellPoint = AllLines[IntersectLineIndex].First;
                AllLines[IntersectLineIndex].First = EntryPoint;
            }
        }
        else
        {
            if (D >= 0)
            {
                NeedDellPoint = AllLines[IntersectLineIndex].Second;
                AllLines[IntersectLineIndex].Second = EntryPoint;
            }
            else
            {
                NeedDellPoint = AllLines[IntersectLineIndex].First;
                AllLines[IntersectLineIndex].First = EntryPoint;
            }
        }


        //Отсекаем аппендиксную линию
        for (int i = 0; i < SuperIndex; i++)
        {

            if (AllLines[i].First == NeedDellPoint || AllLines[i].Second == NeedDellPoint )
            {


                if (AllLines.at(IntersectLineIndex).IsLeft)
                {
                    if ((AllLines[i].First.x() >= NeedDellPoint.x() && AllLines[i].Second.x() >= NeedDellPoint.x()) && AllLines[i].IsLeft == true)
                    {

                        if( AllLines[i].First == NeedDellPoint)
                            NeedDellPoint = AllLines[i].Second;
                        else if (AllLines[i].Second == NeedDellPoint)
                            NeedDellPoint = AllLines[i].First;
                        else {
                            continue;
                        }



                        AllLines[i].First = QPointF(-99999990.0, -99999990.0);
                        AllLines[i].Second = QPointF(-99999990.0, -99999990.0);

                        i=0;
                    }
                }
                else
                {
                    if (AllLines[i].First.x() <= NeedDellPoint.x() && AllLines[i].Second.x() <= NeedDellPoint.x() && AllLines[i].IsLeft == false)
                    {

                        if( AllLines[i].First == NeedDellPoint)
                            NeedDellPoint = AllLines[i].Second;
                        else if (AllLines[i].Second == NeedDellPoint)
                            NeedDellPoint = AllLines[i].First;
                        else {
                            continue;
                        }



                        AllLines[i].First = QPointF(-99999990.0, -99999990.0);
                        AllLines[i].Second = QPointF(-99999990.0, -99999990.0);

                        i=0;
                    }
                }

            }


           // if (DellPointCount == 1)
          //  {
              /*  if( AllLines[DellPointIndex].First == NeedDellPoint)
                    NeedDellPoint = AllLines[DellPointIndex].Second;
                else
                    NeedDellPoint = AllLines[DellPointIndex].First;



                AllLines[DellPointIndex].First = QPointF(-99999990.0, -99999990.0);
                AllLines[DellPointIndex].Second = QPointF(-99999990.0, -99999990.0);

                i=0;*/
          //  }

        }


        AllLines[IntersectLineIndex].IsIntersected = true;

        //Из конца текущей линии пускаем следующую линию
        VoronoyLine NewVoronoyLine = VoronoyLine();
        NewVoronoyLine.First = EntryPoint;
        NewVoronoyLine.IndLeft = LeftBottom.index;
        NewVoronoyLine.IndRight = RightBottom.index;
        AllLines.append(NewVoronoyLine);
    }



    //Для последнего вхождения
    {
        QPointF MaxTopPoint1 = QPointF(0.0, 9999.0);
        QPointF MaxTopPoint2 = QPointF(1.0, 9999.0);

        QLineF MaxTopLine = QLineF(MaxTopPoint1, MaxTopPoint2);


        //Получаем опорную прямую
        QPointF LeftBottomPoint = QPointF(LeftBottom.X, LeftBottom.Y);
        QPointF RightBottomPoint = QPointF(RightBottom.X, RightBottom.Y);

        QLineF Line  = QLineF(LeftBottomPoint, RightBottomPoint);

        //Получаем центр опорной прямой
        QPointF LineCenter = Line.center();

        //Получаем вектор нормали опорной прямой
        QLineF LineForNormal = QLineF(LineCenter, RightBottomPoint);

        QLineF NormalLine = LineForNormal.normalVector();

        QPointF IntersectPoint;
        NormalLine.intersect(MaxTopLine, &IntersectPoint);

        AllLines.last().Second = IntersectPoint;


        //добавляем точке основного массива индекс пренадлежащей ей диаграммы воронова

        LeftBottom.CellVoronoyLines.append(AllLines.length()-1);

        coordArray->replace(LeftBottom.index, LeftBottom);

        RightBottom.CellVoronoyLines.append(AllLines.length()-1);

        coordArray->replace(RightBottom.index, RightBottom);
    }

    return AllLines;
}


//Рандомайз точек
void QVoronoyModel::RandomizePoints(int pointCount)
{

    this->PointCount = pointCount;

    int X;
    int Y;

    this->PointArray.clear();

    for(int i=0; i< pointCount; i++)
    {
        X =  rand() % (this->View->width() - 5);
        Y =  rand() % (this->View->height() -5);

        this->PointArray.append(QMyPoint(X,Y));
        //this->PointArray.last().index = i;
    }
    //Сортировка
    Merge(&PointArray, 0, PointArray.length()-1);

    for (int i = 0; i < this->PointArray.length(); i++)
    {
        this->PointArray[i].index = i;
    }



    //Нахождение ребер диаграммы Вороного
    QList<VoronoyLine> VoronoiLines;

    if (PointArray.length() > 1)
        VoronoiLines = VoronoyDiagramBuild(&PointArray, 0, PointArray.length()-1);

    VoronoyLineArray = VoronoiLines;

    ShellPoints.clear();

    GarvisGeneration(&ShellPoints, PointArray);

    GenerateCircle();

    //Рисование
    this->pScene = new QGraphicsScene(QRectF(0,0,View->width() - 5,View->height() - 5));

    pointsPixmap = new QPixmap(View->width() - 5, View->height() - 5);
    pointsPixmap->fill();

    QPen *DrawingPen = new QPen(Qt::darkGreen, 1, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin);
    QBrush *DrawingBrush = new QBrush(Qt::green);

    pointsPinter = new QPainter(pointsPixmap);

    pointsPinter->setRenderHint(QPainter::Antialiasing);

    pointsPinter->setBrush(*DrawingBrush);
    pointsPinter->setPen(*DrawingPen);



    for (int i = 0; i < this->PointArray.length(); i++)
    {
        int X = PointArray[i].get_X();
        int Y = PointArray[i].get_Y();

        pointsPinter->drawEllipse(X - 3,Y - 3, 6, 6);

    }



    for (int i = 0; i < VoronoiLines.length(); i++)
        pointsPinter->drawLine(VoronoiLines.at(i).First, VoronoiLines.at(i).Second);


    DrawingPen = new QPen(Qt::red, 1, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin);
    DrawingBrush = new QBrush(Qt::red);

    pointsPinter->setBrush(*DrawingBrush);
    pointsPinter->setPen(*DrawingPen);

    for(int i = 0; i < this->ShellPoints.length() - 1; i++)
        pointsPinter->drawLine(ShellPoints.at(i).X + 2, ShellPoints.at(i).Y + 2, ShellPoints.at(i + 1).X + 2, ShellPoints.at(i +1).Y + 2);



    DrawingPen = new QPen(Qt::darkBlue);
    DrawingBrush = new QBrush(QColor(0,0,0,0));

    pointsPinter->setBrush(*DrawingBrush);

    pointsPinter->setPen(*DrawingPen);

    pointsPinter->drawEllipse(CircleCenter, CircleRadius, CircleRadius);
    pointsPinter->drawEllipse(CircleCenter, 3, 3);


    this->Draw();
}


//При изменении размеров окна стираем все точки
void QVoronoyModel::receiveFormSizeChanged()
{
    this->RandomizePoints(0);
}

//Сортировка слиянием
void QVoronoyModel::Merge(QList<QMyPoint> *coordArray, int first, int last)
{
    if (last <= first)
       return;
    int mid = first + (last - first) / 2;

    Merge(coordArray, first, mid);
    Merge(coordArray, mid + 1, last);

    QList<QMyPoint> bufferList = *coordArray;

    for (int k = first; k <= last; k++)
       bufferList.replace(k, coordArray->at(k));

    int i = first, j = mid + 1;

    for (int k = first; k <= last; k++)
    {

       if (i > mid)
       {
           coordArray->replace(k , bufferList.at(j));
           j++;
       }
       else if (j > last)
       {
           coordArray->replace(k , bufferList.at(i));
           i++;
       }
       else if ((bufferList.at(j).X < bufferList.at(i).X))
       {
           coordArray->replace(k, bufferList.at(j));
           j++;
       }
       else
       {
           coordArray->replace(k, bufferList.at(i));
           i++;
       }
    }
}

void QVoronoyModel::GenerateCircle()
{
    //Ищем для вершин диаграммы вороного

    CircleCenter = QPointF();

    QLineF DistanceLine;

    this->CircleRadius = 0;

    //Перебераем все расстояния от краев ребра диаграммы воронова до точки к которой принадлежит это ребро
    for(int i = 0; i < this->VoronoyLineArray.length(); i++)
    {
        QPointF FistIntersect;
        QPointF SecondIntersect;

        QPointF NeedPoint1 = QPointF(VoronoyLineArray.at(i).First.x() + 9999999999999999.0, VoronoyLineArray.at(i).First.y());
        QPointF NeedPoint2 = QPointF(VoronoyLineArray.at(i).First.x() - 9999999999999999.0, VoronoyLineArray.at(i).First.y());

        QLineF NeedLine = QLineF(NeedPoint1, NeedPoint2);

        int NextIndex = 0;

        //Проверяем лежит ли конец ребра в выпуклой оболочке
        for(int j = 0; j < ShellPoints.length() - 1; j++)
        {
            QPointF Start = QPointF(ShellPoints[j].get_X(), ShellPoints[j].get_Y());
            QPointF Finish = QPointF(ShellPoints[j + 1].get_X(), ShellPoints[j + 1].get_Y());

            QLineF NeedShellLine = QLineF(Start, Finish);

            if (NeedLine.intersect(NeedShellLine, &FistIntersect) == QLineF::BoundedIntersection)
            {
                NextIndex = j + 1;
                break;
            }
        }

        for(int j = NextIndex; j < ShellPoints.length() - 1; j++)
        {
            QPointF Start = QPointF(ShellPoints[j].get_X(), ShellPoints[j].get_Y());
            QPointF Finish = QPointF(ShellPoints[j + 1].get_X(), ShellPoints[j + 1].get_Y());

            QLineF NeedShellLine = QLineF(Start, Finish);

            if (NeedLine.intersect(NeedShellLine, &SecondIntersect) == QLineF::BoundedIntersection)
                break;

        }


        if(!((VoronoyLineArray.at(i).First.x() < FistIntersect.x() && VoronoyLineArray.at(i).First.x() < SecondIntersect.x()) || (VoronoyLineArray.at(i).First.x() > FistIntersect.x() && VoronoyLineArray.at(i).First.x() > SecondIntersect.x())))
        {
            QPointF LeftPoint = QPointF(PointArray.at(VoronoyLineArray.at(i).IndLeft).X, PointArray.at(VoronoyLineArray.at(i).IndLeft).Y);

            DistanceLine =  QLineF(VoronoyLineArray.at(i).First, LeftPoint);

            double NeedRadius = DistanceLine.length();

            if(NeedRadius > CircleRadius)
            {
                CircleRadius = NeedRadius;
                CircleCenter = VoronoyLineArray.at(i).First;
            }

        }


        NeedPoint1 = QPointF(VoronoyLineArray.at(i).Second.x() + 9999999999999999.0, VoronoyLineArray.at(i).Second.y());
        NeedPoint2 = QPointF(VoronoyLineArray.at(i).Second.x() - 9999999999999999.0, VoronoyLineArray.at(i).Second.y());

        NeedLine = QLineF(NeedPoint1, NeedPoint2);

        NextIndex = 0;

        //Проверяем лежит ли конец ребра в выпуклой оболочке
        for(int j = 0; j < ShellPoints.length() - 1; j++)
        {
            QPointF Start = QPointF(ShellPoints[j].get_X(), ShellPoints[j].get_Y());
            QPointF Finish = QPointF(ShellPoints[j + 1].get_X(), ShellPoints[j + 1].get_Y());

            QLineF NeedShellLine = QLineF(Start, Finish);

            if (NeedLine.intersect(NeedShellLine, &FistIntersect)== QLineF::BoundedIntersection)
            {
                NextIndex = j + 1;
                break;
            }
        }

        for(int j = NextIndex; j < ShellPoints.length() - 1; j++)
        {
            QPointF Start = QPointF(ShellPoints[j].get_X(), ShellPoints[j].get_Y());
            QPointF Finish = QPointF(ShellPoints[j + 1].get_X(), ShellPoints[j + 1].get_Y());

            QLineF NeedShellLine = QLineF(Start, Finish);

            if (NeedLine.intersect(NeedShellLine, &SecondIntersect) == QLineF::BoundedIntersection)
                break;

        }


        if(!((VoronoyLineArray.at(i).Second.x() < FistIntersect.x() && VoronoyLineArray.at(i).Second.x() < SecondIntersect.x()) || (VoronoyLineArray.at(i).Second.x() > FistIntersect.x() && VoronoyLineArray.at(i).Second.x() > SecondIntersect.x())))
        {
            QPointF LeftPoint = QPointF(PointArray.at(VoronoyLineArray.at(i).IndLeft).X, PointArray.at(VoronoyLineArray.at(i).IndLeft).Y);

            DistanceLine =  QLineF(VoronoyLineArray.at(i).Second, LeftPoint);

            double NeedRadius = DistanceLine.length();

            if(NeedRadius > CircleRadius)
            {
                CircleRadius = NeedRadius;
                CircleCenter = VoronoyLineArray.at(i).Second;
            }

        }
    }


    //Ищем для пересечений ребер диаграмы вороного
    for (int i = 0; i < VoronoyLineArray.length(); i++)
    {
        QLineF VoronoyLine = QLineF(VoronoyLineArray.at(i).First, VoronoyLineArray.at(i).Second);

        for (int j = 0; j < ShellPoints.length() - 1; j++)
        {
            QPointF Start = QPointF(ShellPoints[j].get_X(), ShellPoints[j].get_Y());
            QPointF Finish = QPointF(ShellPoints[j + 1].get_X(), ShellPoints[j + 1].get_Y());

            QLineF NeedShellLine = QLineF(Start, Finish);

            QPointF IntersectPoint;

            //Если пересекаются
            if (VoronoyLine.intersect(NeedShellLine, &IntersectPoint) == QLineF::BoundedIntersection)
            {
                QLineF CenterToStart = QLineF(IntersectPoint, Start);
                QLineF CenterToFinish = QLineF(IntersectPoint, Finish);

                QPointF Left = QPointF(this->PointArray[VoronoyLineArray[i].IndLeft].get_X(), this->PointArray[VoronoyLineArray[i].IndLeft].get_Y());
                QPointF Right = QPointF(this->PointArray[VoronoyLineArray[i].IndRight].get_X(), this->PointArray[VoronoyLineArray[i].IndRight].get_Y());

                QLineF CenterToLeft = QLineF(IntersectPoint, Left);
                QLineF CenterToRight = QLineF(IntersectPoint, Right);

                QLineF MinimemLine = CenterToStart;

                if (CenterToFinish.length() < MinimemLine.length())
                    MinimemLine = CenterToFinish;

                if (CenterToLeft.length() < MinimemLine.length())
                    MinimemLine = CenterToLeft;

                if (CenterToRight.length() < MinimemLine.length())
                    MinimemLine = CenterToRight;


                if(MinimemLine.length() > this->CircleRadius)
                {
                    CircleRadius = MinimemLine.length();
                    CircleCenter = IntersectPoint;
                }
            }
        }
    }
}


void QVoronoyModel::GarvisGeneration(QList<QMyPoint> *ShellPoints, QList<QMyPoint> PointArray)
{
    //Ищем самую нижнюю, самую левую точку
    //if (PointArray.length() < 1)
      //  return;


    QMyPoint MinPoint = PointArray.at(0);
    int MinPointIndex = 0;

    for (int i = 0; i < PointArray.length(); i++)
    {
        if (PointArray[i].get_Y() < MinPoint.get_Y())
        {
                MinPoint = PointArray[i];
                MinPointIndex = i;
        }
        else if (PointArray[i].get_Y() == MinPoint.get_Y())
        {
               if( PointArray[i].get_X() < MinPoint.get_X())
               {
                   MinPoint = PointArray[i];
                   MinPointIndex = i;
               }
        }
    }


    ShellPoints->append(PointArray[MinPointIndex]);

    int X1 = -1;
    int Y1 = 0;
    int X2 = 0;
    int Y2 = 0;
    int NeedX2 = 0;
    int NeedY2 = 0;

    //Генерация массива точек оболочки
    for (int j = 0; j < PointArray.length(); j++)
    {
        double Angle = 360;
        int NextPointIndex = 0;

        for (int i = 0; i< PointArray.length(); i++)
        {
            double NextAngle;

            X2 = PointArray[i].get_X() - ShellPoints->last().get_X();
            Y2 = PointArray[i].get_Y() - ShellPoints->last().get_Y();


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

        ShellPoints->append(PointArray[NextPointIndex]);

        X1 = NeedX2;
        Y1 = NeedY2;

        if (NextPointIndex == MinPointIndex)
            break;
    }

    //ShellPoints->append(ShellPoints->at(0));
}
