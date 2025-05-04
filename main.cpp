// ey.gellis@gmail.com
#include "squaremat.hpp"
#include <iostream>
#include <vector>

int main() {
    try {
        std::cout << "Creating matrices...\n";
        SquareMat mat1(2);
        std::vector<std::vector<double>> data = {
            {1.0, 2.0},
            {3.0, 4.0}
        };
        SquareMat mat2(data);

        std::cout << "\nMatrix 1 (zero matrix):\n" << mat1;
        std::cout << "\nMatrix 2:\n" << mat2;

        std::cout << "\nBasic arithmetic operations:";
        std::cout << "\nMatrix 2 + Matrix 2:\n" << (mat2 + mat2);
        std::cout << "Matrix 2 - Matrix 1:\n" << (mat2 - mat1);
        std::cout << "Matrix 2 * Matrix 2:\n" << (mat2 * mat2);
        std::cout << "Matrix 2 * 2.0:\n" << (mat2 * 2.0);
        std::cout << "2.0 * Matrix 2:\n" << (2.0 * mat2);

        std::cout << "\nSpecial operations:";
        std::cout << "\nTranspose of Matrix 2 (~):\n" << ~mat2;
        std::cout << "Determinant of Matrix 2 (!):" << !mat2 << "\n";
        std::cout << "Matrix 2 ^ 2:\n" << (mat2 ^ 2);

        std::cout << "\nIncrement/Decrement:";
        SquareMat temp = mat2;
        std::cout << "\nPre-increment (++Matrix):\n" << ++temp;
        temp = mat2;
        std::cout << "Post-decrement (Matrix--):\n" << temp--;
        std::cout << "After post-decrement:\n" << temp;

        std::cout << "\nComparison operations:";
        std::cout << "\nMatrix 2 == Matrix 2: " << (mat2 == mat2);
        std::cout << "\nMatrix 1 < Matrix 2: " << (mat1 < mat2);
        std::cout << "\nMatrix 2 >= Matrix 1: " << (mat2 >= mat1);

        std::cout << "\n\nCompound assignment:";
        temp = mat2;
        temp += mat2;
        std::cout << "\nAfter Matrix += Matrix:\n" << temp;
        temp = mat2;
        temp *= 2.0;
        std::cout << "After Matrix *= 2.0:\n" << temp;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
