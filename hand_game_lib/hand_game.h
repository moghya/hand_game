//
// Created by Shubham Sawant on 22/10/22.
//

#ifndef RPS_GAME_HAND_GAME_H
#define RPS_GAME_HAND_GAME_H

#include <functional>
#include <map>
#include <set>

#include "hand.h"
#include "player.h"
#include "rule.h"

namespace moghya {
    class HandGame {
        public:
            enum class State {
                DRAW,
                STALEMATE,
                WINNERS_COMPUTED,
                ERR_INSUFFICIENT_RULES,
                ERR_INTERNAL_ERROR,
            };
            struct Result {
                State state;
                std::set<Player::Ptr> winners;
                Hand::Ptr winningHand;
                std::set<Rule::Ptr> appliedRules;
            };
        public:
            typedef std::shared_ptr<HandGame> Ptr;
            typedef std::map<Player::Ptr,Hand::Ptr> PlayerHandMap;
            typedef std::set<Player::Ptr> PlayerSet;
            typedef std::set<Rule::Ptr> RuleSet;
            typedef std::function<Result(const RuleSet&, const PlayerHandMap&)>
                    ApplyRulesFn;
            typedef std::function<void(const PlayerSet&, const Result&)>
                    ReportResultFn;

            HandGame(std::set<Hand::Ptr>  hands,
                     std::set<Rule::Ptr>  rules,
                     const std::set<Player::Ptr>& players,
                     ReportResultFn reportResultFn = HandGame::ReportResult,
                     ApplyRulesFn applyRulesFn = HandGame::ApplyRules);
            ~HandGame();
            virtual Result Play();

        protected:
            Result GameLoop();
            PlayerHandMap GetPlayerHands();
            static Result ApplyRules(const RuleSet &ruleSet,
                                     const PlayerHandMap &playerHandMap);
            static void ReportResult(const PlayerSet& players,
                                     const Result& result);
        protected:
            std::set<Hand::Ptr> hands;
            std::set<Rule::Ptr> rules;
            std::set<Player::Ptr> players;
            ApplyRulesFn applyRulesFn;
            ReportResultFn reportResultFn;
    };
}

#endif //RPS_GAME_HAND_GAME_H
