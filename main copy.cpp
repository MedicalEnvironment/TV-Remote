#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "remotecontrol.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;

    RemoteControl remoteControl;

    // Expose the RemoteControl object to QML
    engine.rootContext()->setContextProperty("remoteControl", &remoteControl);

    // Load the QML file for the remote control
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
