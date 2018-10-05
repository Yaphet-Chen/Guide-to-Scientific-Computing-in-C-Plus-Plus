/*---------------------------------------------------------------------------*\
 * @File        : Book.hpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : Abstraction, Encapsulation and Modularity Properties of Classes
 *                The extension .hpp indicates that is a header file associated with a C++ program. 
 * @version 0.1
 * @Date        : 2018-10-05
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

/*************************** The Raisond’Être for Classes ***********************************
 *  Encapsulation: the compartmentalisation of all of the resources needed
 *  Modularity: place similar functionality in a few files and access controls can prevent
 *              users from inadvertently corrupting data. Furthermore, combining functionality
 *              in this way allows us to associate data with the functionality.
 *  Abstraction: hide the irrelevant details of functionality from users and allows emphasis
 *               to be placed on the qualities or properties that characterise the objects in
 *               how they act and the type of information that they carry.
 *  Inheritance: allows easy code reuse, extensibility and polymorphism.
 *  Class members: The variables/data and functions associated with a class
 *  Methods: specification of the functions associated with a class
 **/

#ifndef BOOKHEADERDEF // Only if macro BOOKHEADERDEF not defined, execute lines of code until #endif statement
#define BOOKHEADERDEF
/* Define the macro BOOKHEADERDEF. Ensures that this code is only compiled once, no matter how many times it is included.
As BOOKHEADERDEF is now defined, if this code were to be included a second time all code between the #ifndef BOOKHEADERDEF
statement and #endif will now not be included. We therefore see that the #ifndef, #define and #endif statements may be used
to ensure that the contents of a header file are not included more than once. */

#include <string>

class Book
{
public: // Access Privileges: public allows us to access all variables associated with the class.
  std::string author, title, publisher, format;
  int price;
  void SetYearOfPublication(int year);
  int GetYearOfPublication() const;

private: // Access Privileges: private variables may only be accessed by other class members.
  int mYearOfPublication;
}; //Note that the class ends with ;

#endif // Need one of these for every #ifndef statement