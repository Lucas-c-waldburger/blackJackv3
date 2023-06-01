
#ifndef BLACKJACKV3_DECK_H
#define BLACKJACKV3_DECK_H

#include <random>
#include <chrono>
#include "Card.h"

const int NUM_SUITS = 4, NUM_IDS = 13;

class Deck
{
public:
    Deck();

    std::list<Card> cards;

    void fill();
    void shuffle();

    std::list<Card> operator()();
};


#endif //BLACKJACKV3_DECK_H
