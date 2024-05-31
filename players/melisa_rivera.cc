#include "melisa_rivera.h"

int melisa_rivera::amIinDanger(Board const& b, char turn_of)
{
    //filas
    for (int i = 0; i < 9; i += 3)
    {
        if (b[i] == turn_of && b[i+1] == turn_of && b[i+2] == ' ')
            return i+2;
        if (b[i] == turn_of && b[i+1] == ' ' && b[i+2] == turn_of)
            return i+1;
        if (b[i] == ' ' && b[i+1] == turn_of && b[i+2] == turn_of)
            return i;
    }
    //columnas
    for (int i = 0; i < 3; ++i)
    {
        if (b[i] == turn_of && b[i+3] == turn_of && b[i+6] == ' ')
            return i+6;
        if (b[i] == turn_of && b[i+3] == ' ' && b[i+6] == turn_of)
            return i+3;
        if (b[i] == ' ' && b[i+3] == turn_of && b[i+6] == turn_of)
            return i;
    }

    //diagonales
    if (b[0] == turn_of && b[4] == turn_of && b[8] == ' ')
        return 8;
    if (b[0] == turn_of && b[4] == ' ' && b[8] == turn_of)
        return 4;
    if (b[0] == ' ' && b[4] == turn_of && b[8] == turn_of)
        return 0;

    if (b[2] == turn_of && b[4] == turn_of && b[6] == ' ')
        return 6;
    if (b[2] == turn_of && b[4] == ' ' && b[6] == turn_of)
        return 4;
    if (b[2] == ' ' && b[4] == turn_of && b[6] == turn_of)
        return 2;

    return -1;
}

int melisa_rivera::get_move(Board const& b, char turn_of)
{
    char other = (turn_of == 'X') ? 'O' : 'X';
    int dangerM = amIinDanger(b, other);

    int dangerH = amIinDanger(b, turn_of);

    if (dangerH != -1)
        return dangerH;

    if (dangerM != -1)
        return dangerM;

    if (b[4] == ' ')
        return 4;
    for (int i = 0; i < 9; ++i)
        if (i%2 == 0 && b[i] == ' ')
            return i;

}
bool melisa_rivera::move(Board &b, char symbol, int where)
{
    if (where < 0 || where >= 9 || b[where] != ' ')
        return false;
    b[where] = symbol;
    return true;
}

void melisa_rivera::print_board(Board const& b)
{
    /*
    | 6 | | 7 | | 8 |
    | 3 | | 4 | | 5 |
    | 0 | | 1 | | 2 |
    */
    std::cout << " | " << b[6] << " | | " << b[7] << " | | " << b[8] << " | " << std::endl;
    std::cout << " | " << b[3] << " | | " << b[4] << " | | " << b[5] << " | " << std::endl;
    std::cout << " | " << b[0] << " | | " << b[1] << " | | " << b[2] << " | " << std::endl;
}

void melisa_rivera::make_move(Board& b, char symbol, int where)
{
    where = get_move(b, symbol);
    if(move(b, symbol, where))
        b[where] = symbol;
    else
        std::cout << "Invalid move" << std::endl;

    //print_board(b);
}
