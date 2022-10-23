//
// Created by Shubham Sawant on 23/10/22.
//

#ifndef RPS_GAME_NOT_SUFFICIENT_PLAYERS_EXCEPTION_H
#define RPS_GAME_NOT_SUFFICIENT_PLAYERS_EXCEPTION_H

#include <stdexcept>
#include <string>

namespace moghya {
    class NotSufficientPlayerException : public std::runtime_error {
        public:
            explicit NotSufficientPlayerException(const std::string msg);
            ~NotSufficientPlayerException() override;
    };
}
#endif//RPS_GAME_NOT_SUFFICIENT_PLAYERS_EXCEPTION_H
