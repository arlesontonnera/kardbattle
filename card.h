#ifndef CARD_H
#define CARD_H

#include <vector>

enum class Card_element  {None, Fire, Ice, Poison};
enum class Card_status  {None, Burned, Frozen, Poisoned};
enum Card_attack_orientation  {None, Top, Right, Botton, Left};

using attack_orientation = std::vector<Card_attack_orientation>;

class Card
{
public:
    Card();
    Card(const int power, attack_orientation attackDirection, const Card_element element,
         const Card_status status);

    Card& getCard();
    void setCard(const int power, const attack_orientation &attack_direction);
    void setCard(const int power, const attack_orientation &attack_direction, const Card_element &element);
    void setCard(const int power, const attack_orientation &attack_direction, const Card_element &element,
                 const Card_status &status);

    Card makeNeutralCard();
    Card makeRandomCard();

    int getPower() const;
    void setPower(const int power);

    void powerIncrement();
    void powerDecrement();

    attack_orientation getAttack_direction() const;
    void setAttack_direction(const attack_orientation &attack_direction);

    Card_element getElement() const;
    void setElement(const Card_element &element);

    Card_status getStatus() const;
    void setStatus(const Card_status &status);

    friend std::ostream& operator << (std::ostream &stream, const Card &card);

private:
    int m_power;
    std::vector<Card_attack_orientation> m_attack_direction;
    Card_element m_element;
    Card_status m_status;
};

#endif // CARD_H
