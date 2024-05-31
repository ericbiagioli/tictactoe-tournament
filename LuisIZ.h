#ifndef LuisIZ_h
#define LuisIZ_h

#include "Player.h"

struct LuisIzaguirre : public Player
{
    int get_move(Board const& b, char turn_of);
};

#endif
