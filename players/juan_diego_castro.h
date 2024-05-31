#ifndef juan_diego_player_h
#define juan_diego_player_h

#include "Player.h"

struct ByJuanDiego_player: public Player 
{
    int get_move(Board const& b, char turn_of);
};

#endif
