#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>
#include <set>
#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>

class Book
{
private:
	std::string ISBN;
	std::string title;
	int32_t yearOfPublish;

public:
	struct Author
	{
		std::string surname;
		std::string name;
		std::string fathername;
		Author(std::string surname_, std::string name_, std::string fathername_) : 
		surname(surname_),
	    name(name_),
	    fathername(fathername_)
		{
			if (!isupper(surname[0]) || !isupper(name[0]) || !isupper(fathername[0]))
				throw std::runtime_error("Error Author constructor");
		}
		bool operator == (const Author&) const;//перегрузка == для find_if 33:Library.cpp
		bool operator < (const Author&) const;//для sort 68:Libraty.cpp
	};
	Book(std::string, int32_t, std::string, std::set<Author>);
	~Book() = default;
	std::ostream &display(std::ostream &); // Вывод одной книги
	std::string getISBN() const;		   // геттер УДК номера
	std::string getTitle() const;		   // геттер названия
	Book::Author getAuthor(size_t indx);   // геттер автора
	size_t getAuthorsSize();               // геттер размера контейнера авторов

	std::set<Author> authors;
};

#endif // !BOOK_H