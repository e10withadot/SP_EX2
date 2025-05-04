// ey.gellis@gmail.com
#ifndef SQUAREMAT_H
#define SQUAREMAT_H

#include <iostream>
#include <vector>

/**
 * @brief A class representing a square matrix with various mathematical operations
 */
class SquareMat {
private:
	std::vector<std::vector<double>> matrix;
	int size;

	/**
	 * @brief Recursively calculates the determinant of a matrix
	 * @param mat The matrix to calculate determinant for
	 * @return The determinant value
	 */
	double determinantRecursive(const std::vector<std::vector<double>>& mat) const;

public:
	SquareMat();

	SquareMat(int n);

	SquareMat(const std::vector<std::vector<double>>& mat);

	/**
	 * @brief Calculates the sum of all elements in the matrix
	 * @return The sum of all matrix elements
	 */
	int sum() const;

	/**
	 * @brief Access operator for matrix rows
	 * @param index Row index
	 * @return Reference to the row vector
	 */
	std::vector<double>& operator[](int index);

	/**
	 * @brief Const access operator for matrix rows
	 * @param index Row index
	 * @return Const reference to the row vector
	 */
	const std::vector<double>& operator[](int index) const;

	/**
	 * @brief Adds two matrices
	 * @param b Matrix to add
	 * @return Result of addition
	 */
	SquareMat operator+(const SquareMat& b) const;

	/**
	 * @brief Subtracts two matrices
	 * @param b Matrix to subtract
	 * @return Result of subtraction
	 */
	SquareMat operator-(const SquareMat& b) const;

	/**
	 * @brief Negates all elements in the matrix
	 * @return Negated matrix
	 */
	SquareMat operator-() const;

	/**
	 * @brief Multiplies two matrices
	 * @param b Matrix to multiply with
	 * @return Result of multiplication
	 */
	SquareMat operator*(const SquareMat& b) const;

	/**
	 * @brief Multiplies matrix by a scalar (friend function)
	 * @param sc Scalar value
	 * @param mat Matrix to multiply
	 * @return Result of multiplication
	 */
	friend SquareMat operator*(double sc, const SquareMat& mat);

	/**
	 * @brief Multiplies matrix by a scalar
	 * @param sc Scalar value
	 * @return Result of multiplication
	 */
	SquareMat operator*(double sc) const;

	/**
	 * @brief Element-wise modulo operation between matrices
	 * @param b Matrix for modulo operation
	 * @return Result of modulo operation
	 */
	SquareMat operator%(const SquareMat& b) const;

	/**
	 * @brief Element-wise modulo operation with scalar
	 * @param sc Scalar value for modulo
	 * @return Result of modulo operation
	 */
	SquareMat operator%(int sc) const;

	/**
	 * @brief Divides matrix by a scalar
	 * @param sc Scalar value
	 * @return Result of division
	 */
	SquareMat operator/(double sc) const;

	/**
	 * @brief Raises matrix to a power
	 * @param power Exponent value
	 * @return Result of exponentiation
	 */
	SquareMat operator^(unsigned int power) const;

	/**
	 * @brief Pre-increment operator
	 * @return Reference to incremented matrix
	 */
	SquareMat& operator++();

	/**
	 * @brief Post-increment operator
	 * @return Copy of matrix before increment
	 */
	SquareMat operator++(int);

	/**
	 * @brief Pre-decrement operator
	 * @return Reference to decremented matrix
	 */
	SquareMat& operator--();

	/**
	 * @brief Post-decrement operator
	 * @return Copy of matrix before decrement
	 */
	SquareMat operator--(int);

	/**
	 * @brief Transposes the matrix
	 * @return Transposed matrix
	 */
	SquareMat operator~() const;

	/**
	 * @brief Equality comparison operator
	 * @param b Matrix to compare with
	 * @return True if matrices are equal
	 */
	bool operator==(const SquareMat& b) const;

	/**
	 * @brief Inequality comparison operator
	 * @param b Matrix to compare with
	 * @return True if matrices are not equal
	 */
	bool operator!=(const SquareMat& b) const;

	/**
	 * @brief Less than comparison based on matrix sum
	 * @param b Matrix to compare with
	 * @return True if this matrix sum is less than b's sum
	 */
	bool operator<(const SquareMat& b) const;

	/**
	 * @brief Greater than comparison based on matrix sum
	 * @param b Matrix to compare with
	 * @return True if this matrix sum is greater than b's sum
	 */
	bool operator>(const SquareMat& b) const;

	/**
	 * @brief Less than or equal comparison based on matrix sum
	 * @param b Matrix to compare with
	 * @return True if this matrix sum is less than or equal to b's sum
	 */
	bool operator<=(const SquareMat& b) const;

	/**
	 * @brief Greater than or equal comparison based on matrix sum
	 * @param b Matrix to compare with
	 * @return True if this matrix sum is greater than or equal to b's sum
	 */
	bool operator>=(const SquareMat& b) const;

	/**
	 * @brief Calculates the determinant of the matrix
	 * @return Determinant value
	 */
	double operator!() const;

	/**
	 * @brief Addition assignment operator
	 * @param b Matrix to add
	 * @return Reference to this matrix
	 */
	SquareMat& operator+=(const SquareMat& b);

	/**
	 * @brief Subtraction assignment operator
	 * @param b Matrix to subtract
	 * @return Reference to this matrix
	 */
	SquareMat& operator-=(const SquareMat& b);

	/**
	 * @brief Multiplication assignment operator
	 * @param b Matrix to multiply with
	 * @return Reference to this matrix
	 */
	SquareMat& operator*=(const SquareMat& b);

	/**
	 * @brief Scalar multiplication assignment operator
	 * @param sc Scalar value
	 * @return Reference to this matrix
	 */
	SquareMat& operator*=(double sc);

	/**
	 * @brief Scalar division assignment operator
	 * @param sc Scalar value
	 * @return Reference to this matrix
	 */
	SquareMat& operator/=(double sc);

	/**
	 * @brief Element-wise modulo assignment operator
	 * @param b Matrix for modulo operation
	 * @return Reference to this matrix
	 */
	SquareMat& operator%=(const SquareMat& b);

	/**
	 * @brief Scalar modulo assignment operator
	 * @param sc Scalar value for modulo
	 * @return Reference to this matrix
	 */
	SquareMat& operator%=(int sc);

	/**
	 * @brief Output stream operator
	 * @param os Output stream
	 * @param mat Matrix to output
	 * @return Reference to output stream
	 */
	friend std::ostream& operator<<(std::ostream& os, const SquareMat& mat);
};

#endif
