#include "card.h"

#include <random>
#include <iostream>

using namespace std;

Card::Card()
    :Card(0, attack_orientation{Card_attack_orientation::None}, Card_element::None, Card_status::None)
{

}

Card::Card(const int power, attack_orientation attackDirection, const Card_element element,
           const Card_status status)
    : m_power(power)
    , m_attack_direction(attackDirection)
    , m_element(element)
    , m_status(status)
{

}

Card& Card::getCard()
{
    return *this;
}

void Card::setCard(const int power, const attack_orientation &attack_direction)
{
    setCard(power, attack_direction, Card_element::None);
}

void Card::setCard(const int power, const attack_orientation &attack_direction, const Card_element &element)
{
    setCard(power, attack_direction, element, Card_status::None);
}

void Card::setCard(const int power, const attack_orientation &attack_direction, const Card_element &element, const Card_status &status)
{
    setPower(power);
    setAttack_direction(attack_direction);
    setElement(element);
    setStatus(status);
}

Card Card::makeNeutralCard()
{
    return Card(0, attack_orientation{Card_attack_orientation::None}, Card_element::None, Card_status::None);
}

Card Card::makeRandomCard()
{

    // TODO
    // Conferir essa função, escrevi mas não pude testar antes de arrumar o restante do código

    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<> power_r(1, 6);
    int power = power_r(gen);

    uniform_int_distribution<> attack_r(0, 4);
    int attack_size = attack_r(gen);
    attack_orientation attack;

    for (int i = 0; i < attack_size; ++i) {

        int r = 0;
        bool test = false;
        do {
            r = attack_r(gen);
            auto f = find_if(attack.begin(), attack.end(), [=](int i){
                return (r == i);
            });

            test = (f == attack.end());

        } while (test);


        switch (r) {
        case 0:
            attack.push_back(Card_attack_orientation::Top);
            break;
        case 1:
            attack.push_back(Card_attack_orientation::Right);
            break;
        case 2:
            attack.push_back(Card_attack_orientation::Botton);
            break;
        case 3:
            attack.push_back(Card_attack_orientation::Left);
            break;
        }
    }


    Card out(power, attack, Card_element::Fire, Card_status::None);

    return out;
}


int Card::getPower() const
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

Card_element Card::getElement() const
{
    return m_element;
}

void Card::setElement(const Card_element &element)
{
    m_element = element;
}

Card_status Card::getStatus() const
{
    return m_status;
}

void Card::setStatus(const Card_status &status)
{
    m_status = status;
}

attack_orientation Card::getAttack_direction() const
{
    return m_attack_direction;
}

void Card::setAttack_direction(const attack_orientation &attack_direction)
{
    m_attack_direction = attack_direction;
}

ostream& operator << (ostream &stream, const Card &card)
{
    stream << endl;
    stream << "Power: " << card.getPower() << "\n";

    for (size_t i = 0; i < card.getAttack_direction().size(); ++i) {
        switch (i) {
        case Card_attack_orientation::Top :
            stream << "Element: Top\n";
            break;
        case Card_attack_orientation::Right :
            stream << "Element: Right\n";
            break;
        case Card_attack_orientation::Botton :
            stream << "Element: Botton\n";
            break;
        case Card_attack_orientation::Left :
            stream << "Element: Left\n";
            break;
        }
    }

    return stream;
}
