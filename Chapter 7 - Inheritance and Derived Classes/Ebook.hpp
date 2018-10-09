/*---------------------------------------------------------------------------*\
 * @File        : Ebook.hpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : Inheritance, Extensibility and Polymorphism
 * @version 0.1
 * @Date        : 2018-10-09
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

/*********************** Inheritance, Extensibility and Polymorphism ************************
 * Inheritance: allows us to extend the functionality of a class by introducing a new class (derived class),
 *              that contains all the features of the original class (base class, parentclass).
 * Multiple inheritance: derived classes may inherit from more than one base class.
 * Extensibility: the code can be extended easily, and without changing any of the original functional behaviour
 *                of the base class.
 * Polymorphism: the ability to perform the same operations on a wide variety of different types of objects.
 * Dynamic polymorphism :(run-time polymorphism) At run-time, the program is able to decide which object it has
 *                      and therefore which type of Solve to run.
 **/

#ifndef EBOOKHEADERDEF
#define EBOOKHEADERDEF

#include <string>
#include "../Chapter 6 - An Introduction to Classes/Book.hpp"

/********* Access privileges for derived classes *********
 * ╔══════════════════╦═════════════════════════════════╗
 * ║ Access privilege ║ Type of inheritance             ║
 * ║ in base class    ╠═══════════╦═══════════╦═════════╣
 * ║                  ║ Public    ║ Protected ║ Private ║
 * ╠══════════════════╬═══════════╬═══════════╬═════════╣
 * ║ Public           ║ Public    ║ Protected ║ Private ║
 * ╠══════════════════╬═══════════╬═══════════╬═════════╣
 * ║ Protected        ║ Protected ║ Protected ║ Private ║
 * ╠══════════════════╬═══════════╬═══════════╬═════════╣
 * ║ Private          ║ Hidden    ║ Hidden    ║ Hidden  ║
 * ╚══════════════════╩═══════════╩═══════════╩═════════╝
 **/

class Ebook : public Book
{
public:
  Ebook();
  std::string hiddenUrl;
};

/* Note the syntax for overridden default constructors below:
 * this allows the default constructor for the base class Book to be called first
 **/
Ebook::Ebook() : Book()
{
  format = "electronic";
}

#endif