/*---------------------------------------------------------------------------*\
 * @File        : RecursiveFunctions.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : Recursive Functions: call a function from within the same function
 * @version 0.1
 * @Date        : 2018-10-04
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

#include <iostream>
#include <cassert>

int CalculateFactorial(int n);

int main(int argc, char *argv[])
{
    int n = 7;
    std::cout << "The factorial of " << n
              << " is " << CalculateFactorial(n) << "\n";

    return 0;
}

int CalculateFactorial(int n)
{
    assert(n > 0);
    if (n == 1)
    {
        return 1;
    }
    else
    {
        // n>1
        return n * CalculateFactorial(n - 1);
    }
}