#include "board.h"

using namespace std;

Board::Board(unsigned int lines, unsigned int columns)
{
    m_boardLines = lines;
    m_boardColumns = columns;
    m_boardCards.resize(m_boardLines, vector<BoardElement>(m_boardColumns));
}

void Board::setBoardData(Deck &cards, unsigned int line, unsigned int column)
{
    m_boardCards[line][column].isPlaced = true;
    m_boardCards[line][column].index = cards.getPopCardIndex();
    m_boardCards[line][column].card.setPower
            (cards.getCards()[cards.getPopCardIndex()].getPower());
    m_boardCards[line][column].card.setElement
            (cards.getCards()[cards.getPopCardIndex()].getElement());
    m_boardCards[line][column].card.setStatus
            (cards.getCards()[cards.getPopCardIndex()].getStatus());
    m_boardCards[line][column].card.setAttackOrientation
            (AttackOrientation::TOP, cards.getCards()[cards.getPopCardIndex()].
            getAttackOrientationStatus(AttackOrientation::TOP));
    m_boardCards[line][column].card.setAttackOrientation
            (AttackOrientation::BOTTOM, cards.getCards()[cards.getPopCardIndex()].
            getAttackOrientationStatus(AttackOrientation::BOTTOM));
    m_boardCards[line][column].card.setAttackOrientation
            (AttackOrientation::LEFT, cards.getCards()[cards.getPopCardIndex()].
            getAttackOrientationStatus(AttackOrientation::LEFT));
    m_boardCards[line][column].card.setAttackOrientation
            (AttackOrientation::RIGHT, cards.getCards()[cards.getPopCardIndex()].
            getAttackOrientationStatus(AttackOrientation::RIGHT));
    cards.decrementTopCardIndex();
}

vector<vector<Board::BoardElement>> Board::getBoardCards()
{
    return m_boardCards;
}

unsigned int Board::getBoardLines()
{
    return m_boardLines;
}

unsigned int Board::getBoardColumns()
{
    return m_boardColumns;
}

Board::BoardElement Board::getAdjacentCard(AttackOrientation attackOrientation,
                                           unsigned int line, unsigned int column)
{
    BoardElement adjacentCard;
    switch (attackOrientation)
    {
    case AttackOrientation::TOP: if(line > 0)
            adjacentCard = m_boardCards[line - 1][column];
    case AttackOrientation::BOTTOM: if(line < m_boardLines - 1)
            adjacentCard = m_boardCards[line + 1][column];
    case AttackOrientation::LEFT: if(column > 0)
            adjacentCard = m_boardCards[line][column - 1];
    case AttackOrientation::RIGHT: if(column < m_boardColumns - 1)
            adjacentCard = m_boardCards[line][column + 1];
    }
    return adjacentCard;
}

