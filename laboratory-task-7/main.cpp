/*
	При написании программ использовать нуль–терминированные строки
	и работать только с типом char* .Длина каждой строки не превосходит 300
	символов.Словом, входящим в состав строки, назовём непрерывную
	последовательность символов, ограниченную символами–разделителями,
	началом и концом строки.Символы, относящиеся к разделителям, определяет
	пользователь, если иное не сказано в условии задачи.Если решить задачу
	невозможно, программа должна выдать соответствующее сообщение.
	Вариант 14.
	Дана строка, слова в которой состоят из букв латинского алфавита и
	десятичных цифр.Остальные символы – разделители между словами.
	Получить новую строку, выполняя в заданной строке замены по следующему
	правилу.Все слова, имеющие длину менее 5 символов и состоящие только из
	цифр, заменяются словами, получаемыми из исходных путём дописывания
	ведущих нулей до получения длины слова, равной 5. Все слова, состоящие
	только из букв, заменяются словами, записанными в обратном порядке.
	Слова в новой строке должны разделяться ровно одним пробелом.
*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


char *replacingCharacters(char *str) // Замена символов,которорые не являются буквами/цифрами на пробельный символ
{
	for (size_t i = 0; i < strlen(str) - 1; ++i)
	{
		if (!isalnum(str[i]))
		{
			str[i] = ' ';
		}
	}
	return str;
}

bool checkStringWordIsdigit(char *word)
{
	for (size_t i = 0; i < strlen(word); ++i)
	{
		if (!isdigit(word[i]))
		{
			return false;
		}
	}
}

bool checkStringWordIsalpha(char *word)
{
	for (size_t i = 0; i < strlen(word); ++i)
	{
		if (!isalpha(word[i]))
		{
			return false;
		}
	}
}

void stringReplace(char *str)
{
	char result[300];
	char delimiters[300];
	strcpy(result, " ");
	for (char *word = strtok(str, " "); word != NULL; word = strtok(NULL, " "))
	{
		if (checkStringWordIsdigit(word) && strlen(word) < 5)
		{
			sprintf(result + strlen(result), "%05d ", atoi(word));
		}
		else if (checkStringWordIsalpha(word))
		{
			_strrev(word); // разворачиваю строку
			strcat(result, word);
			strcat(result, " ");
		}
		else
		{
			// Слова, не подпадающие под правила, остаются без изменений
			strcat(result, word);
			strcat(result, " ");
		}
	}
	std::cout << result;
}

void checkLength(char *str)
{
	if (strlen(str) > 300)
	{
		throw std::exception("lenth of your string more than 300 symbols");
	}
}

int main()
{
	try
	{
		char str[300];
		std::cout << "Enter your string" << '\n';
		std::cin.getline(str, 300);
		replacingCharacters(str);
		std::cout << "Converted string:" << '\n';
		stringReplace(str);
		return 0;
	}
	catch (const std::exception &is)
	{
		std::cerr << is.what();
	}
}

