#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "backend.h"
#include <QQmlContext>
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
//    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
//                     &app, [url](QObject *obj, const QUrl &objUrl) {
//        if (!obj && url == objUrl)
//            QCoreApplication::exit(-1);
//    }, Qt::QueuedConnection);
    Backend backend;
    engine.rootContext()->setContextProperty("backend",&backend);
    engine.load(url);


    if(engine.rootObjects().isEmpty())
    {
        return -1;
    }

    return app.exec();
}
