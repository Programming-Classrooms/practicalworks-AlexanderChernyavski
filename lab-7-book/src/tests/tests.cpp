#include "../Book/Book.hpp"
#include "../Library/Library.hpp"
#include <gtest/gtest.h>
#include <sstream>

class LibraryTest : public ::testing::Test {
protected:
    LibraryTest()
        : book1("978-3-16-148410-0", 2020, "Title1", {author1}),
          book2("978-1-4028-9462-6", 2021, "Title2", {author2}),
          author1({"John", "Doe", "M"}),
          author2({"Jane", "Smith", "F"}) {}

    void SetUp() override {
        // Add books to library
        library.pushBook(book1);
        library.pushBook(book2);
    }

    Library library;
    Book book1;
    Book book2;
    Book::Author author1;
    Book::Author author2;
};


TEST_F(LibraryTest, SearchBookNotFoundTest) {
    EXPECT_THROW(library.searchBook("NonExistentTitle"), std::invalid_argument);
}

TEST_F(LibraryTest, PopBookTest) {
    library.popBook("Title1");

    // Check if the book was removed
    EXPECT_THROW(library.searchBook("Title1"), std::invalid_argument);
}



TEST_F(LibraryTest, DisplayAuthorsBookNotFoundTest) {
    Book::Author nonExistentAuthor = {"Non", "Existent", "N"};
    EXPECT_THROW(library.displayAuthorsBook(nonExistentAuthor), std::invalid_argument);
}



TEST_F(LibraryTest, PopAuthorTest) {
    Book::Author newAuthor = {"New", "Author", "N"};
    library.addAuthor(newAuthor, "Title1");
    library.popAuthor(newAuthor, "Title1");

    // Check if the author was removed
    std::ostringstream output;
    EXPECT_THROW(library.displayAuthorsBook(newAuthor), std::invalid_argument);
}