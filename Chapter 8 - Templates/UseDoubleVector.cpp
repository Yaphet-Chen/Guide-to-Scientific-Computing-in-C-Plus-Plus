/*---------------------------------------------------------------------------*\
 * @File        : UseDoubleVector.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : Templates to Control Dimensions and Verify Sizes
 * @version 0.1
 * @Date        : 2018-10-09
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

#include <iostream>
#include "DoubleVector.hpp"

int main(int argc, char *argv[])
{
    DoubleVector<5> v;
    v[0] = 1.0; // This is OK
    v[7] = 5.0; // Will trip assertion
    return 0;
}