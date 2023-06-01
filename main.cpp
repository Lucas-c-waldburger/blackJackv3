#include <iostream>
#include "RoundBet.h"


int playOutHandPlayer(Hand& pHand, bool singleDraw = false)
{
    int finalScore = pHand.score();

    std::cout << "\nYOUR HAND: " << '(' << finalScore << ")\n";
    pHand.displayArt();

    if (finalScore < 21)
    {
        switch (Prompts::askPlayerHandOptions()) {
            case HIT:
                pHand.draw();

                if (singleDraw) {
                    finalScore = pHand.score();
                    break;
                }

                finalScore = playOutHandPlayer(pHand);
                break;

            case SURRENDER:
                finalScore = SURRENDER;
                break;

            case STAND:
                break;
        }
    }

    return finalScore;
}

int playOutHandDealer(Hand& dHand)
{
    int finalScore = dHand.score();

    std::cout << "\nDEALERS HAND: " << '(' << finalScore << ")\n";
    dHand.displayArt();

    if (finalScore < 17)
    {
        dHand.draw();
        finalScore = playOutHandDealer(dHand);
    }

    return finalScore;
}


void dealBack(Hand& hand)
{
    while (!hand().empty())
    {
        Card::moveTop(hand.cards, hand.deckPtr->cards);
    }
}

void reset(Player& player, Player& dealer, RoundBet& roundBet)
{
    dealBack(player.hand);
    dealBack(player.splitHand);
    dealBack(dealer.hand);
    player.hand.deckPtr->shuffle();
    roundBet.clear();
}





int main()
{
    // INIT DECK, PLAYER, DEALER, ROUND BET
    std::shared_ptr<Deck> deck = std::make_shared<Deck>();
    std::shared_ptr<Player> player = std::make_shared<Player>(deck, 100);
    Player dealer = Player(deck, 0);
    RoundBet roundBet = RoundBet(player);

    bool keepPlaying = true;

    while (keepPlaying)
    {
    std::cout << "                 ~~~~~~~~~~~                  \n"
              << "~~~~~~~~~~~~~~~~~ NEW ROUND ~~~~~~~~~~~~~~~~~~\n"
              << "                 ~~~~~~~~~~~                  \n" ;

        // GET INITIAL BET
        while (!roundBet.getBetValid())
        {
            try
            {
                roundBet.promptBet();
            }

            catch (std::out_of_range& ex)
            {
                std::cout << ex.what() << "\n\n";
            }

            catch (std::invalid_argument& ex)
            {
                std::cout << ex.what() << "\n\n";
            }
        }

        // DEF FINAL SCORES
        int finalScorePlayerHand = 0, finalScorePlayerSplitHand = 0, finalScoreDealerHand = 0;

        // DEAL & DISPLAY CARDS
        player->hand.draw(2);
        dealer.hand.draw(2);

        std::cout << "DEALER'S HAND:\n";
        dealer.hand.displayWithHidden();

        // CHECK PLAYER & DEALER NATURAL BLACKJACK
        if (player->hand.naturalBlackJack())
        {
            std::cout << "\nYOUR HAND: " << '(' << player->hand.score() << ")\n";
            player->hand.displayArt();

            if (dealer.hand.naturalBlackJack())
                std::cout << "PUSH";
            else
            {
                std::cout << "BLACKJACK! YOU WIN: " << roundBet.getCurrentBet() * 1.5 << " credits\n";
                player->adjustCredits(roundBet.getCurrentBet() * 1.5);
            }
        }
        else if (dealer.hand.naturalBlackJack())
        {
            if (player->hand.naturalBlackJack())
                std::cout << "PUSH";
            else
                std::cout << "DEALER GOT A BLACKJACK, YOU LOSE";
        }
        else
        {

            // ASK DOUBLEDOWN

            // ASK SPLIT
            if (player->hand.ofEqualValue() && player->getCredits() >= roundBet.getCurrentBet())
            {
                std::cout << "\nYOUR HAND: " << '(' << player->hand.score() << ")\n";
                player->hand.displayArt();

                if (Prompts::askPlayerYes("Split your hand?"))
                {
                    player->triggerSplit();
                    player->adjustCredits(roundBet.getCurrentBet() * -1);

                    std::cout << "YOUR NEW HANDS:\n";
                    player->hand.displayArt();
                    std::cout << "\n\n";
                    player->splitHand.displayArt();
                }
            }

            // PLAYER -> PLAY OUT HAND / SPLIT HAND
            if (!player->splitHand().empty())
            {
                finalScorePlayerHand = playOutHandPlayer(player->hand, true);
                finalScorePlayerSplitHand = playOutHandPlayer(player->splitHand, true);
            }
            else
                finalScorePlayerHand = playOutHandPlayer(player->hand);


            // IF 1+ PLAYER HANDS NOT-BUST -> DEALER PLAY OUT HAND
            if (finalScorePlayerHand < 22 || (finalScorePlayerSplitHand < 22 && finalScorePlayerSplitHand != 0))
                finalScoreDealerHand = playOutHandDealer(dealer.hand);

            // GO TO FINAL SCORING
            std::cout << "-----------------------------\n"
                      << "YOUR HAND FINAL SCORE: " << player->hand.score() << '\n';

            if (!player->splitHand().empty())
                std::cout << "YOUR SPLIT HAND FINAL SCORE: " << player->splitHand.score() << '\n';

            std::cout << "-----------------------------\n"
                      << "DEALER'S HAND FINAL SCORE: " << dealer.hand.score()
                      << "\n-----------------------------\n";


            if (finalScoreDealerHand > 21) // CHECK DEALER BUST
            {
                std::cout << "DEALER WENT OVER, YOU WIN: " << roundBet.getCurrentBet() * 1.5 << " credits!\n\n";
                player->adjustCredits(roundBet.getCurrentBet() * 1.5);
            }

            else
            {
                if (finalScorePlayerHand > 21) // CHECK PLAYER BUST
                    std::cout << "YOUR HAND WENT OVER, DEALER WINS\n\n";

                else if (finalScorePlayerHand <= finalScoreDealerHand) // DEALER SCORED HIGHER
                    std::cout << "DEALERS HAND SCORED SAME OR HIGHER, DEALER WINS\n\n";

                else
                {
                    std::cout << "YOUR HAND SCORED HIGHER, YOU WIN: "; // MAIN HAND WON, AWARD APPROPRIATE CREDITS
                    if (!player->splitHand().empty())
                    {
                        std::cout << roundBet.getCurrentBet() / 2 * 1.5 << " credits\n\n";
                        player->adjustCredits((roundBet.getCurrentBet() / 2) * 1.5);
                    }
                    else
                    {
                        std::cout << roundBet.getCurrentBet() * 1.5 << " credits\n\n";
                        player->adjustCredits(roundBet.getCurrentBet() * 1.5);
                    }
                }

                if (!player->splitHand().empty()) // IF SPLIT, ASSESS WINSTATE OF SPLIT HAND
                {
                    if (finalScorePlayerSplitHand > 21) // CHECK BUST
                        std::cout << "YOUR SPLIT HAND WENT OVER, DEALER WINS\n\n";

                    else if (finalScorePlayerSplitHand <= finalScoreDealerHand) // DEALER SCORED HIGHER
                        std::cout << "DEALERS HAND SCORED SAME OR HIGHER THAN YOUR SPLIT HAND, DEALER WINS\n\n";

                    else
                    {
                        std::cout << "YOUR SPLIT HAND SCORED HIGHER, YOU WIN: " << roundBet.getCurrentBet() / 2 * 1.5
                                  << " credits\n\n";
                        player->adjustCredits((roundBet.getCurrentBet() / 2) * 1.5);
                    }
                }
        }
        // IF PLAY AGAIN -> RESET DECK, HANDS, & ROUNDBET
        if (Prompts::askPlayerYes("Play again?"))
            reset(*player, dealer, roundBet);
        else
            keepPlaying = false;

        }
    }

    return 0;
}
