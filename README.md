# Systems Programming Assignment #2

## Overview
This project implements a square matrix class in C++ with various matrix operations. It includes unit testing and demonstrates object-oriented programming concepts.

## Project Structure

### Source Files
- squaremat.hpp - Header file containing the `SquareMat` class declaration
- squaremat.cpp - Implementation file with the matrix operations
- main.cpp - Main program demonstrating usage of the matrix class
- squaremat_test.cpp - Unit tests for the matrix class

### Build System
- Makefile - Build configuration file with the following targets:
  - `Main` - Builds and runs the main program
  - `tests` - Builds and runs the unit tests 
  - `valgrind` - Runs memory leak checks using Valgrind
  - `clean` - Removes generated files

## Building and Running

To build and run the main program:
```bash
make Main
```

To run the tests:
```bash
make tests
```

To check for memory leaks:
```bash
make valgrind
```

To clean up build artifacts:
```bash
make clean
```

## Implementation Details

The `SquareMat` class provides:
- Basic matrix operations (+, -, *)
- Scalar multiplication 
- Special operations like transpose and determinant
- Increment/decrement operators
- Comparison operators
- Input/output stream operators

The implementation is thoroughly tested using the doctest framework with various test cases checking proper functionality and edge cases.

Note: The detailed implementation and specific matrix operations are defined in the respective source files.