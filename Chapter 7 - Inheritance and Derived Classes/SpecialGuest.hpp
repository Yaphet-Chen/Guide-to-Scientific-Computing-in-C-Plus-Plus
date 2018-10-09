/*---------------------------------------------------------------------------*\
 * @File        : SpecialGuest.hpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : Run-Time Polymorphism
 * @version 0.1
 * @Date        : 2018-10-09
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

#ifndef SPECIALGUESTDEF
#define SPECIALGUESTDEF

#include "Guest.hpp"

class SpecialGuest : public Guest
{
  public:
    double CalculateBill();
};

#endif