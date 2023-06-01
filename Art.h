//
// Created by Lower School Music on 5/31/23.
//

#ifndef BLACKJACKV3_ART_H
#define BLACKJACKV3_ART_H

#include <iostream>
#include <vector>


const int DIAMOND = 0, HEART = 1, CLUB = 2, SPADE = 3;
const int TWO_ID = 0, THREE_ID = 1, FOUR_ID = 2, FIVE_ID = 3, SIX_ID = 4, SEVEN_ID = 5, EIGHT_ID = 6, NINE_ID = 7,
          TEN_ID = 8, JACK_ID = 9, QUEEN_ID = 10, KING_ID = 11, ACE_ID = 12;

class Art
{
public:

    static std::vector<std::string> makeArt(int id, int suit);
    static std::vector<std::string> makeHidden();

private:

    static std::string getSuitIcon(int suit);

    static std::vector<std::string> make2(const std::string& suit);
    static std::vector<std::string> make3(const std::string& suit);
    static std::vector<std::string> make4(const std::string& suit);
    static std::vector<std::string> make5(const std::string& suit);
    static std::vector<std::string> make6(const std::string& suit);
    static std::vector<std::string> make7(const std::string& suit);
    static std::vector<std::string> make8(const std::string& suit);
    static std::vector<std::string> make9(const std::string& suit);
    static std::vector<std::string> make10(const std::string& suit);
    static std::vector<std::string> makeJack(const std::string& suit);
    static std::vector<std::string> makeQueen(const std::string& suit);
    static std::vector<std::string> makeKing(const std::string& suit);
    static std::vector<std::string> makeAce(const std::string& suit);


};


#endif //BLACKJACKV3_ART_H
