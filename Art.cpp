
#include "Art.h"


std::vector<std::string> Art::makeArt(int id, int suit)
{
    std::string suitIcon = getSuitIcon(suit);

    switch (id)
    {
        case 0:
            return make2(suitIcon);
        case 1:
            return make3(suitIcon);
        case 2:
            return make4(suitIcon);
        case 3:
            return make5(suitIcon);
        case 4:
            return make6(suitIcon);
        case 5:
            return make7(suitIcon);
        case 6:
            return make8(suitIcon);
        case 7:
            return make9(suitIcon);
        case 8:
            return make10(suitIcon);
        case 9:
            return makeJack(suitIcon);
        case 10:
            return makeQueen(suitIcon);
        case 11:
            return makeKing(suitIcon);
        case 12:
            return makeAce(suitIcon);
    }
}

std::string Art::getSuitIcon(int suit)
{
    switch (suit)
    {
        case DIAMOND:
            return "^";
        case HEART:
            return "v";
        case CLUB:
            return "&";
        case SPADE:
            return "o";
    }
}

std::vector<std::string> Art::make2(const std::string& suit)
{
    std::vector<std::string> artVec =
        {
            " _______ ",
            "|2      |",
            "|   " + suit + "   |",
            "|       |",
            "|   " + suit + "   |",
            "|______2|"
        };
    return artVec;
}

std::vector<std::string> Art::make3(const std::string& suit)
{
    std::vector<std::string> artVec =
        {
            " _______ ",
            "|3      |",
            "| " + suit + "   " + suit + " |",
            "|       |",
            "|   " + suit + "   |",
            "|______3|"
        };
    return artVec;
}

std::vector<std::string> Art::make4(const std::string& suit)
{
    std::vector<std::string> artVec =
        {
            " _______ ",
            "|4      |",
            "| " + suit + "   " + suit + " |",
            "|       |",
            "| " + suit + "   " + suit + " |",
            "|______4|"
        };
    return artVec;
}
std::vector<std::string> Art::make5(const std::string& suit)
{
    std::vector<std::string> artVec =
        {
            " _______ ",
            "|5      |",
            "| " + suit + "   " + suit + " |",
            "|   " + suit + "   |",
            "| " + suit + "   " + suit + " |",
            "|______5|"
        };
    return artVec;
}

std::vector<std::string> Art::make6(const std::string& suit)
{
    std::vector<std::string> artVec =
        {
            " _______ ",
            "|6      |",
            "| " + suit + "   " + suit + " |",
            "| " + suit + "   " + suit + " |",
            "| " + suit + "   " + suit + " |",
            "|______6|"
        };
    return artVec;
}
std::vector<std::string> Art::make7(const std::string& suit)
{
    std::vector<std::string> artVec =
        {
            " _______ ",
            "|7      |",
            "| " + suit + "   " + suit + " |",
            "| " + suit + " " + suit + " " + suit + " |",
            "| " + suit + "   " + suit + " |",
            "|______7|"
        };
    return artVec;
}

std::vector<std::string> Art::make8(const std::string& suit)
{
    std::vector<std::string> artVec =
        {
            " _______ ",
            "|8      |",
            "| " + suit + " " + suit + " " + suit + " |",
            "|  " + suit + " " + suit + "  |",
            "| " + suit + " " + suit + " " + suit + " |",
            "|______8|"
        };
    return artVec;
}

std::vector<std::string> Art::make9(const std::string& suit)
{
    std::vector<std::string> artVec =
        {
            " _______ ",
            "|9      |",
            "| " + suit + " " + suit + " " + suit + " |",
            "| " + suit + " " + suit + " " + suit + " |",
            "| " + suit + " " + suit + " " + suit + " |",
            "|______9|"
        };
    return artVec;
}

std::vector<std::string> Art::make10(const std::string& suit)
{
    std::vector<std::string> artVec =
        {
            " _______ ",
            "|10  " + suit + "  |",
            "| " + suit + " " + suit + " " + suit + " |",
            "| " + suit + " " + suit + " " + suit + " |",
            "| " + suit + " " + suit + " " + suit + " |",
            "|_____10|"
        };
    return artVec;
}

std::vector<std::string> Art::makeJack(const std::string& suit)
{
    std::vector<std::string> artVec =
        {
            " _______ ",
            "|J      |",
            "|   " + suit + "   |",
            "| " + suit + " J " + suit + " |",
            "|   " + suit + "   |",
            "|______J|"
        };
    return artVec;
}

std::vector<std::string> Art::makeQueen(const std::string& suit)
{
    std::vector<std::string> artVec =
        {
            " _______ ",
            "|Q      |",
            "|   " + suit + "   |",
            "| " + suit + " Q " + suit + " |",
            "|   " + suit + "   |",
            "|______Q|"
        };
    return artVec;
}

std::vector<std::string> Art::makeKing(const std::string& suit)
{
    std::vector<std::string> artVec =
        {
            " _______ ",
            "|K      |",
            "|   " + suit + "   |",
            "| " + suit + " K " + suit + " |",
            "|   " + suit + "   |",
            "|______K|"
        };
    return artVec;
}

std::vector<std::string> Art::makeAce(const std::string& suit)
{
    std::vector<std::string> artVec =
        {
            " _______ ",
            "|A      |",
            "|   " + suit + "   |",
            "| " + suit + " A " + suit + " |",
            "|   " + suit + "   |",
            "|______A|"
        };
    return artVec;
}

std::vector<std::string> Art::makeHidden()
{
    std::vector<std::string> artVec =
            {
                  " _______ ",
                R"(|\./.\./|)",
                R"(|./\./\.|)",
                R"(|{..|..}|)",
                R"(|.\/.\/.|)",
                R"(|/_\./_\|)"
            };
    return artVec;
}