/*---------------------------------------------------------------------------*\
 * @Brief       : Laid particular stress on some math constants, functions and operations.
 * 
 * @File        : MathExample.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Date        : 2018-09-28
\*---------------------------------------------------------------------------*/

#include <iostream>
#include <cmath>

int main(int argc, char *argv[])
{
    double x = 7.8, y = 1.65, u = -3.4, z, k;
    int i = 5, j = 2;

    z = M_PI;        // z stores the value of pi
    z = pow(x, y);   // x to the power of y
    z = fmod(x, y);  // remainder when x is divided by y
                     // z is 1.2 since 7.8 = 4*1.65 + 1.2
    z = atan2(y, x); // tangent of angle between the vector
                     // (x, y) and the positive x-axis
                     // note the ordering of y and x in
                     // calling the function atan2
                     // z is 0.208465
    z = fabs(u);     // Absolute value of u
                     // z is 3.4
                     // note fabs should not be confused
                     // with abs (the integer equivalent)

    /* In C++, division of an integer by another integer will return only the integer part 
    of this division: hence dividing i by j will store the integer part of 2.5, which is 2 
    (as everything after the decimal point will be ignored). This value is then stored as 
    the double precision floating point number 2.0 in the memory allocated to k.*/
    k = i / j;
    std::cout << k << "\n";
    k = ((double)(i)) / ((double)(j)); // explicit type conversion
    std::cout << k << "\n";

    return 0;
}