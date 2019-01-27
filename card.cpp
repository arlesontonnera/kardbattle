#include "card.h"

#include <random>

using namespace std;

Card::Card()
    :Card(0, vector<Card_attack_orientation>{}, Card_element::None, Card_status::None)
{

}

Card::Card(const int power, vector<Card_attack_orientation> attackDirection, const Card_element element,
           const Card_status status)
    : m_power(power)
    , m_attack_direction(attackDirection)
    , m_element(element)
    , m_status(status)
{

}

Card Card::getCard() const
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
    return Card(0, vector<Card_attack_orientation>{}, Card_element::None, Card_status::None);
}

Card Card::makeRandomCard()
{
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<> power_r(1, 6);
    int power = power_r(gen);

    uniform_int_distribution<> attack_r(0, 4);
    int attack_size = attack_r(gen);
    attack_orientation attack;

    for (int i = 0; i < attack_size; ++i) {

        int r = 0;

        r = attack_r(gen);
        auto f = find_if(attack.begin(), attack.end(), [=](int i){
            return (r == i);
        });



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
    return (m_power > 0) ? m_power : 0;
}

void Card::setPower(const int power)
{
    m_power = power;
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






//void Card::setPower(size_t power)
//{
//    m_power = power;
//}

//void Card::setElement(Element element)
//{
//    m_element = element;
//}

//Element Card::getElement() const
//{

//}

//void Card::setStatus(Status status)
//{
//    m_status = status;
//}

//void Card::setAttackOrientation(AttackOrientation attackOrientation,
//                                OrientationStatus orientationStatus)
//{

//    switch(attackOrientation)
//    {
//    case AttackOrientation::TOP: m_attackOrientation.topOrientationStatus
//                = orientationStatus; break;
//    case AttackOrientation::BOTTOM: m_attackOrientation.bottomOrientationStatus
//                = orientationStatus; break;
//    case AttackOrientation::LEFT: m_attackOrientation.leftOrientationStatus
//                = orientationStatus; break;
//    case AttackOrientation::RIGHT: m_attackOrientation.rightOrientationStatus
//                = orientationStatus;
//    }
//}

//size_t Card::getPower() const
//{
//    return m_power;
//}

//Element Card::getElement()
//{
//    return m_element;
//}

//string Card::getElement_Str()
//{
//    string str;
//    switch(m_element)
//    {
//    case Element::NEUTRAL: str = "NEUTRAL"; break;
//    case Element::FIRE: str =  "FIRE"; break;
//    case Element::ICE: str =  "ICE"; break;
//    case Element::POISON: str =  "POISON";
//    }
//    return str;
//}

//Status Card::getStatus() const
//{
//    return m_status;
//}

//string Card::getStatus_Str()
//{
//    string str;
//    switch(m_status)
//    {
//    case Status::NEUTRAL: str = "NEUTRAL"; break;
//    case Status::FIREFIGHTER: str =  "FIREFIGHTER"; break;
//    case Status::FROZEN: str =  "FROZEN"; break;
//    case Status::POISONED: str =  "POISONED";
//    }
//    return str;
//}

//OrientationStatus Card::getAttackOrientationStatus(AttackOrientation attackOrientation)
//{
//    OrientationStatus orientationStatus;
//    switch(attackOrientation)
//    {
//    case AttackOrientation::TOP:
//        orientationStatus = m_attackOrientation.topOrientationStatus; break;
//    case AttackOrientation::BOTTOM:
//        orientationStatus = m_attackOrientation.bottomOrientationStatus; break;
//    case AttackOrientation::LEFT:
//        orientationStatus = m_attackOrientation.leftOrientationStatus; break;
//    case AttackOrientation::RIGHT:
//        orientationStatus = m_attackOrientation.rightOrientationStatus;
//    }
//    return orientationStatus;
//}

//string Card::getAttackOrientationStatus_Str(AttackOrientation attackOrientation)
//{
//    string orientationStatusString;
//    switch(getAttackOrientationStatus(attackOrientation))
//    {
//    case OrientationStatus::OFF: orientationStatusString = "OFF"; break;
//    case OrientationStatus::NORMAL: orientationStatusString = "NORMAL"; break;
//    case OrientationStatus::INVERTED: orientationStatusString = "INVERTED";
//    }
//    return orientationStatusString;
//}
