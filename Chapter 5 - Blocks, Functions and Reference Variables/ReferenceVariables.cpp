/*---------------------------------------------------------------------------*\
 * @File        : ReferenceVariables.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : Reference variables: these are variables that are used inside a function that
 *                are a different name for the same variable as that sent to a function.
 * @version 0.1
 * @Date        : 2018-10-04
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

#include <iostream>
#include <cmath>

/* Much easier to use than pointers:
1. Only the inclusion of the symbol & before the variable name in the declaration of the function.
2. Without having to convert to an address with & on the function call
3. Without having to de-reference inside the function */
void CalculateRealAndImaginary(double r, double theta, double &real, double &imaginary);

int main(int argc, char *argv[])
{
    double r = 3.4;
    double theta = 1.23;
    double x, y;

    CalculateRealAndImaginary(r, theta, x, y); // Differ from FunctionWithPointers.cpp
    std::cout << "Real part = " << x << "\n";
    std::cout << "Imaginary part = " << y << "\n";

    return 0;
}

void CalculateRealAndImaginary(double r, double theta, double &real, double &imaginary)
{
    real = r * cos(theta);
    imaginary = r * sin(theta);
}