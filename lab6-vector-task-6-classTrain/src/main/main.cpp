#include "../Train/Train.hpp"
#include "../Functions/functions.hpp"


int main()
{
	try {
		setlocale(LC_ALL, "Russian");
		std::string nameOfDestination, typeOfTrain, timeHH_MM;
		std::vector<Train> trains;
		size_t counter{ 0 };
		uint32_t hours{ 0 }, minutes{ 0 }, timeInWay{ 0 }, numberTrain{ 0 }, minTime{ 0 };
		std::ifstream fin("src/Info/Train.txt");
		checkFile(fin);
		while (fin >> numberTrain >> nameOfDestination >> typeOfTrain >> timeHH_MM >> timeInWay)
		{
			hours = splittingIntoWords(timeHH_MM, 1);
			minutes = splittingIntoWords(timeHH_MM, 2);
			if (typeOfTrain == "Passenger")
			{
				trains.push_back(Train(numberTrain, nameOfDestination, Type::Passenger, hours, minutes, timeInWay));
			}
			if (typeOfTrain == "Express")
			{
				trains.push_back(Train(numberTrain, nameOfDestination, Type::Express, hours, minutes, timeInWay));
			}
		}
		fin.close();

		std::sort(trains.begin(), trains.end(), sortTime);
		std::cout << "Поезда отсортированные по времени" << std::endl; 
		for (auto& train : trains)
		{
			train.display(std::cout);
		}

		int8_t startTimeH{ 9 }, startTimeM{ 34 }, endTimeH{ 20 }, endTimeM{ 40 };
		std::cout << "Поезда из заданного промежутка времени" << std::endl; 
		printTrainsInTimeRange(trains, startTimeH, endTimeH, startTimeM, endTimeM);
		std::cout << "Поезда направляющиеся в одно место" << std::endl; 
		nameOfDestination = "gorodOmsk";
		for (auto& train : trains)
		{
			if (train.getDestination() == nameOfDestination)
			{
				train.display(std::cout);
			}
		}
		
		std::cout << "Скорые поезда направляющиеся в одно место" << std::endl; 
		nameOfDestination = "gorodOmsk";
		for (auto& train : trains)
		{
			if (train.getDestination() == nameOfDestination && train.getType() == Type::Express)
			{
				train.display(std::cout);
			}
		}

		minTime = trains[0].getTime();
		size_t indexOfMinTrain{ 0 };
		std::cout << "самый быстрый поезд в заданный пункн назначения" << std::endl; 
		for (size_t i = 0; i < trains.size(); i++)
		{
			if (trains[i].getTime() < minTime && nameOfDestination == trains[i].getDestination())
			{
				indexOfMinTrain = i;
			}
		}
		trains[indexOfMinTrain].display(std::cout);
	}
	catch (std::invalid_argument& e)
	{
		std::cerr << e.what();
	}
	catch (std::runtime_error& e)
	{
		std::cerr << e.what();
	}
	return 0;
}
