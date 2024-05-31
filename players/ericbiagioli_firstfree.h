#pragma once

#include "Player.h"

struct ericbiagioli_firstfree : public Player {
  int get_move(Board const &b, char turn_of);
};
