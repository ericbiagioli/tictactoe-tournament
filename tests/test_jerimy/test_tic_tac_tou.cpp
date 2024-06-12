#include <iostream>
#include "../../players/jerimy_sandoval.cc"
#include <gtest/gtest.h>
using namespace std;

jerimy_sandoval player;
TEST(MinimaxTest, any_move) {
    Board b;
    b = {
	'X', 'O', 'X',
	'O', 'X', 'O',
	'O', 'X', 'O'
    };
    EXPECT_EQ(player.minimax(b, 'X', true, -1000, 1000), 0);
}
TEST(MinimaxTest, win) {
    Board b;
    b = {
	'X', 'O', 'X',
	'O', 'X', 'O',
	'O', 'X', 'O'
    };
    EXPECT_EQ(player.minimax(b, 'X', true, -1000, 1000), 0);
}
TEST(MinimaxTest, lose) {
    Board b;
    b = {
	'X', 'O', 'X',
	'O', 'X', 'O',
	'O', 'X', 'O'
    };
    EXPECT_EQ(player.minimax(b, 'O', true, -1000, 1000), 0);
}

TEST(MinimaxTest, draw) {
    Board b;
    b = {
	'X', 'O', 'X',
	'O', 'X', 'O',
	'O', 'X', 'O'
    };
    EXPECT_EQ(player.minimax(b, 'O', true, -1000, 1000), 0);
}


int main() {

    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

