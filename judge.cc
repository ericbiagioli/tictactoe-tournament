#include <string>
#include <iostream>
<<<<<<< HEAD
#include "Melisa.h"
=======
#include <memory>
#include <vector>
>>>>>>> origin/main

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

<<<<<<< HEAD
bool isFull(Board const& b)
{
    for (int i = 0; i < 9; ++i)
        if (b[i] == ' ')
            return false;
    return true;
=======
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
>>>>>>> origin/main
}

int main()
{
<<<<<<< HEAD
     MyStrategy p = MyStrategy();
    Board b;

    //inicialiar b con espacios
    for (int i = 0; i < 9; ++i) {
        b[i] = ' ';
    }

    char turn_of = 'X';
    int count = 0;
    while (true) {
        p.print_board(b);
        if (count % 2 == 0) {
            //soliciatar movimiento al usuario
            int move;
            std::cout << "Ingrese su movimiento: ";
            std::cin >> move;
            b[move] = turn_of;
        } else {
            //solicitar movimiento a la computadora
            int move = p.get_move(b, turn_of);
            b[move] = turn_of;
        }
        
        if (won(b, turn_of)) {
            p.print_board(b);
            std::cout << "Ganador: " << turn_of << std::endl;
            break;
        }
        if (isFull(b)) {
            p.print_board(b);
            std::cout << "Empate" << std::endl;
            break;
        }
        turn_of = (turn_of == 'X') ? 'O' : 'X';
        count++;
    }
=======
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

>>>>>>> origin/main
    return 0;
}
