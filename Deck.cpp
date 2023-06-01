#include "Deck.h"


Deck::Deck()
{
    auto now = std::chrono::system_clock::now();
    srand(std::chrono::system_clock::to_time_t(now));

    fill();
    shuffle();
}

void Deck::shuffle()
{
    int newCardPosition = 0;
    for (auto it = cards.begin(); it != cards.end(); it++)
    {
        newCardPosition = rand() % (cards.size() - 1);
        std::swap(*it, *(std::next(cards.begin(), newCardPosition)));
    }
}

void Deck::fill()
{
    for (int i = 0; i < NUM_IDS; i++)
    {
        for (int j = 0; j < NUM_SUITS; j++)
            cards.emplace_back(i, j);
    }
}

std::list<Card> Deck::operator()()
{
    return cards;
}
