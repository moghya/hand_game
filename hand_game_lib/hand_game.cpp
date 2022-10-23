//
// Created by Shubham Sawant on 22/10/22.
//

#include "hand_game.h"
#include "not_sufficient_players_exception.h"
#include <sstream>
#include <string>
#include <utility>


namespace moghya {
    HandGame::HandGame(
         std::set<Hand::Ptr>  hands,
         std::set<Rule::Ptr>  rules,
         const std::set<Player::Ptr>& players,
         HandGame::ReportResultFn reportResultFunc,
         HandGame::ApplyRulesFn applyRuleFunc) :
        hands(std::move(hands)),
        rules(std::move(rules)),
        players(players),
        reportResultFn(std::move(reportResultFunc)),
        applyRulesFn(std::move(applyRuleFunc)) {
        if(players.size() < 2) {
            throw NotSufficientPlayerException("No of players is less that two.");
        }
    }

    HandGame::~HandGame() = default;

    HandGame::Result HandGame::Play() {
        return GameLoop();
    }

    HandGame::PlayerHandMap HandGame::GetPlayerHands() {
        std::stringstream playerHandsStream;
        PlayerHandMap  playerHandMap;
        auto it = players.begin();
        while (it != players.end()) {
            auto hand = (*it)->GetHand(hands);
            playerHandMap[*it] = hand;
            playerHandsStream << "\t" << (*it)->GetId()
                              << " : " << hand->Name() << "\n";
            ++it;
        }
        std::string msg = "\nChosen Hands: \n" + playerHandsStream.str();
        for(auto p: players) p->SendMessage(msg);
        return playerHandMap;
    }

    HandGame::Result HandGame::GameLoop() {
        PlayerHandMap playerHandMap = GetPlayerHands();
        auto result = applyRulesFn(rules, playerHandMap);
        reportResultFn(players, result);
        return result;
    }

    void HandGame::ReportResult(
        const PlayerSet& players,
        const HandGame::Result &result) {
        std::stringstream reportStream;
        switch (result.state) {
            case moghya::HandGame::State::WINNERS_COMPUTED: {
                reportStream << "Winning Hand: "
                             << result.winningHand->Name() << "\n";
                reportStream << "Rules Applied: ";
                for(const auto& rule : result.appliedRules) {
                    reportStream << "\t" << rule->Description() << "\n";
                }
                reportStream << "Winners:\n";
                for (const auto& winner : result.winners) {
                    reportStream << "\t" << winner->GetId() << "\n";
                }
                break;
            }
            case moghya::HandGame::State::DRAW: {
                reportStream << "Draw! "
                             << "All players chose same hand.\n";
                break;
            }
            case moghya::HandGame::State::STALEMATE: {
                reportStream << "Stalemate! "
                             << "No hand could be chosen as winner.\n";
                break;
            }
            case moghya::HandGame::State::ERR_INSUFFICIENT_RULES: {
                reportStream << "Stalemate! "
                             << "No sufficient rules to choose winner.\n";
                break;
            }
            case moghya::HandGame::State::ERR_INTERNAL_ERROR: {
                reportStream << "Error! Unknown Internal Error Occurred.\n";
                break;
            }
        }
        std::string reportMsg = reportStream.str();
        for(auto p: players) p->SendMessage(reportMsg);
    }

    HandGame::Result HandGame::ApplyRules(
            const RuleSet& ruleSet,
            const HandGame::PlayerHandMap& playerHandMap) {
        std::set<Hand::Ptr> uniqueHands;
        for(const auto& mapEntry : playerHandMap) {
            auto hand = mapEntry.second;
            uniqueHands.insert(hand);
        }
        if (uniqueHands.size() == 1) {
            return {State::DRAW, {}, nullptr, {}};
        }

        RuleSet appliedRules;
        auto it = uniqueHands.begin();
        auto winningHand = *it;
        while(++it != uniqueHands.end()) {
            const auto& curr = *it;
            if (winningHand == curr) {
                continue;
            }
            bool applied = false;
            for(const auto& rule : ruleSet) {
                if(auto rc = rule->Apply(winningHand, curr)) {
                    appliedRules.insert(rule);
                    winningHand = rc;
                    applied = true;
                    break ;
                }
            }
            if (!applied) {
                return {State::ERR_INSUFFICIENT_RULES, {}, nullptr, {}};
            }
        }
        std::set<Player::Ptr> winners;
        for(const auto& player : playerHandMap) {
            if(winningHand == player.second) {
                winners.insert(player.first);
            }
        }
        return {State::WINNERS_COMPUTED, winners, winningHand, appliedRules};
    }
}