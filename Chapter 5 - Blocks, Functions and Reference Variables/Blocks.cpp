/*---------------------------------------------------------------------------*\
 * @File        : Blocks.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : A block is any piece of code between curly brackets. A variable, when declared
inside a block, may be used throughout that block, but only within that block.
 * @version 0.1
 * @Date        : 2018-10-02
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

#include <iostream>

/* The same variable name may be used for a variable declared both inside a
block, termed the local variable, and outside the scope of any function (including
the main function)—termed the global variable.*/
int i = 5; // global i
int main(int argc, char *argv[])
{
    int j = 7; // Must be defined in main scope, otherwise the compiler would report an error: ‘j’ was not declared in this scope
    std::cout << i << "\n";
    {
        int i = 10, j = 11;
        std::cout << i << "\n";   // local value of i is 10
        std::cout << ::i << "\n"; // global value of i is 5
        std::cout << j << "\n";   // value of j here is 11
        //The other j (value 7) is inaccessible
    }
    std::cout << j << "\n"; // value of j here is 7
    return 0;
}
/* The multiple declaration of both i and j is bad programming practice, and we suggest that
variables are declared only within the block where they are needed. */