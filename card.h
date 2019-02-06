#ifndef CARD_H
#define CARD_H

#include <vector>
#include <random>

enum class Card_element {None, Fire, Ice, Poison};
enum class Card_status  {None, Burned, Frozen, Poisoned};
enum class Card_attack_direction {Top, Right, Bottom, Left};

using attackDir = std::vector<Card_attack_direction>;

class Card
{
public:
    Card();
    Card(const int power, const attackDir &attackDirection, const Card_element &element, const Card_status &status);

    void setCard(const int power, const attackDir &attackDirection = attackDir{},
                 const Card_element &element = Card_element::None, const Card_status &status = Card_status::None);

    Card makeNeutralCard();
    Card makeRandomCard();

    int power() const;
    void setPower(const int power);

    void powerIncrement();
    void powerDecrement();

    attackDir attackDirection() const;
    void setAttackDirection(const attackDir &attackDirection);

    Card_element element() const;
    void setElement(const Card_element &element);

    Card_status status() const;
    void setStatus(const Card_status &status);

    friend std::ostream& operator << (std::ostream &stream, const Card &card);

private:
    int m_power;
    std::vector<Card_attack_direction> m_attack_direction;
    Card_element m_element;
    Card_status m_status;

    int randomPower();
    Card_element randomElement();
    attackDir randomDirection();
};

#endif // CARD_H
