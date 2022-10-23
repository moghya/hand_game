//
// Created by Shubham Sawant on 22/10/22.
//

#ifndef RPS_GAME_PAPER_HAND_H
#define RPS_GAME_PAPER_HAND_H

#include <memory>

#include "../../hand_game_lib/hand.h"
#include "../../hand_game_lib/singleton.h"

namespace imc {
    class PaperHand : public moghya::Hand, public moghya::Singleton<PaperHand> {
        friend moghya::Singleton<PaperHand>;
        public:
            ~PaperHand() override = default;
            std::string Name() override {
                return "Paper";
            }
        protected:
            PaperHand() : Hand() {}
    };
}

#endif//RPS_GAME_PAPER_HAND_H
