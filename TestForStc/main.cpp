//QT 5.12.0, MinGW 7.3.0 x64
//Created by Pishcheta E.A. 08.2020

#include <QGuiApplication>
#include <QQmlContext>
#include <QQuickView>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <CalculatorForm.h>
#include <CalculatorModel.h>

int main(int argc, char *argv[])
{

    qRegisterMetaType<requestAction>("requestAction");

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));

    QQmlContext *context = engine.rootContext();

    //Объект формы
    QCalculatorForm *Form = new QCalculatorForm(context);

    //Объект модели
    QCalculatorModel *Model = new QCalculatorModel();

    QObject::connect(Form, &QCalculatorForm::sendRequest, Model, &QCalculatorModel::receiveRequest,Qt::QueuedConnection);

    context->setContextProperty("_Form", Form);


    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated, &app,

    [url](QObject *obj, const QUrl &objUrl)
    {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);

    Form->readSettings();


    return app.exec();
}
