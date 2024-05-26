#include "gtest/gtest.h"

#include "src/Book/Book.hpp"
#include "src/Library/LIbrary.hpp"

class LibraryTestNotGPT : public ::testing::Test
{
};


TEST_F(LibraryTestNotGPT, SearchBookTest)
{
    Library libraryTest;
    libraryTest.pushBook(Book("1234567890", {"Author1TEst", "Author2TEst"}, "Beta1", 10, 100));
    libraryTest.pushBook(Book("0987654321", {"Author3TEst"}, "Beta2", 15, 50));

    EXPECT_NO_THROW(libraryTest.searchBook("1234567890"));
    EXPECT_THROW(libraryTest.searchBook("1111111111"), std::invalid_argument);
}

TEST_F(LibraryTestNotGPT, PopBookTest)
{Library library;
    library.pushBook(Book("1234567890", {"Author1TEst", "Author2TEst"}, "Book1", 10, 100));
    library.pushBook(Book("0987654321", {"Author3TEst"}, "NotCopilot", 15, 50));

    EXPECT_NO_THROW(library.popBook("1234567890"));
    EXPECT_THROW(library.popBook("1111111111"), std::invalid_argument);
}

TEST_F(LibraryTestNotGPT, AddAuthorTest)
{
    Library LibraryTest;
    LibraryTest.pushBook(Book("1234567890", {"Author1TEst", "Author2TEst"}, "ALfa", 10, 100));
    LibraryTest.pushBook(Book("0987654321", {"Author3TEst"}, "Beta", 15, 50));

    EXPECT_NO_THROW(LibraryTest.addAuthor("Author4Test", "1234567890"));
    EXPECT_THROW(LibraryTest.addAuthor("Author404", "404"), std::invalid_argument);
}

TEST_F(LibraryTestNotGPT, PopAuthorTest)
{
     Library LibraryTest;
    LibraryTest.pushBook(Book("1234567890", {"Author1TEst", "Author2TEst"}, "Book1", 10, 100));
    LibraryTest.pushBook(Book("0987654321", {"Author3TEst"}, "Book2", 15, 50));

    EXPECT_NO_THROW(LibraryTest.popAuthor("Author1", "1234567890"));
    EXPECT_THROW(LibraryTest.popAuthor("Author404", "1111111111"), std::invalid_argument);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
