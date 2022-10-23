//
// Created by Shubham Sawant on 22/10/22.
//

#ifndef RPS_GAME_SCISSORS_HAND_H
#define RPS_GAME_SCISSORS_HAND_H

#include <memory>

#include "../../hand_game_lib/hand.h"
#include "../../hand_game_lib/singleton.h"

namespace imc {
    class ScissorsHand : public moghya::Hand,
                         public moghya::Singleton<ScissorsHand> {
        friend moghya::Singleton<ScissorsHand>;
        public:
            ~ScissorsHand() override = default;
            std::string Name() override {
                return "Scissors";
            }
        public:
            ScissorsHand() : Hand() {}
    };
}

#endif//RPS_GAME_SCISSORS_HAND_H
