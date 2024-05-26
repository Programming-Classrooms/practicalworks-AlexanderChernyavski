#include <gtest/gtest.h>
#include <fstream>
#include <vector>

#include "src/Functions/functions.hpp"


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

TEST(RemovingAWordByLetterTest, RemoveWordsWithSpecificLetter)
{
    std::vector<std::string> words = {"Apple", "Banan", "Alpfa", "Charlie", "Avocadik"};
    RemovingAWordByLetter('A', words);
    std::vector<std::string> expected = {"Banana", "Cherry"};
    EXPECT_EQ(words, expected);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}