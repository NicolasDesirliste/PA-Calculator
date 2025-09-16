#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "Calculator.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    Calculator calculator;
    engine.rootContext()->setContextProperty("calculator", &calculator);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("MyCalculator", "Main");

    return app.exec();
}
