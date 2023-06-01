
#ifndef BLACKJACKV3_ROUNDBET_H
#define BLACKJACKV3_ROUNDBET_H

#include "Prompts.h"
#include "Player.h"

class RoundBet
{
public:
    RoundBet(std::shared_ptr<Player>& player);

    std::shared_ptr<Player> playerPtr;

    int getCurrentBet();
    bool getBetValid();

    void promptBet();
    void promptDoubleDown();

    void clear();

private:
    int currentBet;
    bool betValid;


};


#endif //BLACKJACKV3_ROUNDBET_H
