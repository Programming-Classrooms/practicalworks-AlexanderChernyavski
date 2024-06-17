#include "src/Functions/functions.hpp"

int main()
{
	try
	{
		std::string name;
		std::vector<Student> students;
		uint32_t course{0}, group{0};

		std::ifstream fin("src/Files/Students.txt");
		std::ofstream fout1("src/Files/Fio.txt");
		std::ofstream fout2("src/Files/Groups.txt");

		checkFile(fin);
		while (fin >> name >> course >> group)
		{
			students.push_back(Student(name, course, group));
		}
		fin.close();

		std::sort(students.begin(), students.end(), [](const Student &a, const Student &b)
				  { return a.name < b.name; });
		for (const auto &student : students)
		{
			fout1 << "Name: " << student.name << std::endl;
		}
		fout1.close();

		std::sort(students.begin(), students.end(), compareCourse);
		for (const auto &student : students)
		{
			fout2 << "Course: " << student.course << " Group: " << student.group << std::endl;
		}
		fout2.close();

		std::cout << "data writen to files";
	}
	catch (std::invalid_argument &e)
	{
		std::cerr << e.what();
	}

	catch (std::runtime_error &e)
	{
		std::cerr << e.what();
	}

	catch (std::ios_base::failure &e)
	{
		std::cerr << e.what();
	}
	return 0;
}