#include "cesar.h"
#include <iostream>


// sobrecarga del operador << para imprimir el tablero
std::ostream& operator<<(std::ostream& os, Board const& b) {
    for (int i = 0; i < 3; ++i) {
        os << b[i * 3] << '|' << b[i * 3 + 1] << '|' << b[i * 3 + 2] << std::endl;
        if (i < 2) os << "-----" << std::endl;
    }
    return os;
}


int main() {
    Cesar_player p;
    Board b;

    //inicialiar b con espacios
    for (int i = 0; i < 9; ++i) {
        b[i] = ' ';
    }

    char turn_of = 'X';
    int count = 0;
    while (true) {
        std::cout << b << std::endl;
        if (count % 2 == 0) {
            //soliciatar movimiento al usuario
            int move;
            std::cout << "Ingrese su movimiento: ";
            std::cin >> move;
            b[move] = turn_of;
        } else {
            //solicitar movimiento a la computadora
            int move = p.get_move(b, turn_of);
            b[move] = turn_of;
        }
        if (p.won(b, turn_of)) {
            std::cout << b << std::endl;
            std::cout << "Ganador: " << turn_of << std::endl;
            break;
        }
        if (p.isFull(b)) {
            std::cout << b << std::endl;
            std::cout << "Empate" << std::endl;
            break;
        }
        turn_of = (turn_of == 'X') ? 'O' : 'X';
        count++;
    }
    return 0;
}