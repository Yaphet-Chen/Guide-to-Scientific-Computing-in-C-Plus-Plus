/*---------------------------------------------------------------------------*\
 * @Brief       : For loops
 * 
 * @File        : ForStatement.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Date        : 2018-09-28
\*---------------------------------------------------------------------------*/
#include <iostream>

int main(int argc, char *argv[])
{
    for (int i = 0; i < 10; i += 2) // Loop counter variables are declared in the context of the loop
    {
        std::cout << i << " ";
    }
    std::cout << "\n";
    std::cout.flush();

    // * * * * * * * * * * * * * * Nest For loops * * * * * * * * * * * * * //
    for (int i = 0; i < 5; i++) // Outer loop
    {
        for (int j = 5; j > i; j--) // Inner loop
        {
            std::cout << "i = " << i
                      << " j = " << j << "\n";
        }
    }
}