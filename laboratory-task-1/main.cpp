/*
	Разработать консольное приложение для вычисления приближённого
	значения функции, используя представление ее в виде ряда Тейлора.
	Вычисления заканчивать, когда очередное слагаемое окажется по модулю
	меньше заданного числа 𝑒𝑝𝑠𝑖𝑙𝑜𝑛, где 0 < 𝑒𝑝𝑠𝑖𝑙𝑜𝑛 <= 10−𝑘
	, 𝑘 – натуральное
	число, 𝑘 > 1. Сравнить полученный результат со значением, вычисленным с
	помощью стандартных функций.Значение 𝑥 и 𝑘 ввести по запросу.
*/


#include <iostream>
#include <cmath>


void checkingEnteredX(int32_t x)
{
	if (x > 1 || x < -1)
	{
		throw std::exception("incorrect because  (x (-1; +1))");
	}
}

void checkingEnteredK(int32_t k)
{
	if (k <= 1)
	{
		throw std::exception("incorrect because k should be > 1");
	}
}

int main()
{
	try
	{
		long double eps, p, sum, x, k;
		int32_t n;
		
		std::cout << "input x (x (-1; +1))";
		std::cin >> x;
		checkingEnteredX(x);
		
		
		std::cout << "input k (k > 1)";
		std::cin >> k;
		checkingEnteredK(k);
		
		eps = pow(10, -k);
		p = x;
		sum = 0;
		n = 1;
		while (fabs(p) >= eps)
		{
			sum += p;
			p = ((p * x * x) * n) / (n + 2);
			n += 2;
		}
		
		std::cout << "arth=" << 0.5 * logf((1 + x) / (1 - x)) << '\n';
		return 0;	
	}
	catch (std::exception e)
	{
		std::cerr << e.what() << '\n';
		return 0;
	}
}

