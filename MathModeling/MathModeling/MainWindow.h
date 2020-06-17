#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "MainModel.h"
#include "ShellModel.h"
#include "VoronoyModel.h"
#include <qdebug.h>
#include "QMouseEvent"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_GeneratePoints_pushButton_clicked();

    void onGraphicsViewMousePress();

    void onGraphicsViewMouseRelease();

    void onGraphicsViewMouseMove(int X, int Y);

    void on_counting_pushButton_clicked();

    void resizeEvent(QResizeEvent * event );

    void on_pretreatment_pushButton_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_SearchMethod_comboBox_currentIndexChanged(int index);

    void on_GenerateShell_pushButton_clicked();

    void on_GenerateVoronoy_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    MainModel *Model;

    QShellModel *ShellModel;

    QVoronoyModel *VoronoyModel;

    double PretreatmentTime = 0.0;

   // virtual void mousePressEvent (QMouseEvent *event);
   // virtual void mouseReleaseEvent (QMouseEvent *event);



signals:
    void send_GeneratePoints(int pointsCount);

    void send_MousePress();

    void send_MouseRelease();

    void send_MouseMove(int X, int Y);

    void send_Counting(Method arg);

    void send_Pretreatment(Method arg);

    void send_formSizeChanged();

    void send_VoronoyGeneratePoints(int pointsCount);


public slots:

    void receivePretreatmetEnded(int time);

    void receiveCountingEnded(int CountFinded, int time , int PointCount, Method method);

    void receiveShellBuildTime(int time);


};

#endif // MAINWINDOW_H
