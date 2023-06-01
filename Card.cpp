
#include "Card.h"

void Card::moveTop(std::list<Card>& donor, std::list<Card>& recipient)
{
    recipient.push_back(std::move(donor.front()));
    donor.pop_front();
}


Card::Card(int id, int suit) : suit(suit), id(id)
{
    art = Art::makeArt(id, suit);

    if (id >= TWO_ID && id < JACK_ID)
        value = id + 2;
    else if (id < ACE_ID)
        value = 10;
    else
        value = 11;
}

int Card::getId()
{
    return id;
}

int Card::getSuit()
{
    return suit;
}

int Card::getValue()
{
    return value;
}

std::vector<std::string> Card::getArt()
{
    return art;
}

bool Card::isAce()
{
    return (id == 13);
}
