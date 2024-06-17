#include "functions.hpp"


bool checkFile(std::ifstream &file)
{
	if (!file.good())
	{
		throw std::invalid_argument("File not found ! ");
	}

	if (!file)
	{
		throw std::ios_base::failure("Error reading file!");
	}

	if (file.peek() == EOF)
	{
		throw std::runtime_error("File is empty!");
	}

	return true;
}

bool sortTime(Train &a, Train &b) noexcept
{
    if (a.getHour() < b.getHour())
    {
        return true;
    }
    else if (a.getHour() == b.getHour())
    {
        return a.getMinures() < b.getMinures();
    }
    else
    {
        return false;
    }
}


int32_t splittingIntoWords(std::string inputString, int32_t i) noexcept
{
	std::string delims = { ':' };
	int32_t HH_MM{ 0 };
	size_t counter{ 0 };
	std::string word;
	std::string::size_type begInd;
	uint32_t len = inputString.size();
	begInd = inputString.find_first_not_of(delims);
	while (begInd != std::string::npos)
	{
		std::string::size_type endInd;
		endInd = inputString.find_first_of(delims, begInd);
		if (endInd == std::string::npos)
		{
			endInd = inputString.length();
		}
		word = inputString.substr(begInd, endInd - begInd);
		switch (i)
		{
		case 1:
			if (counter == 0)
			{
				HH_MM = std::stoi(word);
			}
			if (counter == 1)
			{
				break;
			}
			break;
		case 2:
			if (counter == 0)
			{
				break;
			}
			if (counter == 1)
			{
				HH_MM = std::stoi(word);

			}
			break;
		default:
			break;
		}
		++counter;
		begInd = inputString.find_first_not_of(delims, endInd);
	}
	return HH_MM;
}

void printTrainsInTimeRange(std::vector<Train>& trains, int32_t start_timeH, int32_t end_timeH, int32_t start_timeM, int32_t end_timeM) noexcept
{
    for (auto& train : trains) {
        if (train.getHour() > start_timeH && train.getHour() < end_timeH) {
            train.display(std::cout);
        }
        else if (train.getHour() == start_timeH && train.getMinures() >= start_timeM) {
            train.display(std::cout);
        }
        else if (train.getHour() == end_timeH && train.getMinures() <= end_timeM) {
            train.display(std::cout);
        }
    }
}
