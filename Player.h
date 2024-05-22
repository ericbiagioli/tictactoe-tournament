#ifndef player_h
#define player_h
#include <array>

const int INVALID_BOTH_WON = 0;
const int ENDED_WON_X = 1;
const int ENDED_WON_O = 2;
const int ENDED_NOBODY_WON = 3;
const int NOT_ENDED = 4;

typedef std::array<char, 9> Board;

struct Player
{
    virtual int get_move(Board const&, char) = 0;
};

#endif
