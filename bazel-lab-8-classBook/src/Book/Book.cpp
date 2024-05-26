#include "Book.hpp"


Book::Book( std::string isbn, std::set<std::string> authors, std::string title_, double price_, uint32_t count_) :
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

std::string Book::getISBN() const 
{
	return ISBN;
}

std::string  Book::getTitle() const 
{
	return title;
}

std::ostream& Book::displayBook(std::ostream& out)
{
	out << "ISBN: " << ISBN << " Title: "<<title << " Authors: " << '\n';
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
			ISBN = other.ISBN;
			authors = other.authors;
			title = other.title;
			price = other.price;
			count = other.count;
		}
		return *this;
	}

    
    
