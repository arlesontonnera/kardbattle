#include "card.h"

#include <random>
#include <iostream>
#include <algorithm>

Card::Card()
    :Card(0, AttackDirection{}, Card_element::None, Card_status::None)
{

}

Card::Card(const int power, const AttackDirection &attackDirection, const Card_element &element,
           const Card_status &status)
    : m_power(power)
    , m_attack_direction(attackDirection)
    , m_element(element)
    , m_status(status)
{

}

void Card::setCard(const int power, const AttackDirection &attack_direction,
                   const Card_element &element, const Card_status &status)
{
    setPower(power);
    setAttackDirection(attack_direction);
    setElement(element);
    setStatus(status);
}

Card Card::getNeutralCard()
{
    return Card(0, AttackDirection{}, Card_element::None, Card_status::None);
}

Card Card::getRandomCard()
{
    return Card(getRandomPower(), getRandomDirection(), getRandomElement(), Card_status::None);
}

void Card::setPower(const int power)
{
    m_power = (power > 0) ? power : 0;
}

int Card::getPower() const
{
    return m_power;
}

void Card::setPowerIncrement()
{
    ++m_power;
}

void Card::setPowerDecrement()
{
    if (m_power > 0) {
        --m_power;
    }
}

void Card::setAttackDirection(const AttackDirection &attack_direction)
{
    m_attack_direction = attack_direction;
}

AttackDirection Card::getAttackDirection() const
{
    return m_attack_direction;
}

void Card::setElement(const Card_element &element)
{
    m_element = element;
}

Card_element Card::getElement() const
{
    return m_element;
}

void Card::setStatus(const Card_status &status)
{
    m_status = status;
}

Card_status Card::getStatus() const
{
    return m_status;
}

int Card::getRandomPower()
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> power_r(1, 5);
    int randomPower = power_r(gen);

    return randomPower;
}

Card_element Card::getRandomElement()
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> element_r(0, 3);
    int element = element_r(gen);

    Card_element randomElement{Card_element::None};

    randomElement = (static_cast<Card_element>(element) == Card_element::Fire) ?
                Card_element::Fire
              :
                (static_cast<Card_element>(element) == Card_element::Ice) ?
                    Card_element::Ice
                  :
                    (static_cast<Card_element>(element) == Card_element::Poison) ?
                        Card_element::Poison : Card_element::None;
    return randomElement;
}

AttackDirection Card::getRandomDirection()
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> attack_r(0, 4);
    int quantity = attack_r(gen);

    AttackDirection attack{Card_attack_direction::Top, Card_attack_direction::Right,
                Card_attack_direction::Bottom, Card_attack_direction::Left};

    std::shuffle(attack.begin(), attack.end(), gen);

    attack.resize(static_cast<size_t>(quantity));

    return attack;
}

std::ostream& operator << (std::ostream &stream, const Card &card)
{
    stream << "Power: " << card.getPower() << "\n";

    if (!card.getAttackDirection().empty()) {
        for (const auto &i : card.getAttackDirection()) {
            stream << "Direction: ";
            stream << ((i == Card_attack_direction::Top) ?
                           "Top\n"
                         : (i == Card_attack_direction::Right) ?
                               "Right\n"
                             : (i == Card_attack_direction::Bottom) ?
                                   "Bottom\n"
                                 : /* Card_attack_orientation::Left */ "Left\n");
        }
    }

    stream << "Element: ";
    stream << ((card.getElement() == Card_element::Fire) ?
                   "Fire\n"
                 : (card.getElement() == Card_element::Ice) ?
                       "Ice\n"
                     : (card.getElement() == Card_element::Poison) ?
                           "Poison\n"
                         : "None\n");

    stream << "Status: ";
    stream << ((card.getStatus() == Card_status::Burned) ?
                   "Burned\n"
                 : (card.getStatus() == Card_status::Frozen) ?
                       "Frozen\n"
                     : (card.getStatus() == Card_status::Poisoned) ?
                           "Poisoned\n"
                         : "None\n");
    stream << "\n";
    return stream;
}
