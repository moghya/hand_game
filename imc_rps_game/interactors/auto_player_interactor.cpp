//
// Created by Shubham Sawant on 23/10/22.
//

#include "auto_player_interactor.h"

namespace imc {
    moghya::Hand::Ptr AutoPlayerInteractor::GetHand(
        const std::set<moghya::Hand::Ptr>& hands) {
        std::srand(std::time(nullptr));
        int n = hands.size();
        int index = std::rand()%n;
        auto it = hands.begin();
        std::advance(it, index);
        return *it;
    }
}