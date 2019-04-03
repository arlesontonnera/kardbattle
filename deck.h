#ifndef DECK_H
#define DECK_H

#include "card.h"

#include <stack>

class Deck
{
public:
    Deck(const int deckSize);

    void pop();
    size_t getSize();
    Card top();
    bool isEmpty();

private:
    std::stack<Card> m_cards;
};

#endif // DECK_H
