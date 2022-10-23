cmake_minimum_required(VERSION 3.23)
project(rps_game)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(hand_game_lib)
add_subdirectory(imc_rps_game)

add_executable(rps_game main.cpp)
target_link_libraries(rps_game imc_rps_game)