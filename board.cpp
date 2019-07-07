#include <QtGlobal>
#include <cmath>

#include "board.h"

BoardElement::BoardElement(const int index, const int rows, const int columns)
    : m_index(index)
    , m_rows(rows)
    , m_columns(columns)
{
    makeAdjacents();
}

void BoardElement::setCard(const Card &card)
{
    m_card = card;
}

int BoardElement::getRow()
{
    return static_cast<int>(std::ceil(m_index / static_cast<float>(m_rows)));
}

int BoardElement::getColumn()
{
    return m_index % m_columns;
}

bool BoardElement::isEdge()
{
    return (isTop() or isBotton() or isLeft() or isRight());
}

bool BoardElement::isTop()
{
    return (getRow() == 0);
}

bool BoardElement::isBotton()
{
    return (getRow() == m_rows - 1);
}

bool BoardElement::isLeft()
{
    return (getColumn() == 0);
}

bool BoardElement::isRight()
{
    return (getColumn() == m_columns - 1);
}

int BoardElement::getTopIndex()
{
    return m_index - m_columns;
}

int BoardElement::getBottonIndex()
{
    return m_index + m_columns;
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

void Board::getPower(const int index)
{
    emit powerChanged(m_boardElements.at(index).m_card.getPower());
}

//int Board::getElement(const int index) const
//{
//    return static_cast<int>(m_boardElements.at(index).m_card.getElement());
//}

//int Board::getStatus(const int index) const
//{
//    return static_cast<int>(m_boardElements.at(index).m_card.getStatus());
//}

//bool Board::isAttackDirectionTop(const int index) const
//{
//    for (const auto &i : m_boardElements.at(index).m_card.getAttackDirection()) {
//        if (i == Card_attack_direction::Top) {
//            return true;
//        }
//    }
//    return false;
//}

//bool Board::isAttackDirectionRight(const int index) const
//{
//    for (const auto &i : m_boardElements.at(index).m_card.getAttackDirection()) {
//        if (i == Card_attack_direction::Right) {
//            return true;
//        }
//    }
//    return false;
//}

//bool Board::isAttackDirectionBottom(const int index) const
//{
//    for (const auto &i : m_boardElements.at(index).m_card.getAttackDirection()) {
//        if (i == Card_attack_direction::Bottom) {
//            return true;
//        }
//    }
//    return false;
//}

//bool Board::isAttackDirectionLeft(const int index) const
//{
//    for (const auto &i : m_boardElements.at(index).m_card.getAttackDirection()) {
//        if (i == Card_attack_direction::Left) {
//            return true;
//        }
//    }
//    return false;
//}

Board::Board(const int rows, const int columns)
    : m_rows(rows)
    , m_columns(columns)
{
    Q_ASSERT_X(m_rows <= 0 || m_columns <= 0, "Board Constructor", "Rows or Columns has a value zero or smaller");

    auto boardSize = rows * columns;

    for (auto i = 0; i < boardSize; ++i) {
        m_boardElements.push_back(BoardElement(i, rows, columns));
    }
}

bool Board::isFull()
{
    return (m_boardElements.size() >= static_cast<size_t>(m_rows * m_columns));
}

void Board::setBoardElement(const int index, const Card card)
{
    m_boardElements.at(index).setCard(card);
}
