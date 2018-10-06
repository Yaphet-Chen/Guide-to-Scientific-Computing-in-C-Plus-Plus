/*---------------------------------------------------------------------------*\
 * @File        : UseComplexNumber.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : Operator Overloading
 * @version 0.1
 * @Date        : 2018-10-06
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

#include "ComplexNumber.hpp"

int main(int argc, char *argv[])
{
    ComplexNumber z1(4.0, 3.0);
    std::cout << "z1 = " << z1 << "\n";
    std::cout << "Modulus z1 = " << z1.CalculateModulus() << "\n";
    std::cout << "Argument z1 = " << z1.CalculateArgument() << "\n";

    ComplexNumber z2;
    z2 = z1.CalculatePower(3);
    std::cout << "z2 = z1 * z1 * z1 = " << z2 << "\n";

    ComplexNumber z3;
    z3 = -z2;
    std::cout << "z3 = -z2 = " << z3 << "\n";

    ComplexNumber z4;
    z4 = z1 + z2;
    std::cout << "z1 + z2 = " << z4 << "\n";

    ComplexNumber z5[2];
    z5[0] = z1;
    z5[1] = z2;
    std::cout << "Second element of z5 = " << z5[1] << "\n";

    return 0;
}