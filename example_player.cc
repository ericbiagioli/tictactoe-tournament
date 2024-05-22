#include "example_player.h"


bool is_valid_movei(Board &b, int where)
{
    return (where >= 0 && where < 9 && b[where] == ' ');
}

bool woni(Board const& b, char s)
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

bool is_emptyi(Board const& b)
{
    for (int i = 0; i < 9; ++i)
        if (b[i] != ' ')
            return false;
    return true;
}

bool is_fulli(Board const& b)
{
    for (int i = 0; i < 9; ++i)
        if (b[i] == ' ')
            return false;
    return true;
}

double Example_player::evaluate(Board const& b, char turn_of)
{
    if (woni(b, turn_of))
        return 1;
    if (woni(b, (turn_of == 'X' ? 'O' : 'X')))
        return -1;
    if (is_fulli(b))
        return 0;

    double ans=0, t=0;

    for(int i = 0; i < 9; ++i)
    {
        if (b[i] == ' ')
        {
            Board b_copy = b;
            b_copy[i] = turn_of;
            if (woni(b_copy, turn_of))
                ans += 1;
            else
                ans += evaluate(b_copy, (turn_of == 'X' ? 'O' : 'X'));
            ++t;
            b_copy[i] = ' ';
        }
    }
    return ans/t;
}
int Example_player::get_move(Board const& b, char turn_of)
{
    Board b_copy = b;
    if (is_emptyi(b_copy))
        return 4;
    
    int best_move = -1;
    double best_score = -10000.0;
    
    for (int i = 0; i < 9; ++i)
    {
        if (b_copy[i] == ' '){
            b_copy[i] = turn_of;
            if (woni(b_copy, turn_of))
                return i;
            
            double score = evaluate(b_copy, (turn_of == 'X' ? 'O' : 'X'));
            if (score > best_score)
            {
                best_score = score;
                best_move = i;
            }
            b_copy[i] = ' ';
        }
    }
    return best_move;
}

