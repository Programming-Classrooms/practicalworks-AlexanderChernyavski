#ifndef TRAIN_HPP
#define TRAIN_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>

enum class Type
{
	Passenger,
	Express,
	other
}; 


class Train
{
public:
    Train() = default;
	Train(int32_t, std::string, Type type, int32_t, int32_t, int32_t);
	~Train() = default;

	void display(std::ostream&);//вывод в консоль

	int32_t getHour() const;//геттер часа
	int32_t getMinures() const;// геттер минут
	std::string getDestination() const; // геттер пункта прибытия
	Type getType() const; //геттер типа поезда
	int32_t getTime() const; //геттер времени в пути

private:
	int32_t numberTrain;
	std::string nameOfDestination;
	Type type = Type::other;
	int32_t hours;
	int32_t minutes;
	int32_t timeInWay;
};


#endif // !TRAIN_H