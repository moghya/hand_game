//
// Created by Shubham Sawant on 23/10/22.
//

#ifndef RPS_GAME_ROCKPAPERSCISSORSHANDGAME_H
#define RPS_GAME_ROCKPAPERSCISSORSHANDGAME_H

#include <string>
#include "../hand_game_lib/hand_game.h"

#include "./hands/paper_hand.h"
#include "./hands/rock_hand.h"
#include "./hands/scissors_hand.h"
#include "./rules/paper_wraps_rock_rule.h"
#include "./rules/rock_blunts_scissors_rule.h"
#include "./rules/scissors_cuts_paper_rule.h"

namespace imc {
    class RockPaperScissorsHandGame {
        public:
            RockPaperScissorsHandGame(std::string name,
                                      uint numberOfGames);
            ~RockPaperScissorsHandGame();
            void Start();
        private:
            std::set<moghya::Player::Ptr> players;
            std::set<moghya::Hand::Ptr> hands {
                    imc::PaperHand::Instance(),
                    imc::RockHand::Instance(),
                    imc::ScissorsHand::Instance()
            };
            std::set<moghya::Rule::Ptr> rules {
                    imc::PaperWrapsRock::Instance(),
                    imc::RockBluntsScissors::Instance(),
                    imc::ScissorsCutsPaper::Instance(),
            };
            moghya::HandGame::Ptr gamePtr;
            uint numberOfGames;
    };
}

#endif//RPS_GAME_ROCKPAPERSCISSORSHANDGAME_H
