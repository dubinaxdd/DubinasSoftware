#include "MainModel.h"
#include "QTime"
#include "qdebug.h"


MainModel::MainModel(MyGraphicsView *View)
{
    this->View = View;

    qRegisterMetaType<CoordinateWithIndex>("CoordinateWithIndex");

    FirstDraw = true;

    PointCount = 0;

    this->AnimationTimer = new QTimer();

    this->AnimationTimer->setInterval(100);

    QObject::connect(this->AnimationTimer, &QTimer::timeout, this, &MainModel::TimerTick, Qt::QueuedConnection);

    this->searchRectangle = new QSearchRectangle();

    pointsPixmap = new QPixmap();

    this->AnimationTimer->start();
}


MainModel::~MainModel()
{
}

//Рисование
void MainModel::Draw()
{
    if (FirstDraw)
    {
        RandomizePoints(0);
        FirstDraw = false;
    }

    this->pScene->clear();

    this->pScene->addPixmap(*this->pointsPixmap);

    this->searchRectangle->Draw(this->pScene, this->pointsPixmap);

    this->View->setScene(this->pScene);
}

void MainModel::TimerTick()
{
    this->Draw();
}

//Рандомайз точек
void MainModel::RandomizePoints(int pointCount)
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
}

//Сортировка слиянием
void MainModel::Merge(QList<CoordinateWithIndex> *coordArray, int first, int last)
{
    if (last <= first)
       return;
    int mid = first + (last - first) / 2;

    Merge(coordArray, first, mid);
    Merge(coordArray, mid + 1, last);

    QList<CoordinateWithIndex> bufferList = *coordArray;

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
       else if ((bufferList.at(j).Coord < bufferList.at(i).Coord))
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


//Предобработка
void MainModel::Pretreatment(Method method)
{
    this->AnimationTimer->stop();
    int time = 0;

    QTime timeSpent = QTime();

    switch (method)
    {
        case Method::Trivial :
        {
            break;
        }

        case Method::Dominating :
        {
            timeSpent.start();

            this->DominatingPointArray = QList<QMyPoint>();

            QList<CoordinateWithIndex> Xcoordinates;
            QList<CoordinateWithIndex> Ycoordinates;

            for (int i = 0; i < this->PointArray.length(); i++)
            {
                CoordinateWithIndex needCoord;
                needCoord.Coord = this->PointArray.at(i).X;
                needCoord.Ind = i;

                Xcoordinates.append(needCoord);

                needCoord.Coord = this->PointArray.at(i).Y;
                needCoord.Ind = i;
                Ycoordinates.append(needCoord);
            }

            CoordinateWithIndex needCoord;
            needCoord.Coord = this->View->width()+100000000;
            needCoord.Ind = this->PointArray.length();

            Xcoordinates.append(needCoord);

            needCoord.Coord = this->View->height()+100000000;
            Ycoordinates.append(needCoord);

            Merge(&Xcoordinates, 0, Xcoordinates.length()-1);
            Merge(&Ycoordinates, 0, Ycoordinates.length()-1);

            for (int i = 0; i < Xcoordinates.length(); i++)
            {
                for (int j = 0; j < Ycoordinates.length() ; j++)
                {

                    DominatingPointArray.append(QMyPoint(Xcoordinates[i].Coord,Ycoordinates[j].Coord));

                    int Dominating = 0;
                    if (!(i == 0 || j == 0))
                    {
                        {
                            if (Xcoordinates[i].Coord > this->PointArray[Ycoordinates[j-1].Ind].get_X())
                                Dominating = DominatingPointArray.at(DominatingPointArray.count()-2).Dominating + 1;
                            else
                                Dominating = DominatingPointArray.at(DominatingPointArray.count()-2).Dominating;
                        }
                    }

                    DominatingPointArray.last().Dominating = Dominating;
                }
            }

            time = timeSpent.elapsed();

            break;
        }

        case Method::kDTree :
        {

            timeSpent.start();

            QList<CoordinateWithIndex> Xcoordinates;

            for (int i = 0; i < this->PointArray.length(); i++)
            {
                CoordinateWithIndex needCoord;
                needCoord.Coord = this->PointArray.at(i).X;
                needCoord.Ind = i;

                Xcoordinates.append(needCoord);
            }

            Merge(&Xcoordinates, 0, Xcoordinates.length()-1);

            this->Tree.clear();

            if (Xcoordinates.length()>0)
                TreeBuild(Xcoordinates, -1,false, true, &this->Tree);

            time = timeSpent.elapsed();

            break;
        }

    }

    this->AnimationTimer->start();

    emit sendPretreatmentEnded(time);

}

void MainModel::TreeBuild(QList<CoordinateWithIndex> CoordArray, int IndOfParent, bool isLeftChildren, bool isX, QList<TreeElement> *Tree)
{

        int PointIndex = (CoordArray.length() - 1) / 2; //Получаем центральную точку


        QList<CoordinateWithIndex> LeftSector;
        QList<CoordinateWithIndex> RightSector;


        //Левая часть
        for(int i = 0; i < PointIndex; i++)
        {
                CoordinateWithIndex NeedCwi;

                if (isX)
                    NeedCwi.Coord = this->PointArray[CoordArray[i].Ind].get_Y();
                else
                    NeedCwi.Coord = this->PointArray[CoordArray[i].Ind].get_X();

                NeedCwi.Ind = CoordArray[i].Ind;

                LeftSector.append(NeedCwi);
        }

        Merge(&LeftSector, 0, LeftSector.length()-1);

        //Правая часть
        for(int i = PointIndex+1; i < CoordArray.length(); i++)
        {
                CoordinateWithIndex NeedCwi;

                if (isX)
                    NeedCwi.Coord = this->PointArray[CoordArray[i].Ind].get_Y();
                else
                    NeedCwi.Coord = this->PointArray[CoordArray[i].Ind].get_X();

                NeedCwi.Ind = CoordArray[i].Ind;

                RightSector.append(NeedCwi);
        }

        Merge(&RightSector, 0, RightSector.length()-1);

        //Добавляем элемент дерева
        TreeElement NewTreeElement;
        NewTreeElement.setIsX(isX);
        NewTreeElement.setCoord(CoordArray[PointIndex].Coord);
        NewTreeElement.setInd(CoordArray[PointIndex].Ind);

        //Создаем Левый потомок
        if (LeftSector.length()>0)
            NewTreeElement.setLeftEndTree(false);
        else
            NewTreeElement.setLeftEndTree(true);

        //Создаем Правый потомок
        if (RightSector.length()>0)
            NewTreeElement.setRightEndTree(false);
        else
            NewTreeElement.setRightEndTree(true);


        Tree->append(NewTreeElement);

        if (IndOfParent != -1)
        {
            if (isLeftChildren)
                this->Tree[IndOfParent].setLeftChild(Tree->length()-1);
            else
                this->Tree[IndOfParent].setRightChild(Tree->length()-1);
        }


        int parent = Tree->length()-1;

        //Запускаем рекусию для потомков
        if (LeftSector.length()>0)
            TreeBuild (LeftSector, parent, true, !isX,Tree);


        if (RightSector.length()>0)
            TreeBuild (RightSector, parent, false, !isX,Tree);

}



void MainModel::FastSearch(QMyPoint* point)
{
    //количество точек в массиве (интервал) через который начинается новая колонка с одинаковыми Х
    int deffX = this->PointArray.length()+1;
    //Левая граница поиска
    int leftIndex = 0;

    //Правая граница поиска
    int rightIndex = this->PointArray.length()- 2;



    while (true) {

        int midIndex = static_cast<int>((rightIndex - leftIndex)/2 + leftIndex);

        if (point->get_X() >= DominatingPointArray[(midIndex+1) * deffX].get_X())//>=
        {//Когда отрезаеются точки слева
            leftIndex = midIndex + 1;
        }
        else if (point->get_X() < DominatingPointArray[midIndex * deffX].get_X())//>
        {//Когда отрезаеются точки справа
            if (midIndex == 0)
                break;

            rightIndex = midIndex;
        }
        else if (point->get_X() >= DominatingPointArray[midIndex * deffX].get_X() && point->get_X() < DominatingPointArray[(midIndex+1) * deffX].get_X())//>= <
        {//Когда промежуток найден
            //Начинаем двоичный поиск по Y
            leftIndex = midIndex * deffX;
            rightIndex = leftIndex + deffX - 2;

            int leftLimitIndex = midIndex * deffX;

            while (true)
            {

                int midIndex = static_cast<int>((rightIndex - leftIndex)/2 + leftIndex);

                if (point->get_Y() >= DominatingPointArray[midIndex+1].get_Y())//>=
                {
                     leftIndex = midIndex + 1;
                }
                else if (point->get_Y() < DominatingPointArray[midIndex].get_Y())//<
                {
                    if (midIndex == leftLimitIndex)
                        break;

                    rightIndex = midIndex;
                }
                else if (point->get_Y() >= DominatingPointArray[midIndex].get_Y() && point->get_Y() < DominatingPointArray[midIndex+1].get_Y())//>= <
                {
                    point->Dominating = DominatingPointArray[midIndex + 1 + deffX].Dominating;
                    break;
                }
                else
                    break;
            }
            break;
        }
        else
            break;
    }
}

void MainModel::TreeCounting(int TreeElementIndex, int* PointCount, int MinX, int MaxX, int MinY, int MaxY)
{
    if (this->Tree[TreeElementIndex].getIsX())
    {
        int X = this->Tree[TreeElementIndex].getCoord();

        if (X>MinX && X<= MaxX)
        {
            int PointIndex = this->Tree[TreeElementIndex].getInd();

            int PointY = this->PointArray[PointIndex].get_Y();

            if (PointY > MinY && PointY <=MaxY)
                *PointCount  = *PointCount + 1;

            if (!this->Tree[TreeElementIndex].getLeftEndTree())
                TreeCounting(this->Tree[TreeElementIndex].getLeftChild(),PointCount, MinX, MaxX, MinY, MaxY);

            if (!this->Tree[TreeElementIndex].getRightEndTree())
                TreeCounting(this->Tree[TreeElementIndex].getRightChild(),PointCount, MinX, MaxX, MinY, MaxY);
        }
        else if (X<=MinX)
        {
            if (!this->Tree[TreeElementIndex].getRightEndTree())
                TreeCounting(this->Tree[TreeElementIndex].getRightChild(),PointCount, MinX, MaxX, MinY, MaxY);
        }
        else
        {
            if (!this->Tree[TreeElementIndex].getLeftEndTree())
                TreeCounting(this->Tree[TreeElementIndex].getLeftChild(),PointCount, MinX, MaxX, MinY, MaxY);
        }
    }
    else
    {
        int Y = this->Tree[TreeElementIndex].getCoord();

        if (Y>MinY && Y<= MaxY)
        {
            int PointIndex = this->Tree[TreeElementIndex].getInd();

            int PointX = this->PointArray[PointIndex].get_X();

            if (PointX > MinX && PointX <=MaxX)
                *PointCount  = *PointCount + 1;

            if (!this->Tree[TreeElementIndex].getLeftEndTree())
                TreeCounting(this->Tree[TreeElementIndex].getLeftChild(),PointCount, MinX, MaxX, MinY, MaxY);

            if (!this->Tree[TreeElementIndex].getRightEndTree())
                TreeCounting(this->Tree[TreeElementIndex].getRightChild(),PointCount, MinX, MaxX, MinY, MaxY);
        }
        else if (Y <= MinY)
        {
            if (!this->Tree[TreeElementIndex].getRightEndTree())
                TreeCounting(this->Tree[TreeElementIndex].getRightChild(),PointCount, MinX, MaxX, MinY, MaxY);

        }
        else
        {
            if (!this->Tree[TreeElementIndex].getLeftEndTree())
                TreeCounting(this->Tree[TreeElementIndex].getLeftChild(),PointCount, MinX, MaxX, MinY, MaxY);
        }
    }
}



//подсчет точек
void MainModel::Counting(Method method)
{

    int pointCount = 0;
    int time = 0;

    QTime timeSpent = QTime();
    if (this->PointArray.length() >0)
    {
        switch (method)
        {
            //Тривиальный способ
            case (Method::Trivial):
            {

                timeSpent.start();

                int searchMaxX;
                int searchMinX;
                int searchMaxY;
                int searchMinY;


                if (this->searchRectangle->SecondPoint->get_X() > this->searchRectangle->FirstPoint->get_X())
                {
                    searchMaxX = this->searchRectangle->SecondPoint->get_X();
                    searchMinX = this->searchRectangle->FirstPoint->get_X();
                }
                else
                {
                    searchMaxX = this->searchRectangle->FirstPoint->get_X();
                    searchMinX = this->searchRectangle->SecondPoint->get_X();
                }


                if (this->searchRectangle->SecondPoint->get_Y() > this->searchRectangle->FirstPoint->get_Y())
                {
                    searchMaxY = this->searchRectangle->SecondPoint->get_Y();
                    searchMinY = this->searchRectangle->FirstPoint->get_Y();
                }
                else
                {
                    searchMaxY = this->searchRectangle->FirstPoint->get_Y();
                    searchMinY = this->searchRectangle->SecondPoint->get_Y();
                }



                for(int i= 0; i < 1000 ; i++)
                {
                    pointCount = 0;

                    for (int i = 0; i < this->PointArray.count(); i++)
                    {
                        if ((this->PointArray[i].get_X() <= searchMaxX && this->PointArray[i].get_X() > searchMinX) && (this->PointArray[i].get_Y() <= searchMaxY && this->PointArray[i].get_Y() > searchMinY))
                        {
                            pointCount++;
                        }
                    }
                }
                time = timeSpent.elapsed();

                emit this->sendCountingEnded(pointCount, time, this->PointArray.length(), Method::Trivial);
                break;
            }

            //Метод локусов
            case (Method::Dominating):
            {
                timeSpent.start();

                QMyPoint LeftTopPoint;
                QMyPoint RightTopPoint;
                QMyPoint LeftBotomPoint;
                QMyPoint RightBotomPoint;

                int FirstX = this->searchRectangle->FirstPoint->get_X();
                int SecondX = this->searchRectangle->SecondPoint->get_X();
                int FirstY = this->searchRectangle->FirstPoint->get_Y();
                int SecondY = this->searchRectangle->SecondPoint->get_Y();


                if (FirstX > SecondX && FirstY > SecondY)
                {
                    LeftTopPoint = QMyPoint(SecondX, FirstY);
                    RightTopPoint = QMyPoint(FirstX, FirstY);
                    LeftBotomPoint = QMyPoint(SecondX, SecondY);
                    RightBotomPoint = QMyPoint(FirstX, SecondY);
                }

                if (FirstX <= SecondX && FirstY <= SecondY)
                {
                    LeftTopPoint = QMyPoint(FirstX, SecondY);
                    RightTopPoint = QMyPoint(SecondX, SecondY);
                    LeftBotomPoint = QMyPoint(FirstX, FirstY);
                    RightBotomPoint = QMyPoint(SecondX, FirstY);
                }

                if (FirstX > SecondX && FirstY < SecondY)
                {
                    LeftTopPoint = QMyPoint(SecondX, SecondY);
                    RightTopPoint = QMyPoint(FirstX, SecondY);
                    LeftBotomPoint = QMyPoint(SecondX, FirstY);
                    RightBotomPoint = QMyPoint(FirstX, FirstY);
                }

                if (FirstX <= SecondX && FirstY >= SecondY)
                {
                    LeftTopPoint = QMyPoint(FirstX, FirstY);
                    RightTopPoint = QMyPoint(SecondX, FirstY);
                    LeftBotomPoint = QMyPoint(FirstX, SecondY);
                    RightBotomPoint = QMyPoint(SecondX, SecondY);
                }


                //Двоичный поиск


                for (int i = 0; i < 1000; i++)
                {
                    FastSearch(&RightTopPoint);
                    FastSearch(&LeftTopPoint);
                    FastSearch(&RightBotomPoint);
                    FastSearch(&LeftBotomPoint);
                }


                pointCount = RightTopPoint.Dominating - LeftTopPoint.Dominating - RightBotomPoint.Dominating + LeftBotomPoint.Dominating;

                time = timeSpent.elapsed();


                emit this->sendCountingEnded(pointCount, time, this->PointArray.length(), Method::Dominating);
                break;
            }
            //КД Дерево
            case (Method::kDTree):
            {
                timeSpent.start();

                int searchMaxX;
                int searchMinX;
                int searchMaxY;
                int searchMinY;


                if (this->searchRectangle->SecondPoint->get_X() > this->searchRectangle->FirstPoint->get_X())
                {
                    searchMaxX = this->searchRectangle->SecondPoint->get_X();
                    searchMinX = this->searchRectangle->FirstPoint->get_X();
                }
                else
                {
                    searchMaxX = this->searchRectangle->FirstPoint->get_X();
                    searchMinX = this->searchRectangle->SecondPoint->get_X();
                }


                if (this->searchRectangle->SecondPoint->get_Y() > this->searchRectangle->FirstPoint->get_Y())
                {
                    searchMaxY = this->searchRectangle->SecondPoint->get_Y();
                    searchMinY = this->searchRectangle->FirstPoint->get_Y();
                }
                else
                {
                    searchMaxY = this->searchRectangle->FirstPoint->get_Y();
                    searchMinY = this->searchRectangle->SecondPoint->get_Y();
                }

                for (int i = 0; i < 1000; i++)
                {
                    pointCount = 0;
                    //Поиск по дереву
                    if (this->Tree.length()>0)
                        TreeCounting(0, &pointCount, searchMinX, searchMaxX, searchMinY, searchMaxY);
                }

                time = timeSpent.elapsed();

                emit this->sendCountingEnded(pointCount, time, this->PointArray.length(), Method::kDTree);
                break;
            }
        }
    }
}

//При нажатии кнопки мыши
void MainModel::receiveMousePress()
{
    this->searchRectangle->setMousePressed();
}

//При отпускании кнопки мыши
void MainModel::receiveMouseRelease()
{
    this->searchRectangle->setMouseReleased();
}

//Отслеживает координаты курсора
void MainModel::receiveMouseMove(int X, int Y)
{
    this->searchRectangle->setMousePosition(X,Y);
}

//При изменении размеров окна стираем все точки
void MainModel::receiveFormSizeChanged()
{
    this->RandomizePoints(0);
}

