/*---------------------------------------------------------------------------*\
 * @File        : SimpleFunctions.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : Function prototype, Void function, Pass by copy.
 * @version 0.1
 * @Date        : 2018-10-03
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

#include <iostream>

/* Function prototype: tells the compiler what input variables are required (arguments), and what variable, if any, is returned. */
double CalculateMinimum(double a, double b); // Note that the function prototype ends with a semi-colon.
void PrintPassOrFail(int score, int passMark);
void HasNoEffect(double x);

int main(int argc, char *argv[])
{
    double x = 4.0, y = -8.0;
    double minimum_value = CalculateMinimum(x, y);
    std::cout << "The minimum of " << x << " and " << y
              << " is " << minimum_value << "\n";

    int score = 29, pass_mark = 30;
    PrintPassOrFail(score, pass_mark);

    double z = 2.0;
    /* A copy is sent to a function, and it is this copy of the variable,
    and not the original variable, that is modified inside the function. */
    HasNoEffect(z);
    std::cout << "z in the main function: " << z << "\n"; // will print out 2.0

    return 0;
}

double CalculateMinimum(double a, double b) // Note that there is no need to declare the variables a and b inside the function.
{
    double minimum; // Variables such as minimum that are used inside the function but are not part of the function prototype must be declared within the function block.
    if (a < b)
    {
        minimum = a;
    }
    else
    {
        // a >= b
        minimum = b;
    }

    return minimum; // Note that only one variable may be returned from a function.
}

void PrintPassOrFail(int score, int passMark) // Void function: we do not want a function to return any variable
{
    if (score >= passMark)
    {
        std::cout << "Pass - congratulations!\n";
    }
    else
    {
        // score < passMark
        std::cout << "Fail - better luck next time\n";
    }
}

void HasNoEffect(double z)
{
    // z takes the value 2.0 here
    z += 1.0;
    // z takes the value 3.0 here
    std::cout << "z inside the HasNoEffect function: " << z << "\n"; // will print out 2.0
}
