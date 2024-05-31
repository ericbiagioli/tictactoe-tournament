#include "ericbiagioli_incorrectmoves.h"

int ericbiagioli_incorrectmoves::get_move(Board const &b, char turn_of) {
  for (int i = 0; i < 9; ++i)
    if (b[i] != ' ') {
      return i;
    }
  return 0;
}
