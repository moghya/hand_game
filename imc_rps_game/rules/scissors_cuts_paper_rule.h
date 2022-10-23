//
// Created by Shubham Sawant on 22/10/22.
//

#ifndef RPS_GAME_SCISSORS_CUTS_PAPER_RULE_H
#define RPS_GAME_SCISSORS_CUTS_PAPER_RULE_H

#include "../../hand_game_lib/rule.h"
#include "../../hand_game_lib/singleton.h"

namespace imc {
    class ScissorsCutsPaper : public moghya::Rule,
                              public moghya::Singleton<ScissorsCutsPaper> {
        friend moghya::Singleton<ScissorsCutsPaper>;
    public:
        ~ScissorsCutsPaper() override = default;
        moghya::Hand::Ptr Apply(moghya::Hand::Ptr a, moghya::Hand::Ptr b) override;
        const std::string Description() override;
    protected:
        ScissorsCutsPaper() = default;
    };
}
#endif//RPS_GAME_SCISSORS_CUTS_PAPER_RULE_H
