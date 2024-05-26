/*Поясняю за лабу throw я делал для того чтобы можно было всё нормально
протестировать с помощбю Expect, более того я заранее выводил список всех книг
и если пользователь с первой попытки не может написать в метод название, мне кажется
это его проблемы.Ф-ция readFromFile выполняет считывание из файла инфо о книгах
содавая шаблон я из считанной строки считываю то что максимально походе на заданный шаблон.
Про геттер и конструкторы согласен.G тесты бесполезные.SeptateString считанную строку вида ФИО я stringstrream
делю на Ф И О тк у меня это разные поля в struct Author*/

#include "src/Functions/functions.hpp"


int main()
{
    try
    {
        Book::Author author{"Sidorov", "Alexander", "Vasilievich"};
        Book::Author author404{"Kakoi", "To", "Author"};
        Book::Author authorToAdd{"Ivanov", "Ivan", "Ivanovich"};
        Book::Author authorToTest{"Petrov", "Petr", "Petrovich"};
        
        Library library;

        readFromFile(library);

        library.diplayList();
    
        std::cout << "\nSearch book Introduction Algorithms:" <<'\n';
        library.searchBook("Introduction Algorithms");

        std::cout << "\nSearch book with author Sidorov Alexander Vasilievich" << '\n';
        library.displayAuthorsBook(author);

        std::cout << "\nRemoving Book Database Basics from the library:" <<'\n';
        library.popBook("Database Basics");

        std::cout << "\nAdding an author to Python Programming:" <<'\n';
        library.addAuthor(authorToAdd, "Python Programming");

        library.diplayList();

         std::cout<<"==============================================="<<'\n';
         library.popAuthor(authorToAdd, "Python Programming");
         library.diplayList();
         
        std::cout<<"==============================================="<<'\n';
         library.displayAuthorsBook(authorToTest);

    }
    catch (const std::runtime_error &e)
    {
        std::cerr << e.what();
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr<<e.what();
    }
    catch (const std::ios_base::failure &e)
    {
        std::cerr<<e.what();
    }
    return 0;
}
