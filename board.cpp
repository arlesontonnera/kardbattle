#include "board.h"

#include <QtGlobal>

#include <cmath>

using namespace std;

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
    return static_cast<int>(ceil(m_index / static_cast<float>(m_row)));
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
    if (rowPosition() == 0) {
        return true;
    }

    return false;
}

bool BoardElement::isBotton()
{
    if (rowPosition() == m_row - 1) {
        return true;
    }

    return false;
}

bool BoardElement::isLeft()
{
    if (columnPosition() == 0) {
        return true;
    }

    return false;
}

bool BoardElement::isRight()
{
    if (columnPosition() == m_column - 1) {
        return true;
    }

    return false;
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
    if (!isEdge()) {
        m_edgePosition = EdgePosition::MiddleMiddle;
    }
    else {
        if (isTop()) {
            if (isLeft()) {
                m_edgePosition = EdgePosition::TopLeft;
            }
            else if (isRight()) {
                m_edgePosition = EdgePosition::TopRight;
            }
            else {
                m_edgePosition = EdgePosition::TopMiddle;
            }
        }
        else if (isBotton()) {
            if (isLeft()) {
                m_edgePosition = EdgePosition::BottonLeft;
            }
            else if (isRight()) {
                m_edgePosition = EdgePosition::BottonRight;
            }
            else {
                m_edgePosition = EdgePosition::BottonMiddle;
            }
        }
        else {
            if (isLeft()) {
                m_edgePosition = EdgePosition::MiddleLeft;
            }
            else
            {
                m_edgePosition = EdgePosition::MiddleRight;
            }
        }
    }
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
    if (m_boardElement.size() >= static_cast<size_t>(m_row * m_column)) {
        return true;
    }

    return false;
}
