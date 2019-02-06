#include "deck.h"

Deck::Deck(const int deck_size)
{
    for(auto i = 0; i < deck_size; ++i)
    {
        m_cards.push(Card().makeRandomCard());
    }
}

void Deck::popCard()
{
    m_cards.pop();
    emit cardPopped();
}

Card Deck::topCard() const
{
    return m_cards.top();
}


