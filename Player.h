#pragma once

#include <array>

const int INVALID_BOTH_WON = 0;
const int WON_X = 1;
const int WON_O = 2;
const int NOBODY_WON = 3;
const int NOT_ENDED = 4;
const int DISQUALIFIED_X = 5;
const int DISQUALIFIED_O = 6;

typedef std::array<char, 9> Board;

struct Player {
  virtual int get_move(Board const &, char) = 0;
};
