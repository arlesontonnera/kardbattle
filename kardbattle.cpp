#include <QCoreApplication>

#include <iostream>

#include "deck.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    Deck m_deck(15);

    auto deckSize = m_deck.size();

    for (size_t i = 0; i < deckSize; ++i) {
        std::cout << m_deck.top();
        m_deck.pop();
    }


//    return a.exec(); // Main loop
    return 0;
}
