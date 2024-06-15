//
// Created by juan-diego on 6/11/24.
//

#include <gtest/gtest.h>
#include "juan_diego_castro.h"


TEST(TicTacToeTournamentTest, TestCanPlayOnEmptyBoard) {
  Board b{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
  juan_diego_castro jd;

  int move = jd.get_move(b, 'X');
  ASSERT_GE(move, 0);
  ASSERT_LT(move, b.size());
}

TEST(TicTacToeTournamentTest, TestCanPlayOnSecondTurn) {
  Board b{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
  juan_diego_castro jd;

  for (int i = 0; i < b.size(); ++i) {
    b[i] = 'O'; // The opponent plays
    
    int move = jd.get_move(b, 'X');

    ASSERT_GE(move, 0);
    ASSERT_LT(move, b.size());
    ASSERT_EQ(b[move], ' ');

    b[i] = ' '; // Restores the board
  }
}

TEST(TicTacToeTournamentTest, TestCanPlayOnAlmostFullBoard) {
  Board b{'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'}; // Inittialy we have an full board
  juan_diego_castro jd;

  for (int i = 0; i < b.size(); ++i) {
    b[i] = ' '; // Make the board not empty
    
    int move = jd.get_move(b, 'X');

    ASSERT_EQ(move, i);
    ASSERT_EQ(b[move], ' ');

    b[i] = 'X'; // Restore the value
  }
}

// If Juan Diego plays his turn and the movement equals 8 (the last position) then Juan Diego 
// will win if he plays optimal from that moment.
TEST(TicTacToeTournamentTest, TestPlaysOptimalOnSimpleCase) {
  Board b {
    'X', ' ', ' ', 
    ' ', 'O', ' ', 
    ' ', ' ', ' '
    };

  juan_diego_castro jd;
  int move = jd.get_move(b, 'X');

  ASSERT_GE(move, 0);
  ASSERT_LT(move, b.size());
  ASSERT_NE(b[move], ' ');
  ASSERT_EQ(move, 8);
}



class TicTacToeTournamentTest : public ::testing::Test {
protected:

  void SetUp() override {

  }
  void TearDown() override {
  
  }
};

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
