//
// Created by Shubham Sawant on 22/10/22.
//

#ifndef RPS_GAME_HAND_H
#define RPS_GAME_HAND_H

#include <memory>

namespace moghya {
    class Hand {
        public:
            typedef std::shared_ptr<Hand> Ptr;
            template<typename Derived>
            static std::shared_ptr<Derived> GetDerivedHand(Ptr a, Ptr b) {
                if (auto aa = std::dynamic_pointer_cast<Derived>(a)) {
                    return aa;
                } else if (auto bb = std::dynamic_pointer_cast<Derived>(b)) {
                    return bb;
                }
                return nullptr;
            }
            [[maybe_unused]] virtual std::string Name() = 0;
        protected:
            Hand();
            virtual ~Hand();
    };
}

#endif //RPS_GAME_HAND_H
