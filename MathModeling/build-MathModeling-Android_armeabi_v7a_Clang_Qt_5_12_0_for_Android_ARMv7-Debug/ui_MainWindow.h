/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <mygraphicsview.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout;
    MyGraphicsView *RegFind_graphicsView;
    QGridLayout *gridLayout_2;
    QLineEdit *pointCount_lineEdit;
    QLabel *label;
    QPushButton *GeneratePoints_pushButton;
    QComboBox *SearchMethod_comboBox;
    QGridLayout *gridLayout;
    QPushButton *counting_pushButton;
    QPushButton *pretreatment_pushButton;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_4;
    MyGraphicsView *ShellView_graphicsView;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *ShellPointCount_lineEdit;
    QComboBox *GenerateMethod_comboBox;
    QComboBox *BuildMethod_comboBox;
    QPushButton *GenerateShell_pushButton;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_5;
    MyGraphicsView *Voronoy_graphicsView;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *VoronoyPointCount_lineEdit;
    QPushButton *GenerateVoronoy_pushButton;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout_3;
    QLabel *label_2;
    QLabel *PretreatmentTime_label;
    QTableWidget *tableWidget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(677, 481);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(53, 53, 79, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(79, 79, 118, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(66, 66, 98, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(26, 26, 39, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(35, 35, 52, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush6(QColor(0, 0, 0, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
        QBrush brush7(QColor(255, 255, 220, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        QBrush brush8(QColor(255, 255, 255, 128));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
        MainWindow->setPalette(palette);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush6);
        QBrush brush9(QColor(0, 120, 215, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Highlight, brush9);
        palette1.setBrush(QPalette::Active, QPalette::HighlightedText, brush);
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Highlight, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Highlight, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
        tabWidget->setPalette(palette1);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout = new QVBoxLayout(tab);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        RegFind_graphicsView = new MyGraphicsView(tab);
        RegFind_graphicsView->setObjectName(QString::fromUtf8("RegFind_graphicsView"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush);
        QBrush brush10(QColor(127, 127, 127, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush10);
        QBrush brush11(QColor(170, 170, 170, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush11);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        QBrush brush12(QColor(0, 0, 0, 128));
        brush12.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush12);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush10);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush11);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush12);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush10);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush10);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush11);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush10);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush10);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush12);
        RegFind_graphicsView->setPalette(palette2);

        verticalLayout->addWidget(RegFind_graphicsView);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pointCount_lineEdit = new QLineEdit(tab);
        pointCount_lineEdit->setObjectName(QString::fromUtf8("pointCount_lineEdit"));
        pointCount_lineEdit->setInputMethodHints(Qt::ImhDigitsOnly);

        gridLayout_2->addWidget(pointCount_lineEdit, 0, 1, 1, 1);

        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        label->setPalette(palette3);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        GeneratePoints_pushButton = new QPushButton(tab);
        GeneratePoints_pushButton->setObjectName(QString::fromUtf8("GeneratePoints_pushButton"));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        QBrush brush13(QColor(255, 255, 255, 128));
        brush13.setStyle(Qt::NoBrush);
        palette4.setBrush(QPalette::Active, QPalette::PlaceholderText, brush13);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        QBrush brush14(QColor(255, 255, 255, 128));
        brush14.setStyle(Qt::NoBrush);
        palette4.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush14);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        QBrush brush15(QColor(255, 255, 255, 128));
        brush15.setStyle(Qt::NoBrush);
        palette4.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush15);
        GeneratePoints_pushButton->setPalette(palette4);

        verticalLayout->addWidget(GeneratePoints_pushButton);

        SearchMethod_comboBox = new QComboBox(tab);
        SearchMethod_comboBox->addItem(QString());
        SearchMethod_comboBox->addItem(QString());
        SearchMethod_comboBox->addItem(QString());
        SearchMethod_comboBox->setObjectName(QString::fromUtf8("SearchMethod_comboBox"));
        SearchMethod_comboBox->setEnabled(true);
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush);
        palette5.setBrush(QPalette::Active, QPalette::Light, brush);
        palette5.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette5.setBrush(QPalette::Active, QPalette::Dark, brush10);
        palette5.setBrush(QPalette::Active, QPalette::Mid, brush11);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette5.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush);
        palette5.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette5.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette5.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette5.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        palette5.setBrush(QPalette::Active, QPalette::PlaceholderText, brush12);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Dark, brush10);
        palette5.setBrush(QPalette::Inactive, QPalette::Mid, brush11);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette5.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush12);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush10);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Dark, brush10);
        palette5.setBrush(QPalette::Disabled, QPalette::Mid, brush11);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush10);
        palette5.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush10);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette5.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette5.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
        palette5.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush12);
        SearchMethod_comboBox->setPalette(palette5);

        verticalLayout->addWidget(SearchMethod_comboBox);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        counting_pushButton = new QPushButton(tab);
        counting_pushButton->setObjectName(QString::fromUtf8("counting_pushButton"));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        counting_pushButton->setPalette(palette6);

        gridLayout->addWidget(counting_pushButton, 0, 3, 1, 1);

        pretreatment_pushButton = new QPushButton(tab);
        pretreatment_pushButton->setObjectName(QString::fromUtf8("pretreatment_pushButton"));
        pretreatment_pushButton->setEnabled(true);
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        pretreatment_pushButton->setPalette(palette7);

        gridLayout->addWidget(pretreatment_pushButton, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_4 = new QVBoxLayout(tab_3);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        ShellView_graphicsView = new MyGraphicsView(tab_3);
        ShellView_graphicsView->setObjectName(QString::fromUtf8("ShellView_graphicsView"));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette8.setBrush(QPalette::Active, QPalette::Button, brush);
        palette8.setBrush(QPalette::Active, QPalette::Light, brush);
        palette8.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette8.setBrush(QPalette::Active, QPalette::Dark, brush10);
        palette8.setBrush(QPalette::Active, QPalette::Mid, brush11);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette8.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush);
        palette8.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette8.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette8.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette8.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        palette8.setBrush(QPalette::Active, QPalette::PlaceholderText, brush12);
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Dark, brush10);
        palette8.setBrush(QPalette::Inactive, QPalette::Mid, brush11);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette8.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette8.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette8.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
        palette8.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush12);
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush10);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::Dark, brush10);
        palette8.setBrush(QPalette::Disabled, QPalette::Mid, brush11);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush10);
        palette8.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush10);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette8.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette8.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
        palette8.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush12);
        ShellView_graphicsView->setPalette(palette8);

        verticalLayout_4->addWidget(ShellView_graphicsView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(tab_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        label_3->setPalette(palette9);

        horizontalLayout->addWidget(label_3);

        ShellPointCount_lineEdit = new QLineEdit(tab_3);
        ShellPointCount_lineEdit->setObjectName(QString::fromUtf8("ShellPointCount_lineEdit"));
        ShellPointCount_lineEdit->setInputMethodHints(Qt::ImhPreferNumbers);

        horizontalLayout->addWidget(ShellPointCount_lineEdit);


        verticalLayout_4->addLayout(horizontalLayout);

        GenerateMethod_comboBox = new QComboBox(tab_3);
        GenerateMethod_comboBox->addItem(QString());
        GenerateMethod_comboBox->addItem(QString());
        GenerateMethod_comboBox->addItem(QString());
        GenerateMethod_comboBox->setObjectName(QString::fromUtf8("GenerateMethod_comboBox"));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::Button, brush);
        palette10.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette10.setBrush(QPalette::Active, QPalette::Base, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette10.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette10.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        GenerateMethod_comboBox->setPalette(palette10);

        verticalLayout_4->addWidget(GenerateMethod_comboBox);

        BuildMethod_comboBox = new QComboBox(tab_3);
        BuildMethod_comboBox->addItem(QString());
        BuildMethod_comboBox->addItem(QString());
        BuildMethod_comboBox->setObjectName(QString::fromUtf8("BuildMethod_comboBox"));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::Button, brush);
        palette11.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette11.setBrush(QPalette::Active, QPalette::Base, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette11.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette11.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette11.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette11.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        BuildMethod_comboBox->setPalette(palette11);

        verticalLayout_4->addWidget(BuildMethod_comboBox);

        GenerateShell_pushButton = new QPushButton(tab_3);
        GenerateShell_pushButton->setObjectName(QString::fromUtf8("GenerateShell_pushButton"));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette12.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette12.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        GenerateShell_pushButton->setPalette(palette12);

        verticalLayout_4->addWidget(GenerateShell_pushButton);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        verticalLayout_5 = new QVBoxLayout(tab_4);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        Voronoy_graphicsView = new MyGraphicsView(tab_4);
        Voronoy_graphicsView->setObjectName(QString::fromUtf8("Voronoy_graphicsView"));
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette13.setBrush(QPalette::Active, QPalette::Button, brush);
        palette13.setBrush(QPalette::Active, QPalette::Light, brush);
        palette13.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette13.setBrush(QPalette::Active, QPalette::Dark, brush10);
        palette13.setBrush(QPalette::Active, QPalette::Mid, brush11);
        palette13.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette13.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette13.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette13.setBrush(QPalette::Active, QPalette::Base, brush);
        palette13.setBrush(QPalette::Active, QPalette::Window, brush);
        palette13.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette13.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette13.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette13.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        palette13.setBrush(QPalette::Active, QPalette::PlaceholderText, brush12);
        palette13.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette13.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::Dark, brush10);
        palette13.setBrush(QPalette::Inactive, QPalette::Mid, brush11);
        palette13.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette13.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette13.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette13.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette13.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
        palette13.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush12);
        palette13.setBrush(QPalette::Disabled, QPalette::WindowText, brush10);
        palette13.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette13.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette13.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette13.setBrush(QPalette::Disabled, QPalette::Dark, brush10);
        palette13.setBrush(QPalette::Disabled, QPalette::Mid, brush11);
        palette13.setBrush(QPalette::Disabled, QPalette::Text, brush10);
        palette13.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette13.setBrush(QPalette::Disabled, QPalette::ButtonText, brush10);
        palette13.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette13.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette13.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette13.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette13.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette13.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
        palette13.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush12);
        Voronoy_graphicsView->setPalette(palette13);

        verticalLayout_5->addWidget(Voronoy_graphicsView);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(tab_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        QPalette palette14;
        palette14.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette14.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        label_4->setPalette(palette14);

        horizontalLayout_2->addWidget(label_4);

        VoronoyPointCount_lineEdit = new QLineEdit(tab_4);
        VoronoyPointCount_lineEdit->setObjectName(QString::fromUtf8("VoronoyPointCount_lineEdit"));
        VoronoyPointCount_lineEdit->setInputMethodHints(Qt::ImhPreferNumbers);

        horizontalLayout_2->addWidget(VoronoyPointCount_lineEdit);


        verticalLayout_5->addLayout(horizontalLayout_2);

        GenerateVoronoy_pushButton = new QPushButton(tab_4);
        GenerateVoronoy_pushButton->setObjectName(QString::fromUtf8("GenerateVoronoy_pushButton"));
        QPalette palette15;
        palette15.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette15.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette15.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        GenerateVoronoy_pushButton->setPalette(palette15);

        verticalLayout_5->addWidget(GenerateVoronoy_pushButton);

        tabWidget->addTab(tab_4, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QPalette palette16;
        palette16.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette16.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette16.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        label_2->setPalette(palette16);

        gridLayout_3->addWidget(label_2, 0, 0, 1, 1);

        PretreatmentTime_label = new QLabel(tab_2);
        PretreatmentTime_label->setObjectName(QString::fromUtf8("PretreatmentTime_label"));
        QPalette palette17;
        palette17.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette17.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette17.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        PretreatmentTime_label->setPalette(palette17);

        gridLayout_3->addWidget(PretreatmentTime_label, 0, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout_3);

        tableWidget = new QTableWidget(tab_2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        QPalette palette18;
        palette18.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette18.setBrush(QPalette::Active, QPalette::Button, brush);
        palette18.setBrush(QPalette::Active, QPalette::Light, brush);
        palette18.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette18.setBrush(QPalette::Active, QPalette::Dark, brush10);
        palette18.setBrush(QPalette::Active, QPalette::Mid, brush11);
        palette18.setBrush(QPalette::Active, QPalette::Text, brush6);
        palette18.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette18.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette18.setBrush(QPalette::Active, QPalette::Base, brush);
        palette18.setBrush(QPalette::Active, QPalette::Window, brush);
        palette18.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette18.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette18.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette18.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        palette18.setBrush(QPalette::Active, QPalette::PlaceholderText, brush12);
        palette18.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette18.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette18.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette18.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette18.setBrush(QPalette::Inactive, QPalette::Dark, brush10);
        palette18.setBrush(QPalette::Inactive, QPalette::Mid, brush11);
        palette18.setBrush(QPalette::Inactive, QPalette::Text, brush6);
        palette18.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette18.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette18.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette18.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette18.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette18.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette18.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette18.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
        palette18.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush12);
        palette18.setBrush(QPalette::Disabled, QPalette::WindowText, brush10);
        palette18.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette18.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette18.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette18.setBrush(QPalette::Disabled, QPalette::Dark, brush10);
        palette18.setBrush(QPalette::Disabled, QPalette::Mid, brush11);
        palette18.setBrush(QPalette::Disabled, QPalette::Text, brush10);
        palette18.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette18.setBrush(QPalette::Disabled, QPalette::ButtonText, brush10);
        palette18.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette18.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette18.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        palette18.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette18.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette18.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
        palette18.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush12);
        tableWidget->setPalette(palette18);

        verticalLayout_3->addWidget(tableWidget);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_2->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pointCount_lineEdit->setText(QApplication::translate("MainWindow", "1000", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\202\320\276\321\207\320\265\320\272", nullptr));
        GeneratePoints_pushButton->setText(QApplication::translate("MainWindow", "\320\241\320\263\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\202\320\276\321\207\320\272\320\270", nullptr));
        SearchMethod_comboBox->setItemText(0, QApplication::translate("MainWindow", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274: \320\242\321\200\320\270\320\262\320\270\320\260\320\273\321\214\320\275\321\213\320\271", nullptr));
        SearchMethod_comboBox->setItemText(1, QApplication::translate("MainWindow", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274: \320\234\320\265\321\202\320\276\320\264 \320\233\320\276\320\272\321\203\321\201\320\276\320\262", nullptr));
        SearchMethod_comboBox->setItemText(2, QApplication::translate("MainWindow", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274: k-D \320\264\320\265\321\200\320\265\320\262\320\276", nullptr));

        counting_pushButton->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\264\321\201\321\207\320\270\321\202\320\260\321\202\321\214", nullptr));
        pretreatment_pushButton->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\265\320\264\320\276\320\261\321\200\320\260\320\261\320\276\321\202\320\272\320\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\320\240\320\265\320\263\320\270\320\276\320\275\320\260\320\273\321\214\320\275\321\213\320\271 \320\277\320\276\320\270\321\201\320\272", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\202\320\276\321\207\320\265\320\272:", nullptr));
        ShellPointCount_lineEdit->setText(QApplication::translate("MainWindow", "1000", nullptr));
        GenerateMethod_comboBox->setItemText(0, QApplication::translate("MainWindow", "\320\234\320\265\321\202\320\276\320\264 \320\263\320\265\320\275\320\265\321\200\320\260\321\206\320\270\320\270: \320\237\321\200\321\217\320\274\320\276\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272", nullptr));
        GenerateMethod_comboBox->setItemText(1, QApplication::translate("MainWindow", "\320\234\320\265\321\202\320\276\320\264 \320\263\320\265\320\275\320\265\321\200\320\260\321\206\320\270\320\270: \320\232\321\200\321\203\320\263", nullptr));
        GenerateMethod_comboBox->setItemText(2, QApplication::translate("MainWindow", "\320\234\320\265\321\202\320\276\320\264 \320\263\320\265\320\275\320\265\321\200\320\260\321\206\320\270\320\270: \320\235\320\276\321\200\320\274\320\260\320\273\321\214\320\275\320\276\320\265 \321\200\320\260\321\201\320\277\321\200\320\265\320\264\320\265\320\273\320\265\320\275\320\270\320\265", nullptr));

        BuildMethod_comboBox->setItemText(0, QApplication::translate("MainWindow", "\320\241\320\277\320\276\321\201\320\276\320\261 \320\277\320\276\321\201\321\202\321\200\320\276\320\265\320\275\320\270\321\217: \320\224\320\266\320\260\321\200\320\262\320\270\321\201\320\260", nullptr));
        BuildMethod_comboBox->setItemText(1, QApplication::translate("MainWindow", "\320\241\320\277\320\276\321\201\320\276\320\261 \320\277\320\276\321\201\321\202\321\200\320\276\320\265\320\275\320\270\321\217: \320\223\321\200\321\215\321\205\320\265\320\274\320\260", nullptr));

        GenerateShell_pushButton->setText(QApplication::translate("MainWindow", "\320\241\320\263\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\202\320\276\321\207\320\272\320\270", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "\320\222\321\213\320\277\321\203\320\272\320\273\320\260\321\217 \320\276\320\261\320\276\320\273\320\276\321\207\320\272\320\260", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\202\320\276\321\207\320\265\320\272:", nullptr));
        VoronoyPointCount_lineEdit->setText(QApplication::translate("MainWindow", "100", nullptr));
        GenerateVoronoy_pushButton->setText(QApplication::translate("MainWindow", "\320\241\320\263\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\202\320\276\321\207\320\272\320\270", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "\320\224\320\270\320\260\320\263\321\200\320\260\320\274\320\274\320\260 \320\222\320\276\321\200\320\276\320\275\320\276\320\262\320\260", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217 \320\277\321\200\320\265\320\264\320\276\320\261\321\200\320\260\320\261\320\276\321\202\320\272\320\270:", nullptr));
        PretreatmentTime_label->setText(QApplication::translate("MainWindow", "00", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\320\241\320\262\320\276\320\264\320\272\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
