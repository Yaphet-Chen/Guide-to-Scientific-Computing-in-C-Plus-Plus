/*---------------------------------------------------------------------------*\
 * @File        : UseExampleClass.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : The friend Keyword
 * @version 0.1
 * @Date        : 2018-10-06
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

#include <iostream>
#include "ExampleClass.hpp"

int main(int argc, char *argv[])
{
    ExampleClass example(2.0, 3.0);
    std::cout << "Minimum value = " << example.GetMinimum()
              << "\n";
    std::cout << "Maximum value = " << GetMaximum(example)
              << "\n";
    return 0;
}