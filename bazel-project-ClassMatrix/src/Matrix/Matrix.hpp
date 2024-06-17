#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <iostream>
#include <iomanip>
#include <ctime>


class Matrix
{
public:
	Matrix(int32_t = 0);
	Matrix(const Matrix&);

	~Matrix();

	int32_t getSize() const;
	friend std::ostream& operator<<(std::ostream&, const Matrix&);

	Matrix& operator=(const Matrix&);
	Matrix& operator+=(const Matrix&);
	Matrix& operator-=(const Matrix&);
	Matrix& operator*=(const Matrix&);

	double* operator[](const size_t index);

	Matrix operator+(const Matrix&);
	Matrix operator-(const Matrix&);
	Matrix operator*(const Matrix&);

	Matrix operator*(const int32_t);
	Matrix operator/(const int32_t);

	bool operator>(const Matrix&) const;
	bool operator<(const Matrix&) const;
	bool operator==(const Matrix&) const;
	bool operator!=(const Matrix&) const;

	friend Matrix operator*(const Matrix&, const int32_t);

private:
	int32_t size;
	double** mtrx;
	size_t tempSize;
	void fillMtrxByHands();
	void fillMtrxByRandom();
};

#endif // !MATRIX_H
