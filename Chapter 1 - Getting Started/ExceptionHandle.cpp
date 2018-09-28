/*---------------------------------------------------------------------------*\
 * @Brief       : A less sophisticated exception handle - assert statements
 * 
 * @File        : ExceptionHandle.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Date        : 2018-09-28
\*---------------------------------------------------------------------------*/

#include <iostream>
#include <cassert> //Note the inclusion of the extra header file cassert that is required to use assert statements.
#include <cmath>

int main(int argc, char *argv[])
{
    double a;
    std::cout << "Enter a non-negative number\n";
    std::cin >> a;

    /* Another advantage of assert statements is that they are automatically removed when compiled
    with the “-O” optimisation flag, so that you can test code with the assertions activated but
    distribute a faster program that has them deactivated. */
    assert(a >= 0.0);
    std::cout << "The square root of " << a;
    std::cout << " is " << sqrt(a) << "\n";
    // std::cout.flush();
    // Debug tip: Do not forget to flush the output so that it appears before the program crashes!
    return 0;
}