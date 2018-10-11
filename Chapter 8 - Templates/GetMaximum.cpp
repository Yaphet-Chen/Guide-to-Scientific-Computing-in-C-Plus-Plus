/*---------------------------------------------------------------------------*\
 * @File        : GetMaximum.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : Templates for Static Polymorphism or Compile-time Polymorphism
 * @version 0.1
 * @Date        : 2018-10-11
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

#include <iostream>

// Specifies that the function is defined for a general class T in the function prototype
template <class T>
T GetMaximum(T number1, T number2);

int main(int argc, char *argv[])
{
    // To call the function, we have to put the data type used in angled brackets
    std::cout << GetMaximum<int>(10, -2) << "\n";
    std::cout << GetMaximum<double>(-4.6, 3.5) << "\n";

    return 0;
}

template <class T>
T GetMaximum(T number1, T number2)
{
    T result;
    if (number1 > number2)
    {
        result = number1;
    }
    else
    {
        //number1 <= number2
        result = number2;
    }
    return result;
}