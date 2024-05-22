#include "cesar.h"

int Cesar_player::get_move(Board const& b, char turn_of) {
    // si el tablero esta vacio, jugar en el centro
    if (empty(b)) return 4;

    // puedo ganar en el siguiente movimiento?
    int move = next_inmm_wins(b, turn_of);
    if (move != -1) return move;

    // el otro puede ganar?
    char opponent = (turn_of == 'X') ? 'O' : 'X';
    move = next_inmm_wins(b, opponent);
    if (move != -1) return move;

    //juega en la primera casilla vacia
    // for (int i = 0; i < 9; ++i) {
    //     if (b[i] == ' ') {
    //         return i;
    //     }
    // }

    // return -1;

    //fuerza bruta
    move = bestMove(b, turn_of);
    
    // mover
    return move;

}

int Cesar_player::bestMove(Board b, int turn_of) {
    int best = -1;
    int best_wins = -1;
    for (int i = 0; i < 9; ++i) {
        if (b[i] == ' ') {
            int wins = get_wins(b, turn_of, i);
            if (wins > best_wins) {
                best = i;
                best_wins = wins;
            }
        }
    }
    return best;
}

int Cesar_player::get_wins(Board const& b, char s, int next) {
    char opponent = (s == 'X') ? 'O' : 'X';
    Board b_copy = b;
    b_copy[next] = s;
    int wins = 0;
    for (int i = 0; i < 9; ++i) { //en cual puede poner mi opponent
        if (b_copy[i] == ' ') {
            Board b_copy2 = b_copy;
            b_copy2[i] = opponent;
            //si mi oponente gana, pues wins no aumenta
            if (!won(b_copy2, opponent)) {
                //agregar todos mis posible movimientos
                for (int j = 0; j < 9; ++j) {
                    if (b_copy2[j] == ' ') {
                        Board b_copy3 = b_copy2;
                        b_copy3[j] = s;
                        wins += get_wins(b_copy3, s, j);
                    }
                }
            }
        }
    }

    return wins;
}

bool Cesar_player::won(Board const& b, char s) {
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

bool Cesar_player::isFull(Board const& b) {
    for (int i = 0; i < 9; ++i) {
        if (b[i] == ' ') {
            return false;
        }
    }
    return true;
}

bool Cesar_player::empty(Board const& b) {
    for (int i = 0; i < 9; ++i) {
        if (b[i] != ' ') {
            return false;
        }
    }
    return true;
}

int Cesar_player::next_inmm_wins(Board const& b, char s) {
    for (int i = 0; i < 9; ++i) {
        if (b[i] == ' ') {
            Board b_copy = b;
            b_copy[i] = s;
            if (won(b_copy, s)) {
                return i;
            }
        }
    }
    return -1;
}

