#include <iostream>

#include "imc_rps_game/imc_rock_paper_scissors_hand_game.h"

int main() {
    std::string playerName;
    uint numberOfRounds;
    std::cout << "Enter name of player: ";
    std::cin >> playerName;
    std::cout << "\nEnter number of rounds: ";
    std::cin >> numberOfRounds;
    auto game = imc::RockPaperScissorsHandGame(playerName, numberOfRounds);
    game.Start();
    return 0;
}
