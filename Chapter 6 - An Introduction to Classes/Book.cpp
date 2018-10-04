/*---------------------------------------------------------------------------*\
 * @File        : Book.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : Using the class Book
 * @version 0.1
 * @Date        : 2018-10-04
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

/* It doesn’t matter if we include header files such as iostream, string, etc. more than
once. But we should be very careful not to include files such as Book.hpp in the form
that it was written in the previous section more than once, as this can cause problems.*/
#include <iostream>
/* Coding convention: use quotation marks and angle brackets to make the distinction
between local include files and those from external libraries, respectively. */
#include "Book.hpp" //Enclosed within quotation marks

int main(int argc, char *argv[])
{
    Book my_favourite_book; // Instantiation: declaring an instance of the class
    my_favourite_book.author = "Lewis Carroll";
    my_favourite_book.title = "Alice’s adventures in Wonderland";
    my_favourite_book.publisher = "Macmillan";
    my_favourite_book.price = 199;
    my_favourite_book.format = "hardback";
    my_favourite_book.yearOfPublication = 1865;

    std::cout << "Year of publication of "
              << my_favourite_book.title << " is "
              << my_favourite_book.yearOfPublication << std::endl;
}