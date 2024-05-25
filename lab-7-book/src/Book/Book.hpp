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
		Author(std::string surname_,std::string name_,std::string fathername_):
			surname(surname_),
			name(name_),
			fathername(fathername_)
		{
			if (!isupper(surname[0]) || !isupper(name[0]) || !isupper(fathername[0])) throw std::runtime_error("Error Author constructor");
		}
		bool operator==(const Author& other) const {
			return surname == other.surname && name == other.name && fathername == other.fathername;
		}
		bool operator<(const Author& other) const {
			if (surname != other.surname) return surname < other.surname;
			if (name != other.name) return name < other.name;
			return fathername < other.fathername;
		}
	};
	Book(std::string, int32_t, std::string, std::set<Author>);
	~Book();

	std::ostream& display(std::ostream&);

	std::string getISBN() const;
	std::string getTitle() const;
	Book::Author getAuthor(size_t indx);
	size_t getAuthorsSize();

	std::set<Author> authors;
	
	
};

#endif // !BOOK_H
