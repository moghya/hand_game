//
// Created by Shubham Sawant on 23/10/22.
//

#include <iostream>
#include <memory>

#include "imc_rock_paper_scissors_hand_game.h"
#include "../hand_game_lib/hand_game.h"
#include "interactors/auto_player_interactor.h"

namespace imc {
    RockPaperScissorsHandGame::RockPaperScissorsHandGame(
            std::string name, int numberOfGames) :
        numberOfGames(numberOfGames) {
        assert(numberOfGames > 0);
        auto interactor = std::make_shared<moghya::Interactor>();
        auto autoInteractor = std::make_shared<imc::AutoPlayerInteractor>();
        players.insert(std::make_shared<moghya::Player>(name, interactor));
        players.insert(
                std::make_shared<moghya::Player>("Computer", autoInteractor));
        gamePtr = std::make_shared<moghya::HandGame>(hands, rules, players);
    }

    RockPaperScissorsHandGame::~RockPaperScissorsHandGame() {
    }

    void RockPaperScissorsHandGame::Start() {
        for(int i = 1; i <= numberOfGames; ++i) {
            std::cout << "\nRound " << i << "\n";
            gamePtr->Play();
        }
    }

}