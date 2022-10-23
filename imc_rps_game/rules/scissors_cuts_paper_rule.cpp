//
// Created by Shubham Sawant on 22/10/22.
//

#include "scissors_cuts_paper_rule.h"
#include "../hands/paper_hand.h"
#include "../hands/scissors_hand.h"

using moghya::Hand;

namespace imc {
    Hand::Ptr ScissorsCutsPaper::Apply(Hand::Ptr a, Hand::Ptr b) {
        std::shared_ptr<ScissorsHand> scissors;
        std::shared_ptr<PaperHand> paper;
        scissors = Hand::GetDerivedHand<ScissorsHand>(a, b);
        paper = Hand::GetDerivedHand<PaperHand>(a, b);
        if(!scissors ||  !paper) return nullptr;
        return scissors;
    }

    const std::string ScissorsCutsPaper::Description() {
        return "ScissorsCutsPaper";
    }

}