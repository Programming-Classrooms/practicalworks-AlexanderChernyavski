#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>
#include <set>
#include <iostream>
#include <vector>


class Book
{
public:
	std::set<std::string> authors;
	Book(const std::string, std::set<std::string>, std::string, double, uint32_t);
	Book() = default;
	~Book() = default;

	std::string getISBN() const ;//геттер ISBN
	std::string getTitle() const ;//геттер названия

	std::ostream &displayBook(std::ostream &);

	Book &operator=(const Book &);//для сортировки
	
private:
	std::string ISBN;
	std::string title;
	double price;
	uint32_t count;
};

#endif // !BOOK_H
