#include "Student.hpp"

Student::Student(char *fullName, int32_t grp, int32_t crs) : Person(fullName),
															 group(grp),
															 course(crs)
{
	if (course <= 0)
	{
		throw std::invalid_argument("Course!!!");
	}
	if (group <= 0)
	{
		throw std::invalid_argument("Group must be natural");
	}
}

Student::~Student()
{
}

int32_t Student::getGroup()
{
	return group;
}

int32_t Student::getCourse()
{
	return course;
}

void Student::setCourse(int32_t course)
{
	this->course = course;
}

void Student::setGroup(int32_t group)
{
	this->group = group;
}

void Student::display(std::ostream &out)
{
	Person::display(out);
	out << " Course: " << course << " Group: " << group << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Student &rhs)
{
	out << *((Person *)&rhs);
	out << " Course: " << rhs.course << " Group: " << rhs.group;
	return out;
}
