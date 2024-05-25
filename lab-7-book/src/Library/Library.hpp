#ifndef LIBRARY_HPP
#define LIBRARY_HPP
#include "../Book/Book.hpp"
#include <vector>
#include <algorithm>

class Library
{
public:
	Library();
	~Library();
	void pushBook(const Book&);
	void searchBook(std::string);
	void popBook(const std::string);
	void displayAuthorsBook(const Book::Author&);
	void sortBooksAlf();
	void addAuthor(const Book::Author&, std::string);
	void popAuthor(const Book::Author&, std::string);
	void diplayList();
	
	std::vector<Book> books;
};


#endif // !LIBRARY_H
