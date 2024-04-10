#include "../Matrix/Matrix.hpp"

int main()
{
	try {
		Matrix a(3);
		Matrix d(3);
		a * 3;
		std::cout << d - a;
	}
	catch (std::bad_array_new_length& e)
	{
		std::cerr << e.what();
	}
	catch (std::runtime_error& e)
	{
		std::cerr << e.what();
	}
	return 0;
}