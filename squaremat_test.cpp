// ey.gellis@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "squaremat.hpp"
using namespace matrix;
#include <stdexcept>

TEST_CASE("SquareMat Construction and Basic Operations") {
    SUBCASE("Constructor tests") {
        CHECK_NOTHROW(SquareMat(2));
        CHECK_THROWS_AS(SquareMat(0), std::invalid_argument);
        
        std::vector<std::vector<double>> data = {
            {1.0, 2.0},
            {3.0, 4.0}
        };
        CHECK_NOTHROW(SquareMat varname(data));
        
        std::vector<std::vector<double>> invalid_data = {
            {1.0, 2.0},
            {3.0, 4.0},
            {5.0, 6.0}
        };
        CHECK_THROWS_AS(SquareMat varname(invalid_data), std::invalid_argument);
    }

    SUBCASE("Basic arithmetic operations") {
        std::vector<std::vector<double>> data = {
            {1.0, 2.0},
            {3.0, 4.0}
        };
        SquareMat mat1(data);
        SquareMat mat2(data);

        auto result = mat1 + mat2;
        CHECK(result[0][0] == 2.0);
        CHECK(result[0][1] == 4.0);
        CHECK(result[1][0] == 6.0);
        CHECK(result[1][1] == 8.0);

        result = mat1 - mat2;
        CHECK(result[0][0] == 0.0);
        CHECK(result[0][1] == 0.0);
        CHECK(result[1][0] == 0.0);
        CHECK(result[1][1] == 0.0);

        result = mat1 * mat2;
        CHECK(result[0][0] == 7.0);
        CHECK(result[0][1] == 10.0);
        CHECK(result[1][0] == 15.0);
        CHECK(result[1][1] == 22.0);

        result = mat1 * 2.0;
        CHECK(result[0][0] == 2.0);
        CHECK(result[0][1] == 4.0);
        CHECK(result[1][0] == 6.0);
        CHECK(result[1][1] == 8.0);
    }

    SUBCASE("Special operations") {
        std::vector<std::vector<double>> data = {
            {1.0, 2.0},
            {3.0, 4.0}
        };
        SquareMat mat(data);

        auto trans = ~mat;
        CHECK(trans[0][0] == 1.0);
        CHECK(trans[0][1] == 3.0);
        CHECK(trans[1][0] == 2.0);
        CHECK(trans[1][1] == 4.0);

        CHECK(!mat == -2.0);

        auto pow_result = mat ^ 2;
        CHECK(pow_result[0][0] == 7.0);
        CHECK(pow_result[0][1] == 10.0);
        CHECK(pow_result[1][0] == 15.0);
        CHECK(pow_result[1][1] == 22.0);
    }

    SUBCASE("Increment/Decrement operations") {
        std::vector<std::vector<double>> data = {
            {1.0, 2.0},
            {3.0, 4.0}
        };
        SquareMat mat(data);

        auto result = ++mat;
        CHECK(result[0][0] == 2.0);
        CHECK(mat[0][0] == 2.0);

        result = mat--;
        CHECK(result[0][0] == 2.0);
        CHECK(mat[0][0] == 1.0);
    }

    SUBCASE("Comparison operations") {
        std::vector<std::vector<double>> data1 = {
            {1.0, 2.0},
            {3.0, 4.0}
        };
        std::vector<std::vector<double>> data2 = {
            {2.0, 3.0},
            {4.0, 5.0}
        };
        SquareMat mat1(data1);
        SquareMat mat2(data2);

        CHECK(mat1 < mat2);
        CHECK(mat2 > mat1);
        CHECK(mat1 <= mat2);
        CHECK(mat2 >= mat1);
        CHECK(mat1 == mat1);
        CHECK(mat1 != mat2);
    }

    SUBCASE("Compound assignment operations") {
        std::vector<std::vector<double>> data = {
            {1.0, 2.0},
            {3.0, 4.0}
        };
        SquareMat mat(data);
        SquareMat original = mat;

        mat += original;
        CHECK(mat[0][0] == 2.0);
        CHECK(mat[0][1] == 4.0);
        CHECK(mat[1][0] == 6.0);
        CHECK(mat[1][1] == 8.0);

        mat = original;
        mat *= 2.0;
        CHECK(mat[0][0] == 2.0);
        CHECK(mat[0][1] == 4.0);
        CHECK(mat[1][0] == 6.0);
        CHECK(mat[1][1] == 8.0);
    }
}
