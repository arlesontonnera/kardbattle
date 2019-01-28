#ifndef DECK_H
#define DECK_H

#include "card.h"

#include <stack>

class Deck
{
public:
    Deck(const int deck_size);

    std::stack<Card> m_cards;
};

#endif // DECK_H
