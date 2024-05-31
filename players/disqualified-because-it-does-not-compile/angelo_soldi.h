#pragma once

#include "Player.h"
#include <iostream>

struct angelo_soldi : public Player {
  int get_move(Board const &b, char turn_of);
};
