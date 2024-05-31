#pragma once

#include "Player.h"

struct juan_diego_castro: public Player
{
    int get_move(Board const& b, char turn_of);
};

