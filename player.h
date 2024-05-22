#ifndef player_h
#define player_h


struct player : public player
{
    int get_move(Board const& b, char turn_of);
};

#endif