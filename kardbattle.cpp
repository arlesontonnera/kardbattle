#include <QCoreApplication>

#include <iostream>

#include "card.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    Card m_card;

    std::cout << m_card.makeNeutralCard();

//    return a.exec(); // Main loop
    return 0;
}
