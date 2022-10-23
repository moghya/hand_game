//
// Created by Shubham Sawant on 23/10/22.
//

#ifndef RPS_GAME_AUTO_PLAYER_INTERACTOR_H
#define RPS_GAME_AUTO_PLAYER_INTERACTOR_H

#include "../../hand_game_lib/interactor.h"

namespace imc {
    class AutoPlayerInteractor : public moghya::Interactor {
    public:
        AutoPlayerInteractor() {}
        ~AutoPlayerInteractor() {}
        moghya::Hand::Ptr GetHand(
            const std::set<moghya::Hand::Ptr>& hands) override;
        void PutMessage(const std::string& msg) override {
            return;
        }
    };
}
#endif//RPS_GAME_AUTO_PLAYER_INTERACTOR_H
