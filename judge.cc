#include <string>
#include <iostream>

#include "Player.h"

struct First_free : public Player
{
    int get_move(Board const& b, char turn_of)
    {
        for (int i = 0; i < 9; ++i)
            if (b[i] == ' ')
                return i;
    }
};

bool is_valid_move(Board &b, int where)
{
    return (where >= 0 && where < 9 && b[where] == ' ');
}

bool move(Board &b, char symbol, int where)
{
    if (!is_valid_move(b, where))
        return false;
    b[where] = symbol;
    return true;
}

bool won(Board const& b, char s)
{
    return
        (b[0] == s && b[1] == s && b[2] == s) ||
        (b[3] == s && b[4] == s && b[5] == s) ||
        (b[6] == s && b[7] == s && b[8] == s) ||
        (b[0] == s && b[3] == s && b[6] == s) ||
        (b[1] == s && b[4] == s && b[7] == s) ||
        (b[2] == s && b[5] == s && b[8] == s) ||
        (b[0] == s && b[4] == s && b[8] == s) ||
        (b[6] == s && b[4] == s && b[2] == s);
}

int status(Board const& b)
{
    if (won(b, 'X') && won(b, 'O')) return INVALID_BOTH_WON;
    if (won(b, 'X')) return ENDED_WON_X;
    if (won(b, 'O')) return ENDED_WON_O;
    int t = 0;
    for (int i = 0; i < 9; ++i)
        if (b[i] == ' ')
            ++t;
    if (t == 0)
        return ENDED_NOBODY_WON;
    return NOT_ENDED;
}

int main()
{
    return 0;
}
