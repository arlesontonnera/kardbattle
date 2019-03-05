#ifndef CARD_H
#define CARD_H

#include <vector>
#include <random>

enum class Card_attack_direction {Top, Right, Bottom, Left};
enum class Card_element {None, Fire, Ice, Poison};
enum class Card_status  {None, Burned, Frozen, Poisoned};

using AttackDirection = std::vector<Card_attack_direction>;

class Card
{
public:
    Card();
    Card(const int power, const AttackDirection &attackDirection, const Card_element &element,
         const Card_status &status);

    void setCard(const int power, const AttackDirection &attackDirection = AttackDirection{},
                 const Card_element &element = Card_element::None, const Card_status &status = Card_status::None);

    Card getNeutralCard();
    Card getRandomCard();

    void setPower(const int power);
    int getPower() const;

    void setPowerIncrement();
    void setPowerDecrement();

    void setAttackDirection(const AttackDirection &attackDirection);
    AttackDirection getAttackDirection() const;

    void setElement(const Card_element &element);
    Card_element getElement() const;

    void setStatus(const Card_status &status);
    Card_status getStatus() const;

    friend std::ostream& operator << (std::ostream &stream, const Card &card);

private:
    int m_power;
    std::vector<Card_attack_direction> m_attack_direction;
    Card_element m_element;
    Card_status m_status;

    int getRandomPower();
    Card_element getRandomElement();
    AttackDirection getRandomDirection();
};

#endif // CARD_H
