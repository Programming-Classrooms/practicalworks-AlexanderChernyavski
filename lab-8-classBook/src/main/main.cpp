#include "../Book/Book.hpp"
#include "../Library/LIbrary.hpp"


int main() {
	try {
		Book book1("977-3-16-148410-0", { "Author1", "Author2" }, "Book Title G", 29.99, 100);
		Book book2("978-3-16-148411-0", { "Author3", "Author4" }, "Book Title H", 19.99, 50);
		Book book3("978-3-16-148412-0", { "Author5" }, "Book Title D", 14.99, 80);

		Library library;
		library.pushBook(book1);
		library.pushBook(book2);
		library.pushBook(book3);
		library.displayList();
        std::cout<<"===================================="<<'\n';
		library.sortBooksAlf();

		std::cout << "List of Books in the Library:\n";
		library.displayList();

        std::cout<<"===================================="<<'\n';
		std::cout << "\nSearching for book with ISBN: 978-3-16-148411-0\n";
		library.searchBook("978-3-16-148411-0");

        std::cout<<"===================================="<<'\n';
		std::cout << "\nRemoving book with ISBN: 978-3-16-148412-0\n";
		library.popBook("978-3-16-148412-0");

        std::cout<<"===================================="<<'\n';
		std::cout << "\nUpdated List of Books in the Library:\n";
		library.displayList();

        std::cout<<"===================================="<<'\n';
		std::cout << "\nAdding author 'New Author' to book with ISBN: 978-3-16-148410-0\n";
		library.addAuthor("New Author", "977-3-16-148410-0");

		library.sortBooksNum();

		std::cout << "\nUpdated List of Books in the Library:\n";
		library.displayList();
	}
	catch (const std::invalid_argument& e) {
		std::cerr << e.what();
	}
	catch (const std::runtime_error& e)
	{
        std::cerr<<e.what();
	}
	return 0;
}
