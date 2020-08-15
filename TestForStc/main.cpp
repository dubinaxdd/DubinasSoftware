#include <QGuiApplication>
#include <CalculatorForm.h>
#include <QQmlContext>
#include <QQuickView>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));

    QQmlContext *context = engine.rootContext();

    QCalculatorForm Form(context);

    context->setContextProperty("_Form", &Form);


    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated, &app,

    [url](QObject *obj, const QUrl &objUrl)
    {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);


    return app.exec();
}
