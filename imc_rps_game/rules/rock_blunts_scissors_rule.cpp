//
// Created by Shubham Sawant on 22/10/22.
//

#include "rock_blunts_scissors_rule.h"
#include "../hands/rock_hand.h"
#include "../hands/scissors_hand.h"

using moghya::Hand;
namespace imc {
    Hand::Ptr RockBluntsScissors::Apply(Hand::Ptr a, Hand::Ptr b) {
        std::shared_ptr<RockHand> rock;
        std::shared_ptr<ScissorsHand> scissors;
        rock = Hand::GetDerivedHand<RockHand>(a, b);
        scissors = Hand::GetDerivedHand<ScissorsHand>(a, b);
        if(!rock ||  !scissors) return nullptr;
        return rock;
    }

    const std::string RockBluntsScissors::Description() {
        return "RockBluntsScissors";
    }
}