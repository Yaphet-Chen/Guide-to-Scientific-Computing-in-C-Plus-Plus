/*---------------------------------------------------------------------------*\
 * @Brief       : Warnings on the use of pointers
 * 
 * @File        : Pointers.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Date        : 2018-09-29
\*---------------------------------------------------------------------------*/

#include <iostream>

int main(int argc, char const *argv[])
{
    int total_sum = 10;
    // The expression &total_sum represents the address of total_sum, which will take a constant value throughout execution of the code.
    std::cout << &total_sum << "\n";

    /* Pointer variables
    1. Variables that store addresses, that is, the location in the computer’s memory
    2. The asterisk that prefixes these variables when they are declared indicates that these variables are pointers.
    3. When declaring more than one pointer on a line, the asterisk must be repeated
    4. Coding standards: all pointer variables have names that begin with p_ to denote that they are a pointer variable */
    double *p_x, *p_y;
    int *p_i, j;

    double x, y;
    x = 3.0;
    p_x = &x;       // p_x stores the address of x
    y = *p_x + 1.0; // *p_x is the contents of the memory
    /* The asterisk operator in *p_x is called a pointer de-reference
    and can be thought of as the opposite to the & operator */
    std::cout << "x = " << x << "\ty = " << y << "\n";

    /* Aliasing: the contents of the same variable may be accessed using different names.
    In C++, this is most likely to happen when pointers are involved
    1. When two pointers alias the same address in memory
    2. When a pointer references the contents of another variable
    Pointer aliasing: one or more pointers allow the same variable to be accessed using different names. */
    y = 3.0;
    p_y = &y;
    std::cout << "y = " << y << "\n";
    *p_y = 1.0; // This changes the value of y
    std::cout << "y = " << y << "\n";

    // A variable pointer should not be used until first having been assigned a valid address.
    /* The following code cause Segmentation fault (core dumped)
    Changing the contents of an unspecified location in a computer’s memory
    has the potential to cause problems that may be hard to locate.*/
    double *p_test; // p_test can store the address of a double precision number - haven’t said which address yet
                    // It may therefore be pointing at any location in the computer’s memory.
    // *p_test = 1.0;  // Trying to store the value 1.0 in an unspecified memory location

    /* This problem may be avoided by the use of
    1. The new keyword to allocate a valid memory address to p_x
    2. The delete keyword which releases this memory when this memory is no longer required. */
    p_test = new double; // assigns an address to p_test
    *p_test = 1.0;       // stores 1.0 in memory with address p_test
    delete p_test;       // releases memory for re-use

    return 0;
}