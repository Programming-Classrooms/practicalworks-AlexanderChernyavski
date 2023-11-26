#include<iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>
void main() {
	long double eps, p, s, x,k;
	int n;
	
	std::cout << "input x";
	std::cin >> x;
	if (x > 1 || x < -1) {
		std::cout << "incorrect";
	}
	else {
		std::cout << "k =\n";
		std::cin >> k;
		eps = pow(10, -k);
		if (eps < 0 || eps > 1)
		{
			std::cout << "incorrect";
		}
		p = x;
		s = 0;
		n = 1;
		while (fabs(p) >= eps) {
			s += p;
			p = ((p * x * x)* n) / (n + 2);
			++++n;
			
		
		}
			std::cout << "arth=" << 0.5*logf((1 + x) /( 1 - x)) << '\n';
		
		printf("%.100Lf", s);
	}
	
}
