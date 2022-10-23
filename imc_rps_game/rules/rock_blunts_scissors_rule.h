//
// Created by Shubham Sawant on 22/10/22.
//

#ifndef RPS_GAME_ROCK_BLUNTS_SCISSORS_RULE_H
#define RPS_GAME_ROCK_BLUNTS_SCISSORS_RULE_H

#include "../../hand_game_lib/rule.h"
#include "../../hand_game_lib/singleton.h"

namespace imc {
    class RockBluntsScissors : public moghya::Rule,
                              public moghya::Singleton<RockBluntsScissors> {
        friend moghya::Singleton<RockBluntsScissors>;
    public:
        ~RockBluntsScissors() override = default;
        moghya::Hand::Ptr Apply(
            moghya::Hand::Ptr a, moghya::Hand::Ptr b) override;
        const std::string Description() override;
    protected:
        RockBluntsScissors() = default;
    };
}


#endif//RPS_GAME_ROCK_BLUNTS_SCISSORS_RULE_H
