/*---------------------------------------------------------------------------*\
 * @File        : Book.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : Implementation of methods
 * @version 0.1
 * @Date        : 2018-10-05
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

/* It doesn’t matter if we include header files such as iostream, string, etc. more than
once. But we should be very careful not to include files such as Book.hpp in the form
that it was written in the previous section more than once, as this can cause problems.*/
#include <cassert>
#include "Book.hpp"

void Book::SetYearOfPublication(int year) // This method is associated with a class called Book
{
    assert((year > 1440) && (year < 2020));
    mYearOfPublication = year;
}

/* The keyword const after the declaration of this method is a signal to the compiler that we want to
ensure that the instance of the class will remain constant throughout the execution of the method.*/
int Book::GetYearOfPublication() const
{
    return mYearOfPublication;
}