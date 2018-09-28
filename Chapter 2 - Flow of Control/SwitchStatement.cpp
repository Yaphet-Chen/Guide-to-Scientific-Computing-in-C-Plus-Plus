/*---------------------------------------------------------------------------*\
 * @Brief       : Important points for Switch Statement
 * 
 * @File        : SwitchStatement.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Date        : 2018-09-29
\*---------------------------------------------------------------------------*/

#include <iostream>
int main(int argc, char *argv[])
{
    int i = 1;

    /*However, they are notorious as places where programmers introduce bugs by forgetting 
    to end case statements with the break keyword or by forgetting to give a default case.
    Switch statements should be written with care.*/
    switch (i) // Control variable, must be an integer and not a floating point type.
    {
    case 1:
        std::cout << "i = 1\n";
    case 20:
        std::cout << "i = 1 or i = 20\n";
        break; // At the point when break is reached, the flow of execution will leave the code inside the curly brackets.
    default:
        std::cout << "i is not 1 or 20\n";
    }
    return 0;
}
