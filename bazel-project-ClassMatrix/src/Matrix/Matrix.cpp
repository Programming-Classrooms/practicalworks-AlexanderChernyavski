#include "Matrix.hpp"


Matrix::Matrix(int32_t size) :size(size), mtrx(new double* [size])
{
	char choise;
	if (size <= 0)
	{
		throw std::bad_array_new_length();
	}

	for (size_t i = 0; i < size; ++i)
	{
		mtrx[i] = new double[size];
	}
	std::cout << "If u want to fill mtrx wiht rand elements enter 1 / by hands 2";
	std::cin >> choise;
	switch (choise)
	{
	case '1':
	{
		fillMtrxByRandom();
		break;
	}
	case '2':
	{
		fillMtrxByHands();
		break;
	}
	default:
		throw std::runtime_error("Enter 1 or 2!");
		break;
	}

}

Matrix::Matrix(const Matrix& rhs):size(rhs.size), mtrx(new double* [size])
{
	for (size_t i = 0; i < size; ++i)
	{
		for (size_t j = 0; j < size; ++j)
		{
			mtrx[i][j] = rhs.mtrx[i][j];
		}
	}
}

int32_t Matrix::getSize() const
{
	return size;
}

Matrix::~Matrix()
{
	for (int32_t i = 0; i < size; ++i)
	{
		delete[] mtrx[i];
	}
	delete[] mtrx;
}

Matrix& Matrix::operator=(const Matrix& rhs)
{
	if (this != &rhs)
	{
		for (uint32_t i = 0; i < size; ++i)
		{
			delete[] mtrx[i];
		}
		delete[] mtrx;


		this->size = rhs.size;
		mtrx = new double* [size];
		for (size_t i = 0; i < rhs.size; ++i)
		{
			mtrx[i] = new double[size];
			for (size_t j = 0; j < rhs.size; ++j)
			{
				this->mtrx[i][j] = rhs.mtrx[i][j];
			}
			std::cout << std::endl;
		}
	}
	return *this;
}

Matrix& Matrix::operator+=(const Matrix& rhs)
{
	for (size_t i = 0; i < size; ++i)
	{
		for (size_t j = 0; j < size; ++j)
		{
			mtrx[i][j] += rhs.mtrx[i][j];
		}
	}
	return *this;
}

Matrix& Matrix::operator-=(const Matrix& rhs)
{
	for (size_t i = 0; i < size; ++i)
	{
		for (size_t j = 0; j < size; ++j)
		{
			mtrx[i][j] -= rhs.mtrx[i][j];
		}
	}
	return *this;
}

Matrix& Matrix::operator*=(const Matrix& rhs)
{
	for (size_t i = 0; i < size; ++i)
	{
		for (size_t j = 0; j < size; ++j)
		{
			mtrx[i][j] = 0;
			for (size_t k = 0; k < size; k++)
			{
				mtrx[i][j] += mtrx[i][k] * rhs.mtrx[k][j];
			}
		}
	}
}

double* Matrix::operator[](const size_t index)
{
	if (index < 0 || index >= size) {
		throw std::out_of_range("bad index\n");
	}
	return mtrx[index];
}

Matrix Matrix::operator+(const Matrix& rhs)
{
	if (size != rhs.size)
	{
		throw std::runtime_error("impossible");
	}
	Matrix result = *this;
	for (size_t i = 0; i < size; ++i)
	{
		for (size_t j = 0; j < size; ++j)
		{
			result.mtrx[i][j] += rhs.mtrx[i][j];
		}
	}
	return result;
}

Matrix Matrix::operator-(const Matrix& rhs)
{
	Matrix result(size);
	for (size_t i = 0; i < size; ++i)
	{
		for (size_t j = 0; j < size; ++j)
		{
			result.mtrx[i][j] = mtrx[i][j] - rhs.mtrx[i][j];
		}
	}
	return result;
}

Matrix Matrix::operator*(const int32_t scalar)
{
	Matrix result = *this;
	for (size_t i = 0; i < size; ++i)
	{
		for (size_t j = 0; j < size; ++j)
		{
			result.mtrx[i][j] *= scalar;
		}
	}
	return result;
}

Matrix Matrix::operator*(const Matrix& rhs)
{
	Matrix result = *this;
	for (size_t i = 0; i < size; ++i)
	{
		for (size_t j = 0; j < size; ++j)
		{
			result[i][j] = 0;
			for (size_t k = 0; k < size; k++)
			{
				result[i][j] += mtrx[i][k] * rhs.mtrx[k][j];
			}
		}
	}
	return result;
}

Matrix Matrix::operator/(const int32_t scalar)
{
	Matrix result = *this;
	for (size_t i = 0; i < size; ++i)
	{
		for (size_t j = 0; j < size; ++j)
		{
			result.mtrx[i][j] /= scalar;
		}
	}
	return result;
}

bool Matrix::operator>(const Matrix& rhs) const
{
	if (size != rhs.size)
	{
		throw std::runtime_error("Impossibleto compare");
	}
	for (size_t i = 0; i < size; ++i)
	{
		for (size_t j = 0; j < size; ++j)
		{
			if (!mtrx[i][j] > rhs.mtrx[i][j])
			{
				return false;
			}
		}
	}
}

bool Matrix::operator<(const Matrix& rhs) const
{
	if (size != rhs.size)
	{
		throw std::runtime_error("Impossibleto compare");
	}
	for (size_t i = 0; i < size; ++i)
	{
		for (size_t j = 0; j < size; ++j)
		{
			if (mtrx[i][j] > rhs.mtrx[i][j])
			{
				return false;
			}
		}
	}
}

bool Matrix::operator==(const Matrix& rhs) const
{
	if (size != rhs.size)
	{
		throw std::runtime_error("Impossibleto compare");
	}
	for (size_t i = 0; i < size; ++i)
	{
		for (size_t j = 0; j < size; ++j)
		{
			if (!mtrx[i][j] == rhs.mtrx[i][j])
			{
				return false;
			}
		}
	}
}

bool Matrix::operator!=(const Matrix& rhs) const
{
	if (size != rhs.size)
	{
		throw std::runtime_error("Impossibleto compare");
	}
	for (size_t i = 0; i < size; ++i)
	{
		for (size_t j = 0; j < size; ++j)
		{
			if (mtrx[i][j] == rhs.mtrx[i][j])
			{
			}
			else
			{
				return true;
			}
		}
	}
	return false;
}

Matrix operator*(const Matrix& mtrx, const int32_t scalar)
{
	return (mtrx * scalar);
}


void Matrix::fillMtrxByHands()
{

	for (size_t i = 0; i < size; ++i)
	{
		for (size_t j = 0; j < size; ++j)
		{
			std::cout << "Write element" << " " << "a [" << i << ']' << " " << '[' << j << ']' << ':' << " " << '\n';
			std::cin >> mtrx[i][j];
		}
	}
}

void Matrix::fillMtrxByRandom()
{
	srand(time(NULL));
	int32_t first0, last0;
	std::cout << "Initial value from = \n";
	std::cin >> first0;
	std::cout << "to = \n";
	std::cin >> last0;
	if (first0 > last0)
	{
		std::swap(first0, last0);
	}
	for (size_t i = 0; i < size; ++i)
	{
		for (size_t j = 0; j < size; ++j)
		{
			mtrx[i][j] = rand() % (last0 - first0) + first0;
		}
	}
}

std::ostream& operator<<(std::ostream& out, const Matrix& rhs)
{
	for (size_t i = 0; i < rhs.size; ++i)
	{
		for (size_t j = 0; j < rhs.size; ++j)
		{
			out << std::setw(3) << rhs.mtrx[i][j];
		}
		std::cout << std::endl;
	}
	return out;
}
