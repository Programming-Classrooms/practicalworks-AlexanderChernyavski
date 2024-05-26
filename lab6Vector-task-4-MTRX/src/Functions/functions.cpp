#include "functions.hpp"


void PrintMatrix(std::vector<std::vector<int32_t>> mtrx, size_t numRows, size_t numCols) noexcept
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
void RandomEnter(std::vector<std::vector<int32_t>> &mtrx, size_t numRows, size_t numCols) noexcept
{
    int32_t leftBord{ 0 },rightBord{0};
    std::cout << "Введите границы:"; 
		std::cin >> leftBord >> rightBord;
    for (size_t i = 0; i < numRows; i++)
		{
			for (size_t j = 0; j < numCols; j++)
			{
				mtrx[i][j] = leftBord +rand() %(rightBord - leftBord);
			}
		}
}

void IsCorrectMTRX(int32_t numRows, int32_t numCols)
{
    if (numRows <= 0 || numCols <= 0)
		{
			throw std::bad_array_new_length();
		}
}

void DeleteRowColMTRX(std::vector<std::vector<int32_t>> mtrx, size_t numRows, size_t numCols) noexcept
{
    size_t maxElem{0},maxElemR{0},maxElemC{0};
    maxElem = mtrx[0][0];
		for (size_t i = 0; i < numRows; i++)
		{
			for (size_t j = 0; j < numCols; j++)
			{
				if (maxElem < mtrx[i][j])
				{
					maxElem = mtrx[i][j];
					maxElemR = i;
					maxElemC = j;
				}
			}
		}
		std::vector<std::vector<int32_t>> newMtrx(numRows - 1, std::vector<int32_t>(numCols - 1));
		int32_t p = 0;
		for (size_t i = 0; i < numRows; ++i) {
			if (i == maxElemR) continue;
			int32_t q = 0;
			for (int32_t j = 0; j < numCols; ++j) {
				if (j == maxElemC) continue;
				newMtrx[p][q] = mtrx[i][j];
				++q;
			}
			++p;
		}
        PrintMatrix(newMtrx, numRows-1, numCols-1);
}
int32_t sumRow(const std::vector<int32_t>& row) noexcept
{
	int32_t sum{ 0 };
	for (const auto& elem : row)
	{
		sum += elem;
	}
	return sum;
}
void SwapRowColMTRX(std::vector<std::vector<int32_t>> &mtrx, size_t numRows, size_t numCols) noexcept
{
    for (size_t i = 0; i < numCols; i++)
		{
			for (size_t j = 0; j < numRows - 1; j++)
			{
				if (sumRow(mtrx[j]) > sumRow(mtrx[j + 1]))
				{
					std::swap(mtrx[j], mtrx[j + 1]);
				}
			}
		}
}
