/*При решении следующих задач использовать динамический массив.При
необходимости заполнения массива предусмотреть два способа : ввод с клавиатуры и
заполнение с помощью датчика случайных чисел.В последнем случае перед заполнением
массива ввести границы интервала, которому должны принадлежать элементы массива.
Вывести результаты расчетов.Если по каким - либо причинам решение задачи
невозможно, вывести соответствующее сообщение.
Вариант 14
В целочисленной квадратной матрице :
-Переставить строки матрицы таким образом, чтобы нулевые элементы стояли
на главной диагонали, если в каждой строке и в каждом столбце квадратной
матрицы имеется единственный нуль;
-Подсчитать произведение элементов, лежащих ниже главной диагонали*/


#include <iostream>
#include <iomanip>
#include <ctime>
#include <array>


void cleanMemory(int32_t** matrix, int32_t rows)
{
	for (uint32_t i = 0; i < rows; ++i) {

		delete[] matrix[i];
	}
	delete[] matrix;
}

bool getType() {
	int32_t choise = 0;
	std::cout << "If you want the array to be filled with random elements, enter (0),"
		<< "if you want you to enter it yourself, enter (1) " << '\n';
	std::cin >> choise;
	switch (choise)
	{
	case 0: return true; break;
	case 1: return false; break;
	default:
		throw std::runtime_error("In order to choose how to fill the matrix you need to enter 0 or 1");
	}
}

void randomFilling(int32_t** array, size_t rows, size_t colums)
{
	int32_t first0, last0;
	std::cout << "Initial value from = \n";
	std::cin >> first0;
	std::cout << "to = \n";
	std::cin >> last0;
	if (first0 > last0) {
		std::swap(first0, last0);
	}
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < colums; ++j) {
			array[i][j] = rand() % (last0 - first0) + first0;
		}
	}
}

void inputByHands(int32_t** array, size_t rows, size_t colums)
{
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < colums; ++j) {
			std::cout << "Write element" << " " << "a [" << i << ']' << " " << '[' << j << ']' << ':' << " " << '\n';
			std::cin >> array[i][j];
		}
	}
}

void checkNullElementsInColumsAndInMatrix(int32_t** matrix, size_t rows, size_t colums)
{
	size_t numberOfNullElrmentsInMatrix = 0;
	size_t numberOfNullElrmentsInColum = 0;
	for (size_t j = 0; j < rows; ++j) {
		for (size_t i = 0; i < rows; ++i) {
			if (matrix[i][j] == 0) {
				++numberOfNullElrmentsInColum;
				++numberOfNullElrmentsInMatrix;
				if (numberOfNullElrmentsInColum != 1) {
					cleanMemory(matrix, rows);
					throw std::exception("only 1 null element per colum");
				}
			}
			if (i == colums - 1) {
				numberOfNullElrmentsInColum = 0;
			}
		}
	}
	if (numberOfNullElrmentsInMatrix < rows) {
		cleanMemory(matrix, rows);
		throw std::exception("you shoud  write more null elements");
	}
}


void swapRows(int32_t** array, size_t rows, size_t colums)
{
	for (size_t i = 0; i <= rows; ++i) {
		size_t temp = 0;
		temp = i;
		for (size_t j = 0; j < colums; ++j) {
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
	for (size_t i = 1; i < rows; ++i) {
		for (size_t j = 0; j < i; ++j) {
			Product *= array[i][j];
		}
	}
	return Product;
}

void outPutArray(int32_t** array, size_t rows, size_t colums)
{
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < colums; ++j) {
			std::cout << std::setw(5) << array[i][j];
		}
		std::cout << std::endl;
	}
}

void checkSize(size_t rows)
{
	if (rows <= 0) {
		std::cout << "Not natural lenth";
	}
}

int main()
{
	try {
		size_t rows = 0;
		size_t colums = 0;
		std::cout << "Enter the number of rows that will be equal to the number of matrix columns";
		std::cin >> rows;
		checkSize(rows);
		colums = rows;
		int32_t** array = new int* [rows];
		for (size_t i = 0; i < rows; ++i) {
			array[i] = new int[colums];
		}
		if (getType()) {
			srand(time(NULL));
			randomFilling(array, rows, colums);
			std::cout << '\n' << "Main matrix" << '\n';
			outPutArray(array, rows, colums);
			checkNullElementsInColumsAndInMatrix(array, rows, colums);
			std::cout << "Product Of Elements Lying Below The MainD iagonal:" <<
				productOfElementsLyingBelowTheMainDiagonal(array, rows, colums);
			std::cout << '\n' << "Transformed matrix" << '\n';
			swapRows(array, rows, colums);
			outPutArray(array, rows, colums);
			std::cout << "Product Of Elements Lying Below The MainD iagonal:" <<
				productOfElementsLyingBelowTheMainDiagonal(array, rows, colums);
		}
		else {
			inputByHands(array, rows, colums);
			std::cout << '\n' << "Main matrix" << '\n';
			outPutArray(array, rows, colums);
			checkNullElementsInColumsAndInMatrix(array, rows, colums);
			std::cout << "Product Of Elements Lying Below The MainD iagonal:" <<
				productOfElementsLyingBelowTheMainDiagonal(array, rows, colums);
			std::cout << '\n' << "Transformed matrix" << '\n';
			swapRows(array, rows, colums);
			outPutArray(array, rows, colums);
			std::cout << "Product Of Elements Lying Below The MainD iagonal:" <<
				productOfElementsLyingBelowTheMainDiagonal(array, rows, colums);
		}
	}
	catch (const std::exception& is)
	{
		std::cout << is.what();
	}
	return 0;
}