#pragma once

#include "Player.h"

struct alvaro_garcia : public Player {
  int get_move(Board const &b, char turn_of);
  double evaluate(Board const &b, char turn_of);
};
