#include "LIbrary.hpp"

Library::Library()
{
}

Library::~Library()
{
}

void Library::pushBook(const Book& book)
{
	books.push_back(book);
	size_t length{books.size()};
	for (size_t i = 0; i < length; ++i)
	{
		for (size_t k = i+1; k < length; ++k)
		{
			if (books[i].getISBN() == books[k].getISBN())
			{
				throw std::invalid_argument("Original ISBN!!!!");
			}
		}
	}
}

void Library::searchBook(std::string index)
{
	auto it = std::find_if(books.begin(), books.end(), [&index](Book& book) {return book.getISBN() == index; });
	if (it != books.end())
	{
		std::cout << "Title: " << it->getTitle();
	}
	else
	{
		throw std::invalid_argument("Book not found for this index (searchBook)");
	}

}

void Library::popBook(std::string index)
{
	auto it = std::find_if(books.begin(), books.end(), [&index](Book& book) {return book.getISBN() == index; });
	if (it != books.end())
	{
		books.erase(it);
	}
	else
	{
		throw std::invalid_argument("Book not found for this index (popBook)");
	}
}

void Library::displayList()
{
	for (auto& book : books)
	{
		book.displayBook(std::cout);
	}
}

void Library::sortBooksNum()
{
	std::sort(books.begin(), books.end(), [](Book& a, Book& b) {return a.getISBN() < b.getISBN(); });
}

void Library::sortBooksAlf()
{
	std::sort(books.begin(), books.end(), []( Book& a, Book& b) {return a.getTitle() < b.getTitle(); });
}

void Library::addAuthor(std::string author, std::string index)
{
	uint8_t counter{ 0 };
	for (Book& book : books)
	{
		if (book.getISBN() == index)
		{
			book.authors.insert(author);
			counter = 1;
		}
	}
	if (counter == 0)
	{
		throw std::invalid_argument("Book not found for this index (addAuthor)");
	}
}

void Library::popAuthor(std::string author, std::string index)
{
	uint8_t counter{ 0 };
	for (Book& book : books)
	{
		if (book.getISBN() == index)
		{
			book.authors.erase(author);
			counter = 1;
		}
	}
	if (counter == 0)
	{
		throw std::invalid_argument("Book not found for this index (popAuthor)");
	}
}
