#ifndef example_player_h
#define example_player_h

#include "Player.h"

struct Example_player : public Player
{
    int get_move(Board const& b, char turn_of);
    double evaluate(Board const& b, char turn_of);
};

#endif
