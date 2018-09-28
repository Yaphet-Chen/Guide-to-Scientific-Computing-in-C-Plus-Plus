/*---------------------------------------------------------------------------*\
 * @Brief       : The If statement
 * 
 * @File        : IfElseStatement.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Date        : 2018-09-28
\*---------------------------------------------------------------------------*/

#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    int i = 10;
    double x = -2.0, y;
    // * * * * * * * * * * * * * * Single If statement * * * * * * * * * * * * * //

    // If only one statement—Statement1—is to be executed when the condition p > q is satisfied, then curly brackets are not strictly necessary.
    if ((x < 0.0) && (i != 0)) x = 0.0;
    std::cout << x << "\n";

    if ((x == 0.0) || !(i == 10)) // The condition (in round brackets) is technically know as the guard.
        x = 2.0;
    std::cout << x << "\n";

    /*---------------------------------------------------------------------------*\
    *                             Coding conventions
    * 
    * Although either of these two variants of the code will do what we want it to,
    * we do not recommend them, as the curly brackets make it very clear precisely which
    * statements are executed as a consequence of a given if statement. As such, we
    * would strongly suggest the use of curly brackets, as shown in the code below.
    \*---------------------------------------------------------------------------*/
    if (x > 0.0)
    {
        x = -2.0;
    }
    std::cout << x << "\n";

    // * * * * * * * * * * * * * * Multiple If statement * * * * * * * * * * * * * //
    if (i > 100)
    {
        y = 2.0;
    }
    else if (i < 0)
    {
        y = 10.0;
        i++;
    }
    else
    {
        /* it is always good programming practice to use a comment to explicitly
        state under what conditions the else condition should be met. */
        // When 0 <= i <= 100
        y = 5.0;
        i += 2;
    }
    std::cout << y << "\t" << i << "\n";

    return 0;
}