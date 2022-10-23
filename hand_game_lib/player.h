//
// Created by Shubham Sawant on 22/10/22.
//

#ifndef RPS_GAME_PLAYER_H
#define RPS_GAME_PLAYER_H

#include <iostream>
#include <string>
#include <set>
#include <utility>

#include "hand.h"
#include "interactor.h"

namespace moghya {
    class Player {
        public:
            typedef std::shared_ptr<Player> Ptr;
            Player(std::string id, Interactor::Ptr interactor) :
                id(std::move(id)), interactor(std::move(interactor)) {}
            Hand::Ptr GetHand(const std::set<Hand::Ptr>& hands) {
                return interactor->GetHand(hands);
            }
            void SendMessage(const std::string& msg) {
                interactor->PutMessage(msg);
            }
            std::string GetId() {
                return id;
            }
        private:
            std::string id;
            Interactor::Ptr interactor;
    };
}

#endif//RPS_GAME_PLAYER_H
