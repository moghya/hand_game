cmake_minimum_required(VERSION 3.23)
project(rps_game)

set(CMAKE_CXX_STANDARD 17)
set(SRC
        ./hands/rock_hand.cpp
        ./hands/paper_hand.cpp
        ./hands/scissors_hand.cpp
        ./rules/paper_wraps_rock_rule.cpp
        ./rules/rock_blunts_scissors_rule.cpp
        ./rules/scissors_cuts_paper_rule.cpp
        ./interactors/auto_player_interactor.cpp
        imc_rock_paper_scissors_hand_game.cpp
    )
add_library(imc_rps_game ${SRC})
target_link_libraries(imc_rps_game hand_game_lib)
