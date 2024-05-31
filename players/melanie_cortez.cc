#include "melanie_cortez.h"

int melanie_cortez::get_move(Board const& b, char turn_of)
{
    char other = (turn_of == 'X')? 'O':'X';

    for (int i = 0; i < 9; i++){
        switch (i){ // to win
            case 0:
                if ((b[1] == b[2] && b[1] != turn_of) ||
                    (b[3] == b[6] && b[3] != turn_of) ||
                    (b[4] == b[8] && b[4] != turn_of))
                    return 0;
                break;
            case 1:
                if ((b[0] == b[2] && b[0] != turn_of) ||
                    (b[4] == b[7] && b[4] != turn_of))
                    return 1;
                break;
            case 2:
                if ((b[1] == b[0] && b[1] != turn_of) ||
                    (b[4] == b[6] && b[4] != turn_of) ||
                    (b[5] == b[8] && b[5] != turn_of))
                    return 2;
                break;
            case 3:
                if ((b[0] == b[6] && b[0] != turn_of) ||
                    (b[4] == b[5] && b[4] != turn_of))
                    return 3;
                break;
            case 4:
                if ((b[8] == b[0] && b[0] != turn_of) ||
                    (b[2] == b[6] && b[2] != turn_of) ||
                    (b[1] == b[7] && b[1] != turn_of) ||
                    (b[3] == b[5] && b[3] != turn_of))
                    return 4;
                break;
            case 5:
                if ((b[2] == b[8] && b[2] != turn_of) ||
                    (b[3] == b[4] && b[2] != turn_of))
                    return 5;
                break;
            case 6:
                if ((b[0] == b[3] && b[0] != turn_of) ||
                    (b[7] == b[8] && b[7] != turn_of) ||
                    (b[4] == b[2] && b[4] != turn_of))
                    return 6;
                break;
            case 7:
                if ((b[1] == b[4] && b[1] != turn_of) ||
                    (b[6] == b[8] && b[6] != turn_of))
                    return 7;
                break;
            case 8:
                if ((b[2] == b[5] && b[2] != turn_of) ||
                    (b[6] == b[7] && b[6] != turn_of) ||
                    (b[0] == b[4] && b[0] != turn_of))
                    return 8;
                break;
        }

        switch (i){ // if not possible win, stop opp win
            case 0:
                if ((b[1] == b[2] && b[1] != other) ||
                    (b[3] == b[6] && b[3] != other) ||
                    (b[4] == b[8] && b[4] != other))
                    return 0;
                break;
            case 1:
                if ((b[0] == b[2] && b[0] != other) ||
                    (b[4] == b[7] && b[4] != other))
                    return 1;
                break;
            case 2:
                if ((b[1] == b[0] && b[1] != other) ||
                    (b[4] == b[6] && b[4] != other) ||
                    (b[5] == b[8] && b[5] != other))
                    return 2;
                break;
            case 3:
                if ((b[0] == b[6] && b[0] != other) ||
                    (b[4] == b[5] && b[4] != other))
                    return 3;
                break;
            case 4:
                if ((b[8] == b[0] && b[0] != other) ||
                    (b[2] == b[6] && b[2] != other) ||
                    (b[1] == b[7] && b[1] != other) ||
                    (b[3] == b[5] && b[3] != other))
                    return 4;
                break;
            case 5:
                if ((b[2] == b[8] && b[2] != other) ||
                    (b[3] == b[4] && b[2] != other))
                    return 5;
                break;
            case 6:
                if ((b[0] == b[3] && b[0] != other) ||
                    (b[7] == b[8] && b[7] != other) ||
                    (b[4] == b[2] && b[4] != other))
                    return 6;
                break;
            case 7:
                if ((b[1] == b[4] && b[1] != other) ||
                    (b[6] == b[8] && b[6] != other))
                    return 7;
                break;
            case 8:
                if ((b[2] == b[5] && b[2] != other) ||
                    (b[6] == b[7] && b[6] != other) ||
                    (b[0] == b[4] && b[0] != other))
                    return 8;
                break;
        }
    }

    if (b[0] == ' ') return 0;
    if (b[6] == ' ') return 6;
    if (b[2] == ' ') return 2;
    if (b[8] == ' ') return 8;

    for (int i = 0; i < 9; i++){
        if (b[i] == ' ') return i;
    }
    return -1;
}
