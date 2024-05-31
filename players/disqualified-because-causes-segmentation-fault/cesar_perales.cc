#include "cesar_perales.h"

int cesar_perales::get_move(Board const& b, char turn_of) {
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

int cesar_perales::bestMove(Board b, int turn_of) {
    int best = -1;
    int best_wins = -9999991;
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

int cesar_perales::get_wins(Board const& b, char s, int next) {
    Board b_copy = b;
    b_copy[next] = s;
    if (won(b_copy, s)) {
        return 1;
    }
    char opponent = (s == 'X') ? 'O' : 'X';
    int wins = 0;
    for (int i = 0; i < 9; ++i) {
        if (b_copy[i] == ' ') {
            b_copy[i] = opponent;
            if (won(b_copy, opponent)) {
                return -1;
            }
            for (int j = 0; j < 9; ++j) {
                if (b_copy[j] == ' ') {
                    wins += get_wins(b_copy, s, j);
                }
            }
        }
    }
    return wins;
}


bool cesar_perales::won(Board const& b, char s) {
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

bool cesar_perales::isFull(Board const& b) {
    for (int i = 0; i < 9; ++i) {
        if (b[i] == ' ') {
            return false;
        }
    }
    return true;
}

bool cesar_perales::empty(Board const& b) {
    for (int i = 0; i < 9; ++i) {
        if (b[i] != ' ') {
            return false;
        }
    }
    return true;
}

int cesar_perales::next_inmm_wins(Board const& b, char s) {
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

