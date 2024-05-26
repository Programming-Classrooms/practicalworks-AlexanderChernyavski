#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <iomanip>



int main()
{
	uint32_t choise1;
	std::vector<int32_t> vectorOfImtNum;

	uint8_t compCounter{ 0 };
	size_t counter{ 0 }, leftBord{ 0 }, rightBord{ 0 };
	int32_t value{ 0 }, sum{ 0 }, naprimerN{ 0 }, average{ 0 }, minElem{ 0 }, maxElem{ 0 }, diffMinMax{ 0 };
	while (true)
	{
		std::cout << "rwif";
		std::cin >> choise1;
		switch (choise1)
		{
		case 1:
			std::cout << "white number";
			std::cin >> value;
			vectorOfImtNum.push_back(value);
			break;
		case 2:
			return 0;
			break;
		case 3:
			sum = std::accumulate(vectorOfImtNum.begin(), vectorOfImtNum.end(), 0);
			std::cout << "kefkp" << sum;
			sum = 0;
			break;
		case 4:
			std::cout << "ejfrjf";
			counter = vectorOfImtNum.size();
			break;
		case 5:
			std::cout << "keofk";
			std::cin >> naprimerN;
			counter = std::count_if(vectorOfImtNum.begin(), vectorOfImtNum.end(), [naprimerN](int i) { return i > naprimerN; });
			std::cout << "jefjo    " << counter;
			counter = 0;
			break;
		case 6:
			for (int32_t& number : vectorOfImtNum)
			{
				sum += number;
				++counter;
			}
			average = sum / counter;
			std::replace(vectorOfImtNum.begin(), vectorOfImtNum.end(), 0, average);
			break;
		case 7:
			sum = std::accumulate(vectorOfImtNum.begin() + leftBord, vectorOfImtNum.end() + rightBord + 1, 0);
			std::transform(vectorOfImtNum.begin(), vectorOfImtNum.end(), vectorOfImtNum.begin(), [sum](int i) { return i + sum; });
			break;
		case 8:
			vectorOfImtNum[0] = minElem, maxElem;
			for (int32_t& number : vectorOfImtNum)
			{
				if (number < minElem)
				{
					number = minElem;
				}
				else if (number > maxElem)
				{
					number = maxElem;
				}
				diffMinMax = maxElem - minElem;
				for (int32_t& number : vectorOfImtNum)
				{
					if (number % 2 == 0)
					{
						number = diffMinMax;
					}
				}
				diffMinMax = *std::max_element(vectorOfImtNum.begin(), vectorOfImtNum.end()) - *std::min_element(vectorOfImtNum.begin(), vectorOfImtNum.end());
				std::transform(vectorOfImtNum.begin(), vectorOfImtNum.end(), vectorOfImtNum.begin(), [diffMinMax](int i) { return abs(i) % 2 == 0 ? diffMinMax : i; });
				break;
			}
		case 9:
			counter = 1;
			for (int32_t& number : vectorOfImtNum)
			{
				for (int32_t& element : vectorOfImtNum)
				{
					++counter;
					if (abs(number) == abs(element) && compCounter > 1)
					{
						auto it = std::find(vectorOfImtNum.begin() + counter, vectorOfImtNum.end(), element);
						vectorOfImtNum.erase(it);
					}
					else if (abs(number) == abs(element) && compCounter < 1)
					{
						++compCounter;
					}
				}
				counter = 1;
			}
			counter = 0;
			break;
		case 10:
			std::cout << "All elements: ";
			for (int32_t& number : vectorOfImtNum)
			{
				std::cout << number << "\t";
			}
			break;
		default:
			break;
		}

	}
	return 0;
}