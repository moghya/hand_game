//
// Created by Shubham Sawant on 22/10/22.
//

#include "paper_wraps_rock_rule.h"
#include "../hands/paper_hand.h"
#include "../hands/rock_hand.h"

using moghya::Hand;
namespace imc {
    Hand::Ptr PaperWrapsRock::Apply(Hand::Ptr a, Hand::Ptr b) {
        std::shared_ptr<PaperHand> paper;
        std::shared_ptr<RockHand> rock;
        paper = Hand::GetDerivedHand<PaperHand>(a, b);
        rock = Hand::GetDerivedHand<RockHand>(a, b);
        if(!paper ||  !rock) return nullptr;
        return paper;
    }

    const std::string PaperWrapsRock::Description() {
        return "PaperWrapsRock";
    }
}