#include "src/Functions/functions.hpp"


int main()
{
	try
	{
		setlocale(LC_ALL, "Russian");
		std::vector<std::string> list;
		std::ifstream fin("src/Files/list.txt");
		checkFile(fin);
		std::string line;
		char choise, letter;
		while (getline(fin, line))
		{
			list.push_back(line);
		}
		fin.close();
		std::cout << "Список записан в вектор";
		while (true)
		{
			std::cout << "Выберите вариант 1-сортировка 2-вывод слова по букве 3-удаление по букве 4-закончить работу";
			std::cin >> choise;
			switch (choise)
			{
			case '1':
				std::sort(list.begin(), list.end());
				PrintList(list);
				break;
			case '2':
				std::cout << "Введите букву:";
				std::cin >> letter;
				SpellingAWordByLetter(letter, list);
				break;
			case '3':
				std::cout << "Введите букву:";
				std::cin >> letter;
				RemovingAWordByLetter(letter, list);
				PrintList(list);
				break;
			case '4':
				return 0;
			default:
				throw std::runtime_error("неправильный выбор");
				break;
			}
		}
	}
	catch (const std::runtime_error &e)
	{
		std::cerr << e.what();
	}
	catch (const std::invalid_argument &e)
	{
		std::cerr << e.what();
	}
	catch (const std::ios_base::failure &e)
	{
		std::cerr << e.what();
	}
	return 0;
}