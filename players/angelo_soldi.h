#ifndef example_player_h
#define example_player_h

#include <iostream>
#include "Player.h"

struct Example_player : public Player
{
    int get_move(Board const& b, char turn_of);
};

#endif
