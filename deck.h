#ifndef DECK_H
#define DECK_H

#include <QObject>
#include <stack>

#include "card.h"

class Deck : public QObject
{
    Q_OBJECT

    //Q_PROPERTY(int size READ getSize WRITE setSize NOTIFY sizeChanged)
    //Q_PROPERTY(int power READ getPower NOTIFY powerChanged)
    //Q_PROPERTY(int element READ getElement NOTIFY elementChanged)
    //Q_PROPERTY(int status READ getStatus NOTIFY statusChanged)
    //Q_PROPERTY(bool attackDirectionTop READ isAttackDirectionTop NOTIFY attackDirectionTopChanged)
    //Q_PROPERTY(bool attackDirectionRight READ isAttackDirectionRight NOTIFY attackDirectionRightChanged)
    //Q_PROPERTY(bool attackDirectionBottom READ isAttackDirectionBottom NOTIFY attackDirectionBottomChanged)
    //Q_PROPERTY(bool attackDirectionLeft READ isAttackDirectionLeft NOTIFY attackDirectionLeftChanged)

signals:
    void sizeChanged(const int size); // void sizeChanged();
    void powerChanged(const int power); // void powerChanged();
    void elementChanged(const int element); // void elementChanged();
    void statusChanged(const int status); // void statusChanged();
    void attackDirectionTopChanged(const bool attackDirectionTop); // void attackDirectionTopChanged();
    void attackDirectionRightChanged(const bool attackDirectionRight); // void attackDirectionRightChanged();
    void attackDirectionBottomChanged(const bool attackDirectionBottom); // void attackDirectionBottomChanged();
    void attackDirectionLeftChanged(const bool attackDirectionLeft); // void attackDirectionLeftChanged();

public slots: //
    void setSize(const int size); //
    void getSize(); //
    void getPower(); //
    void getElement(); //
    void getStatus(); //
    void attackDirectionTop(); //
    void attackDirectionRight(); //
    void attackDirectionBottom(); //
    void attackDirectionLeft(); //

public:

    explicit Deck(QObject *parent = nullptr);

    //void setSize(const int size);
    //int getSize() const;

    Card getTop() const;
    bool isEmpty() const;
    void pop();

    //int getPower() const;
    //int getElement() const;
    //int getStatus() const;
    //bool isAttackDirectionTop() const;
    //bool isAttackDirectionRight() const;
    //bool isAttackDirectionBottom() const;
    //bool isAttackDirectionLeft() const;

private:
    std::stack<Card> m_cards;
};

#endif // DECK_H
