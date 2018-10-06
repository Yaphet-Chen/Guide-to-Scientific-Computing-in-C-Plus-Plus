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

#include <iostream>
class ComplexNumber
{
  private: // Prevent inadvertent corruption of these members
    double mRealPart;
    double mImaginaryPart;

  public:
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