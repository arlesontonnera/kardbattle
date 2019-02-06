#ifndef DECK_H
#define DECK_H

#include "card.h"

#include <QObject>

#include <stack>

class Deck
{
public:
    Deck(const int deck_size);
    ~Deck();

    void popCard();
    Card topCard() const;

signals:
    void cardPopped();

private:
    std::stack<Card> m_cards;
};

#endif // DECK_H
