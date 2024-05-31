#pragma once

#include "Player.h"

struct melanie_cortez : public Player {
  int get_move(Board const &b, char turn_of);
};
