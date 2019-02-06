#ifndef PLAYER_H
#define PLAYER_H

#include <QString>

class Player
{
public:
    Player(const QString &name, const int score);

    QString name() const;
    void setName(const QString &name);

    int score() const;
    void setScore(int score);

    void addScore();
    void subtractScore();

    Player &operator ++();
    Player operator ++(int);

    Player &operator --();
    Player operator --(int);

private:
    QString m_name;
    int m_score;
};

#endif // PLAYER_H
