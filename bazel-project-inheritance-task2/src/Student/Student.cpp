#include "Student.hpp"

bool checkName(std::string Name)
{
	size_t 	length = size(Name);
	if (!isupper(Name[0]))
	{
		return false;
	}
	for (size_t i = 0; i < length; i++)
	{
		if (!isalpha(Name[i]))
		{
			return false;
		}
		return true;
	}
}

Student::Student(std::string Name, int32_t cors, int32_t grop, int32_t recNumb) :
	ID(std::rand() % 90000000 + 10000000),
	name(Name),
	course(cors),
	group(grop),
	recordNumber(recNumb)
{
	if (!checkName(name))
	{
		throw std::runtime_error("The name is made up of letters and starts with a capital letter!");
	}

	if (course > 6 || course <= 0)
	{
		throw std::invalid_argument("course mus be natural and 5<=");
	}
	if (group <= 0)
	{
		throw std::invalid_argument("group mush be natural");
	}
	if (recordNumber <= 0)
	{
		throw std::invalid_argument("recordnumberr mush be natural");
	}
}

Student::Student(const Student& rhs) :
	ID(rhs.ID),
	name(rhs.name),
	course(rhs.course),
	group(rhs.group),
	recordNumber(rhs.recordNumber)
{
}

Student::~Student()
{
}

const int32_t Student::getID()
{
	return ID;
}

std::string Student::getName()
{
	return name;
}

int32_t Student::getCourse()
{
	return course;
}

int32_t Student::getGroup()
{
	return group;
}

const int32_t Student::getrecordNum()
{
	return recordNumber;
}

void Student::display(std::ostream& out)
{
	out << "ID: " << ID << " Name: " << name << " Record number: " << recordNumber << " Group: " << group << " Course: " << course << '\n';
}

bool Student::equal(int32_t ID)
{
	if (this->ID == ID)
	{
		return true;
	}
	return false;
}

bool Student::equalGroup(int32_t group)
{
	if (this->group == group)
	{
		return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& out, Student& rhs)
{
	rhs.display(out);
	return out;
}
