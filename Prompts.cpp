//
// Created by Lower School Music on 5/31/23.
//

#include "Prompts.h"

bool Prompts::askPlayerYes(std::string question)
{
    char decision;
    std::cout << question <<  " Y/N: ";
    std::cin >> decision;
    std::cout << '\n';

    return (std::tolower(decision) == 'y');
}

int Prompts::handleMisspelledHandOptions(std::string& decision)
{
    int hitCertainty = 0, standCertainty = 0, surrenderCertainty = 0;

    if (decision.length() <= 4)
        hitCertainty += 1;
    if (decision.length() > 3 && decision.length() <= 6)
        standCertainty += 1;
    else if (decision.length() > 6)
        surrenderCertainty += 1;

    for (char c : decision)
    {
        switch(c)
        {
            case 'h': case 'i':
            {
                hitCertainty += 1;
                break;
            }
            case 'a': default:
            {
                standCertainty += 1;
                break;
            }
            case 'u': case 'r': case 'e':
            {
                surrenderCertainty += 1;
                break;
            }

        }
    }

    if (hitCertainty > standCertainty)
    {
        if (hitCertainty >= surrenderCertainty)
            return HIT;
    }
    else
    {
        if (standCertainty >= surrenderCertainty)
            return STAND;
    }

    return SURRENDER;
}





int Prompts::askPlayerHandOptions()
{
    std::string rawDecision, loweredDecision;
    std::cout << "hit, stand, or surrender?: ";
    std::cin >> rawDecision;
    std::cout << '\n';

    for (char c : rawDecision)
        loweredDecision += std::tolower(c);

    if (loweredDecision == "hit")
        return HIT;
    if (loweredDecision == "stand")
        return STAND;
    if (loweredDecision == "surrender")
        return SURRENDER;

    return Prompts::handleMisspelledHandOptions(loweredDecision);
}