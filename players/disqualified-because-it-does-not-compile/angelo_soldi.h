#pragma once

#include <iostream>
#include "Player.h"

struct angelo_soldi : public Player
{
    int get_move(Board const& b, char turn_of);
};

