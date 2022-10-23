cmake_minimum_required(VERSION 3.23)
project(rps_game)

set(CMAKE_CXX_STANDARD 17)

set(SRC
        singleton.cpp
        hand.cpp
        rule.cpp
        interactor.cpp
        player.cpp
        not_sufficient_players_exception.cpp
        hand_game.cpp
        )

add_library(hand_game_lib ${SRC})
