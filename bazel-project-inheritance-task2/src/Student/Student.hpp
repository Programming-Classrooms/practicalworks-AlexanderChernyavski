#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include <ctime>
#include <vector>


class Student
{
public:
	Student(std::string, int32_t, int32_t, int32_t);
	Student(const Student&);
	virtual ~Student();

	const int32_t getID();
	std::string getName();
	int32_t getCourse();
	int32_t getGroup();
	const int32_t getrecordNum();

	friend std::ostream& operator<<(std::ostream&, Student&);
	virtual void display(std::ostream&);

	bool equal(int32_t);
	bool equalGroup(int32_t);
protected:
	const int32_t ID;
	std::string name;
	int32_t course;
	int32_t group;
	const int32_t recordNumber;
};

#endif // !STUDENT_H

