#include "deck.h"

#include <iostream>

Deck::Deck(const int deck_size)
{
    for(auto i = 0; i < deck_size; ++i)
    {
        Card c;
        m_cards.push(c.getRandomCard());
    }
}

void Deck::pop()
{
    m_cards.pop();
}

size_t Deck::size()
{
    return m_cards.size();
}

Card Deck::top()
{
    return m_cards.top();

}

bool Deck::empty()
{
    return m_cards.empty();
}

