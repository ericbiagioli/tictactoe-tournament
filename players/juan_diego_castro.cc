#include "juan_diego_castro.h"

int juan_diego_castro::get_move(Board const &b, char turn_of) {
  for (int i = 0; i < 3; ++i) {
    int s = i * 3;
    if (b[s] == turn_of && b[s + 1] == turn_of && b[s + 2] == ' ')
      return s + 2;
    if (b[s] == turn_of && b[s + 2] == turn_of && b[s + 1] == ' ')
      return s + 1;
    if (b[s + 1] == turn_of && b[s + 2] == turn_of && b[s] == ' ')
      return s;
    if (b[i] == turn_of && b[i + 3] == turn_of && b[i + 6] == ' ')
      return i + 6;
    if (b[i] == turn_of && b[i + 6] == turn_of && b[i + 3] == ' ')
      return i + 3;
    if (b[i + 3] == turn_of && b[i + 6] == turn_of && b[i] == ' ')
      return i;
  }

  if (b[0] == turn_of && b[4] == turn_of && b[8] == ' ')
    return 8;
  if (b[0] == turn_of && b[8] == turn_of && b[4] == ' ')
    return 4;
  if (b[4] == turn_of && b[8] == turn_of && b[0] == ' ')
    return 0;

  if (b[2] == turn_of && b[4] == turn_of && b[6] == ' ')
    return 6;
  if (b[2] == turn_of && b[6] == turn_of && b[4] == ' ')
    return 4;
  if (b[4] == turn_of && b[6] == turn_of && b[2] == ' ')
    return 2;

  if (b[4] == ' ')
    return 4;
  for (int i : {0, 2, 6, 8})
    if (b[i] == ' ')
      return i;
  for (int i : {1, 3, 5, 7})
    if (b[i] == ' ')
      return i;

  return -1;
}
