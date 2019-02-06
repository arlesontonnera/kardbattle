#ifndef DECK_H
#define DECK_H

#include "card.h"

#include <stack>

class Deck
{
public:
    Deck(const int deck_size);

    void pop();
    size_t size();
    Card top();
    bool empty();

private:
    std::stack<Card> m_cards;
};

#endif // DECK_H
