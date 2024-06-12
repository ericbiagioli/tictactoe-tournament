#pragma once
#include "../Player.h"
struct jerimy_sandoval : public Player {
    int get_move(Board const& b, char turn_of);
    int minimax(Board const& b, char player, bool is_maximizing, int alpha, int beta);
};

