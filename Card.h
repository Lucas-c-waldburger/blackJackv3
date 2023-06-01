#ifndef BLACKJACKV3_CARD_H
#define BLACKJACKV3_CARD_H


#include <iostream>
#include "Art.h"
#include <list>


class Card
{
public:

    Card(int id, int suit);

    int getId();
    int getSuit();
    int getValue();
    std::vector<std::string> getArt();

    bool isAce();

    static void moveTop(std::list<Card>& donor, std::list<Card>& recipient);

private:

    int id;
    int suit;
    int value;
    std::vector<std::string> art;

};



#endif //BLACKJACKV3_CARD_H
