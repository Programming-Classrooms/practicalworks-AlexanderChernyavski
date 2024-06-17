#include "src/Functions/functions.hpp"

int main()
{
	try {
		int32_t leftBord{ 0 },rightBord{0};
		int32_t maxRow{ 0 }, maxCol{ 0 };
		std::setlocale(LC_ALL, "Russian");
		std::cout << "Введите количество сторк и столбцов"; 
		std::cin >> maxRow >> maxCol;
		IsCorrectMTRX(maxRow,maxCol);
		
		std::vector<std::vector<int32_t>> mtrx(maxRow, std::vector<int32_t>(maxCol));
		RandomEnter(mtrx,maxRow,maxCol);

		 std::cout << "Иcходная матрица: " << '\n'; 
		PrintMatrix(mtrx, maxRow, maxCol);
		
		std::cout << "Матрица после удаления строк и столбцов: "<<'\n'; 
		DeleteRowColMTRX(mtrx,maxRow,maxCol);
		
		std::cout << "матрица после перестановок строк и столбцов: " << '\n'; 
		SwapRowColMTRX(mtrx,maxRow,maxCol);
		PrintMatrix(mtrx, maxRow, maxCol);
	}
	catch (const std::bad_array_new_length& e)
	{
		std::cerr << e.what();
	}
	return 0;
}