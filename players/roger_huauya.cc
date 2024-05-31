#include "roger_huauya.h"

bool roger_huauya::won2(Board const& b, char s)
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

bool roger_huauya::can_win(Board const& b, char token, int move) {
    Board temp = b;
    temp[move] = token;
    return won2(temp, token);
}

int roger_huauya::get_move(Board const& b, char token) {
    for (int i = 0; i < 9; ++i) {
        if (b[i] == ' ' && can_win(b, token, i)) {
            return i;
        }
    }

    char opponent = (token == 'X') ? 'O' : 'X';
    for (int i = 0; i < 9; ++i) {
        if (b[i] == ' ' && can_win(b, opponent, i)) {
            return i;
        }
    }

    if (b[4] == ' ') {
        return 4;
    }

    const std::vector<int> corners = {0, 2, 6, 8};
    for (int corner : corners) {
        if (b[corner] == ' ') {
            return corner;
        }
    }

    for (int i = 0; i < 9; ++i) {
        if (b[i] == ' ') {
            return i;
        }
    }

    return -1;
}
