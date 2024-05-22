#include <iostream>
#include "../Book/Book.hpp"
#include "../Library/LIbrary.hpp"

int main() {
	try {
		// Create some books
		Book book1("978-3-16-148410-0", { "Author1", "Author2" }, "Book Title G", 29.99, 100);
		Book book2("978-3-16-148411-0", { "Author3", "Author4" }, "Book Title H", 19.99, 50);
		Book book3("978-3-16-148412-0", { "Author5" }, "Book Title D", 14.99, 80);
		Book book4("978-3-16-148412-0", { "Author7" }, "Book Title L", 14223, 40);

		// Create a library and add books to it
		Library library;
		library.pushBook(book1);
		library.pushBook(book2);
		library.pushBook(book3);
		library.pushBook(book4);
		// Display the list of books in the library
		std::cout << "List of Books in the Library:\n";
		library.displayList();

		// Search for a book by ISBN
		std::cout << "\nSearching for book with ISBN: 978-3-16-148411-0\n";

		library.searchBook("978-3-16-148411-0");


		// Remove a book from the library
		std::cout << "\nRemoving book with ISBN: 978-3-16-148412-0\n";

		library.popBook("978-3-16-148412-0");


		// Display the updated list of books
		std::cout << "\nUpdated List of Books in the Library:\n";
		library.displayList();

		// Add an author to a book
		std::cout << "\nAdding author 'New Author' to book with ISBN: 978-3-16-148410-0\n";
		library.addAuthor("New Author", "978-3-16-148410-0");


		// Display the updated list of books
		std::cout << "\nUpdated List of Books in the Library:\n";
		library.displayList();
	}
	catch (const std::invalid_argument& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
