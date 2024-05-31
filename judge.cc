#include <algorithm>
#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include <map>

#include "Player.h"
#include "all_headers_autogenerated.h"

const size_t n_games = 1;

struct Participant {
  std::string name;
  Player *player;
  int played, won, lost, drawn;
  bool disqualified;

  Participant() : played(0), won(0), lost(0), drawn(0), player(nullptr),
                  name(""), disqualified(false) {
  }

  Participant(Player *_player) : played(0), won(0), lost(0), drawn(0),
                                 player(_player), name(""), disqualified(false) {
  }

  Participant(Player *_player, std::string const& _name) : played(0), won(0),
    lost(0), drawn(0), player(_player), name(_name), disqualified(false) {
  }
};

inline bool is_valid_move(Board &b, int pos) {
    return (pos >= 0 && pos < 9 && b[pos] == ' ');
}

bool move(Board &b, char symbol, int pos) {
    if (!is_valid_move(b, pos)) {
        return false;
    }

    b[pos] = symbol;
    return true;
}

bool eq(char a, char b, char c, char p) {
  return (a == p) && (b == p) && (c == p);
}

bool won(Board const& b, char s) {
    return (eq(b[0], b[1], b[2], s) || eq(b[3], b[4], b[5], s) ||
         eq(b[6], b[7], b[8], s) || eq(b[0], b[3], b[6], s) ||
         eq(b[1], b[4], b[7], s) || eq(b[2], b[5], b[8], s) ||
         eq(b[0], b[4], b[8], s) || eq(b[6], b[4], b[2], s));
}

int status(Board const& b) {
    if (won(b, 'X') && won(b, 'O')) {
      return INVALID_BOTH_WON;
    }

    if (won(b, 'X')) {
      return WON_X;
    }

    if (won(b, 'O')) {
      return WON_O;
    }

    int t = 0;
    for (int i = 0; i < 9; ++i) {
        if (b[i] == ' ') {
            ++t;
        }
    }

    if (t == 0) {
        return NOBODY_WON;
    }

    return NOT_ENDED;
}

std::ostream& operator<<(std::ostream& o, Board const& b) {
  o << " " << b[6] << " | " << b[7] << " | " << b[8] << std::endl
    << "-----------" << std::endl
    << " " << b[3] << " | " << b[4] << " | " << b[5] << std::endl
    << "-----------" << std::endl
    << " " << b[0] << " | " << b[1] << " | " << b[2] << std::endl;
  return o;
}

int play_game(Participant const& X, Participant const& O) {
  Board b{' ', ' ', ' ', ' ', ' ', ' ',' ', ' ', ' '};
  char turn_of = 'X';

  while (status(b) == NOT_ENDED) {
    Player *player_to_move = ((turn_of == 'X') ? X.player : O.player);
    int where = player_to_move->get_move(b, turn_of);

    if (is_valid_move(b, where))
      b[where] = turn_of;
    else
      return (turn_of == 'X') ? DISQUALIFIED_X : DISQUALIFIED_O;

    turn_of = ((turn_of == 'X') ? 'O' : 'X');
  }

  return status(b);
}

std::string result_code_to_str(int code) {
  if (code == 0) return "INVALID_BOTH_WON";
  if (code == 1) return "WON_X";
  if (code == 2) return "WON_O";
  if (code == 3) return "NOBODY_WON";
  if (code == 4) return "NOT_ENDED";
  if (code == 5) return "DISQUALIFIED_X";
  if (code == 6) return "DISQUALIFIED_O";
  return "";
}

void make_registrations(std::vector<Participant> &participants) {
  participants.push_back(Participant(new ericbiagioli_firstfree(), "Eric Biagioli - first free 1"));
  participants.push_back(Participant(new ericbiagioli_firstfree(), "Eric Biagioli - first free 2"));
  participants.push_back(Participant(new ericbiagioli_firstfree(), "Eric Biagioli - first free 3"));
  participants.push_back(Participant(new ericbiagioli_incorrectmoves(), "Eric Biagioli - incorrect moves 1"));
  participants.push_back(Participant(new ericbiagioli_incorrectmoves(), "Eric Biagioli - incorrect moves 2"));
  participants.push_back(Participant(new ericbiagioli_incorrectmoves(), "Eric Biagioli - incorrect moves 3"));
}

bool compare_participants(const Participant& p1, const Participant& p2)
{
  if (p1.disqualified && p2.disqualified)
    return p1.name < p2.name;
  if (p1.disqualified && !p2.disqualified)
    return false;
  if (!p1.disqualified && p2.disqualified)
    return true;
  if (p1.won > p2.won)
    return true;
  if (p2.won > p1.won)
    return false;
  if (p1.drawn > p2.drawn)
    return true;
  if (p2.drawn > p1.drawn)
    return false;
  return p1.name < p2.name;
}

int main() {
  std::vector<Participant> participants;
  make_registrations(participants);

  std::vector<std::tuple<size_t, size_t, int>> results;

  for (size_t a = 0; a < participants.size(); ++a) {
    for (size_t b = 0; b < participants.size(); ++b) {
      if (a != b) {
        for (size_t t = 0; t < n_games; ++t) {
          int g = play_game(participants[a], participants[b]);
          results.push_back(std::make_tuple(a, b, g));
        }
      }
    }
  }

  std::vector<bool> disqualified(participants.size(), false);
  for (int i = 0; i < results.size(); ++i) {
    int X = std::get<0>(results[i]);
    int O = std::get<1>(results[i]);
    if (std::get<2>(results[i]) == DISQUALIFIED_X) {
      disqualified[X] = true;
      participants[X].disqualified = true;
    }
    if (std::get<2>(results[i]) == DISQUALIFIED_O) {
      disqualified[O] = true;
      participants[O].disqualified = true;
    }
  }

  std::cout << std::endl;
  std::cout << "Disqualified players: " << std::endl;
  for (int i = 0; i < disqualified.size(); ++i) {
    if (disqualified[i]) {
      std::cout << participants[i].name << std::endl;
    }
  }
  std::cout << std::endl;

  for (int i = 0; i < results.size(); ++i)
  {
    int X = std::get<0>(results[i]);
    int O = std::get<1>(results[i]);
    int g = std::get<2>(results[i]);
    participants[X].played++;
    participants[O].played++;
    if (disqualified[X] && disqualified[O]) { continue; }
    if (disqualified[X]) { participants[O].won++; participants[X].won = -1; participants[X].lost = -1; participants[X].played = -1; participants[X].drawn = -1; continue; }
    if (disqualified[O]) { participants[X].won++; participants[O].won = -1; participants[O].lost = -1; participants[O].played = -1; participants[O].drawn = -1; continue; }
    if (g == WON_X) { participants[X].won++; participants[O].lost++; continue; }
    if (g == WON_O) { participants[O].won++; participants[X].lost++; continue; }
    if (g == NOBODY_WON) { participants[O].drawn++; participants[X].drawn++; continue; }
  }

  std::sort(participants.begin(), participants.end(), compare_participants);

  for (int i = 0; i < participants.size(); ++i)
  {
    std::cout << "Participant: " << participants[i].name << std::endl;
    std::cout << "  disqualified: " << ((participants[i].disqualified) ? "DISQUALIFIED" : "not disqualified") << std::endl;
    std::cout << "  won: " << participants[i].won << std::endl;
    std::cout << "  lost: " << participants[i].lost << std::endl;
    std::cout << "  drawn: " << participants[i].drawn << std::endl;

  }

  return 0;
}
