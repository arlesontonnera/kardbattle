#ifndef BOARD_H
#define BOARD_H

#include <QObject>
#include <iostream>
#include <string>
#include "card.h"
#include "deck.h"

class Board
{
private:
    struct BoardElement {
        bool isPlaced = false;
        unsigned int index;
        Card card;
    };
    unsigned int m_boardLines;
    unsigned int m_boardColumns;
    vector<vector<BoardElement>> m_boardCards;
public:
    Board(unsigned int lines, unsigned int columns);

    void setBoardData(Deck &cards, unsigned int line, unsigned int column);

    vector<vector<BoardElement>> getBoardCards();
    unsigned int getBoardLines();
    unsigned int getBoardColumns();

    BoardElement getAdjacentCard(AttackOrientation attackOrientation,
                                  unsigned int line, unsigned int column);
};

#endif // BOARD_H
