/*---------------------------------------------------------------------------*\
 * @File        : Test.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : Test Vector, Matrix and LinearSystem classes.
 * @version 0.1
 * @Date        : 2018-10-14
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

#include "Vector.hpp"
#include "Matrix.hpp"
#include "LinearSystem.hpp"

int main(int argc, char const *argv[])
{
    /*++++++++++++++++++++++++++++++++++ Test Vector Class ++++++++++++++++++++++++++++++++++++++*/
    Vector v1(5);
    std::cout << "v1 is \n"
              << v1;
    Vector v2(v1);
    v2.SetUniRand(0.0, 1.0);
    std::cout << "v2 is \n"
              << v2;
    std::cout << v1[0] << "\t" << v1.Read(4) << std::endl;
    std::cout << v2(1) << "\t" << v2(5) << std::endl;
    Vector v3 = v1 - v2;
    std::cout << "v3 is \n"
              << v3;
    Vector v4 = v2 * 2.0;
    std::cout << "v4 is \n"
              << v4;
    std::cout << "L1-norm of v4 is " << v4.CalculateNorm(1.0) << std::endl
              << "L2-norm of v4 is " << v4.CalculateNorm() << std::endl
              << "Length of v4 is " << length(v4) << std::endl;

    /*++++++++++++++++++++++++++++++++++ Test Matrix Class ++++++++++++++++++++++++++++++++++++++*/
    Matrix mat1(5, 5);
    std::cout << "mat1 is \n"
              << mat1;
    Matrix mat2(mat1);
    mat2.SetUniRand(-1.0, 0.0);
    std::cout << "mat2 is \n"
              << mat2;
    Matrix mat3 = -mat2;
    std::cout << "mat3 is \n"
              << mat3;
    Matrix mat4 = mat2 * 2.0 + mat3;
    std::cout << "mat4 is \n"
              << mat4;
    std::cout << "Determinant of mat4 is " << mat4.CalculateDeterminant() << std::endl;
    Vector v5 = mat4 * v4;
    std::cout << "v5 is \n"
              << v5;
    Vector v6 = v4 * mat4;
    std::cout << "v6 is \n"
              << v6;

    /*+++++++++++++++++++++++++++++++ Test LinearSystem Class +++++++++++++++++++++++++++++++++++*/
    LinearSystem lin(mat4, v4);
    Vector v7 = lin.Solve();
    std::cout << "v7 is \n"
              << v7;
    std::cout << "Verify if mat4*v7-v4=0 \n"
              << mat4 * v7 - v4;

    return 0;
}