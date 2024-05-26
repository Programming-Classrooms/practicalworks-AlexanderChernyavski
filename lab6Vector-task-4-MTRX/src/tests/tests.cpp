#include <gtest/gtest.h>
#include <vector>
#include <sstream>

#include "src/Functions/functions.hpp"


TEST(MatrixTest, IsCorrectMTRXTest)
{
    EXPECT_NO_THROW(IsCorrectMTRX(3, 3));
    EXPECT_ANY_THROW(IsCorrectMTRX(-8, 3));
    
}


TEST(MatrixTest, SumRowTest)
{
    std::vector<int32_t> row = {1, 2, 3};
    EXPECT_EQ(sumRow(row), 6);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    srand((unsigned)time(0));
    return RUN_ALL_TESTS();
}