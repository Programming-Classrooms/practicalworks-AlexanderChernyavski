#include "../Library/LIbrary.hpp"

Library::Library()
{
}

Library::~Library()
{
}

void Library::pushBook(const Book& book)
{
	books.insert(book);
	
}

void Library::searchBook(std::string index)
{
	auto it = std::find_if(books.begin(), books.end(), [&index](const Book& book) { return book.getISBN() == index; });
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
	auto it = std::find_if(books.begin(), books.end(), [&index](const Book& book) {return book.getISBN() == index; });
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
	for (const auto& book : books)
	{
		book.displayBook(std::cout);
	}
}

void Library::sortBooksNum()
{
	struct CompareISBN {
		bool operator()(const Book& a, const Book& b) const {
			return a.getISBN() < b.getISBN();
		}
	};
	std::set<Book,CompareISBN> temp;
	books.insert(temp.begin(), temp.end());
	for (const auto& t : temp)
	{
		t.displayBook(std::cout);
	}
}

void Library::sortBooksAlf()
{
	struct CompareTitle {
		bool operator()(const Book& a, const Book& b) const {
			return a.getTitle() < b.getTitle();
		}
	};
	std::set<Book, CompareTitle> temp;
	books.insert(temp.begin(), temp.end());
	for (const auto& t : temp)
	{
		t.displayBook(std::cout);
	}
}



Book* Library::findBook(const std::string& isbn)
{
	 auto it = std::find_if(books.begin(), books.end(), [&isbn](const Book& book) { return book.getISBN() == isbn; });
	 if (it != books.end())
	 {
		 return const_cast<Book*>(&(*it));
	 }
	else
	{
		throw std::invalid_argument("Book not found for this index (searchBook)");
	}
}


void Library::addAuthor( std::string author, std::string index)
{
	Book* book = findBook(index);
	book->insertAuthor(author);
}


void Library::popAuthor(std::string author, std::string index)
{
	Book* book = findBook(index);
	book->eraseAuthor(author);
}
