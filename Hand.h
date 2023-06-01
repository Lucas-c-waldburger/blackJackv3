
#ifndef BLACKJACKV3_HAND_H
#define BLACKJACKV3_HAND_H

#include <memory>
#include "Deck.h"

class Hand
{
public:
    Hand() = default;
    Hand(std::shared_ptr<Deck>& deck);

    std::list<Card> cards;
    std::shared_ptr<Deck> deckPtr;

    void displayArt();
    void displayWithHidden();

    void draw(int amount = 1);

    bool ofEqualValue();
    bool naturalBlackJack();

    int score();

    std::list<Card> operator()();

};


#endif //BLACKJACKV3_HAND_H
