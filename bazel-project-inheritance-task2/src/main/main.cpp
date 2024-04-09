#include "../Student/Student.hpp"
#include "../studentfirstsessh/studentfirstsessh.hpp"
#include "../studentsecondsessh/studentsecondsessh.hpp"


template<typename T>
double countGPAInGroup(std::vector<Student*> students, int32_t groupToCalcGPA, T* studentf, size_t counter)
{
	int32_t total{ 0 };
	size_t countPeopleInGroup{ 0 };
	for (size_t i = 0; i < counter; i++)
	{
		if (students[i]->equalGroup(groupToCalcGPA))
		{
			total += studentf->GPAcalculation();
			++countPeopleInGroup;
		}
	}
	return total * 1.0 / countPeopleInGroup;
}


int main()
{
	try {
		srand(time(NULL));
		std::string namest;
		std::vector<Student*> students;
		StudentFirstSession* studentf = nullptr;
		StudentSecondSession* studentS = nullptr;
		int32_t group{ 0 }, course{ 0 }, recnum{ 0 };
		char choice , choise2, choise3;
		size_t counter = 0;
		int32_t marksF[4]{}, marksS[5]{};
		size_t countPeopleInGroup1{ 0 };
		size_t countPeopleInGroup2{ 0 };
		int32_t groupToCalcGPA{ 0 };
		double GPA1{ 0 }, GPA2{ 0 };
		int32_t total{ 0 }, total2{ 0 };

		while (true) {
			std::cout << "1. Enter a student\n2. Display a list of students\n3.Calculating GPA\n4.Calculate group GPA\n5.Finish\n";
			std::cin >> choice;
			switch (choice)
			{
			case '1':
				std::cout << "Enter name:";
				std::cin >> namest;
				std::cout << "Enter course: ";
				std::cin >> course;
				std::cout << "Enter group: ";
				std::cin >> group;
				std::cout << "Enter recordnumber";
				std::cin >> recnum;
				std::cout << "Enter marks firsr session";
				for (size_t i = 0; i < 4; i++)
				{
					std::cout << "Enter mark" << i << '\n';
					std::cin >> marksF[i];
				}

				std::cout << "Did the student pass the 2nd session? 1-Yes/ 2-No";
				std::cin >> choise2;
				switch (choise2)
				{
				case '1':
					std::cout << "Enter marks second session";
					for (size_t i = 0; i < 5; i++)
					{
						std::cout << "Enter mark" << i << '\n';
						std::cin >> marksS[i];
					}
					students.push_back(new StudentSecondSession(namest, course, group, recnum, marksF, marksS));
					break;
				case'2':
					students.push_back(new StudentFirstSession(namest, course, group, recnum, marksF));
					break;
				default:
					throw std::runtime_error("invalid choise!");
					break;
				}
				++counter;
				break;

			case '2':
				for (size_t i = 0; i < counter; i++)
				{
					students[i]->display(std::cout);
				}
				break;
			case'3':
				int32_t ID;
				std::cout << "Enter student ID: ";
				std::cin >> ID;
				for (size_t i = 0; i < counter; ++i)
				{
					if (students[i]->equal(ID))
					{
						std::cin >> choise3;
						switch (choise3)
						{
						case'1':
							studentf = dynamic_cast<StudentFirstSession*>(students[i]);
							std::cout << "GPA of student 1 session" << studentf->GPAcalculation();
							break;

						case'2':
							studentS = dynamic_cast<StudentSecondSession*>(students[i]);
							if (studentS)
							{
								std::cout << "GPA of student 1, 2 session" << studentS->GPAcalculation();
							}
							break;

						default:
							throw std::runtime_error("invalid choise!");
							break;
						}

					}

				}

				break;
			case'4':
				std::cout << "1-calculate the average score for 1 session / 2-calculate the score for 2 sessions";
				std::cin >> choise3;
				switch (choise3)
				{
				case '1':
					GPA1 = countGPAInGroup(students, groupToCalcGPA, studentf, counter);

					std::cout << "Average score for 1 session for the selected group" << GPA1;
					break;
				case '2':

					if (GPA1 == 0)
					{
						GPA1 = countGPAInGroup(students, groupToCalcGPA, studentf, counter);
					}

					GPA2 = countGPAInGroup(students, groupToCalcGPA, studentS, counter);
					std::cout << "Average score for 1, 2 session for the selected group" << (GPA1 + GPA2) / 2;
					break;
				default:
					throw std::runtime_error("invalid choise!");
					break;
				}
				break;
			case'5':
				return 0;
				break;

			default:
				throw std::runtime_error("Please enter 1, 2, 3, 4 or 5");
				break;
			}
		}
	}

	catch (const std::invalid_argument& e)
	{
		std::cerr << e.what();
	}
	catch (const std::runtime_error& e)
	{
		std::cerr << e.what();
	}
	return 0;
};