#include <iostream>
#include <vector>
#include<ctime>
#include <iomanip>
#include <algorithm>

int32_t sumRow(const std::vector<int32_t>& row)
{
	int32_t sum{ 0 };
	for (const int32_t& elem : row)
	{
		sum += elem;
	}
	return sum;
}
void printMtrx(std::vector<std::vector<int32_t>> mtrx, size_t numRows, size_t numCols)
{
	for (size_t i = 0; i < numRows; i++)
	{
		for (size_t j = 0; j < numCols; j++)
		{
			std::cout << std::setw(3) << mtrx[i][j];
		}
		std::cout << std::endl;
	}
}

int main()
{
	try {
		int32_t N = 5; 
		int32_t M = 4;  
		int32_t maxElem{ 0 }, leftBord{ 0 },rightBord{0};
		size_t maxRow{ 0 }, maxCol{ 0 };
		std::setlocale(LC_ALL, "Russian");
		std::cout << "Введите количество сторк и столбцов"; 
		std::cin >> N >> M;
		if (N <= 0 || M <= 0)
		{
			throw std::bad_array_new_length();
		}
		std::cout << "Введите границы:"; 
		std::cin >> leftBord >> rightBord;
		std::vector<std::vector<int32_t>> mtrx(N, std::vector<int32_t>(M));
		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = 0; j < M; j++)
			{
				mtrx[i][j] = leftBord +rand() %(rightBord - leftBord);
			}
		}
		 std::cout << "Иcходная матрица: " << '\n'; 
		printMtrx(mtrx, N, M);
		maxElem = mtrx[0][0];
		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = 0; j < M; j++)
			{
				if (maxElem < mtrx[i][j])
				{
					maxElem = mtrx[i][j];
					maxRow = i;
					maxCol = j;
				}
			}
		}
		std::vector<std::vector<int32_t>> newMtrx(N - 1, std::vector<int32_t>(M - 1));
		int32_t p = 0;
		for (size_t i = 0; i < N; ++i) {
			if (i == maxRow) continue;
			int32_t q = 0;
			for (int32_t j = 0; j < M; ++j) {
				if (j == maxCol) continue;
				newMtrx[p][q] = mtrx[i][j];
				++q;
			}
			++p;
		}
		std::cout << "Матрица после удаления строк и столбцов: "<<'\n'; 
		printMtrx(newMtrx, N-1, M-1);
		for (size_t i = 0; i < N; i++)
		{
			for (size_t j = 0; j < N - 1; j++)
			{
				if (sumRow(mtrx[j]) > sumRow(mtrx[j + 1]))
				{
					std::swap(mtrx[j], mtrx[j + 1]);
				}
			}
		}
		std::cout << "матрица после перестановок строк и столбцов: " << '\n'; 
		printMtrx(mtrx, N, M);
	}
	catch (const std::bad_array_new_length& e)
	{
		std::cerr << e.what();
	}
	return 0;
}