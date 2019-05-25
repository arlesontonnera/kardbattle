#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <memory>

class Card;

enum class EdgePosition : int {
    TopLeft,      TopMiddle,      TopRight,
    MiddleLeft,   MiddleMiddle,   MiddleRight,
    BottonLeft,   BottonMiddle,   BottonRight
};

struct BoardElement
{
    BoardElement(const int index, const int rowPosition, const int columnPosition);

    // Ainda estou em dúvida se será necessário esse m_isPlaced, pois o card é um ptr e inicia como nullptr
    // Então podemos verificar se a posição X a card == nullptr assim não haveria necessidade da variável bool
    bool m_isPlaced;
    std::shared_ptr<Card> m_card;
    std::vector<int> m_adjacents;

private:
    int m_index;
    int m_rows;
    int m_columns;

    EdgePosition m_edgePosition;

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
private:
    int m_rows;
    int m_columns;
    std::vector<BoardElement> m_boardElements;
};

#endif // BOARD_H
