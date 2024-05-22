#include "Book.hpp"


Book::Book(const std::string isbn, std::set<std::string> authors, std::string title_, double price_, uint32_t count_) :
	ISBN(isbn),
	authors(authors),
	title(title_),
	price(price_),
	count(count_)
{
	if (price <= 0 || count <= 0)
	{
		throw std::runtime_error("must be natural");
	}

}

Book::~Book()
{
}

std::string Book::getISBN()
{
	return ISBN;
}

std::string  Book::getTitle()
{
	return title;
}

std::ostream& Book::displayBook(std::ostream& out)
{
	out << "ISBN: " << ISBN << " Title: " << " Authors: " << '\n';
	for (auto& author : authors)
	{
		out << author << '\n';
	}
	out << " Price: " << price << " Circulation" << count;
	return out;
}

Book& Book::operator=(const Book& other)
{
		if (this != &other) 
		{
			authors = other.authors;
			title = other.title;
			price = other.price;
			count = other.count;
		}
		return *this;
	}
