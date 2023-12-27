/*Словом, входящим в состав строки, назовём непрерывную
последовательность символов, ограниченную символами–разделителями,
началом и концом строки.Символы, относящиеся к разделителям, определяет
пользователь, если иное не сказано в условии задачи.Если решить задачу
невозможно, программа должна выдать соответствующее сообщение.
Вариант 14.
Дана строка, слова в которой состоят из букв латинского алфавита и
десятичных цифр.Остальные символы считаются разделителями между
словами.Получить новую строку, выполняя в заданной строке замены по
следующему правилу.Все слова, имеющие длину менее 7 символов и
состоящие только из цифр, заменяются словами, записанными в обратном
порядке.Во всех словах, в которых встречаются как буквы, так и цифры,
строчные буквы заменяются на прописные.Все слова, состоящие только из
букв, записываются строчными буквами.Слова в новой строке должны
разделяться ровно одним пробелом.*/


#include <iostream>
#include <string>


std::string searchForDelimiters(std::string &input, std::string &delims)
{
	for (const char &c : input) {
		if (!std::isalnum(c)) {
			delims.push_back(c);
		}
	}
	return delims;
}

std::string characterReplace(std::string word)
{
	std::string result;
	const std::string numbers = "1234567890";
	const std::string letters = "QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm";
	size_t wordLength = word.length();
	if (word.find_first_not_of(numbers) == std::string::npos && word.length() < 7) {
		std::string temp;
		for (int32_t i = wordLength; i >= 0; --i) {
			temp += word[i];
		}
		word = temp;
		result = word + " ";
	}
	if (word.find_first_not_of(letters) == std::string::npos) {
		for (size_t i = 0; i <= wordLength - 1; ++i) {
			word[i] = tolower(word[i]);
		}
		result = word + " ";
	}
	else {
		for (int i = 0; i <= wordLength - 1; ++i) {
			word[i] = toupper(word[i]);
		}
		result = word + " ";
	}
	return result;
}

void splittingIntoWords(std::string inputString)
{
	std::string delims;
	searchForDelimiters(inputString, delims);
	std::string word;
	std::string::size_type begInd;
	uint32_t len = inputString.size();
	begInd = inputString.find_first_not_of(delims);
	while (begInd != std::string::npos) {
		std::string::size_type endInd;
		endInd = inputString.find_first_of(delims, begInd);
		if (endInd == std::string::npos) {
			endInd = inputString.length();
		}
		word = inputString.substr(begInd, endInd - begInd);
		std::cout << characterReplace(word);
		begInd = inputString.find_first_not_of(delims, endInd);
	}
}

int main()
{
	std::string inputString;
	std::cout << "Enter your string:";
	getline(std::cin, inputString);
	std::cout << "Converted String:";
	splittingIntoWords(inputString);
	return 0;
}

