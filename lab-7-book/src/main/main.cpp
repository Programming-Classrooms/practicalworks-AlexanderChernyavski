#include "../Book/Book.hpp"
#include "../Library/Library.hpp"
#include <regex>
#include <fstream>

void separateString(const std::string &FIO, std::set<Book::Author> &FIOs) noexcept
{
    std::istringstream iss(FIO);
    std::string surname, name, fathername;
    iss >> surname >> name >> fathername;
    if (!surname.empty() && !name.empty() && !fathername.empty())
    {
        FIOs.insert(Book::Author(surname, name, fathername));
    }
}
bool checkString2(std::ifstream &fin) noexcept
{
    std::string buffer;
    getline(fin, buffer);
    if (buffer != "\r")
    {
        return true;
    }
    return false;
}
bool checkString(std::ifstream &fin, std::string &text) noexcept
{
    if (getline(fin, text) && !text.empty() && text != "\r")
    {
        return true;
    }
    return false;
}

void ReadFromFile(Library &library)
{
    std::string text;
    std::string ISBN, title, FIO, temp;
    int year = 0;
    std::regex title_regex("[A-Za-z]+[a-z]{3,} [A-Za-z]+[a-z]{3,}");
    std::regex name_regex("[A-Z][a-z]+ [A-Z][a-z]+ [A-Z][a-z]+");
    std::regex ISBN_regex("[0-9]{3}-[0-9]-[0-9]{2}-[0-9]{6}-[0-9]");
    std::regex year_regex("\\d{4}");
    std::set<Book::Author> FIOs;
    bool checker = false;
    std::ifstream fin("src/Files/data.txt");

    if (!fin.is_open())
    {
        std::cerr << "Failed to open the file." << std::endl;
        return;
    }

    while (!fin.eof())
    {
        for (size_t i = 0; i < 4; i++)
        {
            if (checkString(fin, text))
            {
                std::smatch match;
                switch (i)
                {
                case 0:
                {
                    if (std::regex_search(text, match, ISBN_regex))
                    {
                        ISBN = match[0];
                    }
                    break;
                }
                case 1:
                {
                    std::sregex_iterator nameIterator(text.begin(), text.end(), name_regex);
                    for (std::sregex_iterator it = nameIterator; it != std::sregex_iterator(); ++it)
                    {
                        separateString(it->str(), FIOs);
                    }
                    break;
                }
                case 2:
                {
                    if (std::regex_search(text, match, title_regex))
                    {
                        title = match[0];
                    }
                    break;
                }
                case 3:
                {
                    if (std::regex_search(text, match, year_regex))
                    {
                        year = std::stoi(match[0]);
                    }
                    break;
                }
                default:
                    break;
                }
            }
            else if (i == 0)
            {
                checker = true;
                break;
            }
            else if (i > 0)
            {
                --i;
                continue;
            }
        }
        if (!checker)
        {
            library.pushBook(Book(ISBN, year, title, FIOs));
            FIOs.clear();
        }
        checker = false;
    }
}

int main()
{
    try
    {
        // Creating authors
        Book::Author author1{"Sidorov", "Alexander", "Vasilievich"};

        // Creating a library
        Library library;
        ReadFromFile(library);

        library.diplayList();
        // Searching for a book by title
        std::cout << "\nSearching for Book 2:" << std::endl;

        library.searchBook("Introduction Algorithms");
        // Search authors book
        std::cout << "\nSearch authors book" << '\n';
        library.displayAuthorsBook(author1);

        // Removing a book from the library
        std::cout << "\nRemoving Book 1 from the library:" << std::endl;

        library.popBook("Database Basics");

        std::cout << "\nAdding an author to Book 3:" << std::endl;

        Book::Author author3{"David", "Brown", "Johnson"};
        library.addAuthor(author3, "Book 3");
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}