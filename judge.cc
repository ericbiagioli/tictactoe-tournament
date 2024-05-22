#include <string>
#include <iostream>
#include <memory>
#include <vector>

#include "Player.h"
#include "example_player.h"

bool is_valid_move(Board &b, int where)
{
    return (where >= 0 && where < 9 && b[where] == Token::EMPTY);
}

bool move(Board &b, Token symbol, int where)
{
    if (!is_valid_move(b, where))
        return false;
    b[where] = symbol;
    return true;
}

bool won(Board const& b, Token s)
{
    for (int i = 0; i < 3; ++i)
    {
        if (b[i] == s && b[i + 3] == s && b[i + 6] == s)
            return true;
        if (b[3 * i] == s && b[3 * i + 1] == s && b[3 * i + 2] == s)
            return true;
    }
    if (b[0] == s && b[4] == s && b[8] == s)
        return true;
    if (b[2] == s && b[4] == s && b[6] == s)
        return true;
    return false;
}


Status status(Board const& b)
{  
   if (won(b, Token::X) && won(b, Token::O)) return Status::INVALID_BOTH_WON;
    if (won(b, Token::X)) return Status::ENDED_WON_X;
    if (won(b, Token::O)) return Status::ENDED_WON_O;
    int t = 0;
    for (int i = 0; i < 9; ++i)
        if (b[i] == Token::EMPTY)
            ++t;
    if (t == 0)
        return Status::ENDED_NOBODY_WON;
    return Status::NOT_ENDED;
}

std::ostream& operator<<(std::ostream& os, const Board& b)
{
    for (int i = 0; i < 9; ++i)
    {
        if (i % 3 == 0)
            os << std::endl;
        if (b[i] == Token::X)
            os << "X ";
        else if (b[i] == Token::O)
            os << "O ";
        else
            os << ". ";
    }
    return os;
}

int play_game(Player *p_X, Player *p_O)
{
    Board b{};
    char whomoves = 'X';
    while (status(b) == NOT_ENDED)
    {
        int next_move = -1;
        if (whomoves == 'X')
            next_move = p_X->get_move(b, 'X');
        else
            next_move = p_O->get_move(b, 'O');

        if (is_valid_move(b, next_move))
            b[next_move] = whomoves;
        else
            return (whomoves == 'X' ? ENDED_WON_O : ENDED_WON_X);
        whomoves = ((whomoves == 'X') ? 'O' : 'X');
    }
    return status(b);
}

int main()
{
    Example_player p1 = Example_player(Token::X);
    Example_player p2 = Example_player(Token::O);
    Board b = {
        Token::EMPTY, Token::EMPTY, Token::EMPTY,
        Token::EMPTY, Token::EMPTY, Token::EMPTY,
        Token::EMPTY, Token::EMPTY, Token::EMPTY
    };
    Token turn_of = Token::X;
    while (status(b) == Status::NOT_ENDED)
    {
        int _move = (turn_of == Token::X) ? p1.get_move(b) : p2.get_move(b);
        if (move(b, turn_of, _move))
            turn_of = (turn_of == Token::X) ? Token::O : Token::X;
    }

    std::cout << "Game final board:" << std::endl;
    std::cout << b << std::endl;

    if (status(b) == Status::INVALID_BOTH_WON)
        std::cout << "Both players won\n";
    else if (status(b) == Status::ENDED_WON_X)
        std::cout << "Player 1 won\n";
    else if (status(b) == Status::ENDED_WON_O)
        std::cout << "Player 2 won\n";
    else if (status(b) == Status::ENDED_NOBODY_WON)
        std::cout << "Nobody won\n";
    
    
    return 0;
}
