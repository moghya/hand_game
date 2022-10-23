//
// Created by Shubham Sawant on 22/10/22.
//

#ifndef RPS_GAME_PAPER_WRAPS_ROCKS_RULE_H
#define RPS_GAME_PAPER_WRAPS_ROCKS_RULE_H

#include "../../hand_game_lib/rule.h"
#include "../../hand_game_lib/singleton.h"

namespace imc {
    class PaperWrapsRock : public moghya::Rule,
                           public moghya::Singleton<PaperWrapsRock> {
        friend Singleton<PaperWrapsRock>;
        public:
            ~PaperWrapsRock() = default;
            moghya::Hand::Ptr Apply(
                    moghya::Hand::Ptr a, moghya::Hand::Ptr b) override;
            const std::string Description() override;
        protected:
            PaperWrapsRock() = default;
    };
}

#endif//RPS_GAME_PAPER_WRAPS_ROCKS_RULE_H
