#pragma once

#include "Player.h"

struct arthur_tadier : public Player
{
    int get_move(Board const& b, char turn_of);
    bool eq(char a, char b, char c, char p);
    bool won(Board const &b, char s);
};

