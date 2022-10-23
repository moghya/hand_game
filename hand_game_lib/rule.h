//
// Created by Shubham Sawant on 22/10/22.
//

#ifndef RPS_GAME_RULE_H
#define RPS_GAME_RULE_H

#include "hand.h"

namespace moghya {
    class Rule {
        public:
            typedef std::shared_ptr<Rule> Ptr;
            virtual Hand::Ptr Apply(Hand::Ptr a, Hand::Ptr b) = 0;
            virtual const std::string Description() = 0;
        protected:
            Rule() = default;
            virtual ~Rule() = default;
    };
}

#endif//RPS_GAME_RULE_H
