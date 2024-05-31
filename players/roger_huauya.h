#pragma once

#include <vector>
#include "Player.h"

struct roger_huauya : public Player
{
    roger_huauya() {}
    int get_move(Board const& b, char token);
    bool won2(Board const& b, char s);
    bool can_win(Board const& b, char token, int move);
};

