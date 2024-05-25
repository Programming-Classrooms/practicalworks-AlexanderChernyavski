#include "Library.hpp"

Library::Library()
{

}

Library::~Library()
{
}

void Library::pushBook(const Book& book) 
{
	books.push_back(book);
	sortBooksAlf();
}

void Library::searchBook( std::string title) 
{
	bool found = false;
	for (auto& book : books)
	{
		if (book.getTitle() == title)
		{
			book.display(std::cout);
			found = true;
		}
		if (found) break;
	}
	
	if (!found)
	{
		throw std::invalid_argument("Book not found for this title (searchBook)");
	}

}

void Library::popBook(const std::string title) 
{
	auto it = std::find_if(books.begin(), books.end(), [&title](Book& book) {return book.getTitle() == title; });
	if (it != books.end())
	{
		books.erase(it);
	}
	else
	{
		throw std::invalid_argument("Book not found for this index (popBook)");
	}
}

void Library::displayAuthorsBook(const Book::Author& author) 
{
	bool found = false;
	for (Book& book : books)
	{
		size_t size = book.getAuthorsSize();
		for (size_t i = 0; i < size; i++)
		{
			if (book.getAuthor(i).fathername == author.fathername && book.getAuthor(i).name == author.name && book.getAuthor(i).surname == author.surname)
			{
				book.display(std::cout);
				found = true;
			}
		}
	}
	if (!found)
	{
		throw std::invalid_argument("Book not found for this author (displaysAuthorsBook)");
	}
}

void Library::sortBooksAlf()
{
	std::sort(books.begin(), books.end(), [](Book& a, Book& b) {return a.getTitle() < b.getTitle(); });
}


void Library::addAuthor(const Book::Author& author, std::string title)
{
	bool found = false;
	for (Book& book : books)
	{
		if (book.getTitle() == title)
		{
			book.authors.emplace(author);
			found = true;
			break;
		}
		if (found) break; 
	}
	if (!found)
	{
		throw std::invalid_argument("Book not found for this index (addAuthor)");
	}
}



void Library::popAuthor(const Book::Author& author, std::string title)
{
	bool found = false;
	for (Book& book : books)
	{
		if (book.getTitle() == title)
		{
			for (auto it = book.authors.begin(); it != book.authors.end(); ++it)
			{
				if (*it == author) 
				{
					book.authors.erase(it);
					found = true;
					break; 
				}
			}
		}
		if (found) break; 
	}
	if (!found)
	{
		throw std::invalid_argument("Book not found for this index (popAuthor)");
	}
}

void Library::diplayList()
{
	for (Book& book : books)
	{
		book.display(std::cout);
		std::cout << '\n';
	}
}
