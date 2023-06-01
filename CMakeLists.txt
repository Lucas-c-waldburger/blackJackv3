cmake_minimum_required(VERSION 3.24)
project(blackJackv3)

set(CMAKE_CXX_STANDARD 17)

add_executable(blackJackv3 main.cpp Card.cpp Card.h Hand.cpp Hand.h Deck.cpp Deck.h Player.cpp Player.h Art.cpp Art.h Prompts.cpp Prompts.h RoundBet.cpp RoundBet.h)
