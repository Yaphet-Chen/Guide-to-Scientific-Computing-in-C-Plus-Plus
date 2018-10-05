/*---------------------------------------------------------------------------*\
 * @File        : UseBookClass.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : Using the Book Class
 * @version 0.1
 * @Date        : 2018-10-05
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

#include <iostream>
/* Coding convention: use quotation marks and angle brackets to make the distinction
between local include files and those from external libraries, respectively. */
#include "Book.hpp" //Enclosed within quotation marks

int main(int argc, char *argv[])
{
    Book promotion_book; // Instantiation: declaring an instance of the class

    promotion_book.author = "Iris Murdoch";
    promotion_book.title = "The sea, the sea";
    promotion_book.publisher = "Chatto & Windus";
    promotion_book.price = 299;
    promotion_book.format = "hardback";
    // Made mYearOfPublication a private member, we cannot directly access this member from outside the class.
    promotion_book.SetYearOfPublication(1978);

    std::cout << "Year of publication of "
              << promotion_book.title << " is "
              << promotion_book.GetYearOfPublication() // Including empty brackets after using this class method
              << std::endl;
}