

#ifndef BLACKJACKV3_PROMPTS_H
#define BLACKJACKV3_PROMPTS_H
#include <iostream>

const int SURRENDER = -2, BUST = -1, NOT_PLAYED_OUT = 0, HIT = 1, STAND = 2;

namespace Prompts
{

    extern bool askPlayerYes(std::string question);

    extern int handleMisspelledHandOptions(std::string& decision);

    extern int askPlayerHandOptions();

}


#endif //BLACKJACKV3_PROMPTS_H
