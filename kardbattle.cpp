#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "deck.h"
#include "board.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    //qmlRegisterType<Deck>("Qml.Cpp_Deck",1,0,"Cpp_Deck");

    Deck cpp_Deck;
    engine.rootContext()->setContextProperty("cpp_Deck", &cpp_Deck);

    Board cpp_Board(4,4);
    cpp_Board.setBoardElement(0, cpp_Deck.getTop());
    cpp_Board.setBoardElement(2, cpp_Deck.getTop());
    engine.rootContext()->setContextProperty("cpp_Board", &cpp_Board);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
