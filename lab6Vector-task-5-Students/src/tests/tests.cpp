#include <gtest/gtest.h>

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

TEST(CompareCourseTest, DifferentCourses) {
    Student test1("AlfaTest", 1, 11);
    Student test2("BetaTest", 2, 12);
    EXPECT_TRUE(compareCourse(test1, test2));
    EXPECT_FALSE(compareCourse(test2, test1));
}

TEST(CompareCourseTest, DifferentGroups) {
    Student test1("AlfaTest", 1, 11);
    Student test2("BetaTest", 1, 12);
    EXPECT_TRUE(compareCourse(test1, test2));
    EXPECT_FALSE(compareCourse(test2, test2));
}

TEST(CompareCourseTest,DifferentNames) {
    Student test1("AlfaTest", 1, 11);
    Student test2("BetaTest", 1, 11);
    EXPECT_TRUE(compareCourse(test1, test2));
    EXPECT_FALSE(compareCourse(test2, test1));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}