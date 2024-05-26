#include "functions.hpp"

void addNumber(std::vector<int32_t> &vectorOfIntNum, int32_t value)
{
	vectorOfIntNum.push_back(value);
}

int32_t calculate(const std::vector<int32_t> &vectorOfIntNum)
{
	return vectorOfIntNum.size();
}

int32_t calculateSum(const std::vector<int32_t> &vectorOfIntNum)
{
	return std::accumulate(vectorOfIntNum.begin(), vectorOfIntNum.end(), 0);
}

void replaceZerosWithAverage(std::vector<int32_t> &vectorOfIntNum)
{
	int32_t sum = std::accumulate(vectorOfIntNum.begin(), vectorOfIntNum.end(), 0);
	int32_t length = vectorOfIntNum.size();
	int32_t average = sum / length;
	std::replace(vectorOfIntNum.begin(), vectorOfIntNum.end(), 0, average);
}

void replaceEvenNumbers(std::vector<int32_t> &vectorOfIntNum)
{
	int32_t diffMinMax = *std::max_element(vectorOfIntNum.begin(), vectorOfIntNum.end()) - *std::min_element(vectorOfIntNum.begin(), vectorOfIntNum.end());
	std::transform(vectorOfIntNum.begin(), vectorOfIntNum.end(), vectorOfIntNum.begin(), [diffMinMax](size_t i)
				   { return abs(i) % 2 == 0 ? diffMinMax : i; });
}

void addToInterval(std::vector<int32_t> &vectorOfIntNum, int32_t leftBord, int32_t rightBord)
{
	int32_t sum = std::accumulate(vectorOfIntNum.begin() + leftBord, vectorOfIntNum.end() + rightBord + 1, 0);
	std::transform(vectorOfIntNum.begin(), vectorOfIntNum.end(), vectorOfIntNum.begin(), [sum](int i)
				   { return i + sum; });
}

void removeDuplicates(std::vector<int32_t> &vectorOfIntNum)
{
	for (size_t i = 0; i < vectorOfIntNum.size(); ++i)
	{
		int32_t num = vectorOfIntNum[i];
		uint32_t absNum = std::abs(num);

		bool found = false;
		for (size_t j = 0; j < i; ++j)
		{
			if (std::abs(vectorOfIntNum[j]) == absNum)
			{
				found = true;
				break;
			}
		}

		if (found)
		{
			vectorOfIntNum.erase(vectorOfIntNum.begin() + i);
			--i;
		}
	}
}

size_t countGreaterThan(std::vector<int32_t> &vectorOfIntNum, int32_t naprimerN)
{
	return std::count_if(vectorOfIntNum.begin(), vectorOfIntNum.end(), [naprimerN](int32_t i)
						 { return i > naprimerN; });
}

size_t numberOfEqual(std::vector<int32_t> &vectorOfIntNum, int32_t naprimerN)
{
	return std::count_if(vectorOfIntNum.begin(), vectorOfIntNum.end(), [naprimerN](int32_t i)
						 { return i == naprimerN; });
}
