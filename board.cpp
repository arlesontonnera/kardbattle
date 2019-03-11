#include "board.h"

#include <QtGlobal>

#include <cmath>

BoardElement::BoardElement(const int index, const int row, const int column)
    : m_isPlaced(false)
    , m_card(nullptr)
    , m_index(index)
    , m_row(row)
    , m_column(column)
{
    makeAdjacents();
}

int BoardElement::rowPosition()
{
    return static_cast<int>(std::ceil(m_index / static_cast<float>(m_row)));
}

int BoardElement::columnPosition()
{
    return m_index % m_column;
}

void BoardElement::makeAdjacents()
{
    setEdgePosition();

    switch (m_edgePosition) {
    case EdgePosition::MiddleMiddle:
        m_adjacents.push_back(topIndex());
        m_adjacents.push_back(bottonIndex());
        m_adjacents.push_back(leftIndex());
        m_adjacents.push_back(rightIndex());
        break;

    case EdgePosition::TopLeft:
        m_adjacents.push_back(bottonIndex());
        m_adjacents.push_back(rightIndex());
        break;

    case EdgePosition::TopMiddle:
        m_adjacents.push_back(bottonIndex());
        m_adjacents.push_back(leftIndex());
        m_adjacents.push_back(rightIndex());
        break;

    case EdgePosition::TopRight:
        m_adjacents.push_back(bottonIndex());
        m_adjacents.push_back(leftIndex());
        break;

    case EdgePosition::MiddleLeft:
        m_adjacents.push_back(topIndex());
        m_adjacents.push_back(bottonIndex());
        m_adjacents.push_back(rightIndex());
        break;

    case EdgePosition::MiddleRight:
        m_adjacents.push_back(topIndex());
        m_adjacents.push_back(bottonIndex());
        m_adjacents.push_back(leftIndex());
        break;

    case EdgePosition::BottonLeft:
        m_adjacents.push_back(topIndex());
        m_adjacents.push_back(rightIndex());
        break;

    case EdgePosition::BottonMiddle:
        m_adjacents.push_back(topIndex());
        m_adjacents.push_back(leftIndex());
        m_adjacents.push_back(rightIndex());
        break;

    case EdgePosition::BottonRight:
        m_adjacents.push_back(topIndex());
        m_adjacents.push_back(leftIndex());
        break;
    }
}

bool BoardElement::isEdge()
{
    if (isTop() or isBotton() or isLeft() or isRight()) {
        return true;
    }

    return false;
}

bool BoardElement::isTop()
{
    return (rowPosition() == 0);
}

bool BoardElement::isBotton()
{
    return (rowPosition() == m_row - 1);
}

bool BoardElement::isLeft()
{
    return (columnPosition() == 0);
}

bool BoardElement::isRight()
{
    return (columnPosition() == m_column - 1);
}

int BoardElement::topIndex()
{
    return m_index - m_column;
}

int BoardElement::bottonIndex()
{
    return m_index + m_column;
}

int BoardElement::leftIndex()
{
    return m_index - 1;
}

int BoardElement::rightIndex()
{
    return m_index + 1;
}

void BoardElement::setEdgePosition()
{
    m_edgePosition = !isEdge() ?
                EdgePosition::MiddleMiddle
              : isTop() and isLeft() ?
                    EdgePosition::TopLeft
                  : isTop() and isRight() ?
                        EdgePosition::TopRight
                      : isTop() ?
                            EdgePosition::TopMiddle

                          : isBotton() and isLeft() ?
                                EdgePosition::BottonLeft
                              : isBotton() and isRight() ?
                                    EdgePosition::BottonRight
                                  : isBotton() ?
                                        EdgePosition::BottonMiddle

                                      : isLeft() ?
                                            EdgePosition::MiddleLeft
                                          : /* isRight() */
                                            EdgePosition::MiddleRight;
}

Board::Board(const int row, const int column)
    : m_row(row)
    , m_column(column)
{
    Q_ASSERT_X(row <= 0 or column <= 0, "Board Constructor", "Rows or Columns has a value zero or smaller");

    auto boardSize = row * column;

    for (auto i = 0; i < boardSize; ++i) {
        m_boardElement.push_back(BoardElement(i, row, column));
    }
}

bool Board::isFull()
{
    return (m_boardElement.size() >= static_cast<size_t>(m_row * m_column));
}
