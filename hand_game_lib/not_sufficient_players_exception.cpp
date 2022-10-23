//
// Created by Shubham Sawant on 23/10/22.
//

#include "not_sufficient_players_exception.h"

namespace moghya {
    NotSufficientPlayerException::NotSufficientPlayerException(
            const std::string msg)
        : std::runtime_error(msg.c_str()) {
    }
    NotSufficientPlayerException::~NotSufficientPlayerException() = default;
}