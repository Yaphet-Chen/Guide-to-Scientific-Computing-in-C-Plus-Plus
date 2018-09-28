/*---------------------------------------------------------------------------*\
 * @Brief       : Tips for loops and branches
 * 
 * @File        : Ch2_Tips.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Date        : 2018-09-29
\*---------------------------------------------------------------------------*/

#include <iostream>
#include <cmath>
#include <cfloat> // DBL_EPSILON ~ 2e-16 is defined in <cfloat>

int main(int argc, char *argv[])
{
    /* * * * * * * * * * Tip 1: Never put semi-colon ; after for, while or if * * * * * * * * * * * */
    double x = 2.0;
    for (int i = 0; i < 5; i++);
    {
        // A block with special scope.
        // This block has no connection with the for loop and is executed once.
        x *= 2.0;
    }
    std::cout << "x = " << x << "\n"; // Output x = 4 instead of  2*2^5 = 64

    /* * * * * * * * * * * * * * * * * Tip 2: Counting from Zero * * * * * * * * * * * * * * * * */
    // This loop is natural for MATLAB programmers
    for (int j = 1; j <= 4; j++)
    {
        std::cout << "j = " << j << "\n";
    }
    // This loop is natural for C++ programmers
    for (int j = 0; j < 4; j++)
    {
        std::cout << "j = " << j << "\n";
    }
    /*The reason for this is that while M ATLAB and Fortran use one-based indexing
    where array indexing starts at 1, C++ uses zero-based indexing.*/

    /* * * * * * * * * * * * * * * * Tip 3: Equality Versus Assignment * * * * * * * * * * * * * * * * */
    x == 2 + 2;
    // This erroneous line has no effect
    // After testing x against the value 4, the true/false answer is discarded.

    x = 3;
    //This erroneous line will alter the value of x
    if (x = 4)
    {
        x = 6;
    }
    std::cout << "x = " << x << "\n";
    // The GNU C++ compiler will give warnings with flag -Wall, and errors with flag -Werror

    /* * * * * * * * * * * * * * Tip 5: Comparing Two Floating Point Numbers * * * * * * * * * * * * * */
    double p = 5.0, q = 5.0 + DBL_EPSILON;
    int k = 1;
    if (fabs(p - q) < p * DBL_EPSILON)
    {
        k = 0;
    }
    std::cout << "k = " << k << "\n";
    return 0;
}
