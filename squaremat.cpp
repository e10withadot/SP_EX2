// ey.gellis@gmail.com
#include "squaremat.hpp"
#include <cmath>
#include <ostream>
#include <vector>
#include <iostream>
#include <stdexcept>

SquareMat::SquareMat() : size(1), matrix(1, std::vector<double>(1, 0.0)) {}

SquareMat::SquareMat(int n) : size(n), matrix(n, std::vector<double>(n, 0.0)) {
	if(n == 0)
		throw std::invalid_argument("Matrix size is not > 0");
}

SquareMat::SquareMat(const std::vector<std::vector<double>>& mat) {
	if (mat.empty())
		throw std::invalid_argument("Input matrix cannot be empty");

	int n = mat.size();
	for (const std::vector<double>& row : mat) {
		if (row.size() != n)
			throw std::invalid_argument("Input matrix must be square");
	}

	size = n;
	matrix = mat;
}

double SquareMat::determinantRecursive(const std::vector<std::vector<double>>& mat) const {
	int n = static_cast<int>(mat.size());

	if (n == 1)
		return mat[0][0];
	if (n == 2)
		return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];

	double det = 0.0;
	for (int col = 0; col < n; ++col) {
		std::vector<std::vector<double>> submat(n - 1, std::vector<double>(n - 1));
		for (int i = 1; i < n; ++i) {
			int subcol = 0;
			for (int j = 0; j < n; ++j) {
				if (j == col) continue;
				submat[i - 1][subcol++] = mat[i][j];
			}
		}
		double sign = (col % 2 == 0) ? 1.0 : -1.0;
		det += sign * mat[0][col] * determinantRecursive(submat);
	}
	return det;
}

std::vector<double>& SquareMat::operator[](int index) {
	if (index >= size)
		throw std::out_of_range("Row index out of range");
	return matrix[index];
}

const std::vector<double>& SquareMat::operator[](int index) const {
	if (index >= size)
		throw std::out_of_range("Row index out of range");
	return matrix[index];
}

SquareMat SquareMat::operator+(const SquareMat& b) const {
	if (size != b.size)
		throw std::invalid_argument("Matrix sizes must match for addition");

	SquareMat result(size);
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			result.matrix[i][j] = matrix[i][j] + b.matrix[i][j];
	return result;
}
SquareMat SquareMat::operator-(const SquareMat& b) const {
	if (size != b.size)
		throw std::invalid_argument("Matrix sizes must match for subtraction");

	SquareMat result(size);
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			result.matrix[i][j] = matrix[i][j] - b.matrix[i][j];
	return result;
}
SquareMat SquareMat::operator-() const {
	SquareMat result(size);
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			result.matrix[i][j] = -matrix[i][j];
	return result;
}
SquareMat SquareMat::operator*(const SquareMat& b) const {
	if (size != b.size)
		throw std::invalid_argument("Matrix sizes must match for multiplication");

	SquareMat result(size);

	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j) {
			double sum = 0.0;
			for (int k = 0; k < size; ++k)
				sum += matrix[i][k] * b.matrix[k][j];
			result.matrix[i][j] = sum;
		}

	return result;
}
SquareMat operator*(double sc, const SquareMat& mat) {
	SquareMat result(mat.size);
	for (int i = 0; i < mat.size; ++i)
		for (int j = 0; j < mat.size; ++j)
			result.matrix[i][j] = sc * mat.matrix[i][j];
	return result;
}
SquareMat SquareMat::operator*(double sc) const {
	SquareMat result(size);
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			result.matrix[i][j] = matrix[i][j] * sc;
	return result;
}
SquareMat SquareMat::operator%(const SquareMat& b) const {
	if (size != b.size)
		throw std::invalid_argument("Matrix sizes must match for modulo");

	SquareMat result(size);
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j) {
			double divisor = b.matrix[i][j];
			if (divisor == 0.0) {
				throw std::domain_error("Modulo by zero element in matrix");
			}
			double dividend = matrix[i][j];
			result.matrix[i][j] = dividend - divisor * std::floor(dividend / divisor);
		}
	return result;
}
SquareMat SquareMat::operator%(int sc) const {
	if (sc == 0)
		throw std::invalid_argument("Modulo by zero is undefined");

	SquareMat result(size);
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j) {
			double val = matrix[i][j];
			result.matrix[i][j] = val - sc * std::floor(val / sc);
		}
	return result;
}
SquareMat SquareMat::operator/(double sc) const {
	if (sc == 0.0)
		throw std::invalid_argument("Division by zero is undefined");

	SquareMat result(size);
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			result.matrix[i][j] = matrix[i][j] / sc;
	return result;
}
static SquareMat identityMatrix(int n) {
	SquareMat id(n);
	for (int i = 0; i < n; ++i)
		id[i][i] = 1.0;
	return id;
}
SquareMat SquareMat::operator^(unsigned int power) const {
	if (power == 0)
		return identityMatrix(size);

	SquareMat result = identityMatrix(size);
	SquareMat base = *this;
	unsigned int p = power;

	while (p > 0) {
		if (p & 1)
			result = result * base;
		base = base * base;
		p >>= 1;
	}
	return result;
}
SquareMat& SquareMat::operator++() {
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			++matrix[i][j];
	return *this;
}
SquareMat SquareMat::operator++(int) {
	SquareMat temp = *this;
	++(*this);
	return temp;
}
SquareMat& SquareMat::operator--() {
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			--matrix[i][j];
	return *this;
}
SquareMat SquareMat::operator--(int) {
	SquareMat temp = *this;
	--(*this);
	return temp;
}
SquareMat SquareMat::operator~() const {
	SquareMat result(size);
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			result.matrix[j][i] = matrix[i][j];
	return result;
}
int SquareMat::sum() const {
	int res = 0;
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			res+=matrix[i][j];
	return res;
}
bool SquareMat::operator==(const SquareMat& b) const {
	return sum() == b.sum();
}
bool SquareMat::operator!=(const SquareMat& b) const {
	return sum() != b.sum();
}
bool SquareMat::operator<(const SquareMat& b) const {
	return sum() < b.sum();
}
bool SquareMat::operator>(const SquareMat& b) const {
	return sum() > b.sum();
}
bool SquareMat::operator<=(const SquareMat& b) const {
	return sum() <= b.sum();
}
bool SquareMat::operator>=(const SquareMat& b) const {
	return sum() >= b.sum();
}
double SquareMat::operator!() const {
	std::vector<std::vector<double>> matVec(size, std::vector<double>(size));
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			matVec[i][j] = matrix[i][j];

	return determinantRecursive(matVec);
}
SquareMat& SquareMat::operator+=(const SquareMat& b) {
	if (size != b.size)
		throw std::invalid_argument("Matrix sizes must match for addition");

	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			matrix[i][j] += b.matrix[i][j];

	return *this;
}
SquareMat& SquareMat::operator-=(const SquareMat& b) {
	if (size != b.size)
		throw std::invalid_argument("Matrix sizes must match for subtraction");

	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			matrix[i][j] -= b.matrix[i][j];

	return *this;
}
SquareMat& SquareMat::operator*=(const SquareMat& b) {
	if (size != b.size)
		throw std::invalid_argument("Matrix sizes must match for multiplication");

	SquareMat result(size);
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j) {
			double sum = 0.0;
			for (int k = 0; k < size; ++k)
				sum += matrix[i][k] * b.matrix[k][j];
			result.matrix[i][j] = sum;
		}

	*this = result;
	return *this;
}
SquareMat& SquareMat::operator*=(double sc) {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            matrix[i][j] *= sc;
    return *this;
}
SquareMat& SquareMat::operator/=(double sc) {
	if (sc == 0.0)
		throw std::invalid_argument("Division by zero is undefined");

	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			matrix[i][j] /= sc;

	return *this;
}
SquareMat& SquareMat::operator%=(const SquareMat& b) {
	if (size != b.size)
		throw std::invalid_argument("Matrix sizes must match for modulo");

	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j) {
			if (b.matrix[i][j] == 0.0)
				throw std::invalid_argument("Modulo by zero is undefined");
			matrix[i][j] = std::fmod(matrix[i][j], b.matrix[i][j]);
		}
	return *this;
}
SquareMat& SquareMat::operator%=(int sc) {
	if (sc == 0)
		throw std::invalid_argument("Modulo by zero is undefined");

	double dsc = static_cast<double>(sc);
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size; ++j)
			matrix[i][j] = std::fmod(matrix[i][j], dsc);

	return *this;
}

std::ostream& operator<<(std::ostream& os, const SquareMat& mat) {
	for (int i = 0; i < mat.size; ++i) {
		for (int j = 0; j < mat.size; ++j) {
			os << mat.matrix[i][j];
			if (j + 1 < mat.size)
				os << " ";
		}
		os << "\n";
	}
	return os;
}
