/*---------------------------------------------------------------------------*\
 * @File        : PointersToClasses.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : Pointers to Classes
 * @version 0.1
 * @Date        : 2018-10-06
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

#include <iostream>
#include "Book.hpp"

int main(int argc, char *argv[])
{
    Book *p_book_i_am_reading = new Book;             // Declare a pointer and allocate memory
    (*p_book_i_am_reading).author = "Philip Pullman"; // Note the brackets placing here
    p_book_i_am_reading->title = "Lyra’s Oxford";     // -> means “de-reference and then access the member”

    p_book_i_am_reading->SetYearOfPublication(2003);

    std::cout << "Year of publication of "
              << (*p_book_i_am_reading).title << " is "
              << p_book_i_am_reading->GetYearOfPublication()
              << std::endl;

    delete p_book_i_am_reading; //always write a delete statement to match a new statement.
}
