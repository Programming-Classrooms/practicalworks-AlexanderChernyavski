#include <gtest/gtest.h>

#include "src/Stack/Stack.hpp"


TEST(StackTest, PushPopOperators) {
    Stack<int32_t> testStack;
    Stack<int32_t> testStack2;
    testStack.push(1);
    testStack.push(2);
    testStack.push(3);

    EXPECT_EQ(testStack[0], 3);
    EXPECT_EQ(testStack[1], 2);
    EXPECT_EQ(testStack[2], 1);

    testStack2 = testStack;

    testStack.pop();
    
    EXPECT_EQ(testStack[0], 2);
    EXPECT_EQ(testStack2[0],3);
}

TEST(StackTest, EmptyStack) {
    Stack<int32_t> testStack;
    
    ASSERT_TRUE(testStack.isEmpty());

    testStack.push(1);
    ASSERT_FALSE(testStack.isEmpty());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}