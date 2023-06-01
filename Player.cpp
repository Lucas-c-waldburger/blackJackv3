
#include "Player.h"

Player::Player(std::shared_ptr<Deck>& deck, int startingCredits) : credits(startingCredits)
{
    hand = Hand(deck);
    splitHand = Hand(deck);
}

int Player::getCredits()
{
    return credits;
}

void Player::adjustCredits(int adjustment)
{
    credits += adjustment;
}

void Player::printCredits()
{
    std::cout << "CURRENT CREDITS: " << credits << '\n';
}

void Player::triggerSplit()
{
    Card::moveTop(hand.cards, splitHand.cards);
    hand.draw();
    splitHand.draw();
}





