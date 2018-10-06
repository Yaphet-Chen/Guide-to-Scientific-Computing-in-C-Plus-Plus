/*---------------------------------------------------------------------------*\
 * @File        : ComplexNumber.hpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : Operator Overloading
 * @version 0.1
 * @Date        : 2018-10-06
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

#ifndef COMPLEXNUMBERHEADERDEF
#define COMPLEXNUMBERHEADERDEF

/* Class names are also in camel-case (as are function names) */
#include <iostream>
class ComplexNumber
{
  private: // Prevent inadvertent corruption of these members
  /* Class data which have access controls are also in camel-case with “m” (for “my”) to denote “private” or “protected”. */
    double mRealPart;
    double mImaginaryPart;

  public:
    /************************************** Coding standard rules ********************************************
    Function names are in camel-case and the first word is a verb, to indicate what it is that they do.
    Names of arguments to functions (and class methods) are in also camel-case, but they begin in lower-case.
    The same format is also applied to member data of classes, class methods as well as to regular functions. */
    ComplexNumber();
    ComplexNumber(double x, double y);
    double CalculateModulus() const;
    double CalculateArgument() const;
    ComplexNumber CalculatePower(double n) const;
    ComplexNumber &operator=(const ComplexNumber &z);
    ComplexNumber operator-() const;
    ComplexNumber operator+(const ComplexNumber &z) const;
    ComplexNumber operator-(const ComplexNumber &z) const;
    friend std::ostream &operator<<(std::ostream &output, const ComplexNumber &z); // External function, not member method
};

#endif