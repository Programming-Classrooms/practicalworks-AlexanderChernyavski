#define _CRT_SECURE_NO_WARNINGS
#include "Person.hpp"


Person::Person(char* Name) :fullName(new char[strlen(Name + 1)])
{
	if (fullName == nullptr)
	{
		throw std::invalid_argument("Please enter name");
	}
	strcpy(fullName, Name);
}

Person::~Person()
{
	delete[] fullName;
}

char* Person::getFullName()
{
	size_t size = sizeof(fullName);
	char* result = new char[size];
	strcpy(result, fullName);
	return result;
}

void Person::setFullName(char* rhs)
{
	strcpy(fullName, rhs);
}

void Person::display(std::ostream& out)
{
	out << "Name: " << fullName;
}


std::ostream& operator<<(std::ostream& out, const Person& rhs)
{
	out << rhs.fullName;
	return out;
}
