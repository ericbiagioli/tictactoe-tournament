#pragma once

#include "Player.h"

struct luis_izaguirre : public Player
{
    int get_move(Board const& b, char turn_of);
};

