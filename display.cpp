#include "display.h"

using namespace std;

void set_cursor_position(const int m_x, const int m_y)
{
#ifdef _WIN32
#include <windows.h>
    HANDLE Screen;
    Screen = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Position={m_x, m_y};
    SetConsoleCursorPosition(Screen, Position);
#else
    printf("\033[%d;%dH", m_y, m_x);
#endif
}



Display::Display(Deck cards, Board board) : m_cards(cards), m_board(board)
{

}

/*
void Display::displayPopCard()
{
    unsigned int centerboard =
            (((m_frameWidth * m_board.getBoardColumns())
              + (m_board.getBoardColumns() - 1)) / 2)
            - (m_frameWidth / 2);
    // Line 1:
    cout << string(centerboard, ' ');
    cout << string(m_frameWidth, m_placedPattern) << " ";
    cout << endl;
    // Line 2:
    cout << string(centerboard, ' ');
    string symbolTop;
    switch (static_cast <unsigned int>
            (m_cards.getCards()[m_cards.getPopCardIndex()].getAttackOrientationStatus
             (Card_attack_orientation::TOP)))
    {
    case 0: symbolTop = " "; break;
    case 1: symbolTop = "^"; break;
    case 2: symbolTop = "v"; break;
    }
    cout << '*' << string(10, ' ') << symbolTop << string(10, ' ') << '*' << " ";
    cout << endl;
    // Line 3:
    cout << string(centerboard, ' ');
    cout << "* " << "Index: " << m_cards.getPopCardIndex()
         << string(m_frameWidth - 10 -
                   (std::to_string(m_cards.getPopCardIndex()).length()), ' ')
         << '*' << " ";
    cout << endl;
    // Line 4:
    cout << string(centerboard, ' ');
    cout << "* " << "Power: " << m_cards.getCards()[m_cards.getPopCardIndex()]
            .getPower() << string((m_frameWidth - 10 - std::to_string
                                   (m_cards.getCards()[m_cards.getPopCardIndex()]
                                   .getPower()).size()), ' ') << '*' << " ";
    cout << endl;
    // Line 5:
    cout << string(centerboard, ' ');
    cout << "* " << "Element: " << m_cards.getCards()[m_cards.getPopCardIndex()]
            .getElement_Str() << string((m_frameWidth - 12 - m_cards.getCards()[m_cards
                                         .getPopCardIndex()].getElement_Str()
                                        .size()), ' ') << '*' << " ";
    cout << endl;
    // Line 6:
    cout << string(centerboard, ' ');
    cout << "* " << "Status: "
         << m_cards.getCards()[m_cards.getPopCardIndex()].getStatus_Str()
         << string((m_frameWidth - 11 - m_cards.getCards()[m_cards.getPopCardIndex()]
                   .getStatus_Str().size()), ' ') << '*' << " ";
    cout << endl;
    // Line 7:
    cout << string(centerboard, ' ');
    cout << '*' << string(m_frameWidth-2, ' ') << '*' << " ";
    cout << endl;
    // Line 8:
    cout << string(centerboard, ' ');
    string symbolLeft;
    switch(static_cast <unsigned int>(m_cards.getCards()[m_cards.getPopCardIndex()]
                                      .getAttackOrientationStatus
                                      (Card_attack_orientation::LEFT)))
    {
    case 0: symbolLeft = " "; break;
    case 1: symbolLeft = "<"; break;
    case 2: symbolLeft = ">";
    }
    string symbolRight;
    switch(static_cast <unsigned int>(m_cards.getCards()[m_cards.getPopCardIndex()]
                                      .getAttackOrientationStatus
                                      (Card_attack_orientation::RIGHT)))
    {
    case 0: symbolRight = " "; break;
    case 1: symbolRight = ">"; break;
    case 2: symbolRight = "<";
    }
    cout << "* " << symbolLeft << string(17, ' ') << symbolRight << " *" << " ";
    cout << endl;
    // Line 9:
    cout << string(centerboard, ' ');
    cout << '*' << string(m_frameWidth - 2, ' ') << '*' << " ";
    cout << endl;
    // Line 10:
    cout << string(centerboard, ' ');
    cout << '*' << string(m_frameWidth - 2, ' ') << '*' << " ";
    cout << endl;
    // Line 11:
    cout << string(centerboard, ' ');
    cout << '*' << string(m_frameWidth - 2, ' ') << '*' << " ";
    cout << endl;
    // Line 12:
    cout << string(centerboard, ' ');
    cout << '*' << string(m_frameWidth - 2, ' ') << '*' << " ";
    cout << endl;
    // Line 13:
    cout << string(centerboard, ' ');
    cout << '*' << string(m_frameWidth - 2, ' ') << '*' << " ";
    cout << endl;
    // Line 14:
    cout << string(centerboard, ' ');
    string symbolBottom;
    switch(static_cast <unsigned int>(m_cards.getCards()[m_cards.getPopCardIndex()]
                                      .getAttackOrientationStatus
                                      (Card_attack_orientation::BOTTOM)))
    {
    case 0: symbolBottom = " "; break;
    case 1: symbolBottom = "v"; break;
    case 2: symbolBottom = "^";
    }
    cout << '*' << string(10, ' ') << symbolBottom << string(10, ' ') << '*' << " ";
    cout << endl;
    // Line 15:
    cout << string(centerboard, ' ');
    cout << string(m_frameWidth, m_placedPattern) << " ";
    cout << endl << endl;
}

void Display::displayBoard()
{
    // Line 1:
    for (unsigned int line = 0; line < m_board.getBoardLines(); line++) {
        for (unsigned int column = 0; column < m_board.getBoardColumns(); column++) {
            if (static_cast <unsigned int>
                    (m_board.getBoardCards()[line][column].isPlaced)) { //If placed
                cout << string(m_frameWidth, m_placedPattern) << " ";
            }
            else {//If non placed
                cout << string(m_frameWidth, m_int_placedPattern) << " ";
            }
        }
        cout << endl;
        // Line 2:
        for (unsigned int column = 0; column < m_board.getBoardColumns(); column++) {
            if (static_cast <unsigned int>
                    (m_board.getBoardCards()[line][column].isPlaced)) { //If placed
                string symbolTop;
                switch (static_cast <unsigned int>
                        (m_board.getBoardCards()[line][column].card.
                         getAttackOrientationStatus(Card_attack_orientation::TOP)))
                {
                case 0: symbolTop = " "; break;
                case 1: symbolTop = "^"; break;
                case 2: symbolTop = "v";
                }
                cout << '*' << string(10, ' ') << symbolTop << string(10, ' ')
                     << '*' << " ";
            }
            else { //If non placed
                cout << string(m_frameWidth, m_int_placedPattern) << " ";
            }
        }
        cout << endl;
        // Line 3:
        for (unsigned int column = 0; column < m_board.getBoardColumns(); column++) {
            if (static_cast <unsigned int>
                    (m_board.getBoardCards()[line][column].isPlaced)) { //If placed
                cout << "* " << "Index: "
                     << m_board.getBoardCards()[line][column].index
                     << string(m_frameWidth - 10 -
                               (std::to_string(m_board.getBoardCards()[line][column]
                                               .index).length()), ' ')
                     << '*' << " ";
            }
            else { //If non placed
                cout << string(m_frameWidth, m_int_placedPattern) << " ";
            }
        }
        cout << endl;
        // Line 4:
        for (unsigned int column = 0; column < m_board.getBoardColumns(); column++) {
            if (static_cast <unsigned int>
                    (m_board.getBoardCards()[line][column].isPlaced)) { //If placed
                cout << "* " << "Power: "
                     << m_board.getBoardCards()[line][column].card.getPower()
                     << string(m_frameWidth - 10 -
                               (std::to_string(m_board.getBoardCards()[line][column]
                                               .card.getPower()).size()), ' ')
                     << '*' << " ";
            }
            else { //If non placed
                cout << string(m_frameWidth, m_int_placedPattern) << " ";
            }
        }
        cout << endl;
        // Line 5:
        for (unsigned int column = 0; column < m_board.getBoardColumns(); column++) {
            if (static_cast <unsigned int>
                    (m_board.getBoardCards()[line][column].isPlaced)) { //If placed
                cout << "* " << "Element: "
                     << m_board.getBoardCards()[line][column].card.getElement_Str()
                     << string(m_frameWidth - 12 -
                               m_board.getBoardCards()[line][column]
                               .card.getElement_Str().size(), ' ')
                     << '*' << " ";
            }
            else { //If non placed
                cout << string(m_frameWidth, m_int_placedPattern) << " ";
            }
        }
        cout << endl;
        // Line 6:
        for (unsigned int column = 0; column < m_board.getBoardColumns(); column++) {
            if (static_cast <unsigned int>
                    (m_board.getBoardCards()[line][column].isPlaced)) { //If placed
                cout << "* " << "Status: "
                     << m_board.getBoardCards()[line][column].card.getStatus_Str()
                     << string((m_frameWidth - m_board.getBoardCards()[line][column]
                                .card.getStatus_Str().size()) - 11, ' ')
                     << '*' << " ";
            }
            else { //If non placed
                cout << string(m_frameWidth, m_int_placedPattern) << " ";
            }
        }
        cout << endl;
        // Line 7:
        for (unsigned int column = 0; column < m_board.getBoardColumns(); column++) {
            if (static_cast <unsigned int>
                    (m_board.getBoardCards()[line][column].isPlaced)) { //If placed
                cout << '*' << string(m_frameWidth-2, ' ') << '*' << " ";
            }
            else { //If non placed
                cout << string(m_frameWidth, m_int_placedPattern) << " ";
            }
        }
        cout << endl;
        // Line 8:
        for (unsigned int column = 0; column < m_board.getBoardColumns(); column++) {
            if (static_cast <unsigned int>
                    (m_board.getBoardCards()[line][column].isPlaced)) { //If placed
                string symbolLeft;
                switch(static_cast <unsigned int>
                       (m_board.getBoardCards()[line][column]
                        .card.getAttackOrientationStatus(Card_attack_orientation::LEFT)))
                {
                case 0: symbolLeft = " "; break;
                case 1: symbolLeft = "<"; break;
                case 2: symbolLeft = ">";
                }
                string symbolRight;
                switch(static_cast <unsigned int>
                       (m_board.getBoardCards()[line][column]
                        .card.getAttackOrientationStatus(Card_attack_orientation::RIGHT)))
                {
                case 0: symbolRight = " "; break;
                case 1: symbolRight = ">"; break;
                case 2: symbolRight = "<";
                }
                cout << "* " << symbolLeft << string(17, ' ') << symbolRight
                     << " *" << " ";
            }
            else { //If non placed
                cout << string(m_frameWidth, m_int_placedPattern) << " ";
            }
        }
        cout << endl;
        // Line 9:
        for (unsigned int column = 0; column < m_board.getBoardColumns(); column++) {
            if (static_cast <unsigned int>
                    (m_board.getBoardCards()[line][column].isPlaced)) { //If placed
                cout << '*' << string(m_frameWidth - 2, ' ') << '*' << " ";
            }
            else { //If non placed
                cout << string(m_frameWidth, m_int_placedPattern) << " ";
            }
        }
        cout << endl;
        // Line 10:
        for (unsigned int column = 0; column < m_board.getBoardColumns(); column++) {
            if (static_cast <unsigned int>
                    (m_board.getBoardCards()[line][column].isPlaced)) { //If placed
                cout << '*' << string(m_frameWidth - 2, ' ') << '*' << " ";
            }
            else { //If non placed
                cout << string(m_frameWidth, m_int_placedPattern) << " ";
            }
        }
        cout << endl;
        // Line 11:
        for (unsigned int column = 0; column < m_board.getBoardColumns(); column++) {
            if (static_cast <unsigned int>
                    (m_board.getBoardCards()[line][column].isPlaced)) { //If placed
                cout << '*' << string(m_frameWidth - 2, ' ') << '*' << " ";
            }
            else { //If non placed
                cout << string(m_frameWidth, m_int_placedPattern) << " ";
            }
        }
        cout << endl;
        // Line 12:
        for (unsigned int column = 0; column < m_board.getBoardColumns(); column++) {
            if (static_cast <unsigned int>
                    (m_board.getBoardCards()[line][column].isPlaced)) { //If placed
                cout << '*' << string(m_frameWidth - 2, ' ') << '*' << " ";
            }
            else { //If non placed
                cout << string(m_frameWidth, m_int_placedPattern) << " ";
            }
        }
        cout << endl;
        // Line 13:
        for (unsigned int column = 0; column < m_board.getBoardColumns(); column++) {
            if (static_cast <unsigned int>
                    (m_board.getBoardCards()[line][column].isPlaced)) { //If placed
                cout << '*' << string(m_frameWidth - 2, ' ') << '*' << " ";
            }
            else { //If non placed
                cout << string(m_frameWidth, m_int_placedPattern) << " ";
            }
        }
        cout << endl;
        // Line 14:
        for (unsigned int column = 0; column < m_board.getBoardColumns(); column++) {
            if (static_cast <unsigned int>
                    (m_board.getBoardCards()[line][column].isPlaced)) { //If placed
                string symbolBottom;
                switch(static_cast <unsigned int>
                       (m_board.getBoardCards()[line][column]
                        .card.getAttackOrientationStatus(Card_attack_orientation::BOTTOM)))
                {
                case 0: symbolBottom = " "; break;
                case 1: symbolBottom = "v"; break;
                case 2: symbolBottom = "^";
                }
                cout << '*' << string(10, ' ') << symbolBottom << string(10, ' ')
                     << '*' << " ";
            }
            else { //If non placed
                cout << string(m_frameWidth, m_int_placedPattern) << " ";
            }
        }
        cout << endl;
        // Line 15:
        for (unsigned int column = 0; column < m_board.getBoardColumns(); column++) {
            if (static_cast <unsigned int>
                    (m_board.getBoardCards()[line][column].isPlaced)) { //If placed
                cout << string(m_frameWidth, m_placedPattern) << " ";
            }
            else { //If non placed
                cout << string(m_frameWidth, m_int_placedPattern) << " ";
            }
        }
        cout << endl << endl;
    }
}
*/
