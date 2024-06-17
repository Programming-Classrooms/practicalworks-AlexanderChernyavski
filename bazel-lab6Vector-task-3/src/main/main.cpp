#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>

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

int main()
{
	try
	{
		setlocale(LC_ALL, "Russian");
		std::vector<std::string> list;
		std::ifstream fin("src/Files/list.txt");
		checkFile(fin);
		std::string line;
		char choise1, letter;
		while (getline(fin, line))
		{
			std::getline(fin, line);
			list.push_back(line);
		}
		fin.close();
		std::cout << "Список записан в вектор";
		while (true)
		{
			std::cout << "Выберите вариант 1-сортировка 2-вывод слова по букве 3-удаление по букве 4-закончить работу";
			std::cin >> choise1;
			switch (choise1)
			{
			case '1':
				std::sort(list.begin(), list.end());
				for (const auto &word : list)
				{
					std::cout << word << '\n';
				}
				break;
			case '2':
				std::cout << "Введите букву:";
				std::cin >> letter;
				for (const auto &word : list)
				{
					if (word[0] == letter)
					{
						std::cout << word;
					}
				}
				break;
			case '3':
				std::cout << "Введите букву:";
				std::cin >> letter;
				for (const auto &word : list)
				{
					if (word[0] == letter)
					{
						auto iterator = std::find(list.begin(), list.end(), word);
						list.erase(iterator);
					}
				}
				for (const auto &word : list)
				{
					std::cout << word << '\n';
				}
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
	return 0;
}