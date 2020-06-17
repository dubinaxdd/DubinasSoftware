#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "QMessageBox"

#include "MyGraphicsView.h"

#include "QCursor"
#include "QGraphicsScene"

#include "QTableWidgetItem"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qRegisterMetaType <Method> ("Method");

    this->Model = new MainModel(ui->RegFind_graphicsView);

    this->ShellModel = new QShellModel(ui->ShellView_graphicsView, this);

    this->VoronoyModel = new QVoronoyModel(ui->Voronoy_graphicsView, this);

    QObject::connect(this, &MainWindow::send_GeneratePoints, this->Model, &MainModel::RandomizePoints, Qt::QueuedConnection);
    QObject::connect(this, &MainWindow::send_Counting, this->Model, &MainModel::Counting, Qt::QueuedConnection);
    QObject::connect(this, &MainWindow::send_Pretreatment, this->Model, &MainModel::Pretreatment, Qt::QueuedConnection);

    QObject::connect(this->ui->RegFind_graphicsView, &MyGraphicsView::mousePress, this, &MainWindow::onGraphicsViewMousePress, Qt::QueuedConnection);
    QObject::connect(this->ui->RegFind_graphicsView, &MyGraphicsView::mouseRelease, this, &MainWindow::onGraphicsViewMouseRelease, Qt::QueuedConnection);
    QObject::connect(this->ui->RegFind_graphicsView, &MyGraphicsView::mouseMove, this, &MainWindow::onGraphicsViewMouseMove, Qt::QueuedConnection);


    QObject::connect(this, &MainWindow::send_MousePress, this->Model, &MainModel::receiveMousePress, Qt::QueuedConnection);
    QObject::connect(this, &MainWindow::send_MouseRelease, this->Model, &MainModel::receiveMouseRelease, Qt::QueuedConnection);
    QObject::connect(this, &MainWindow::send_MouseMove, this->Model, &MainModel::receiveMouseMove, Qt::QueuedConnection);

    QObject::connect(this, &MainWindow::send_formSizeChanged, this->Model, &MainModel::receiveFormSizeChanged, Qt::QueuedConnection);

    QObject::connect(this->Model, &MainModel::sendPretreatmentEnded, this, &MainWindow::receivePretreatmetEnded, Qt::QueuedConnection);
    QObject::connect(this->Model, &MainModel::sendCountingEnded, this, &MainWindow::receiveCountingEnded, Qt::QueuedConnection);
    QObject::connect(this, &MainWindow::send_formSizeChanged, this->ShellModel, &QShellModel::receiveFormSizeChanged, Qt::QueuedConnection);

    QObject::connect(this->ShellModel, &QShellModel::SendTime, this, &MainWindow::receiveShellBuildTime, Qt::QueuedConnection);

    QObject::connect(this, &MainWindow::send_VoronoyGeneratePoints, this->VoronoyModel, &QVoronoyModel::RandomizePoints, Qt::QueuedConnection);

    this->ui->pretreatment_pushButton->setVisible(false);


    int wid = static_cast<int>(this->ui->tableWidget->width()/3);

    this->ui->tableWidget->insertColumn(0);
    this->ui->tableWidget->setColumnWidth(0,wid);


    this->ui->tableWidget->insertColumn(1);
    this->ui->tableWidget->setColumnWidth(1,wid);

    this->ui->tableWidget->insertColumn(2);
    this->ui->tableWidget->setColumnWidth(2,wid);

    this->ui->tableWidget->insertRow(0);

    QTableWidgetItem *asd0 = new QTableWidgetItem();
    asd0->setText("Метод");
    this->ui->tableWidget->setItem(0,0,asd0);

    QTableWidgetItem *asd1 = new QTableWidgetItem();
    asd1->setText("Количество точек");
    this->ui->tableWidget->setItem(0,1,asd1);


    QTableWidgetItem *asd2 = new QTableWidgetItem();
    asd2->setText("Время");
    this->ui->tableWidget->setItem(0,2,asd2);






}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_GeneratePoints_pushButton_clicked()
{

    if(this->ui->SearchMethod_comboBox->currentIndex() == Method::Trivial)
    {
        this->ui->pretreatment_pushButton->setVisible(false);
        this->ui->counting_pushButton->setVisible(true);
    }
    else
    {
        this->ui->pretreatment_pushButton->setVisible(true);
        this->ui->counting_pushButton->setVisible(false);
    }

    emit this->send_GeneratePoints(this->ui->pointCount_lineEdit->text().toInt());
}


void MainWindow::onGraphicsViewMousePress()
{
    emit this->send_MousePress();
}


void MainWindow::onGraphicsViewMouseRelease()
{
    emit this->send_MouseRelease();
}

void MainWindow::onGraphicsViewMouseMove(int X, int Y)
{
    emit this->send_MouseMove(X,Y);
}


void MainWindow::on_counting_pushButton_clicked()
{

    this->send_Counting(static_cast<Method>(this->ui->SearchMethod_comboBox->currentIndex()));
}


void MainWindow::resizeEvent(QResizeEvent * event )
{
    Q_UNUSED(event);

    emit this->send_formSizeChanged();

    if(this->ui->SearchMethod_comboBox->currentIndex() == Method::Trivial)
    {
        this->ui->pretreatment_pushButton->setVisible(false);
        this->ui->counting_pushButton->setVisible(true);
    }
    else
    {
        this->ui->pretreatment_pushButton->setVisible(true);
        this->ui->counting_pushButton->setVisible(false);
    }


}

void MainWindow::on_pretreatment_pushButton_clicked()
{
    this->ui->pretreatment_pushButton->setVisible(false);
    this->ui->counting_pushButton->setVisible(true);

    emit send_Pretreatment(static_cast<Method>(this->ui->SearchMethod_comboBox->currentIndex()));
}


void MainWindow::receivePretreatmetEnded(int time)
{
    double ftime = time/1000.;

    PretreatmentTime = ftime;

    QMessageBox msgBox;
    msgBox.setWindowTitle("Предобработка");
    msgBox.setText("Затрачено времени: " +  QString("%1").arg(ftime, 4, 'd', 3) + " с");
    msgBox.exec();

    this->ui->PretreatmentTime_label->setText(QString("%1").arg(ftime, 4, 'd', 3) + " с");
}

void MainWindow::receiveCountingEnded(int CountFinded, int time , int PointCount, Method method)
{
    double asd = time/1000.;

    QMessageBox msgBox;
    msgBox.setWindowTitle("Подсчет точек");
    msgBox.setText("Количество точек в области: " + QString::number(CountFinded) + "\nЗатрачено времени: " + QString("%1").arg(asd, 4, 'd', 3) + " с");
    msgBox.exec();

    int RowCount = this->ui->tableWidget->model()->rowCount();
    //this->ui->tableView->model()->insertRow(RowCount);
    //this->ui->tableView->model()->setItemData()

    this->ui->tableWidget->insertRow(RowCount);

    QString MethodText;

    switch (method)
    {
        case Method::Trivial :
            MethodText = "Тривиальный";
        break;

        case Method::kDTree :
            MethodText = "k-D Дерево";
        break;

        case Method::Dominating :
            MethodText = "Метод Локусов";
        break;

    }

    int wid = static_cast<int>(this->ui->tableWidget->width()/4);
    int wid2 = static_cast<int>(this->ui->tableWidget->width()/3);

    this->ui->tableWidget->setColumnWidth(0,wid2);
    this->ui->tableWidget->setColumnWidth(1,wid);
    this->ui->tableWidget->setColumnWidth(2,wid);
    this->ui->tableWidget->setRowHeight(0,150);

    QTableWidgetItem *asd0 = new QTableWidgetItem();
    asd0->setText(MethodText);
    this->ui->tableWidget->setItem(RowCount,0,asd0);

    QTableWidgetItem *asd1 = new QTableWidgetItem();
    asd1->setText(QString::number(PointCount));
    this->ui->tableWidget->setItem(RowCount,1,asd1);


    QTableWidgetItem *asd2 = new QTableWidgetItem();
    asd2->setText(QString("%1").arg(asd + PretreatmentTime, 4, 'd', 3));
    this->ui->tableWidget->setItem(RowCount,2,asd2);
}

void MainWindow::receiveShellBuildTime(int time)
{
    double asd = time/1000.;

    QMessageBox msgBox;
    msgBox.setWindowTitle("Построение оболочки");
    msgBox.setText("Затрачено времени: " + QString("%1").arg(asd, 4, 'd', 3) + " с");
    msgBox.exec();
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    Q_UNUSED(index);

    int wid = static_cast<int>(this->ui->tableWidget->width()/4);
    int wid2 = static_cast<int>(this->ui->tableWidget->width()/3);
    this->ui->tableWidget->setColumnWidth(0,wid2);
    this->ui->tableWidget->setColumnWidth(1,wid);
    this->ui->tableWidget->setColumnWidth(2,wid);
    this->ui->tableWidget->setRowHeight(0,150);
}

void MainWindow::on_SearchMethod_comboBox_currentIndexChanged(int index)
{
    if(index == Method::Trivial)
    {
        this->ui->pretreatment_pushButton->setVisible(false);
        this->ui->counting_pushButton->setVisible(true);
        PretreatmentTime = 0.0;
    }
    else
    {
        this->ui->pretreatment_pushButton->setVisible(true);
        this->ui->counting_pushButton->setVisible(false);
    }
}

void MainWindow::on_GenerateShell_pushButton_clicked()
{
    this->ShellModel->RandomizePoints(ui->ShellPointCount_lineEdit->text().toInt(), static_cast<TGenerateMethod>(ui->GenerateMethod_comboBox->currentIndex()),static_cast<TGenerateType>(ui->BuildMethod_comboBox->currentIndex()));
}

void MainWindow::on_GenerateVoronoy_pushButton_clicked()
{
    emit send_VoronoyGeneratePoints(ui->VoronoyPointCount_lineEdit->text().toInt());
}
