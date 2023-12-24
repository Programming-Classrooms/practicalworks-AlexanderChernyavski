///Использовать динамичкский массив.
// Максимальную размерность массива задать именованной константой.
// Реальное количество элементов массива ввести с клавиатуры с контролем на выход
// за границы массива.Массивы должны состоять не менее, чем из одного элемента.
// предусмотреть два способа заполнения массива : с клавиатуры и с помощью
// датчика случайных чисел.В последнем случае перед заполнением массива ввести
// границы интервала, которому должны принадлежать элементы массива.
// Вывести результаты расчетов.Если по каким - либо причинам решение задачи
// невозможно, вывести соответствующее сообщение.
// Дополнительных массивов для преобразования данных использовать нельзя.
//Вариант 28
//В одномерном массиве, состоящем из n целых элементов :
//-найти самую длинную цепочку подряд стоящих элементов, которая является
//«палиндромом».В такой цепочке первое число равно последнему числу, второе –
//предпоследнему и т.д.
//- произведение элементов массива, расположенных между первым и вторым нулевыми
//элементами.
//Преобразовать массив таким образом, чтобы в первой его половине располагались элементы,
//стоявшие в нечетных позициях, а во второй половине — элементы, стоявшие в четных
//позициях.Порядок следования элементов не изменять.



#include <iostream>
#include <ctime>
#include <memory>


void outputArray(std::shared_ptr<int32_t[]> arr, size_t n)
{
	for (size_t i = 0; i < n; ++i) 
	{
		std::cout << arr[i] << " ";
	}
	std::cout<<'\n';
}

bool getType()
{
	int32_t choise = 0;
	std::cout << "If you want the array to be filled with random elements, enter (0)"
	          <<"if you want you to enter it yourself, enter (1)" << '\n';
	std::cin >> choise;
   
	if (choise < 0 || choise > 1)
	{
		throw std::exception("Enter only (0) or (1) to select array padding");
	}
	switch (choise)
	{
	case 0: return true; break;
	case 1: return false; break;
	}
}

std::shared_ptr<int32_t[]> randomFilling(size_t size, std::shared_ptr<int32_t[]> arr)
{
	int32_t first0, last0;
	std::cout << "Initial value from = \n";
	std::cin >> first0;
	std::cout << "to = \n";
	std::cin >> last0;
	if (first0 > last0)
	{
		std::swap(first0, last0);
	}
	for (size_t i = 0; i < size; ++i)
	{
		arr[i] = rand() % (last0 - first0) + first0;
	}
	return arr;
}

std::shared_ptr<int32_t[]> fillingByHands(size_t size, std::shared_ptr<int32_t[]> arr)
{
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << "Enter " << i << " " << "element\n";
		std::cin >> arr[i];
	}
	return arr;
}

void zeroIndex(std::shared_ptr<int32_t[]> arr, size_t n)
{
	int32_t firstZero = -1;
	int32_t secondZero = -1;
	int32_t result = 0;
	for (size_t i = 0; i < n; ++i) 
	{

		if (arr[i] == 0) {
			if (firstZero == -1) 
			{
				firstZero = i;
			}
			else {
				secondZero = i;
				break;
			}
		}
	}
	if (firstZero == !- 1 && secondZero == !- 1) 
	{
		for (size_t i = firstZero + 1; i <= secondZero; ++i) 
		{
			result *= arr[i];
		}
		std::cout << "the product is equal to" << result;
	}
	if (firstZero == -1 && secondZero == -1) 
	{
		std::cout << "there are no zero elements" << '\n';
	}
	 if (firstZero == 0 && secondZero == -1)
	 {
		std::cout << "there is no second zero element" << '\n';
	 }
	if (firstZero == !- 1 && secondZero == firstZero + 1)
	{
		std::cout << "it is impossible to calculate the product"<<'\n';
	}
}

void transformArray(size_t n, std::shared_ptr<int32_t[]> arr) 
{
	std::cout << "Transformed array:" << std::endl;
	for (size_t i = 0; i < n; ++i) 
	{
		if (i % 2 == 0) 
		{
			std::cout << arr[i]<<'\t';
		}
	}
	for (size_t i = 0; i < n; ++i) {
		if (i % 2 == 1) 
		{
			std::cout << arr[i]<<'\t';
		}
	}
}

void polindrom(size_t n, std::shared_ptr<int32_t[]> arr) 
{
	size_t maxLength = 0;
	size_t start = 0;
	size_t end = 0;
	for (size_t i = 0; i < n; ++i) 
	{ 
		for (size_t j = i; j < n; ++j) 
		{
			bool isPalindrome = true;
			for (size_t k = i; k <= (i + j) / 2; ++k) 
			{
				if (arr[k] != arr[j - (k - i)]) 
				{
					isPalindrome = false;
					break;
				}
			}
			if (isPalindrome && (j - i + 1) > maxLength) 
			{
				maxLength = j - i + 1;
				start = i;
				end = j;
			}
		}
	}
	if (maxLength > 0) 
	{
		std::cout << "Longest palindrome chain: ";
		for (size_t i = start; i <= end; ++i) 
		{
			std::cout << arr[i] << " ";
		}
		std::cout << '\n';
	}
	else 
	{
		std::cout << "Palindrome not found." << '\t';
	}
}

void checkLenthArray(int32_t a)
{
	while (a < 1)
	{
		std::cout << "Not natural lenth\n";
		std::cin >> a;
	} 
}

int main() 
{
	srand(time(NULL));
		size_t size = 0;
		std::cout << "Enter the number of elements in the array\n";
		std::cin >> size;
		checkLenthArray(size);
		std::shared_ptr <int32_t[]> arr(new int32_t[size]);
    try 
	{
		if (getType())
		{
			randomFilling(size, arr);
			outputArray(arr, size);
			zeroIndex(arr, size);
			polindrom(size, arr);
			transformArray(size, arr);
		}
		else 
		{
			fillingByHands(size, arr);
			outputArray( arr, size);
			zeroIndex(arr, size);
			polindrom(size, arr);
			transformArray(size, arr);
		}
	}
	catch (const std::exception& is)
	{
		std::cerr << is.what();
	}
	return 0;
}
