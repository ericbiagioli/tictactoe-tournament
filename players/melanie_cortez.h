#ifndef melanie_player_h
#define melanie_player_h

#include "Player.h"

struct Melanie_player : public Player
{
    int get_move(Board const& b, char turn_of);
};

#endif
