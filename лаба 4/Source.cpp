#include <iostream>
#include <iomanip>
#include <ctime>
#include <array>

bool Gettype() {
	__int32 choise = 0;
	std::cout << "If you want the array to be filled with random elements, enter (0),"
		<< "if you want you to enter it yourself, enter (1) " << '\n';
	std::cin >> choise;
	if (choise < 0 || choise>1)
	{
		throw std::exception("Write 0 or 1!!"); //надо изме5нить комментарий
	}
	switch (choise)
	{
	case 0: return true; break;
	case 1: return false; break;
	}
}


void CheckNullElements(__int32** array, size_t rows, size_t colums, size_t numberOfNullElrmentsColum)
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


void CheckNuberOfNUllElements(__int32** array, size_t rows, size_t colums, size_t numberOfNullElrments)
{
	size_t NumberOfNUllEments = 0;
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


void SwapRows(__int32** array, size_t rows, size_t colums)
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


int64_t ProductOfElementsLyingBelowTheMainDiagonal(__int32** array, size_t rows, size_t colums)
{
	__int32 Product = 1;
	for (size_t i = 1; i  < rows; i++)
	{
		for (size_t j = 0; j < i; j++)
		{
			Product *= array[i][j];
		}
	}
	return Product ;
	std::cout << "Product Of Elements Lying Below The MainD iagonal:"<<" " << Product;
}


void OutPutArray(__int32** array, size_t rows, size_t colums)
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


void Check(size_t rows)
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
	Check(rows);

	colums = rows;
	__int32** array = new int* [rows];
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < colums; j++)
		{
			array[i] = new int[colums];
		}
	}
	try {

		try {

			if (Gettype()) {
				srand(time(NULL));
				for (size_t i = 0; i < rows; i++)
				{
					for (size_t j = 0; j < colums; j++)
					{
						array[i][j] = rand() % 20;
					}
				}
				std::cout << '\n' << "Main matrix" << '\n';
				OutPutArray(array, rows, colums);
			}
			else
			{
				for (size_t i = 0; i < rows; i++)
				{
					for (size_t j = 0; j < colums; j++)
					{
						std::cout << "Write element" << " " << "a" << '[' << i << ']' << " " << '[' << j << ']' << ':' << " ";
						std::cin >> array[i][j];
					}
				}
				std::cout << '\n' << "Main matrix" << '\n';
				OutPutArray(array, rows, colums);
				for (size_t j = 0; j < rows; ++j)
				{
					for (size_t i = 0; i < rows; ++i)
					{
						if (array[i][j] == 0)
						{
							numberOfNullElrmentsColum++;
							if (numberOfNullElrmentsColum != 1) {
								std::cout << "only 1 null element per colum";
								throw std::string("only 1 null element per colum");
							}
						}

						if (i == colums - 1) {
							numberOfNullElrmentsColum = 0;
						}
					}
				}
				try
				{
					CheckNullElements(array, rows, colums, numberOfNullElrments);
					try {
						CheckNuberOfNUllElements(array, rows, colums, numberOfNullElrments);
						std::cout << "Product Of Elements Lying Below The MainD iagonal:" <<
							ProductOfElementsLyingBelowTheMainDiagonal(array, rows, colums);
						std::cout << '\n' << "Transformed matrix" << '\n';
						SwapRows(array, rows, colums);
						OutPutArray(array, rows, colums);
						std::cout << "Product Of Elements Lying Below The MainD iagonal:" <<
							ProductOfElementsLyingBelowTheMainDiagonal(array, rows, colums);
					}
					catch (const std::exception& errormessage)
					{
						std::cout << errormessage.what();
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
				std::cout << error.what();
			}
			throw std::string();
		}
	
catch (const std::string& isa)
{
	delete[] array;
}
	catch (const std::exception& is)
	{
		std::cout << is.what();
	}
	catch (const std::string ErrorMessage )
	{
		std::cout << ErrorMessage;
	}
	return 0;
}