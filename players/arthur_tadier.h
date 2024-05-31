#ifndef arthur_player_h
#define arthur_player_h

#include "Player.h"

struct Arthur : public Player
{
    int get_move(Board const& b, char turn_of);
};

#endif
