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

	void pushBook(const Book&);//Добаавление книги
	void searchBook(std::string);//Поиск книги

	void popBook(const std::string);//Удаление книги

	void sortBooksAlf();//Сортиоует книги в алфавитном порядке

	void addAuthor(const Book::Author&, std::string);//Добавление автора
	void popAuthor(const Book::Author&, std::string);//Удаление автора

	void diplayList();//Вывод списка книг
	void displayAuthorsBook(const Book::Author&);//Выводит название книги по автору

	public:
	std::vector<Book> books;
};


#endif // !LIBRARY_H
