#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "control/playerviewcontrol.h"
#include "players/playerbuilder.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    qRegisterMetaType<player::P2D>("player::P2D");
    qRegisterMetaType<player::Player>("player::Player");
    qRegisterMetaType<player::P2D*>("player::P2D*");

    QList<player::Player> players ({
                                       player::PlayerBuilder::build(player::PlayerType::TANK, 10, 10, true, 0),
                                       player::PlayerBuilder::build(player::PlayerType::SHIP, 18.8, 20, true, 0),
                                       player::PlayerBuilder::build(player::PlayerType::CHARACTER, 28.5, 30, true, 0),
                                       player::PlayerBuilder::build(player::PlayerType::NO_TYPE, 38.18, 40, false, 0),
                                   });

    qmlRegisterType<PlayerViewControl>("PlayerViewControl", 1, 0, "PlayerViewControl");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.setInitialProperties({{"playersLoaded", QVariant::fromValue(players)}});
    engine.load(url);  

    return app.exec();
}
