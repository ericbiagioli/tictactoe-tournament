#include <gtest/gtest.h>
#include "Player.h"
#include "players/ericbiagioli_firstfree.h"

TEST(ValidAnswersAlways, CorrectBehaviour) {
  EXPECT_TRUE(false) << "Test not passed";
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

