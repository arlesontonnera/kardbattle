#include "card.h"

Card::Card()
{

}

void Card::setPower(unsigned int power)
{
    m_power = power;
}

void Card::setElement(Element element)
{
    m_element = element;
}

void Card::setStatus(Status status)
{
    m_status = status;
}

void Card::setAttackOrientation(AttackOrientation attackOrientation,
                                OrientationStatus orientationStatus)
{

    switch(attackOrientation)
    {
    case AttackOrientation::TOP: m_attackOrientation.topOrientationStatus
                = orientationStatus; break;
    case AttackOrientation::BOTTOM: m_attackOrientation.bottomOrientationStatus
                = orientationStatus; break;
    case AttackOrientation::LEFT: m_attackOrientation.leftOrientationStatus
                = orientationStatus; break;
    case AttackOrientation::RIGHT: m_attackOrientation.rightOrientationStatus
                = orientationStatus;
    }
}

unsigned int Card::getPower()
{
    return m_power;
}

Element Card::getElement()
{
    return m_element;
}

string Card::getElement_Str()
{
    string str;
    switch(m_element)
    {
    case Element::NEUTRAL: str = "NEUTRAL"; break;
    case Element::FIRE: str =  "FIRE"; break;
    case Element::ICE: str =  "ICE"; break;
    case Element::POISON: str =  "POISON";
    }
    return str;
}

Status Card::getStatus()
{
    return m_status;
}

string Card::getStatus_Str()
{
    string str;
    switch(m_status)
    {
    case Status::NEUTRAL: str = "NEUTRAL"; break;
    case Status::FIREFIGHTER: str =  "FIREFIGHTER"; break;
    case Status::FROZEN: str =  "FROZEN"; break;
    case Status::POISONED: str =  "POISONED";
    }
    return str;
}

OrientationStatus Card::getAttackOrientationStatus(AttackOrientation attackOrientation)
{
    OrientationStatus orientationStatus;
    switch(attackOrientation)
    {
    case AttackOrientation::TOP:
        orientationStatus = m_attackOrientation.topOrientationStatus; break;
    case AttackOrientation::BOTTOM:
        orientationStatus = m_attackOrientation.bottomOrientationStatus; break;
    case AttackOrientation::LEFT:
        orientationStatus = m_attackOrientation.leftOrientationStatus; break;
    case AttackOrientation::RIGHT:
        orientationStatus = m_attackOrientation.rightOrientationStatus;
    }
    return orientationStatus;
}

string Card::getAttackOrientationStatus_Str(AttackOrientation attackOrientation)
{
    string orientationStatusString;
    switch(getAttackOrientationStatus(attackOrientation))
    {
    case OrientationStatus::OFF: orientationStatusString = "OFF"; break;
    case OrientationStatus::NORMAL: orientationStatusString = "NORMAL"; break;
    case OrientationStatus::INVERTED: orientationStatusString = "INVERTED";
    }
    return orientationStatusString;
}
