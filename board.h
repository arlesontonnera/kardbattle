#ifndef BOARD_H
#define BOARD_H

#include <QObject>
#include <vector>

#include "card.h"

enum class EdgePosition : int {
    TopLeft,      TopMiddle,      TopRight,
    MiddleLeft,   MiddleMiddle,   MiddleRight,
    BottonLeft,   BottonMiddle,   BottonRight
};

struct BoardElement
{
    friend class Board;
private:
    BoardElement(const int index, const int rows, const int columns);

    void setCard(const Card &card);

    int getRow();
    int getColumn();

    bool isEdge();

    bool isTop();
    bool isBotton();
    bool isLeft();
    bool isRight();

    int getTopIndex();
    int getBottonIndex();
    int getLeftIndex();
    int getRightIndex();

    void setEdgePosition();
    void makeAdjacents();

    Card m_card;
    EdgePosition m_edgePosition;
    std::vector<int> m_adjacents;
    int m_index;
    int m_rows;
    int m_columns;
};

class Board : public QObject
{
    Q_OBJECT

signals:

    void powerChanged(const int power);

public slots:
    void getPower(const int index);
//    int getElement(const int index) const;
//    int getStatus(const int index) const;
//    bool isAttackDirectionTop(const int index) const;
//    bool isAttackDirectionRight(const int index) const;
//    bool isAttackDirectionBottom(const int index) const;
//    bool isAttackDirectionLeft(const int index) const;

public:
    Board(const int rows, const int columns);

    bool isFull();
    void setBoardElement(const int index, const Card card);

private:
    int m_rows;
    int m_columns;
    std::vector<BoardElement> m_boardElements;
};

#endif // BOARD_H
