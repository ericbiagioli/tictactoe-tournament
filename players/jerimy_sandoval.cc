#include "../players/jerimy_sandoval.h"

int jerimy_sandoval::get_move(Board const& b, char turn_of) {
    int best_move = -1;
    int best_score = -1000;
    for (int i = 0; i < 9; ++i) {
        if (b[i] == ' ') {
            Board new_board = b;
            new_board[i] = turn_of;
            int score = minimax(new_board, turn_of == 'X' ? 'O' : 'X', false, -1000, 1000);
            if (score > best_score) {
                best_score = score;
                best_move = i;
            }
        }
    }
    return best_move;
}

int jerimy_sandoval::minimax(Board const& b, char player, bool is_maximizing, int alpha, int beta) {
        // Verificar si el juego ha terminado y quién ha ganado
    char opponent = (player == 'X') ? 'O' : 'X';
    bool is_game_over = true;
    bool is_tie = true;
    bool is_x_won = false;
    bool is_o_won = false;

    for (int i = 0; i < 9; ++i) {
        if (b[i] == ' ') {
            is_game_over = false;
            is_tie = false;
        }
    }

    if (!is_game_over) {
        // Verificar filas, columnas y diagonales para determinar si alguien ha ganado
        for (int i = 0; i < 3; ++i) {
            if ((b[i] == b[i + 3] && b[i + 3] == b[i + 6] && b[i] != ' ') ||
                (b[i * 3] == b[i * 3 + 1] && b[i * 3 + 1] == b[i * 3 + 2] && b[i * 3] != ' ')) {
                if (b[i] == 'X')
                    is_x_won = true;
                else if (b[i] == 'O')
                    is_o_won = true;
            }
        }

        if ((b[0] == b[4] && b[4] == b[8] && b[0] != ' ') ||
            (b[2] == b[4] && b[4] == b[6] && b[2] != ' ')) {
            if (b[4] == 'X')
                is_x_won = true;
            else if (b[4] == 'O')
                is_o_won = true;
        }
    }

    // Retornar el valor según el estado del juego
    if (is_x_won) return 1;
    if (is_o_won) return -1;
    if (is_tie) return 0;

    if (is_maximizing) {
        int best_score = -1000;
        for (int i = 0; i < 9; ++i) {
            if (b[i] == ' ') {
                Board new_board = b;
                new_board[i] = player;
                int score = minimax(new_board, player == 'X' ? 'O' : 'X', false, alpha, beta);
                best_score = std::max(best_score, score);
                alpha = std::max(alpha, score);
                if (beta <= alpha) {
                    break;
                }
            }
        }
        return best_score;
    } else {
        int best_score = 1000;
        for (int i = 0; i < 9; ++i) {
            if (b[i] == ' ') {
                Board new_board = b;
                new_board[i] = player;
                int score = minimax(new_board, player == 'X' ? 'O' : 'X', true, alpha, beta);
                best_score = std::min(best_score, score);
                beta = std::min(beta, score);
                if (beta <= alpha) {
                    break;
                }
            }
        }
        return best_score;
    }
}
