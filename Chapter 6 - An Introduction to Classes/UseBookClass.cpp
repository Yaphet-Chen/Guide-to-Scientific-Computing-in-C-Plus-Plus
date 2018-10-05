/*---------------------------------------------------------------------------*\
 * @File        : UseBookClass.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : Using the Book Class
 * @version 0.1
 * @Date        : 2018-10-06
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

    // Test the overridden constructor
    Book my_book;
    std::cout << "The author is " << my_book.author << "\n";

    Book good_read;

    good_read.author = "C S Lewis";
    good_read.title = "The silver chair";
    good_read.publisher = "Geoffrey Bles";
    good_read.price = 699;
    good_read.format = "paperback";
    good_read.SetYearOfPublication(1953);

    // Use the overridden copy constructor to create another instance with class members taking identical values
    Book another_book(good_read);
    std::cout << "Year of publication of "
              << another_book.title << " is "
              << another_book.GetYearOfPublication()
              << std::endl;

    // Use Specialised constructor
    Book an_extra_book("The Magician’s nephew");
    std::cout << "The title is " << an_extra_book.title << "\n";
}