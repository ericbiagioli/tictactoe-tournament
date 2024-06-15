#include <limits>
#include "juan_diego_castro.h"



inline bool is_valid_move(Board &b, int pos) {
    return (pos >= 0 && pos < 9 && b[pos] == ' ');
}


bool eq(char a, char b, char c, char p) {
    return (a == p) && (b == p) && (c == p);
}



bool won(Board const &b, char s) {
    return (eq(b[0], b[1], b[2], s) || eq(b[3], b[4], b[5], s) ||
            eq(b[6], b[7], b[8], s) || eq(b[0], b[3], b[6], s) ||
            eq(b[1], b[4], b[7], s) || eq(b[2], b[5], b[8], s) ||
            eq(b[0], b[4], b[8], s) || eq(b[6], b[4], b[2], s));
}

int status(Board const &b) {
    if (won(b, 'X') && won(b, 'O')) {
        return INVALID_BOTH_WON;
    }

    if (won(b, 'X')) {
        return WON_X;
    }

    if (won(b, 'O')) {
        return WON_O;
    }

    int t = 0;
    for (int i = 0; i < 9; ++i) {
        if (b[i] == ' ') {
            ++t;
        }
    }

    if (t == 0) {
        return NOBODY_WON;
    }

    return NOT_ENDED;
}


int minimax(Board const &b, char turn_of, int depth) {
    int s = status(b);

    if (s == WON_X) {
        return 10 - depth; // 'X' wins
    }
    if (s == WON_O) {
        return depth - 10; // 'O' wins
    }
    if (s == NOBODY_WON) {
        return 0; // Draw
    }

    if (turn_of == 'X') {
        int bestScore = std::numeric_limits<int>::min();
        for (int i = 0; i < 9; ++i) {
            if (b[i] == ' ') {
                Board copy = b;
                copy[i] = 'X';
                int score = minimax(copy, 'O', depth + 1);
                bestScore = std::max(bestScore, score);
            }
        }
        return bestScore;
    } else {
        int bestScore = std::numeric_limits<int>::max();
        for (int i = 0; i < 9; ++i) {
            if (b[i] == ' ') {
                Board copy = b;
                copy[i] = 'O';
                int score = minimax(copy, 'X', depth + 1);
                bestScore = std::min(bestScore, score);
            }
        }
        return bestScore;
    }
}


int juan_diego_castro::get_move(Board const &b, char turn_of) {
    int bestMove = -1;
    int bestScore = std::numeric_limits<int>::min();
    for (int i = 0; i < 9; ++i) {
        if (b[i] == ' ') {
            Board copy = b;
            copy[i] = turn_of;
            int score = minimax(copy, (turn_of == 'X') ? 'O' : 'X', 0);
            if (score > bestScore) {
                bestScore = score;
                bestMove = i;
            }
        }
    }
    return bestMove;
}
