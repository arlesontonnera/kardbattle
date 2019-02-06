#ifndef DISPLAY_H
#define DISPLAY_H

#include <QObject>
#include <iostream>
#include <string>
#include "card.h"
#include "deck.h"
#include "board.h"

class Display
{
public:
    Display(Deck cards, Board board);


    void displayPopCard();
    void displayBoard();

private:
    Deck m_cards;
    Board m_board;
    unsigned int m_frameWidth = 23;
    char m_placedPattern = '*';
    char m_int_placedPattern = '%';
};

#endif // DISPLAY_H
