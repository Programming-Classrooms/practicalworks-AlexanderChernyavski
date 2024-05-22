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
	Book* findBook(const std::string&);
	void addAuthor(std::string, std::string);
	void popAuthor(std::string, std::string);
private:
	
	std::set<Book> books;
};


#endif // !LIBRARY_H
