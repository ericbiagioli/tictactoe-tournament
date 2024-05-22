#ifndef player_h
#define player_h
#include <array>
#include <iostream>

enum class Status { INVALID_BOTH_WON, ENDED_WON_X, ENDED_WON_O, ENDED_NOBODY_WON, NOT_ENDED };
enum class Token { X, O, EMPTY };

typedef std::array<Token, 9> Board;

//override board <<

struct Player
{   
    Token token;
    Player(Token t) : token{t} {}
    virtual int get_move(Board const&)=0;
};

#endif
