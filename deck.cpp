#include <iostream>

#include "deck.h"

Deck::Deck(QObject *parent) : QObject(parent)
{
    setSize(8); //Default value
}

//void Deck::setSize(const int size)
//{
//    for(auto i = 0; i < size; ++i)
//    {
//        Card card;
//        m_cards.push(card.getRandomCard());
//    }
//    emit sizeChanged();
//    emit powerChanged();
//    emit elementChanged();
//    emit statusChanged();
//    emit attackDirectionTopChanged();
//    emit attackDirectionRightChanged();
//    emit attackDirectionBottomChanged();
//    emit attackDirectionLeftChanged();
//}

//int Deck::getSize() const
//{
//    return m_cards.size();
//}

Card Deck::getTop() const
{
    return m_cards.top();
}

bool Deck::isEmpty() const
{
    return m_cards.empty();
}

void Deck::pop()
{
    m_cards.pop();
}

//int Deck::getPower() const
//{
//    return getTop().getPower();
//}

//int Deck::getElement() const
//{
//    return static_cast<int>(getTop().getElement());
//}

//int Deck::getStatus() const
//{
//    return static_cast<int>(getTop().getStatus());
//}

//bool Deck::isAttackDirectionTop() const
//{
//    for (const auto &i : getTop().getAttackDirection()) {
//        if (i == Card_attack_direction::Top) {
//            return true;
//        }
//    }
//    return false;
//}

//bool Deck::isAttackDirectionRight() const
//{
//    for (const auto &i : getTop().getAttackDirection()) {
//        if (i == Card_attack_direction::Right) {
//            return true;
//        }
//    }
//    return false;
//}

//bool Deck::isAttackDirectionBottom() const
//{
//    for (const auto &i : getTop().getAttackDirection()) {
//        if (i == Card_attack_direction::Bottom) {
//            return true;
//        }
//    }
//    return false;
//}

//bool Deck::isAttackDirectionLeft() const
//{
//    for (const auto &i : getTop().getAttackDirection()) {
//        if (i == Card_attack_direction::Left) {
//            return true;
//        }
//    }
//    return false;
//}

void Deck::setSize(const int size) //
{
    for(auto i = 0; i < size; ++i)
    {
        Card card;
        m_cards.push(card.getRandomCard());
    }
    emit sizeChanged(size);
}

void Deck::getSize()
{
    emit sizeChanged(m_cards.size());
}

void Deck::getPower() //
{
    emit powerChanged(m_cards.top().getPower());
}

void Deck::getElement() //
{
    emit elementChanged(static_cast<int>(m_cards.top().getElement()));
}

void Deck::getStatus() //
{
    emit statusChanged(static_cast<int>(m_cards.top().getStatus()));
}

void Deck::attackDirectionTop() //
{
    bool value = false;
    for (const auto &i : getTop().getAttackDirection()) {
        if (i == Card_attack_direction::Top) {
            value = true;
        }
    }
    emit attackDirectionTopChanged(value);
}

void Deck::attackDirectionRight() //
{
    bool value = false;
    for (const auto &i : getTop().getAttackDirection()) {
        if (i == Card_attack_direction::Right) {
            value = true;
        }
    }
    emit attackDirectionRightChanged(value);
}

void Deck::attackDirectionBottom() //
{
    bool value = false;
    for (const auto &i : getTop().getAttackDirection()) {
        if (i == Card_attack_direction::Bottom) {
            value = true;
        }
    }
    emit attackDirectionBottomChanged(value);
}

void Deck::attackDirectionLeft() //
{
    bool value = false;
    for (const auto &i : getTop().getAttackDirection()) {
        if (i == Card_attack_direction::Left) {
            value = true;
        }
    }
    emit attackDirectionLeftChanged(value);
}
