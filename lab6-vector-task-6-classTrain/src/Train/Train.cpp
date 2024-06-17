#include "Train.hpp"

Train::Train(int32_t number, std::string name, Type type_, int32_t h, int32_t m, int32_t time) :
	numberTrain(number),
	nameOfDestination(name),
	type(type_),
	hours(h),
	minutes(m),
	timeInWay(time)
{
	if (numberTrain <= 0 || hours < 0 || minutes < 0 || time <= 0)
	{
		throw std::invalid_argument("must be natural!");
	}
}

void Train::display(std::ostream& out)
{
	out << "Number of train: " << numberTrain << " Name of destination: " << nameOfDestination;
	switch (type)
	{
	case Type::Passenger:
		out << " Type of train: Passenger";
		break;
	case Type::Express:
		out << " Type of train: Express";
		break;
	default:
		break;
	}
	//Вот это всё что ниже для коррекного выода времени которое задано в формате напр. 09:45, 03:08
	if (hours >= 0 && hours <= 9)
	{
		if (minutes >= 0 && minutes <= 9)
		{
			out << " time: 0" << hours << ":0" << minutes << " time in the way: " << timeInWay << std::endl;
		}
		else
		{
			out << " time: 0" << hours << ':' << minutes << " time in the way: " << timeInWay << std::endl;
		}
	}
	else if (minutes >= 0 && minutes <= 9)
	{
		out << " time: " << hours << ":0" << minutes << " time in the way: " << timeInWay << std::endl;
	}
	else
	{
		out << " time: " << hours << ':' << minutes << " time in the way: " << timeInWay << std::endl;
	}

}

int32_t Train::getHour() const
{
	return hours;
}

int32_t Train::getMinures() const 
{
	return minutes;
}

std::string Train::getDestination() const
{
	return nameOfDestination;
}

Type Train::getType() const
{
	return type;
}

int32_t Train::getTime() const
{
	return timeInWay;
}
