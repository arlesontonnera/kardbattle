#include "card.h"

#include <random>
#include <iostream>

Card::Card()
    :Card(0, attackDir{}, Card_element::None, Card_status::None)
{

}

Card::Card(const int power, const attackDir &attackDirection, const Card_element &element,
           const Card_status &status)
    : m_power(power)
    , m_attack_direction(attackDirection)
    , m_element(element)
    , m_status(status)
{

}

void Card::setCard(const int power, const attackDir &attack_direction,
                   const Card_element &element, const Card_status &status)
{
    setPower(power);
    setAttackDirection(attack_direction);
    setElement(element);
    setStatus(status);
}

Card Card::makeNeutralCard()
{
    return Card(0, attackDir{}, Card_element::None, Card_status::None);
}

Card Card::makeRandomCard()
{
    Card out(randomPower(), randomDirection(), randomElement(), Card_status::None);

    return out;
}


int Card::power() const
{
    return m_power;
}

void Card::setPower(const int power)
{
    m_power = (power > 0) ? power : 0;
}

void Card::powerIncrement()
{
    ++m_power;
}

void Card::powerDecrement()
{
    if (m_power > 0) {
        --m_power;
    }
}

Card_element Card::element() const
{
    return m_element;
}

void Card::setElement(const Card_element &element)
{
    m_element = element;
}

Card_status Card::status() const
{
    return m_status;
}

void Card::setStatus(const Card_status &status)
{
    m_status = status;
}

int Card::randomPower()
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> power_r(1, 5);
    int power = power_r(gen);

    return power;
}

Card_element Card::randomElement()
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> element_r(0, 3);
    int element = element_r(gen);

    Card_element el{Card_element::None};

    el =   (static_cast<Card_element>(element) == Card_element::Fire)   ? Card_element::Fire
         : (static_cast<Card_element>(element) == Card_element::Ice)    ? Card_element::Ice
         : (static_cast<Card_element>(element) == Card_element::Poison) ? Card_element::Poison : Card_element::None;

    return el;
}

attackDir Card::randomDirection()
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> attack_r(0, 4);
    int qty = attack_r(gen);

    attackDir attack{Card_attack_direction::Top, Card_attack_direction::Right,
                             Card_attack_direction::Bottom, Card_attack_direction::Left};

    std::shuffle(attack.begin(), attack.end(), gen);

    attack.resize(static_cast<size_t>(qty));

    return attack;
}

attackDir Card::attackDirection() const
{
    return m_attack_direction;
}

void Card::setAttackDirection(const attackDir &attack_direction)
{
    m_attack_direction = attack_direction;
}

std::ostream& operator << (std::ostream &stream, const Card &card)
{
    stream << "Power: " << card.power() << "\n";

    if (!card.attackDirection().empty()) {
        for (const auto &i : card.attackDirection()) {

            stream << "Direction: ";

            stream << ((    i == Card_attack_direction::Top)    ? "Top\n"
                         : (i == Card_attack_direction::Right)  ? "Right\n"
                         : (i == Card_attack_direction::Bottom) ? "Bottom\n"
                         :    /* Card_attack_orientation::Left */   "Left\n");
        }
    }

    stream << "Element: ";
    stream << ((    card.element() == Card_element::Fire)   ? "Fire\n"
                 : (card.element() == Card_element::Ice)    ? "Ice\n"
                 : (card.element() == Card_element::Poison) ? "Poison\n" : "None\n");


    stream << "Status: ";
    stream << ((    card.status() == Card_status::Burned)   ? "Burned\n"
                 : (card.status() == Card_status::Frozen)   ? "Frozen\n"
                 : (card.status() == Card_status::Poisoned) ? "Poisoned\n" : "None\n");

    stream << "\n";
    return stream;
}
