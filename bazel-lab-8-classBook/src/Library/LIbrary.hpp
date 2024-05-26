#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <vector>
#include <algorithm>

#include "../Book/Book.hpp"


class Library
{
public:
	Library() = default;
	~Library() = default;

	void pushBook(const Book&);//довавление книги
	void searchBook(std::string);//поиск книги
	void popBook(std::string);//удаление книги

	void displayList();//вывод списка книг

	void sortBooksNum();// сорт. по номеру
	void sortBooksAlf();// сорт по алфавиту

	void addAuthor(std::string, std::string);//добавление автора
	void popAuthor(std::string, std::string);//удаление автора
private:
	std::vector<Book> books;
};


#endif // !LIBRARY_H
