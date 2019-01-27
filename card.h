#ifndef CARD_H
#define CARD_H

#include <QObject>
#include <string>

using namespace std;

enum class Element  {NEUTRAL, FIRE, ICE, POISON};
enum class Status  {NEUTRAL, FIREFIGHTER, FROZEN, POISONED};
enum class AttackOrientation  {TOP, BOTTOM, LEFT, RIGHT};
enum class OrientationStatus  {OFF, NORMAL, INVERTED};

class Card
{
private:
    struct attackOrientationStruct {
        OrientationStatus topOrientationStatus;
        OrientationStatus bottomOrientationStatus;
        OrientationStatus leftOrientationStatus;
        OrientationStatus rightOrientationStatus;
    };

    unsigned int m_power;
    attackOrientationStruct m_attackOrientation;
    Element m_element;
    Status m_status;
public:
    Card();
    void setPower(unsigned int power);
    void setElement(Element elementlementlement);
    void setStatus(Status status);
    void setAttackOrientation(AttackOrientation attackOrientation,
                              OrientationStatus orientationStatus);

    unsigned int getPower();
    Element getElement();
    string getElement_Str();
    Status getStatus();
    string getStatus_Str();
    OrientationStatus getAttackOrientationStatus(AttackOrientation attackOrientation);
    string getAttackOrientationStatus_Str(AttackOrientation attackOrientation);
};

#endif // CARD_H
