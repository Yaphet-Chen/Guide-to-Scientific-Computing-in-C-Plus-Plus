/*---------------------------------------------------------------------------*\
 * @Brief       : The word cerr is a contraction of console error.
 * 
 * @File        : RedirectConsoleOutput.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Date        : 2018-09-29
\*---------------------------------------------------------------------------*/

#include <iostream>

int main(int argc, char *argv[])
{
    int x = 1, y = 0;
    std::cout << "x = " << x << "\n";
    /* On a Linux system this output may very easily be redirected to a single file rather than the screen.
                                    ./RedirectConsoleOutput > SampleOutput.txt                          */
    if (y == 0)
    {
        std::cerr << "Error - division by zero\n";
    /* The syntax for std::cerr is identical to that for std::cout. When output is
    redirected to a specified file, only the std::cout statements are redirected: the
    output from a std::cerr statement will still be printed to the screen.*/
    }
    else
    {
        // y not zero
        std::cout << x / y << "\n";
    }
}