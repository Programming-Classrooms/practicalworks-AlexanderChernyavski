//При решении следующих задач использовать динамический массив.При
//необходимости заполнения массива предусмотреть два способа : ввод с клавиатуры и
//заполнение с помощью датчика случайных чисел.В последнем случае перед заполнением
//массива ввести границы интервала, которому должны принадлежать элементы массива.
//Вывести результаты расчетов.Если по каким - либо причинам решение задачи
//невозможно, вывести соответствующее сообщение.
//Вариант 14
//В целочисленной квадратной матрице :
//-Переставить строки матрицы таким образом, чтобы нулевые элементы стояли
//на главной диагонали, если в каждой строке и в каждом столбце квадратной
//матрицы имеется единственный нуль;
//-Подсчитать произведение элементов, лежащих ниже главной диагонали

#include <iostream>
#include <iomanip>
#include <ctime>
#include <array>


bool getType() {
	int32_t choise = 0;
	std::cout << "If you want the array to be filled with random elements, enter (0),"
		<< "if you want you to enter it yourself, enter (1) " << '\n';
	std::cin >> choise;
	if (choise < 0 || choise>1)
	{
		throw std::exception("In order to choose how to fill the matrix you need to enter 0 or 1");
	}
	switch (choise)
	{
	case 0: return true; break;
	case 1: return false; break;
	}
}

 int32_t** randomFilling(int32_t** array, size_t rows, size_t colums)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < colums; j++)
		{
			array[i][j] = rand() % 20;
		}
	}
	return array;
}

 int32_t** inputByHands(int32_t** array, size_t rows, size_t colums)
 {
	 for (size_t i = 0; i < rows; i++)
	 {
		 for (size_t j = 0; j < colums; j++)
		 {
			 std::cout << "Write element" << " " << "a" << '[' << i << ']' << " " << '[' << j << ']' << ':' << " ";
			 std::cin >> array[i][j];
		 }
	 }
	 return array;
 }

void checkNullElementsInColums(int32_t** array, size_t rows, size_t colums, size_t numberOfNullElrmentsColum)
{
	for (size_t j = 0; j < rows; ++j)
	{
		for (size_t i = 0; i < rows; ++i)
		{
			if (array[i][j] == 0)
			{
			    numberOfNullElrmentsColum++;
				if (numberOfNullElrmentsColum != 1) 
				{
					throw std::exception("only 1 null element per colum");
				}
			}
			if (i == colums - 1) 
			{
			    numberOfNullElrmentsColum = 0;
			}
		}
	}
}

void checkNuberOfNUllElements(int32_t** array, size_t rows, size_t colums, size_t numberOfNullElrments)
{
	size_t numberOfNUllEments = 0;
	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < rows; j++)
		{
			if (array[i][j] == 0)
			{
				numberOfNullElrments++;
			}
		}
	}
	if (numberOfNullElrments < rows)
	{
		throw std::exception("you shoud to write more null elements");
	}
}

void swapRows(int32_t** array, size_t rows, size_t colums)
{
	for (size_t i = 0; i + 1 < rows ; i++)
	{
		size_t temp = 0;
		temp = i;
		for (size_t j = 0; j < colums; j++) 
		{
			if (array[i][j] == 0) {
				temp = j;
				std::swap(array[i], array[temp]);
			}
		}
	}
}

int64_t productOfElementsLyingBelowTheMainDiagonal(int32_t** array, size_t rows, size_t colums)
{
	uint32_t Product = 1;
	for (size_t i = 1; i  < rows; i++)
	{
		for (size_t j = 0; j < i; j++)
		{
			Product *= array[i][j];
		}
	}
	return Product ;
	std::cout << "Product Of Elements Lying Below The MainD iagonal:"<<" " << Product << '\n';
}

void outPutArray(int32_t** array, size_t rows, size_t colums)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < colums; j++)
		{
			std::cout << std::setw(5) << array[i][j] << '\t';
		}
		std::cout << std::endl;
	}
}

void checkSize(size_t rows)
{
	while (rows <= 0)
	{
		std::cout<<"Not natural lenth";
	}
}

int main()
{
	size_t numberOfNullElrments = 0;
	size_t numberOfNullElrmentsColum = 0;
	size_t rows = 0;
	size_t colums = 0;
	std::cout << "Enter the number of rows that will be equal to the number of matrix columns";
	std::cin >> rows;
	checkSize(rows);
	colums = rows;
	int32_t** array = new int* [rows];
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < colums; j++)
		{
			array[i] = new int[colums];
		}
	}
	try {

		try {

			if (getType()) {
				srand(time(NULL));
				randomFilling(array, rows, colums);
				std::cout << '\n' << "Main matrix" << '\n';
				outPutArray(array, rows, colums);
				try
				{
					checkNullElementsInColums(array, rows, colums, numberOfNullElrments);
					try {
						checkNuberOfNUllElements(array, rows, colums, numberOfNullElrments);
						std::cout << "Product Of Elements Lying Below The MainD iagonal:" <<
							productOfElementsLyingBelowTheMainDiagonal(array, rows, colums);
						std::cout << '\n' << "Transformed matrix" << '\n';
						swapRows(array, rows, colums);
						outPutArray(array, rows, colums);
						std::cout << "Product Of Elements Lying Below The MainD iagonal:" <<
							productOfElementsLyingBelowTheMainDiagonal(array, rows, colums);
					}
					catch (const std::exception& errormessage)
					{
						std::cerr << errormessage.what();
					}
				}
				catch (const std::exception& ErrorMessage)
				{
					std::cerr << ErrorMessage.what();
				}
			}
			else
			{
				inputByHands(array, rows, colums);
				std::cout << '\n' << "Main matrix" << '\n';
				outPutArray(array, rows, colums);
				try
				{
					checkNullElementsInColums(array, rows, colums, numberOfNullElrments);
					try {
						checkNuberOfNUllElements(array, rows, colums, numberOfNullElrments);
						std::cout << "Product Of Elements Lying Below The MainD iagonal:" <<
							productOfElementsLyingBelowTheMainDiagonal(array, rows, colums);
						std::cout << '\n' << "Transformed matrix" << '\n';
						swapRows(array, rows, colums);
						outPutArray(array, rows, colums);
						std::cout << "Product Of Elements Lying Below The MainD iagonal:" <<
							productOfElementsLyingBelowTheMainDiagonal(array, rows, colums);
					}
					catch (const std::exception& errormessage)
					{
						std::cerr << errormessage.what();
					}
				}
				catch (const std::exception& ErrorMessage)
				{
					std::cerr << ErrorMessage.what();
				}
			}
		}
			catch (const std::exception& error)
			{
				std::cerr << error.what();
			}
			throw std::string();
		}
	
catch (const std::string& isa)
{
	delete[] array;
}
	catch (const std::exception& is)
	{
		std::cerr << is.what();
	}
	return 0;
}