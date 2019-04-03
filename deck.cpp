#include "deck.h"

#include <iostream>

Deck::Deck(const int deckSize)
{
    for(auto i = 0; i < deckSize; ++i)
    {
        Card card;
        m_cards.push(card.getRandomCard());
    }
}

void Deck::pop()
{
    m_cards.pop();
}

size_t Deck::getSize()
{
    return m_cards.size();
}

Card Deck::top()
{
    return m_cards.top();

}

bool Deck::isEmpty()
{
    return m_cards.empty();
}

