#include <gtest/gtest.h>
#include <sstream>

#include "../Book/Book.hpp"
#include "../Library/Library.hpp"
#include "../Functions/functions.hpp"


class LibraryTest : public ::testing::Test {
protected:
    
};


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


TEST_F(LibraryTest, SearchBookTest) {
    Library libraryTest;
    Book::Author authorTest({"Test", "Author", "Google"});
    Book bookTest("978-3-16-1789-5", 1995, "TestTitle", {authorTest});
    libraryTest.pushBook(bookTest);
    EXPECT_NO_THROW(libraryTest.searchBook("TestTitle"));
}

TEST_F(LibraryTest, PopBookTest) {
    Library libraryTest;
    Book::Author authorTest({"Test", "Author", "Google"});
    Book bookTest("978-3-16-1789-5", 1995, "TestTitle", {authorTest});
    libraryTest.pushBook(bookTest);
    libraryTest.popBook("Test Title");
    EXPECT_NO_THROW(libraryTest.searchBook("TestTitle"));
}

TEST_F(LibraryTest, PopAuthorTest) {
    Library libraryTest;
    Book::Author newAuthor = {"New", "TEst", "Author"};
    libraryTest.addAuthor(newAuthor, "Title1");
    libraryTest.popAuthor(newAuthor, "Title1");
}
