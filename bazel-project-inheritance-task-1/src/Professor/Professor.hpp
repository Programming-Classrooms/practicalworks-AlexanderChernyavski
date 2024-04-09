#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP
#include "../Person/Person.hpp"


class Professor:public Person
{
public:
	Professor(char* = nullptr, char* = nullptr);
	~Professor();

	char* getDepartment();

	void setDepartment(char*);

	friend std::ostream& operator<<(std::ostream&, const Professor&);
	void display(std::ostream&) override;
private:
	char* department;
};


#endif // !PROFESSOR_H
