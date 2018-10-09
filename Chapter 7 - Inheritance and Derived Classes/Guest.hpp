/*---------------------------------------------------------------------------*\
 * @File        : Guest.hpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : Run-Time Polymorphism
 * @version 0.1
 * @Date        : 2018-10-09
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

#ifndef GUESTDEF
#define GUESTDEF

#include <string>

class Guest
{
  public:
    std::string name, roomType, arrivalDate;
    int numberOfNights;
    double telephoneBill;
    /* Virtual methods: the method does different things for different derived classes.
    The virtual keyword is a signal to the compiler that a method has the potential to be overridden by a derived class. */
    virtual double CalculateBill();
};

#endif
