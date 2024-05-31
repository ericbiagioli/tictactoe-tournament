#pragma once

#include "Player.h"
#include <iostream>


struct melisa_rivera : public Player
{
    int amIinDanger(Board const& b, char turn_of);
    int get_move(Board const& b, char turn_of);
    bool move(Board &b, char symbol, int where);
    void make_move(Board& b, char symbol, int where);
    void print_board(Board const& b);

};
