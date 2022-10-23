//
// Created by Shubham Sawant on 22/10/22.
//

#ifndef RPS_GAME_ROCK_HAND_H
#define RPS_GAME_ROCK_HAND_H

#include <memory>

#include "../../hand_game_lib/hand.h"
#include "../../hand_game_lib/singleton.h"

namespace imc {
    class RockHand : public moghya::Hand, public moghya::Singleton<RockHand> {
        friend moghya::Singleton<RockHand>;
        public:
            ~RockHand() override = default;
            std::string Name() override {
                return "Rock";
            }
        protected:
            RockHand() : Hand() {}
    };
}

#endif//RPS_GAME_ROCK_HAND_H
