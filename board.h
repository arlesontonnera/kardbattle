#ifndef BOARD_H
#define BOARD_H

#include "card.h"

#include <vector>


enum class EdgePosition : int {
    TopLeft,      TopMiddle,      TopRight,
    MiddleLeft,   MiddleMiddle,   MiddleRight,
    BottonLeft,   BottonMiddle,   BottonRight
};

struct BoardElement
{
    BoardElement(const int index, const int rows, const int columns);

    void setCard(const Card &card);

private:
    Card m_card;
    EdgePosition m_edgePosition;
    std::vector<int> m_adjacents;

    int m_index;
    int m_rows;
    int m_columns;

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
};

class Board
{
public:
    Board(const int rows, const int columns);

    bool isFull();
    void setBoardElement(const int index, const Card &card);
private:
    int m_rows;
    int m_columns;
    std::vector<BoardElement> m_boardElements;
};

#endif // BOARD_H
