#ifndef LIBRARY_HPP
#define LIBRARY_HPP
#include "../Book/Book.hpp"
#include <vector>
#include <algorithm>

class Library
{
public:
	explicit Library();
	~Library();
	void pushBook(const Book&);
	void searchBook(std::string);
	void popBook(std::string);
	void displayList();
	void sortBooksNum();
	void sortBooksAlf();
	void addAuthor(std::string, std::string);
	void popAuthor(std::string, std::string);
private:
	std::vector<Book> books;
};


#endif // !LIBRARY_H
