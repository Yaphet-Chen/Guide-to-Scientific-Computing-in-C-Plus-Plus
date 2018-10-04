/*---------------------------------------------------------------------------*\
 * @File        : Book.hpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : Abstraction, Encapsulation and Modularity Properties of Classes
 *                The extension .hpp indicates that is a header file associated with a C++ program. 
 * @version 0.1
 * @Date        : 2018-10-04
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

#include <string>
/** Encapsulation: the compartmentalisation of all of the resources needed
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

class Book
{
  public: // Access Privileges: public allows us to access all variables associated with the class.
    std::string author, title, publisher, format;
    int price; //Given in pence
    int yearOfPublication;
}; //Note that the class ends with ;
