#ifndef BOOK_HPP
#define BOOK_HPP
#include <string>
#include <set>
#include<iostream>
#include <vector>

class Book
{
public:
	std::set<std::string> authors;
	Book(const std::string, std::set<std::string>,std::string ,double,uint32_t);
	~Book();
	std::string getISBN();
	std::string getTitle();
	std::ostream& displayBook(std::ostream&);
	Book& operator =(const Book&);
private:
	const std::string ISBN;
	std::string title;
	double price;
	uint32_t count;
   
};



#endif // !BOOK_H
