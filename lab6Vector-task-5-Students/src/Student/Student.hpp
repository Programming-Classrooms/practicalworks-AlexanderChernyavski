#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>



struct Student
{
	std::string name;
	uint32_t course;
	uint32_t group;
	Student(std::string n, uint32_t c, uint32_t g) : name(n), course(c), group(g){};
	
};