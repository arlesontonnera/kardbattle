#include <QCoreApplication>
#include <iostream>

#include "card.h"
#include "deck.h"
#include "board.h"
#include "display.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Deck cards(30);
    Board board(3, 3);

    board.setBoardData(cards, 1, 1);
    board.setBoardData(cards, 1, 2);
    board.setBoardData(cards, 0, 0);
    board.setBoardData(cards, 2, 2);

    Display display(cards, board);
    //display.showDeckData();
    display.displayBoard();
    display.displayPopCard();

    return a.exec();
}
