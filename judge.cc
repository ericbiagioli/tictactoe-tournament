#include <string>
#include <iostream>

#include "Player.h"
#include "asoldi.h"

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

int eva(Board const& b, char turn_of){
    // Try to find a winning move first
    for (int i = 0; i < 9; ++i) {
        if (is_valid_move(const_cast<Board&>(b), i)) {
            Board temp = b;
            if (::move(temp, turn_of, i) && won(temp, turn_of)) {
                return i;
            }
        }
    }

    // Try to block the opponent's winning move
    char opponent = (turn_of == 'X') ? 'O' : 'X';
    for (int i = 0; i < 9; ++i) {
        if (is_valid_move(const_cast<Board&>(b), i)) {
            Board temp = b;
            if (move(temp, opponent, i) && won(temp, opponent)) {
                return i;
            }
        }
    }

    // Otherwise, take the first available move
    for (int i = 0; i < 9; ++i) {
        if (is_valid_move(const_cast<Board&>(b), i)) {
            return i;
        }
    }

    // no moves are available, return an invalid move
    return -1;
}

int main() {
    Board b = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char turn_of = 'X';
    int s;
    Example_player p;
    while (status(b) == NOT_ENDED) {
        s = p.get_move(b, turn_of);
        if (is_valid_move(b, s)) {
            move(b, turn_of, s);
            turn_of = (turn_of == 'X') ? 'O' : 'X';
        }
    }
    std::cout << "VIVO";
    switch (status(b)) {
        case ENDED_WON_X:
            std::cout << "X won" << std::endl;
            break;
        case ENDED_WON_O:
            std::cout << "O won" << std::endl;
            break;
        case ENDED_NOBODY_WON:
            std::cout << "Nobody won" << std::endl;
            break;
        case INVALID_BOTH_WON:
            std::cout << "Both won" << std::endl;
            break;
    }
    return 0;
}



