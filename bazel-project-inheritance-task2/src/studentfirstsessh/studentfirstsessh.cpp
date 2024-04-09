#include "studentfirstsessh.hpp"


StudentFirstSession::StudentFirstSession(std::string name, int32_t grop, int32_t crs, int32_t recnum, int32_t*marksF):
	Student(name,grop,crs,recnum),
	marksFirst(new int32_t[4])
{
	for (size_t i = 0; i < 4; i++)
	{
		if (marksFirst[i] < 0 || marksFirst[i] >10)
		{
			throw std::invalid_argument("mark cannot be >10 || 0<");
		}
	}
	marksFirst = std::move(marksF);
}

StudentFirstSession::StudentFirstSession(const StudentFirstSession& rhs):
	Student(rhs.name, rhs.group, rhs.course, rhs.recordNumber),
	marksFirst(rhs.marksFirst)
{
	marksFirst = std::move(rhs.marksFirst);
}

StudentFirstSession::~StudentFirstSession()
{
	delete[] marksFirst;
}

int32_t StudentFirstSession::getMarksFirst(size_t i)
{
	return marksFirst[i];
}

void StudentFirstSession::setMarksFirst(size_t i, int32_t mark)
{
	this->marksFirst[i] = mark;
}

void StudentFirstSession::display(std::ostream& out)
{
	Student::display(out);
	out << "Marks" << '\n';
	for (size_t i = 0; i < 4; i++)
	{
		out << marksFirst[i]<<'\n';
	}
}

double StudentFirstSession::GPAcalculation()
{
	int32_t sum = 0;
	double GPA = 0;
	for (size_t i = 0; i < 4 ; i++)
	{
		sum += marksFirst[i];
	}
	GPA = sum*1.0 / 4;
	return sum * 1.0 / 4;
}
