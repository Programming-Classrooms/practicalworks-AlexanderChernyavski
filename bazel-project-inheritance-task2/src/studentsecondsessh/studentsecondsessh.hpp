#ifndef STUDENTSECONDSESSH_H
#define STUDENTSECONDSESSH_H
#include "../studentfirstsessh/studentfirstsessh.hpp"

class StudentSecondSession:public StudentFirstSession
{
public:
	StudentSecondSession(std::string, int32_t, int32_t, int32_t,int32_t*,int32_t*);
	StudentSecondSession(const StudentSecondSession&);
	virtual ~StudentSecondSession();
	double GPAcalculation() override;
	void display(std::ostream&) override;
	friend std::ostream& operator<<(std::ostream&, StudentSecondSession&);
private:
	int32_t* marksSecond;
};


#endif // !STUDENTSECONDSESSH_H
