#include "example_player.h"

int Example_player::get_move(Board const& b)  {
    for (int i = 0; i < 9; ++i)
        if (b[i] ==  Token::EMPTY)
            return i;
    return -1;
}

