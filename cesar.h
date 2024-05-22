#include "player.h"

struct Cesar_player : public Player
{
    int get_move(Board const& b, char turn_of)
    {
        bool is_empty = true;
        // middle cell if the board is empty
        for (int i = 0; i < 9; ++i) {
            if (b[i] != ' ') {
                is_empty = false;
                break;
            }
        }

        if (is_empty) return 4;

        // puedo ganar en el siguiente movimiento?
        for (int i = 0; i < 9; ++i) {
            if (b[i] == ' ') {
                Board b_copy = b;
                b_copy[i] = turn_of;
                if (won(b_copy, turn_of)) {
                    return i;
                }
            }
        }

        // el otro puede ganar?
        char opponent = (turn_of == 'X') ? 'O' : 'X';

        for (int i = 0; i < 9; ++i) {
            if (b[i] == ' ') {
                Board b_copy = b;
                b_copy[i] = opponent;
                if (won(b_copy, opponent)) {
                    return i;
                }
            }
        }

        // usar fuerza bruta para encontrar el mejor movimiento que me da la mayor cantidad de posibilidades de ganar
        
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
};