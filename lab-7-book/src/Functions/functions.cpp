#include "functions.hpp"


bool checkFile(std::ifstream &file)
{
	if (!file.good())
	{
		throw std::invalid_argument("File not found ! ");
	}

	if (!file)
	{
		throw std::ios_base::failure("Error reading file!");
	}

	if (file.peek() == EOF)
	{
		throw std::runtime_error("File is empty!");
	}

	return true;
}

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

bool checkingStringsForEmptiness(std::ifstream &fin, std::string &text) noexcept
{
    if (getline(fin, text) && !text.empty() && text != "\r")
    {
        return true;
    }
    return false;
}

void readFromFile(Library &library)
{
    std::string text;
    std::string ISBN, title, FIO, temp;
    int32_t year = 0;

    std::regex title_regex("[A-Za-z]+[a-z]{3,} [A-Za-z]+[a-z]{3,}");
    std::regex name_regex("[A-Z][a-z]+ [A-Z][a-z]+ [A-Z][a-z]+");
    std::regex ISBN_regex("[0-9]{3}-[0-9]-[0-9]{2}-[0-9]{6}-[0-9]");
    std::regex year_regex("\\d{4}");

    std::set<Book::Author> FIOs;//ФИО которые считаются из файла
    bool flag = false; //Флаг создан для тогоб чтобы предотвратить неграмотное считывание файлабесли строки разорваны между собой как у второй книги
    std::ifstream fin("src/Books/Books.txt");

    checkFile(fin);

    while (!fin.eof())
    {
        for (size_t i = 0; i < 4; i++)
        {
            if (checkingStringsForEmptiness(fin, text))
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
                flag = true;
                break;
            }
            else if (i > 0)
            {
                --i;
                continue;
            }
        }
        if (!flag)
        {
            library.pushBook(Book(ISBN, year, title, FIOs));
            FIOs.clear();
        }
        flag = false;
    }
}
