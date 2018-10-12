/*---------------------------------------------------------------------------*\
 * @File        : UseException.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : Using Exceptions 
 * @version 0.1
 * @Date        : 2018-10-12
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

/* Floating point unit renders sqrt(-1.0), 0.0/0.0 and log(0.0) as “not a number” or nan for short.
Some calculations such as 1.0/0.0 will resolve to a floating point representation of infinity (inf).

It would be prudent to check in any piece of code that uses division, square root, logarithms etc.
that the values of all the arguments are in a sensible range.

The three exception levels of error are a compromise between patching the problem to carry on,
and stopping completely. 
1. If the error can be fixed safely, then fix it. If need be, warn the user.
2. If the error could be caused by some reasonable user input then throw an exception up to the 
   calling code, since the calling code should have enough context to fix the problem.
3. If the error should not happen under normal circumstances then trip an assertion. */

/******************************************* test-driven development ****************************************************
Writing the code that tests the new functionality comes before writing the new code for implementing this functionality. 
1. Use a C++ testing framework library, such as CxxTest, Boost.Test or googletest. This will help you structure your tests.
2. Add one or more tests for every new piece of functionality.
3. Make tests definitive—they should either pass or fail. However, beware of floating point tolerances
   and allow for rounding errors in calculations.
4. Remember to write tests for corner cases. These are test inputs which may be rare, but might cause problems —
   collinear triangles, singular matrices, the complex number 0+0i etc.
5. Review your tests from time to time. Add new tests as necessary and remove only those which you know to be redundant.
6. Automate your testing, so that you do not have to remember to run the tests or remember to check the results. */

#include <iostream>
#include <fstream>
#include "Exception.hpp"

void ReadFile(const std::string &fileName, double x[], double y[])
{
    std::ifstream read_file(fileName.c_str()); // Converted C++ string to a C string
    if (read_file.is_open() == false)
    {
        /* Throw is used when the error is identified. The function called will encapsulate information
        about the error into an Exception object and throw it back to the caller. */
        throw(Exception("FILE", "File can’t be opened"));
    }
    for (int i = 0; i < 6; i++)
    {
        read_file >> x[i] >> y[i];
    }
    read_file.close();

    std::cout << fileName << " read successfully\n";
}

int main(int argc, char *argv[])
{
    double x[6], y[6];
    try
    {
        /* Try is used in the calling code and tells the program to execute some statements
        in the knowledge that some error might happen. */
        ReadFile("Output.dat", x, y);
    }
    catch (Exception &error)
    {
        /* Catch is used in the calling code to show how to attempt to fix the error.
        Every block of code that has the try keyword must be matched by a catch block. */
        error.PrintDebug();
        std::cout << "Couldn’t open Output.dat\n";
        std::cout << "Give alternative location\n";
        std::string file_name;
        std::cin >> file_name;
        ReadFile(file_name, x, y);
    }
}