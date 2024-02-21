/*
	Вариант 14
	Реализовать механизм сложения двух разреженных матриц с  практически неограниченной размерностью,
	а также механизм умножения  такой матрицы на целое число. Элементы матриц – данные типа int. 
	Предусмотреть организацию ввода-вывода как через консоль, так и через  текстовые файлы.  
*/


#include <iostream>
#include <fstream>
#include <iomanip>


void outputMatrixInConsole(int32_t** matrix, int32_t numRows, int32_t numCols)
{
	for (size_t i = 0; i < numRows; ++i)
	{
		for (size_t j = 0; j < numCols; ++j)
		{
			std::cout << std::setw(3) << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void cleanMemory(int32_t** matrix, int32_t rows)
{
	if (rows >= 0)
	{
		for (uint32_t i = 0; i < rows; ++i) {

			delete[] matrix[i];
		}
		delete[] matrix;
	}
	else 
	{
		delete[] matrix;
	}

}

size_t countByteOfFile(const std::string filename)
{
	size_t counter = 0;
	std::ifstream fin(filename);
	while (!fin.eof())
	{
		fin.get();
		++counter;
	}
	fin.close();
	--counter;
	return counter;
}

void checkSizeofMatrix(int32_t numRows, int32_t numCols)
{
	if (numRows <= 0 || numCols <= 0)
	{
		throw std::exception("The size of matrix maust be natural");
	}
}

void checkSizeofMatrixBeforeAdd(int32_t numRows1, int32_t numCols1, int32_t numRows2, int32_t numCols2)
{
	if (numRows1 != numRows2 || numCols1 != numCols2)
	{
		throw std::exception("It is impossible to add matrices, the dimensions of the matrices are different");
	}
}

void innputMatrixByHands(int32_t**& matrix, int32_t& numRows, int32_t& numCols)
{
	std::cout << "Write number of rows";
	std::cin >> numRows;
	std::cout << "Write number of colums";
	std::cin >> numCols;

	checkSizeofMatrix(numRows, numCols);
	
	matrix = new int32_t * [numRows];
	for (size_t i = 0; i < numRows; ++i)
	{
		matrix[i] = new int32_t[numCols];
	}

	for (size_t i = 0; i < numRows; ++i)
	{
		for (size_t j = 0; j < numCols; ++j)
		{
			std::cout << "Write element" << " " << "a [" << i << "] [" << j << "] :" << " ";
			std::cin >> matrix[i][j];
		}
	}
	std::cout << "Your matrix:\n";
	outputMatrixInConsole(matrix, numRows, numCols);
}

bool checkSparseMatrix(int32_t** matrix, int32_t numRows, int32_t numCols)
{
	size_t counterOfNullElements = 0;
	for (size_t i = 0; i < numRows; ++i)
	{
		for (size_t j = 0; j < numCols; ++j)
		{
			if (matrix[i][j] == 0)
			{
				++counterOfNullElements;
			}
		}
	}
	if (counterOfNullElements <= (numCols * numRows - counterOfNullElements))
	{
		return false;
	}
	return true;
}

void readSparseMatrixFromFile(const std::string filename, int32_t**& matrix, int32_t& numRows, int32_t& numCols)
{
	std::ifstream file(filename);
	
	    if (file.is_open())
	    {
			if (countByteOfFile(filename) == 0)
			{
				throw std::exception("File is empty");
			}
	        int32_t countElementsInmatrix = 0;// число чисел в файле
	        int32_t temp;
	        while (!file.eof()) {
	            file >> temp;
	            countElementsInmatrix++;
	        }
	        file.seekg(0, std::ios::beg);
	        file.clear();
	        int32_t countSpaceInMatrix = 0;
	        char symbol;
			while (!file.eof())
			{
				file.get(symbol);
				if (symbol == ' ') ++countSpaceInMatrix;
				if (symbol == '\n') break;
			}
	        file.seekg(0, std::ios::beg);
	        file.clear();
	
	         numRows = countElementsInmatrix / (countSpaceInMatrix );//число строк
	         numCols = countSpaceInMatrix ;//число столбцов 
	        matrix = new int32_t* [numRows];
			for (size_t i = 0; i < numRows; ++i)
			{
				matrix[i] = new int32_t[numCols];
			}
	
			for (size_t i = 0; i < numRows; ++i)
			{
				for (size_t j = 0; j < numCols; ++j)
				{
					file >> matrix[i][j];
				}
			}
			std::cout << "Matrix read from file:\n";
			outputMatrixInConsole(matrix, numRows, numCols);
	        file.close();
		}
	    else
	    {
	        std::cout << "File not found.";
	    }
}

void addSparseMatrices
(int32_t**& matrix1, int32_t** matrix2, int32_t numRows, int32_t numCols, int32_t numRows2, int32_t numCols2)
{
	
	checkSizeofMatrixBeforeAdd(numRows, numCols, numRows2, numCols2);
	for (size_t i = 0; i < numCols; ++i)
	{
		for (size_t j = 0; j < numRows; ++j)
		{
			matrix1[i][j] += matrix2[i][j];
		}
	}
}

void writeSparseMatrixToFile(int32_t** matrix, int32_t numRows, int32_t numCols, const std::string filename)
{
	std::ofstream file(filename);

	if (file.is_open())
	{
		for (size_t i = 0; i < numRows; ++i)
		{
			for (size_t j = 0; j < numCols; ++j)
			{
				file << matrix[i][j] << " ";
			}
			file << std::endl;
		}
		file.close();
	}
	else {
		throw  std::exception("Unable to open file");
	}
}

int32_t** multiplySparseMatrixByScalar(int32_t**& matrix, int32_t numRows, int32_t numCols, int32_t scalar)
{
	for (size_t i = 0; i < numRows; ++i)
	{
		for (size_t j = 0; j < numCols; ++j)
		{
			matrix[i][j] *= scalar;
		}
	}
	return matrix;
}



void selectHowToWrite
(int32_t** matrix, int32_t numRows1, int32_t numCols1)
{
	uint32_t choiceForTask;
	std::cout << "Choose an option:\n";
	std::cout << "1. Output result to file\n";
	std::cout << "2. Output result to console\n";
	std::cout << "What did you choose: ";
	std::cin >> choiceForTask;
	std::cout << "\n";
	switch (choiceForTask)
	{
	case 1:
		writeSparseMatrixToFile(matrix, numRows1, numCols1, "result.txt");
		std::cout << "Result is writen to file result.txt" << '\n';
		break;
	case 2:
		outputMatrixInConsole(matrix, numRows1, numCols1);
		break;
	default:
		throw std::runtime_error("Invalid choice. Choose between 1, 2, and 3.\n");
	}
}

void selectInputOptionTofillOutTheMatrixNo2
(int32_t**& matrix2, int32_t& numRows2, int32_t& numCols2)
{
	uint32_t choiceForArray;
	std::cout << "Choose which array you want:\n";
	std::cout << "1.Fill matrix from file\n";
	std::cout << "2. Fill matrix by hands\n";
	std::cout << "What did you choose: ";
	std::cin >> choiceForArray;
	std::cout << '\n';
	switch (choiceForArray)
	{
	case 1:
		readSparseMatrixFromFile("matrix2.txt", matrix2, numRows2, numCols2);
		if (!checkSparseMatrix(matrix2, numRows2, numCols2))
		{
			throw std::exception("The matrix2 is not sparse");
		}

		break;
	case 2:
		innputMatrixByHands(matrix2, numRows2, numCols2);
		if (!checkSparseMatrix(matrix2, numRows2, numCols2))
		{
			throw std::exception("The matrix2 is not sparse");
		}
		break;
	default:
		throw std::runtime_error("Invalid choice. Choose between 1, 2, and 3.\n");
	}
}

void selectInputOption
(int32_t** matrix1, int32_t numRows1, int32_t numCols1, int32_t** matrix2, int32_t numRows2, int32_t numCols2)
{
	int32_t scalar;
	uint32_t choiceForTask;
	std::cout << "Choose an option:\n";
	std::cout << "1. Multiply matrix with scalar\n";
	std::cout << "2. Multiply matrix with matrix\n";
	std::cout << "What did you choose: ";
	std::cin >> choiceForTask;
	std::cout << "\n";
	switch (choiceForTask)
	{
	case 1:
		std::cout << "Enter the number by which you want to multiply the matrix:";
		std::cin >> scalar;
		multiplySparseMatrixByScalar(matrix1, numRows1, numCols1, scalar);
		selectHowToWrite(matrix1, numRows1, numCols1);
		break;
	case 2:
		selectInputOptionTofillOutTheMatrixNo2(matrix2, numRows2, numCols2);
		addSparseMatrices(matrix1, matrix2, numRows1, numCols1, numRows2, numCols2);
		selectHowToWrite(matrix1,numRows1, numCols1);
		break;
	default:
		throw std::runtime_error("Invalid choice. Choose between 1, 2, and 3.\n");
	}
}

int main()
{
	std::cout << "Notice! " << '\n';
	std::cout << "A sparse matrix is a matrix with predominantly zero elements. " << '\n';
	std::cout << "Otherwise, if most of the matrix elements are non-zero, the matrix is considered dense or full. " << '\n';
	int32_t numRows1 = 0, numCols1 = 0, numRows2 = 0, numCols2 = 0;
	int32_t** matrix1 = nullptr;
	int32_t** matrix2 = nullptr;
	uint32_t choiceForMatrix;
	std::cout << "Choose which array you want:\n";
	std::cout << "1. Fill marits from file\n";
	std::cout << "2. Fill matrix by hands\n";
	std::cout << "What did you choose: ";
	std::cin >> choiceForMatrix;
	std::cout << '\n';
	try
	{
		switch (choiceForMatrix)
		{
		case 1:
			readSparseMatrixFromFile("matrix1.txt", matrix1, numRows1, numCols1);
			if (!checkSparseMatrix(matrix1, numRows1, numCols1))
			{
				throw std::exception("The matrix №1 is not sparse");
			}
			selectInputOption(matrix1, numRows1, numCols1, matrix1, numRows2, numCols2);
			break;
		case 2:
			innputMatrixByHands(matrix1, numRows1, numCols1);
			if (!checkSparseMatrix(matrix1, numRows1, numCols1))
			{
				throw std::exception("The matrix №1 is not sparse");
			}
			selectInputOption(matrix1, numRows1, numCols1, matrix1, numRows2, numCols2);
			break;

		default:
			throw std::runtime_error("Invalid choice. Choose between 1, 2, and 3.\n");
		}
	}
	catch (std::exception& is)
	{
		std::cerr << is.what();
	}
	cleanMemory(matrix1, numRows1);
	cleanMemory(matrix2, numRows2);
	return 0;
}

