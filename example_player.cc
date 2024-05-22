#include "example_player.h"

int Example_player::get_move(Board const& b, char token)  {
    for (int i = 0; i < 9; ++i)
        if (b[i] ==  ' ')
            return i;
    return -1;
}

