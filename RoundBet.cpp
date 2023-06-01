//
// Created by Lower School Music on 6/1/23.
//

#include "RoundBet.h"

RoundBet::RoundBet(std::shared_ptr<Player>& player) : playerPtr(player), currentBet(0), betValid(false)
{}

int RoundBet::getCurrentBet()
{
    return currentBet;
}

bool RoundBet::getBetValid()
{
    return betValid;
}

void RoundBet::promptBet()
{
    playerPtr->printCredits();
    std::cout << "Place your bet: ";
    std::cin >> currentBet;
    std::cout << "\n\n";

    if (currentBet > playerPtr->getCredits())
        throw std::out_of_range("Bet exceeds credit amount!");
    if (currentBet == 0)
        throw std::invalid_argument("Bet cannot be 0 credits!");

    playerPtr->adjustCredits(currentBet * -1);
    betValid = true;
}

void RoundBet::promptDoubleDown()
{
    if (currentBet <= playerPtr->getCredits()) {
        std::cout << "CURRENT CREDITS: " << playerPtr->getCredits();

        if (Prompts::askPlayerYes("Double Down?"))
        {
            playerPtr->adjustCredits(currentBet * -1);
            currentBet *= 2;
        }
    }
}

void RoundBet::clear()
{
    currentBet = 0;
    betValid = false;
}