#include "deck.h"

Deck::Deck(unsigned int totalCards)
{

    long long seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine gen (seed);
    std::uniform_int_distribution<int> distPower(1,5);
    std::uniform_int_distribution<int> distElement(0,3);
    std::uniform_int_distribution<int> distOrientationStatus(0,2);

    m_totalCards = totalCards;
    m_topCardIndex = static_cast <int> (m_totalCards - 1);
    m_cards.resize(m_totalCards);
    for(unsigned int index = 0; index < totalCards; index++) {
        m_cards[index].setPower(static_cast <unsigned int> (distPower(gen)));
        m_cards[index].setElement(static_cast <Element> (distElement(gen)));
        m_cards[index].setStatus(Status::NEUTRAL);
        m_cards[index].setAttackOrientation(AttackOrientation::TOP,
                                            static_cast <OrientationStatus>
                                            (distOrientationStatus(gen)));
        m_cards[index].setAttackOrientation(AttackOrientation::BOTTOM,
                                            static_cast <OrientationStatus>
                                            (distOrientationStatus(gen)));
        m_cards[index].setAttackOrientation(AttackOrientation::LEFT,
                                            static_cast <OrientationStatus>
                                            (distOrientationStatus(gen)));
        m_cards[index].setAttackOrientation(AttackOrientation::RIGHT,
                                            static_cast <OrientationStatus>
                                            (distOrientationStatus(gen)));
    }
}

void Deck::decrementTopCardIndex()
{
    m_topCardIndex--;
}

vector<Card> Deck::getCards()
{
    return m_cards;
}

unsigned int Deck::getPopCardIndex()
{
    return static_cast <unsigned int> (m_topCardIndex);
}

bool Deck::emptyDeck()
{
    return (m_topCardIndex == -1) ? true : false;
}
