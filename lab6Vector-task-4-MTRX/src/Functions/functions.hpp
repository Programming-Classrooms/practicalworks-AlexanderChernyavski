#include <iostream>
#include <vector>
#include<ctime>
#include <iomanip>
#include <algorithm>


int32_t sumRow(const std::vector<int32_t>& row) noexcept; 

void PrintMatrix(std::vector<std::vector<int32_t>> mtrx, size_t numRows, size_t numCols) noexcept;
void RandomEnter(std::vector<std::vector<int32_t>> &mtrx, size_t numRows, size_t numCols) noexcept;//заполнение случайными числами
void IsCorrectMTRX(int32_t numRows, int32_t numCols);// проверка на то чтобы строки и столбцы были натуральными числами и тем самым создалась корректная матрица
void DeleteRowColMTRX(std::vector<std::vector<int32_t>> mtrx, size_t numRows, size_t numCols) noexcept;
void SwapRowColMTRX(std::vector<std::vector<int32_t>> &mtrx, size_t numRows, size_t numCols) noexcept;