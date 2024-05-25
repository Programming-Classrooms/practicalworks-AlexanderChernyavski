#include "Book.hpp"

Book::Book(std::string isbn_, int32_t year_, std::string title_, std::set<Author> authors_):
	ISBN(isbn_),
	yearOfPublish(year_),
	title(title_),
	authors(authors_)
{
 if (yearOfPublish < 0) throw std::invalid_argument("Error constructor Book");
}

Book::~Book()
{
}

std::ostream& Book::display(std::ostream& out)
{
	out<<'\n' << "ISBN: " << ISBN << '\n' << "Year of Publish: " << yearOfPublish << '\n' << "Title: " << title << '\n' << "Author: ";
	for (auto& author : authors)
	{
		out << author.surname << ' ';
		out << author.name << ' ';
		out << author.fathername<<"; ";
	}
	return out;
}

std::string Book::getISBN() const
{
	return ISBN;
}

std::string  Book::getTitle() const
{
	return title;
}


Book::Author Book::getAuthor(size_t indx)
{
	auto it = *next(authors.begin(), 0);
	return it;
}

size_t Book::getAuthorsSize()
{
	return authors.size();
}

bool operator<(const Book::Author& a, const Book::Author& b) {
	if (a.surname != b.surname) {
		return a.surname < b.surname;
	}
	if (a.name != b.name) {
		return a.name < b.name;
	}
	return a.fathername < b.fathername;
}
