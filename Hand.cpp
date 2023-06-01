
#include "Hand.h"


Hand::Hand(std::shared_ptr<Deck>& deck) : deckPtr(deck)
{}

void Hand::displayArt()
{
    for (int i = 0; i < 6; i++)
    {
        for (auto& card : cards)
            std::cout << card.getArt()[i] << "  ";
        std::cout << '\n';
    }

}

void Hand::displayWithHidden()
{
    std::vector<std::string> hiddenCard = Art::makeHidden();
    for (int i = 0; i < 6; i++)
        std::cout << cards.front().getArt()[i] << "  " << hiddenCard[i] << '\n';
}

void Hand::draw(int amount)
{
    for (int i = 0; i < amount; i++)
    {
        Card::moveTop(deckPtr->cards, this->cards);
    }
}

bool Hand::ofEqualValue()
{
    return (cards.size() == 2 && cards.front().getValue() == cards.back().getValue());
}

bool Hand::naturalBlackJack()
{
    return (cards.size() == 2 && score() == 21);
}


int Hand::score()
{
    int score = 0;
    int aceCount = 0;

    for (auto it = cards.begin(); it != cards.end(); it++)
    {
        score += it->getValue();

        if (it->getId() == ACE_ID)
            aceCount += 1;
    }

    while (aceCount > 0)
    {
        if (score > 21)
        {
            score -= 10;
        }
        aceCount--;
    }

    return score;
}

std::list<Card> Hand::operator()()
{
    return cards;
}



