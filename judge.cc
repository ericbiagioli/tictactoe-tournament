#include <string>
#include <iostream>
#include "Melisa.h"

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

bool isFull(Board const& b)
{
    for (int i = 0; i < 9; ++i)
        if (b[i] == ' ')
            return false;
    return true;
}

int main()
{
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
    return 0;
}
