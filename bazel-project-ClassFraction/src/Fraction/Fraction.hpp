#ifndef FRACTION_HPP
#define FRACTION_HPP
#include <iostream>
#include <numeric>

class Fraction
{
public:
	Fraction(int32_t = 0 , uint32_t = 1);
	Fraction(const Fraction&);
	Fraction(Fraction&&) noexcept;

	~Fraction();

	int32_t getDiv() const;
	uint32_t getDen() const;

	friend std::ostream& operator<<(std::ostream&,  Fraction&);
	friend std::istream& operator>>(std::istream&,  Fraction&);

	Fraction operator+(const Fraction&);
	Fraction operator+(int32_t);
	friend Fraction operator+(int32_t, const Fraction&);

	Fraction operator++();
	Fraction& operator++(int32_t);

	Fraction operator-(const Fraction&);
	Fraction operator-(const int32_t);
	friend Fraction operator-(const int32_t, const Fraction&);
	Fraction operator-();
	Fraction& operator--();

	Fraction operator*(const int32_t);
	friend Fraction operator*(const int32_t, const Fraction&);
	Fraction operator*(const Fraction&);

	Fraction operator/(const Fraction&);
	Fraction operator/(const int32_t);
	friend Fraction operator/(const int32_t,  Fraction&);

	Fraction& operator=(const Fraction&);
	Fraction& operator+=(const Fraction&);
	Fraction& operator-=(const Fraction&);
	Fraction& operator*=(const Fraction&);
	Fraction& operator/=(const Fraction&);
	
	bool operator>(const Fraction&);
	bool operator<(const Fraction&);
	bool operator==(const Fraction&);
	Fraction operator!=(const Fraction&);

	double FractToDouble();
	Fraction reduction();

private:
	int32_t divider;
	uint32_t denominator;
};

#endif // !FRACTION_H
