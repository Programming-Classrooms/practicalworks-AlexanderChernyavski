#ifndef STUDENTFIRSTSESSH_H
#define STUDENTFIRSTSESSH_H
#include "../Student/Student.hpp"
class StudentFirstSession:public Student
{
public:
	StudentFirstSession(std::string, int32_t, int32_t, int32_t, int32_t*);
	StudentFirstSession(const StudentFirstSession&);
	~StudentFirstSession();
	int32_t getMarksFirst(size_t i);
	void setMarksFirst(size_t i, int32_t mark);
	void display(std::ostream&) override;
	virtual double GPAcalculation();
protected:
	int32_t* marksFirst;
};


#endif // !STUDENTFIRSTSESS_H
