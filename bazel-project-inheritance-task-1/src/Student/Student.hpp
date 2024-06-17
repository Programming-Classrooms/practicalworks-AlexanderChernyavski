#ifndef STUDENT_HPP
#define STUDENT_HPP
#include "../Person/Person.hpp"


class Student :public Person
{
public:
	Student(char* = nullptr, int32_t = 0, int32_t = 0);
	~Student();

	int32_t getGroup();
	int32_t getCourse();

	void setCourse(int32_t);
	void setGroup(int32_t);

	friend std::ostream& operator<<(std::ostream&, const Student&);
	void display(std::ostream&) override;
private:
	int32_t group;
	int32_t course;
};


#endif // !STUDENT_H
