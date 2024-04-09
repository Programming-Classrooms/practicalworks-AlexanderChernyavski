#define _CRT_SECURE_NO_WARNINGS
#include "Professor.hpp"

Professor::Professor(char *fullName, char *depart) : Person(fullName),
													 department(new char[strlen(depart + 1)])
{
	if (department == nullptr)
	{
		throw std::invalid_argument("Please enter department");
	}
	strcpy(department, depart);
}

Professor::~Professor()
{
	delete[] department;
}

char *Professor::getDepartment()
{
	char *result = nullptr;
	strcpy(result, department);
	return result;
}

void Professor::setDepartment(char *rhs)
{
	strcpy(department, rhs);
}

void Professor::display(std::ostream &out)
{
	Person::display(out);
	out << " Department: " << department << '\n';
}

std::ostream &operator<<(std::ostream &out, const Professor &rhs)
{
	out << "Name: " << rhs.fullName << " Department: " << rhs.department;
	return out;
}
