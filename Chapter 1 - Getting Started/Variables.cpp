/*---------------------------------------------------------------------------*\
 * @Brief       : Basic summary of arrays, boolean variables, ASCII chars and strings
 * 
 * @File        : Variables.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Date        : 2018-09-28
\*---------------------------------------------------------------------------*/

#include <iostream>
#include <string> //To use strings in C++ requires the header file string.

int main(int argc, char *argv[])
{
    /* In contrast to MATLAB and Fortran, in C++ the indices of an array of length n
    start with entry 0 and end with entry n-1. This is known as “zero-based indexing”.*/

    /* Note that the curly bracket notation may only be used to populate arrays at the
    same time as when they are declared—for example the code */
    double array1[3] = {5.0, 1.0, 2.0};
    /* array1 represents the vector
                (5)
                (1)
                (2)
    */
    int array2[2][3] = {{1, 6, -4}, {2, 2, 2}};
    /* array2 represents the matrix
            (1  6 -4) 
            (2  2  2)
    */

    bool flag1, flag2;
    flag1 = true;
    flag2 = false;

    char letter;
    letter = 'a'; // note the single quotation marks
    std::cout << "The character is " << letter << "\n";
    std::cout << flag1 << "  " << flag2 << "\n";

    std::string city; // note the std::
    city = "Oxford";  // note the double quotation marks
    std::cout << "String length = " << city.length() << "\n";
    std::cout << "Third character = " << city.at(2) << "\n";
    std::cout << "Third character = " << city[2] << "\n";
    std::cout << city << "\n";
    /* Prints the contents of city to the screen, but does so by first converting from a C++ string to a
    C string, which is an array of type char. The string utility function c_str is not needed here,
    but is useful in cases where we need to pass a C++ string to a function which expects an array of type char. */
    std::cout << city.c_str() << "\n";

    return 0;
}