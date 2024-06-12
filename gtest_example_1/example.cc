#include <gtest/gtest.h>

// Function to be tested
int Add(int a, int b) {
    return a + b;
}

// Test case
TEST(AdditionTest, HandlesPositiveInput) {
    EXPECT_EQ(Add(1, 2), 3);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

