#include "../Book/Book.hpp"


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

std::string const& Book::getISBN() const
{
	return ISBN;
}

std::string const& Book::getTitle() const
{
	return title;
}

 std::ostream& Book::displayBook(std::ostream& out) const
{
	out << "ISBN: " << ISBN << " Title: " <<title<< " Authors: " << '\n';
	for (const auto& author : authors)
	{
		out << author << '\n';
	}
	out << " Price: " << price << " Circulation" << count;
	return out;
}

 void Book::insertAuthor(const std::string& author)
 {
	 authors.insert(author);
 }

 void Book::eraseAuthor(std::string& author)
 {
	 authors.erase(author);
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

	 bool Book::operator<(const Book& rhs) const
	 {
	    return ISBN<rhs.ISBN;
	 }
