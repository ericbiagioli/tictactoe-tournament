#include "Player.h"

struct Cesar_player : public Player
{
    int get_move(Board const& b, char turn_of);
    int bestMove(Board b, int turn_of); //busca de los 9 posibles movimientos cual es el mejor
    int get_wins(Board const& b, char s, int next); //retorna cuantas veces gana el jugador s si juega en la posicion next
    
    bool isFull(Board const& b);

    bool empty(Board const& b);

    int next_inmm_wins(Board const& b, char s);

    bool won(Board const& b, char s);
};