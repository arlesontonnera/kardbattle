#include "player.h"

Player::Player(const QString &name, const int score)
    : m_name(name)
    , m_score(score)
{

}

QString Player::name() const
{
    return m_name;
}

void Player::setName(const QString &name)
{
    m_name = name;
}

int Player::score() const
{
    return m_score;
}

void Player::setScore(int score)
{
    m_score = score;
}

void Player::addScore()
{
    ++m_score;
}

void Player::subtractScore()
{
    if (m_score > 0) {
        --m_score;
    }
}

Player &Player::operator ++()
{
    addScore();

    return *this;
}

Player Player::operator ++(int)
{
    Player out(*this);

    out.addScore();

    return out;
}

Player &Player::operator --()
{
    subtractScore();

    return *this;
}

Player Player::operator --(int)
{
    Player out(*this);

    out.subtractScore();

    return out;
}
