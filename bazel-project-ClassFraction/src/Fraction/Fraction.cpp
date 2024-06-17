
#include "Fraction.hpp"

int32_t gcd(int a, int b) {
	while (b != 0) {
		int temp = a % b;
		a = b;
		b = temp;
	}
	return a;
}


Fraction::Fraction(int32_t div, uint32_t den) :divider(div), denominator(den)
{
	if (denominator == 0 || divider == 0)
	{
		throw std::invalid_argument("Denonimator must be  not equal to 0");
	}
}

Fraction::Fraction(const Fraction& init) :divider(init.divider), denominator(init.denominator)
{
}

Fraction::Fraction(Fraction&& rhs) noexcept : divider(0), denominator(1)
{
	this->divider = rhs.divider;
	this->denominator = rhs.denominator;

	rhs.divider = 0;
	rhs.denominator = 1;
}

Fraction::~Fraction()
{
}

int32_t Fraction::getDiv() const
{
	return divider;
}

uint32_t Fraction::getDen() const
{
	return denominator;
}

Fraction Fraction::operator+(const Fraction& Fract)
{
	return Fraction(divider * Fract.denominator + Fract.divider * denominator, denominator * Fract.denominator);
}

Fraction Fraction::operator-(const Fraction& Fract)
{
	return Fraction(divider * Fract.denominator - Fract.divider * denominator, denominator * Fract.denominator);
}

Fraction Fraction::operator-(const int32_t scalar)
{
	return Fraction(divider - scalar * denominator, denominator);
}

Fraction Fraction::operator-()
{
	return Fraction(-divider, denominator);
}

Fraction Fraction::operator*(const int32_t scalar)
{
	return Fraction(divider * scalar, denominator);
}

Fraction Fraction::operator*(const Fraction& Fract)
{
	return Fraction(divider * Fract.divider, denominator * Fract.denominator);
}

Fraction Fraction::operator/(const Fraction& Fract)
{
	return Fraction(divider * Fract.denominator, denominator * Fract.divider);
}

Fraction Fraction::operator/(const int32_t scalar)
{
	if ( scalar == 0)
	{
		throw std::invalid_argument("scalar must be  not equal to 0");
	}
	return Fraction(divider, denominator * scalar);
}

Fraction& Fraction::operator=(const Fraction& rhs)
{
	if (this != &rhs)
	{
		this->divider = rhs.divider;
		this->denominator = rhs.denominator;
	}
	return *this;
}

Fraction& Fraction::operator+=(const Fraction& rhs)
{
	this->divider = divider * rhs.denominator + rhs.divider * denominator;
	this->denominator = denominator * rhs.denominator;
	return *this;
}

Fraction& Fraction::operator-=(const Fraction& rhs)
{
	this->divider = divider * rhs.denominator - rhs.divider * denominator;
	this->denominator = denominator * rhs.denominator;
	return *this;
}

Fraction& Fraction::operator*=(const Fraction& rhs)
{
	this->divider = divider * rhs.divider;
	this->denominator = denominator * rhs.denominator;
	return *this;
}

Fraction& Fraction::operator/=(const Fraction& rhs)
{
	this->divider = divider * rhs.denominator;
	this->denominator = denominator * rhs.divider;
	return *this;
}

Fraction Fraction::operator+(int32_t scalar)
{
	return Fraction(divider + scalar * denominator, denominator);
}

Fraction operator+(int32_t scalar, const Fraction& rhs)
{
	return Fraction(rhs.divider + scalar * rhs.denominator, rhs.denominator);
}

Fraction operator-(const int32_t scalar, const Fraction& rhs)
{
	return Fraction(rhs.divider - scalar * rhs.denominator, rhs.denominator);
}

Fraction operator*(const int32_t scalar, const Fraction& rhs)
{
	return Fraction(rhs.divider * scalar, rhs.denominator);
}

Fraction operator/(const int32_t scalar, Fraction& rhs)
{
	return Fraction(scalar * rhs.denominator, rhs.divider);
}

Fraction& Fraction::operator++(int32_t)
{
	Fraction result{ *this };
	result.divider++;
	return *this;
	//return result;
}

Fraction Fraction::operator++()
{
	++this->divider;
	return *this;
}

Fraction& Fraction::operator--()
{
	--this->divider;
	return *this;
}


bool Fraction::operator>(const Fraction& Fract)
{
	return (this->divider * Fract.denominator > Fract.divider * denominator);
}

bool Fraction::operator<(const Fraction& Fract)
{
	return !(this->divider * Fract.denominator > Fract.divider * denominator);
}

bool Fraction::operator==(const Fraction& Fract)
{
	return (this->divider * Fract.denominator == Fract.divider * denominator);
}

Fraction Fraction::operator!=(const Fraction& Fract)
{
	return (this->divider = Fract.denominator, this->denominator = Fract.divider);
}

double Fraction::FractToDouble()
{
	return (static_cast<double>(divider) / denominator);
}

  Fraction Fraction::reduction()
{
	int32_t GCD = gcd(divider, denominator);
	if (GCD != 1)
	{
		this->divider = divider / GCD;
		this->denominator = denominator / GCD;
	}
	return *this;
}


std::ostream& operator<<(std::ostream& out,  Fraction& Fraction)
{
	Fraction.reduction();
	out << Fraction.divider << "/" <<Fraction.denominator;
	return out;
}

std::istream& operator>>(std::istream& in, Fraction& rhs)
{
	in >> rhs.divider >> rhs.denominator;
	return in;
}
