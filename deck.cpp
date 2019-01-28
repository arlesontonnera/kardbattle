#include "deck.h"

Deck::Deck(const int deck_size)
{
    for(auto i = 0; i < deck_size; ++i)
    {
        m_cards.push(Card().makeRandomCard());
    }
}


