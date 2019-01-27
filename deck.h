#ifndef DECK_H
#define DECK_H

#include <QObject>
#include <iostream>
#include <chrono>
#include <random>
#include "card.h"

class Deck
{
private:
    unsigned int m_totalCards;
    int m_topCardIndex;
    vector<Card> m_cards;
public:
    Deck(unsigned int totalCards);

    void decrementTopCardIndex();

    vector<Card> getCards();
    unsigned int getPopCardIndex();
    bool emptyDeck();
};

#endif // DECK_H
