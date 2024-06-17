#include "studentsecondsessh.hpp"

StudentSecondSession::StudentSecondSession(std::string name, int32_t crs, int32_t grp, int32_t recnum, int32_t* marksF, int32_t* marksS) :
	StudentFirstSession(name, crs, grp, recnum, marksF),
	marksSecond(new int32_t[5])
{
	marksSecond = std::move(marksS);
}

StudentSecondSession::StudentSecondSession(const StudentSecondSession& rhs):
	StudentFirstSession(rhs.name, rhs.course, rhs.group, rhs.recordNumber, rhs.marksFirst),
	marksSecond(rhs.marksSecond)
{
	marksSecond = std::move(marksSecond);
}

StudentSecondSession::~StudentSecondSession()
{
	delete[] marksSecond;
}

double StudentSecondSession::GPAcalculation()
{
	int32_t sum1{0}, sum2{0};
	double GPA2{0};
	for (size_t i = 0; i < 4; i++)
	{
		sum1 += marksFirst[i];
	}
	for (size_t i = 0; i < 5; i++)
	{
		sum2 += marksSecond[i];
	}
	GPA2 = (sum1+sum2) * 1.0 / 9;
	return (sum1 + sum2) * 1.0 / 9;
}

void StudentSecondSession::display(std::ostream& out)
{
	StudentFirstSession::display(out);
	out << "Marks second session" << '\n';
	for (size_t i = 0; i < 5; i++)
	{
		out << marksSecond[i] << '\n';
	}
}

std::ostream& operator<<(std::ostream& out, StudentSecondSession& rhs)
{
	rhs.display(out);
	return out;
}
