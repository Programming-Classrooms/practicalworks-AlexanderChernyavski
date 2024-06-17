#include <gtest/gtest.h>

#include "src/Functions/functions.hpp"


TEST(VectorOperationsTest, AddNumberTest) {
    std::vector<int32_t> vectorOfIntNumTest;
    addNumber(vectorOfIntNumTest, 5);
    EXPECT_EQ(vectorOfIntNumTest.size(), 1);
    EXPECT_EQ(vectorOfIntNumTest[0], 5);
}

TEST(VectorOperationsTest, CalculateSumTest) {
    std::vector<int32_t> vectorOfIntNumTest;
    addNumber(vectorOfIntNumTest, 5);
    addNumber(vectorOfIntNumTest, 10);
    addNumber(vectorOfIntNumTest, -3);
    int32_t sum = calculateSum(vectorOfIntNumTest);
    EXPECT_EQ(sum, 12);
}

TEST(VectorOperationsTest, ReplaceZerosWithAverageTest) {
    std::vector<int32_t> vectorOfIntNumTest;
    addNumber(vectorOfIntNumTest, 5);
    addNumber(vectorOfIntNumTest, 0);
    addNumber(vectorOfIntNumTest, 10);
    addNumber(vectorOfIntNumTest, 0);
    replaceZerosWithAverage(vectorOfIntNumTest);
    EXPECT_EQ(vectorOfIntNumTest[1], 3);  
    EXPECT_EQ(vectorOfIntNumTest[3], 3);  
}


TEST(VectorOperationsTest, RemoveDuplicatesTest) {
    std::vector<int32_t> vectorOfIntNumTest;
    addNumber(vectorOfIntNumTest, 5);
    addNumber(vectorOfIntNumTest, 10);
    addNumber(vectorOfIntNumTest, 5);  
    addNumber(vectorOfIntNumTest, -5);
    addNumber(vectorOfIntNumTest, 2);
    addNumber(vectorOfIntNumTest, 10);  
    removeDuplicates(vectorOfIntNumTest);
    EXPECT_EQ(vectorOfIntNumTest.size(), 3);  
}