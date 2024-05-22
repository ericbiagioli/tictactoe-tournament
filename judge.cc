#include <string>
#include <iostream>
#include <memory>
#include <vector>

#include "Player.h"
#include "example_player.h"

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


struct ByJuanDiego_player: public Player 
{
    int get_move(Board const& b, char turn_of) {
        for (int i = 0; i < 3; ++i) {
            int s = i * 3;
            if (b[s] == turn_of && b[s + 1] == turn_of && b[s + 2] == ' ') 
                return s + 2;
            if (b[s] == turn_of && b[s + 2] == turn_of && b[s + 1] == ' ') 
                return s + 1;
            if (b[s + 1] == turn_of && b[s + 2] == turn_of && b[s] == ' ') 
                return s;
            if (b[i] == turn_of && b[i + 3] == turn_of && b[i + 6] == ' ') 
                return i + 6;
            if (b[i] == turn_of && b[i + 6] == turn_of && b[i + 3] == ' ') 
                return i + 3;
            if (b[i + 3] == turn_of && b[i + 6] == turn_of && b[i] == ' ') 
                return i;
        }
    
        if (b[0] == turn_of && b[4] == turn_of && b[8] == ' ') 
            return 8;
        if (b[0] == turn_of && b[8] == turn_of && b[4] == ' ') 
            return 4;
        if (b[4] == turn_of && b[8] == turn_of && b[0] == ' ') 
            return 0;
    
        if (b[2] == turn_of && b[4] == turn_of && b[6] == ' ') 
            return 6;
        if (b[2] == turn_of && b[6] == turn_of && b[4] == ' ') 
            return 4;
        if (b[4] == turn_of && b[6] == turn_of && b[2] == ' ') 
            return 2;
        
    
        if (b[4] == ' ') 
            return 4;
        for (int i : {0, 2, 6, 8}) if (b[i] == ' ') 
            return i;
        for (int i : {1, 3, 5, 7}) if (b[i] == ' ') 
            return i;
    
        return -1;
    }
};

int main()
{
    std::vector<Player*> players;
    std::vector<std::string> names;

    players.push_back(new Example_player());
    names.push_back("Example_player");
    players.push_back(new Example_player());
    names.push_back("Example_player");

    for (int i =0; i < players.size(); ++i)
        for (int j = i + 1; j < players.size(); ++j)
        {
            std::cout << "Game between " << names[i] << " (X) and " << names[j] << "(O) " << std::endl;
            int result = play_game(players[0], players[1]);
            if (result == ENDED_NOBODY_WON)
                std::cout << "  " << "Nobody won" << std::endl;
            else if (result == ENDED_WON_X)
                std::cout << "  " << "X won" << std::endl;
            else if (result == ENDED_WON_O)
                std::cout << "  " << "O won" << std::endl;
            else
                std::cout << "  " << "Not handled result" << std::endl;
        }

    return 0;
}
