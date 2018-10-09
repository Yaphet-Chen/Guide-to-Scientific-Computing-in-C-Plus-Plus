/*---------------------------------------------------------------------------*\
 * @File        : Guest.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : Run-Time Polymorphism
 * @version 0.1
 * @Date        : 2018-10-09
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

#include "Guest.hpp"

/* Even though this method is a virtual method, it is written in exactly the same
way as if it were not declared as virtual. */
double Guest::CalculateBill()
{
    return telephoneBill + ((double)(numberOfNights)) * 50.0;
}