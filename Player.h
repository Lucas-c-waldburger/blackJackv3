//
// Created by Lower School Music on 5/31/23.
//

#ifndef BLACKJACKV3_PLAYER_H
#define BLACKJACKV3_PLAYER_H


#include <memory>
#include "Hand.h"



class Player
{

public:
    Player(std::shared_ptr<Deck>& deck, int startingCredits);
    Hand hand, splitHand;

    int getCredits();
    void adjustCredits(int adjustment);
    void printCredits();

    int playOutHand(Hand& pHand, bool singleDraw = false);

    void triggerSplit();

private:
    int credits;

};




#endif //BLACKJACKV3_PLAYER_H
