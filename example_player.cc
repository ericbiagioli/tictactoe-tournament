#include "example_player.h"

int Example_player::get_move(Board const& b, char turn_of)
{
    for (int i = 0; i < 9; ++i)
        if (b[i] == ' ')
            return i;
    return -1;
}

