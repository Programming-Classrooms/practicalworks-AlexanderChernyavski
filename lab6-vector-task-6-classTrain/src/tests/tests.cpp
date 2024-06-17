#include <gtest/gtest.h>

#include "../Train/Train.hpp"
#include "../Functions/functions.hpp"


TEST(CheckFileTest, File404) {
    std::ifstream file("File404.txt");
    EXPECT_THROW(checkFile(file), std::invalid_argument);
}

TEST(CheckFileTest, FileIsNon404) {
    std::ofstream outTest("FileIsNon404.txt");
    outTest << "Ia ne spisal eto c Copilot" <<'\n';
    outTest.close();
    std::ifstream file("FileIsNon404.txt");
    EXPECT_NO_THROW(checkFile(file));
}

TEST(SplittingIntoWordsTest, SplittingTest) {
    EXPECT_EQ(splittingIntoWords("10:30", 1), 10);  
    EXPECT_EQ(splittingIntoWords("10:30", 2), 30);  

    EXPECT_EQ(splittingIntoWords("9:45", 1), 9);    
    EXPECT_EQ(splittingIntoWords("9:45", 2), 45); 
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
