#ifndef PERSON_HPP
#define PERSON_HPP
#include <iostream>
#include <vector>
#include <cstring>


class Person
{
public:
	Person(char* = nullptr);
	virtual ~Person();

	char* getFullName();
	void setFullName(char*);

	friend std::ostream& operator<<(std::ostream&, const Person&);
	virtual void display(std::ostream&);

protected:
	char* fullName;
};


#endif // PERSON_H
