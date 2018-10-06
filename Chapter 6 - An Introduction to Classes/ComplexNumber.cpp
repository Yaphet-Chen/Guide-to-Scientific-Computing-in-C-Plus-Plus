/*---------------------------------------------------------------------------*\
 * @File        : ComplexNumber.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : Operator Overloading
 * @version 0.1
 * @Date        : 2018-10-06
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

#include "ComplexNumber.hpp"
#include <cmath>

// Override default constructor
// Set real and imaginary parts to zero
ComplexNumber::ComplexNumber()
{
    mRealPart = 0.0;
    mImaginaryPart = 0.0;
}

// Constructor that sets complex number z=x+iy
ComplexNumber::ComplexNumber(double x, double y)
{
    mRealPart = x;
    mImaginaryPart = y;
}

/*---------------------------------------------------------------------------*\
 * @Brief       : Method for computing the modulus of a complex number
 *              1. The () indicates that no arguments are required since member methods can access all class members
 *              2. Reserved keyword const to ensure that class memebers are left unchanged
 * @Return      : double 
\*---------------------------------------------------------------------------*/
double ComplexNumber::CalculateModulus() const
{
    return sqrt(mRealPart * mRealPart + mImaginaryPart * mImaginaryPart);
}

// Method for computing the argument of a complex number
double ComplexNumber::CalculateArgument() const
{
    return atan2(mImaginaryPart, mRealPart);
}

// Method for raising complex number to the power n using De Moivre’s theorem
ComplexNumber ComplexNumber::CalculatePower(double n) const // Note that returned type is  ComplexNumber
{
    // Complex number must be converted to polar form first
    double modulus = CalculateModulus(); // Call methods from within the class.
    double argument = CalculateArgument();
    double mod_of_result = pow(modulus, n);
    double arg_of_result = argument * n;
    double real_part = mod_of_result * cos(arg_of_result);
    double imag_part = mod_of_result * sin(arg_of_result);
    ComplexNumber z(real_part, imag_part);
    return z;
}

/*---------------------------------------------------------------------------*\
 * @Brief       : Overloading the = (assignment) operator
 *                The argument is a reference with the const keyword, like copy constructor
 * @Param       : z 
 * @Return      : ComplexNumber& 
\*---------------------------------------------------------------------------*/
ComplexNumber &ComplexNumber::operator=(const ComplexNumber &z)
{
    mRealPart = z.mRealPart;
    mImaginaryPart = z.mImaginaryPart;
    /* Every object in C++ has access to its own address through a this pointer. Only member functions have a this pointer. */
    return *this; // Returning an object i.e., *this returns a reference to the object.
}

// Overloading the unary - operator
ComplexNumber ComplexNumber::operator-() const // The original complex number is left unchanged (through use of const)
{
    ComplexNumber w;
    w.mRealPart = mRealPart;
    w.mImaginaryPart = mImaginaryPart;
    return w;
}

/*---------------------------------------------------------------------------*\
 * @Brief       : Overloading the binary + operator
 * 
 * @Param       : z - is that to the right of the + operator, the class itself is the left operand. 
 * @Return      : ComplexNumber 
\*---------------------------------------------------------------------------*/
ComplexNumber ComplexNumber::operator+(const ComplexNumber &z) const
{
    ComplexNumber w;
    w.mRealPart = mRealPart + z.mRealPart;
    w.mImaginaryPart = mImaginaryPart + z.mImaginaryPart;
    return w;
}

// Overloading the binary - operator
ComplexNumber ComplexNumber::operator-(const ComplexNumber &z) const
{
    ComplexNumber w;
    w.mRealPart = mRealPart - z.mRealPart;
    w.mImaginaryPart = mImaginaryPart - z.mImaginaryPart;
    return w;
}

// Overloading the output stream insertion << operator
std::ostream &operator<<(std::ostream &output, const ComplexNumber &z) // External function, not member method
{
    // Format as "(a + bi)" or as "(a - bi)"
    output << "(" << z.mRealPart << " ";
    if (z.mImaginaryPart >= 0.0)
    {
        output << "+ " << z.mImaginaryPart << "i)";
    }
    else
    {
        // z.mImaginaryPart < 0.0
        // Replace + with minus sign
        output << "- " << -z.mImaginaryPart << "i)";
    }
}