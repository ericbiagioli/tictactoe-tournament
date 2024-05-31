#include <array>
#include <vector>

#include "arthur.h"

using namespace std;

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

int Arthur::get_move(Board const& b, char turn_of)
{
    // turn 1 and 2: pick center if possible
    if (b[4] == ' ') return 4;

    char opponent = turn_of == 'X' ? 'O' : 'X';
    int turn = 1;
    int opponentFirstPosition = -1;
    vector<int> possible = {};

    for (int i = 0; i < 9; i++) {
        // not empty, do not consider
        if (b[i] != ' ') {
            turn++;
            if (opponentFirstPosition == -1 && b[i] == opponent) opponentFirstPosition = i;
            continue;
        }

        Board modified = b;
        modified[i] = turn_of;

        // if we win, play this
        if (won(modified, turn_of)) {
            return i;
        }

        // evaluate opponent response
        bool opponentWins = false;
        for (int j = 0; j < 9; j++) {
            if (modified[j] != ' ') continue;

            modified[j] = opponent;
            opponentWins |= won(modified, opponent);
            modified[j] = ' ';
        }
        
        // if they win, don't play this
        if (opponentWins) continue;


        possible.push_back(i);
    }

    // turn 3 side pick: pick an adjacent corner
    if (turn == 3 && opponentFirstPosition % 2 == 1) return opponentFirstPosition < 4 ? 0 : 8;

    // pick first move
    return possible[0];
}
