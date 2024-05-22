#ifndef example_player_h
#define example_player_h

#include "Player.h"

struct Example_player : public Player
{
    Example_player() {}
    int get_move(Board const& b, char token);
};

#endif
