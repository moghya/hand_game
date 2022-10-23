//
// Created by Shubham Sawant on 22/10/22.
//

#ifndef RPS_GAME_INTERACTOR_H
#define RPS_GAME_INTERACTOR_H

#include <iostream>
#include <set>
#include <sstream>
#include <string>

#include "hand.h"

namespace moghya {
    class Interactor {
        public:
            typedef std::shared_ptr<Interactor> Ptr;
            Interactor() = default;
            virtual ~Interactor() = default;
            virtual Hand::Ptr GetHand(const std::set<Hand::Ptr>& hands) {
                do {
                    std::stringstream getHandMsgStream;
                    getHandMsgStream << "\nEnter Hand No.\n";
                    int index = 0;
                    for (const auto& hand : hands) {
                        getHandMsgStream << ++index <<  ") "
                                         << hand->Name() << "\n";
                    }
                    PutMessage(getHandMsgStream.str());
                    int input;
                    std::cin >> input;
                    if (input > 0 && input <= hands.size()) {
                        auto it = hands.begin();
                        std::advance(it, input-1);
                        return *it;
                    } else {
                        PutMessage("Invalid input!\n");
                    }
                } while(true);
            }
            virtual void PutMessage(const std::string& msg) {
                std::cout << msg;
            }
    };
}

#endif//RPS_GAME_INTERACTOR_H
