#define _CRT_SECURE_NO_WARNINGS
#include "../Person/Person.hpp"
#include "../Student/Student.hpp"
#include "../Professor/Professor.hpp"

int main()
{
	try
	{
		std::vector<Person *> persons;
		Student *students = nullptr;
		Professor *professors = nullptr;
		int32_t group = 0, course = 0;
		char choice = '0';
		size_t counter = 0;

		while (true)
		{
			std::cout << "1. Enter a student\n2. Enter a teacher\n3. Display a list of students\n4. Display a list of teachers\n5. Finish\n";
			std::cin >> choice;
			switch (choice)
			{
			case '1':
				char namest[100];
				std::cout << "Enter name:";
				std::cin >> namest;
				std::cout << "Enter course: ";
				std::cin >> course;
				std::cout << "Enter group: ";
				std::cin >> group;
				persons.push_back(new Student(namest, course, group));

				++counter;
				break;

			case '2':
				char nameP[100];
				char depatment[100];
				std::cout << "Enter name: ";
				std::cin >> nameP;
				std::cout << "Enter department: ";
				std::cin >> depatment;
				persons.push_back(new Professor(nameP, depatment));
				++counter;
				break;

			case '3':
				for (size_t i = 0; i < counter; i++)
				{
					students = dynamic_cast<Student *>(persons[i]);
					if (students)
					{
						persons[i]->display(std::cout);
					}
				}
				break;

			case '4':
				for (size_t i = 0; i < counter; i++)
				{
					professors = dynamic_cast<Professor *>(persons[i]);
					if (professors)
					{
						persons[i]->display(std::cout);
					}
				}
				break;
			case '5':
				return 0;
				break;

			default:
				throw std::runtime_error("Please write 1, 2, 3, 4 or 5");
				break;
			}
		}
	}

	catch (const std::invalid_argument &e)
	{
		std::cerr << e.what();
	}
	return 0;
}