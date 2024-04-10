#include "../Fraction/Fraction.hpp"

int main()
{
	try
	{
		Fraction a(1, 5), b(8, 19);
		double d;
		a = 5 / a;
		d = a.FractToDouble();
		std::cout << a;
	}


	catch (const std::invalid_argument& e)
	{
		std::cerr << e.what();
	}
	return 0;
}