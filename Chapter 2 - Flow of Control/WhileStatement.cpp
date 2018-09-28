/*---------------------------------------------------------------------------*\
 * @Brief       : While statement & Do-While statement
 * 
 * @File        : WhileStatement.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Date        : 2018-09-28
\*---------------------------------------------------------------------------*/

#include <iostream>

int main(int argc, char *argv[])
{
    double x = 10.0;
    int count = 0;

    /*The important thing to note in the example output above is that the condition x > 1.0
    is tested only at the beginning of the statements enclosed within the curly brackets.*/
    while (x > 1.0)
    {
        x *= 0.5;
        std::cout << "x = " << x << ", count = "
                  << count << "\n";
        count++;
        std::cout << "x = " << x << ", count = "
                  << count << "\n";
        std::cout << "Reached bottom of while loop\n";
    }
    std::cout << "count = " << count << "\n";

    /*Were we to want a loop to be executed at least once, regardless of any other conditions,
    then when can use the do-while syntax which tests at the end of the loop, as shown below.*/
    x = 0.8, count = 0;
    do
    {
        x *= 0.5;
        std::cout << "x = " << x << ", count = "
                  << count << "\n";
        count++;
        std::cout << "x = " << x << ", count = "
                  << count << "\n";
        std::cout << "Reached bottom of do-while loop\n";
    } while (x > 1.0);
    std::cout << "count = " << count << "\n";

    return 0;
}