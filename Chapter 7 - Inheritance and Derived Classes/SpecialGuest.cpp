/*---------------------------------------------------------------------------*\
 * @File        : SpecialGuest.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : Run-Time Polymorphism
 * @version 0.1
 * @Date        : 2018-10-09
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

#include "SpecialGuest.hpp"

double SpecialGuest::CalculateBill()
{
    return 45.0 + ((double)(numberOfNights - 1)) * 40.0;
}