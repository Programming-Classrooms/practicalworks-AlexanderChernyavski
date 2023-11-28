*/Вариант 28
В одномерном массиве, состоящем из n целых элементов:
- найти самую длинную цепочку подряд стоящих элементов, которая является
«палиндромом». В такой цепочке первое число равно последнему числу, второе –
предпоследнему и т.д.
- произведение элементов массива, расположенных между первым и вторым нулевыми
элементами.
Преобразовать массив таким образом, чтобы в первой его половине располагались элементы,
стоявшие в нечетных позициях, а во второй половине — элементы, стоявшие в четных
позициях. Порядок следования элементов не изменять.*/

#include <iostream>
#include <ctime>


void outputArray(__int32 arr[], size_t n)
{
	for (size_t i = 0; i < n; ++i) 
	{
		std::cout << arr[i] << " ";
	}
	std::cout<<'\n';
}


bool getType(){
	__int32 choise = 0;
	std::cout << "Если хочешь чтобы массив заполнился случайными элементами то введи(0),"
	          <<"если хочешь заполнить ассив элементами вручную ,то введи (1) " << '\n';
	std::cin >> choise;
   
	if (choise < 0 || choise > 1)
	{
		throw std::exception("Допистымые значения для выбора заполнения элементами массива (0) или (1)");
	}
	
	switch (choise)
	{
	case 0: return true; break;
	case 1: return false; break;
	}
}


void zeroIndex(__int32 arr[], size_t n) {
	__int32 firstZero = -1;
	__int32 secondZero = -1;
	 __int32 result = 0;

	for (size_t i = 0; i < n; ++i) {

		if (arr[i] == 0) {
			if (firstZero == -1) {
				firstZero = i;
			}
			else {
				secondZero = i;
				break;
			}
		}
	}
	if (firstZero == !- 1 && secondZero == !- 1) {
		for (size_t i = firstZero + 1; i <= secondZero; ++i) {
			result *= arr[i];

		}
		std::cout << "Произведение равно" << result;
	}
	if (firstZero == -1 && secondZero == -1) {
		std::cout << "нулевых элементов нету " << '\n';
	}

	 if (firstZero == 0 && secondZero == -1)
	{
		std::cout << "нету второго нулевого элемента" << '\n';
	}
	if (firstZero == !- 1 && secondZero == firstZero + 1)
	{
		std::cout << "произведение вычислить невозможно (между нулевыми элементами нету чисел)"<<'\n';
	}
	
}
void transMassiv(size_t& n, __int32 arr[]) {

	for (size_t i = 0; i < n; ++i) {
		if (i % 2 == 0) {
			std::cout << arr[i]<<'\t';
		}
	}

	for (size_t i = 0; i < n; ++i) {
		if (i % 2 == 1) {
			std::cout << arr[i]<<'\t';
		}
	}
}
void polindrom(size_t &n, __int32 arr[]) {
	size_t maxLength = 0;
	size_t start = 0;
	size_t end = 0;

	for (size_t i = 0; i < n; ++i) { 
		for (size_t j = i; j < n; ++j) {
			bool isPalindrome = true;
			for (size_t k = i; k <= (i + j) / 2; ++k) {
				if (arr[k] != arr[j - (k - i)]) {
					isPalindrome = false;
					break;
				}
			}

			if (isPalindrome && (j - i + 1) > maxLength) {
				maxLength = j - i + 1;
				start = i;
				end = j;
			}
		}
	}

	if (maxLength > 0) {
		std::cout << "Самаядлинна цепочка палиндрома: ";
		for (size_t i = start; i <= end; ++i) {
			std::cout << arr[i] << " ";
		}
		std::cout << '\n';
	}
	else {
		std::cout << "Палиндрома нет" << '\t';

	}
}


void checkLenthArray(__int32 a)
{
	while (a < 1)
	{
		std::cout << "Not natural lenth\n";
		std::cin >> a;
	} 
}


int main() {
	srand(time(NULL));
	
		setlocale(LC_ALL, "Russian");
		size_t n = 0;
		std::cout << "Введите количество элементов в массиве\n";
		std::cin >> n;
		checkLenthArray(n);
		__int32* arr = new int[n];
    try {
		
		if (getType())
		{
			__int32 first0, last0;
			std::cout << "Начальное значение от= \n";
			std::cin >> first0;
			std::cout << "до = \n";
			std::cin >> last0;
			if (first0 > last0)
			{
				std::swap(first0, last0);
			}
			for ( size_t i = 0; i < n; ++i) {
				arr[i] = rand() % (last0 - first0) + first0;
			}
			outputArray( arr, n);
			zeroIndex(arr, n);
			polindrom(n, arr);
			transMassiv(n, arr);
		}
		else {
			for ( size_t i = 0; i < n; ++i) {
				std::cout << "Введите " << i << " " << "элемент\n";
				std::cin >> arr[i];
			}
			outputArray( arr, n);
			zeroIndex(arr, n);
			polindrom(n, arr);
			transMassiv(n, arr);
		}
		throw std::string();
	}
	catch (const std::string& isa)
	{
		delete[] arr;
	}
	catch (const std::exception& is)
	{
		std::cerr << is.what();
	}

	return 0;
}
