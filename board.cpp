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

int BoardElement::getRowPosition()
{
    return static_cast<int>(std::ceil(m_index / static_cast<float>(m_row)));
}

int BoardElement::getColumnPosition()
{
    return m_index % m_column;
}

bool BoardElement::isEdge()
{
    return (isTop() or isBotton() or isLeft() or isRight());
}

bool BoardElement::isTop()
{
    return (getRowPosition() == 0);
}

bool BoardElement::isBotton()
{
    return (getRowPosition() == m_row - 1);
}

bool BoardElement::isLeft()
{
    return (getColumnPosition() == 0);
}

bool BoardElement::isRight()
{
    return (getColumnPosition() == m_column - 1);
}

int BoardElement::getTopIndex()
{
    return m_index - m_column;
}

int BoardElement::getBottonIndex()
{
    return m_index + m_column;
}

int BoardElement::getLeftIndex()
{
    return m_index - 1;
}

int BoardElement::getRightIndex()
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

void BoardElement::makeAdjacents()
{
    setEdgePosition();

    switch (m_edgePosition) {
    case EdgePosition::MiddleMiddle:
        m_adjacents.push_back(getTopIndex());
        m_adjacents.push_back(getBottonIndex());
        m_adjacents.push_back(getLeftIndex());
        m_adjacents.push_back(getRightIndex());
        break;

    case EdgePosition::TopLeft:
        m_adjacents.push_back(getBottonIndex());
        m_adjacents.push_back(getRightIndex());
        break;

    case EdgePosition::TopMiddle:
        m_adjacents.push_back(getBottonIndex());
        m_adjacents.push_back(getLeftIndex());
        m_adjacents.push_back(getRightIndex());
        break;

    case EdgePosition::TopRight:
        m_adjacents.push_back(getBottonIndex());
        m_adjacents.push_back(getLeftIndex());
        break;

    case EdgePosition::MiddleLeft:
        m_adjacents.push_back(getTopIndex());
        m_adjacents.push_back(getBottonIndex());
        m_adjacents.push_back(getRightIndex());
        break;

    case EdgePosition::MiddleRight:
        m_adjacents.push_back(getTopIndex());
        m_adjacents.push_back(getBottonIndex());
        m_adjacents.push_back(getLeftIndex());
        break;

    case EdgePosition::BottonLeft:
        m_adjacents.push_back(getTopIndex());
        m_adjacents.push_back(getRightIndex());
        break;

    case EdgePosition::BottonMiddle:
        m_adjacents.push_back(getTopIndex());
        m_adjacents.push_back(getLeftIndex());
        m_adjacents.push_back(getRightIndex());
        break;

    case EdgePosition::BottonRight:
        m_adjacents.push_back(getTopIndex());
        m_adjacents.push_back(getLeftIndex());
        break;
    }
}

Board::Board(const int rows, const int columns)
    : m_rows(rows)
    , m_columns(columns)
{
    Q_ASSERT_X(rows <= 0 or columns <= 0, "Board Constructor", "Rows or Columns has a value zero or smaller");

    auto boardSize = rows * columns;

    for (auto i = 0; i < boardSize; ++i) {
        m_boardElements.push_back(BoardElement(i, rows, columns));
    }
}

bool Board::isFull()
{
    return (m_boardElements.size() >= static_cast<size_t>(m_rows * m_columns));
}
