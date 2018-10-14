/*---------------------------------------------------------------------------*\
 * @File        : Vector.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : Implementation of Vector class
 * @version 0.1
 * @Date        : 2018-10-14
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

#include <cmath>
#include <iostream>
#include <cassert>
#include <random>
#include "Vector.hpp"

/*---------------------------------------------------------------------------*\
 * @Brief       : Overridden copy constructor
 *                Allocates memory for new vector, and copies entries of other vector into it.
 *                The automatically generated copy constructor would not allocate any memory
 *                for the new copy of the data, and what actually happen is that the pointer mData
 *                in the original vector u would be assigned to the pointer mData in the new vector v.
 *                Moreover, both vectors would attempt to de-allocate it (by calling delete in their
 *                destructor) when they went out of scope.
 * @Param       : otherVector 
\*---------------------------------------------------------------------------*/
Vector::Vector(const Vector &otherVector)
{
    mSize = otherVector.GetSize();
    mData = new double[mSize];
    for (int i = 0; i < mSize; i++)
    {
        mData[i] = otherVector.mData[i];
    }
}

/*---------------------------------------------------------------------------*\
 * @Brief       : Constructor for vector of a given size
 *                Allocates memory, and initialises entries to zero
 *                The default constructor takes no arguments, and cannot allocate an appropriate size to the vector,
 *                and so we ensure the automatically generated default constructor is never used by
 *                supplying an alternative specialised constructor.
 * @Param       : size 
\*---------------------------------------------------------------------------*/
Vector::Vector(int size)
{
    assert(size > 0);
    mSize = size;
    mData = new double[mSize];
    for (int i = 0; i < mSize; i++)
    {
        mData[i] = 0.0;
    }
}

// Overridden destructor to correctly free memory
Vector::~Vector()
{
    delete[] mData; // Every new statement was matched by a delete statement
}

// Method to get the size of a vector
int Vector::GetSize() const
{
    return mSize;
}

// Set entities from uniform random distribution
void Vector::SetUniRand(double lower, double upper)
{
    assert(lower < upper);
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(lower, upper);
    for (int i = 0; i < mSize; i++)
    {
        mData[i] = distribution(generator);
    }
}

/*---------------------------------------------------------------------------*\
 * @Brief       : Overloading square brackets
 *                Note that this uses ‘zero-based’ indexing, and overloading allow us to
 *                check that the index falls within the correct range
 * @Param       : i 
 * @Return      : double& 
\*---------------------------------------------------------------------------*/
double &Vector::operator[](int i)
{
    assert(i > -1);
    assert(i < mSize);
    return mData[i];
}

/*---------------------------------------------------------------------------*\
 * @Brief       : Read-only variant of []
 *                Note that this uses ‘zero-based’ indexing, and a check on the validity of the index
 * @Param       : i 
 * @Return      : double 
\*---------------------------------------------------------------------------*/
double Vector::Read(int i) const
{
    assert(i > -1);
    assert(i < mSize);
    return mData[i];
}

/*---------------------------------------------------------------------------*\
 * @Brief       : Overloading round brackets
 *                Note that this uses ‘one-based’ indexing, and a check on the validity of the index
 * @Param       : i 
 * @Return      : double& 
\*---------------------------------------------------------------------------*/
double &Vector::operator()(int i)
{
    assert(i > 0);
    assert(i < mSize + 1);
    return mData[i - 1];
}

// Overloading the assignment operator
Vector &Vector::operator=(const Vector &otherVector)
{
    assert(mSize == otherVector.mSize);
    for (int i = 0; i < mSize; i++)
    {
        mData[i] = otherVector.mData[i];
    }
    return *this;
}

// Overloading the unary + operator
Vector Vector::operator+() const
{
    Vector v(mSize);
    for (int i = 0; i < mSize; i++)
    {
        v[i] = mData[i];
    }
    return v;
}

// Overloading the unary - operator
Vector Vector::operator-() const
{
    Vector v(mSize);
    for (int i = 0; i < mSize; i++)
    {
        v[i] = -mData[i];
    }
    return v;
}

// Overloading the binary + operator
Vector Vector::operator+(const Vector &v1) const

{
    assert(mSize == v1.mSize);
    Vector v(mSize);
    for (int i = 0; i < mSize; i++)
    {
        v[i] = mData[i] + v1.mData[i];
    }
    return v;
}

// Overloading the binary - operator
Vector Vector::operator-(const Vector &v1) const
{
    assert(mSize == v1.mSize);
    Vector v(mSize);
    for (int i = 0; i < mSize; i++)
    {
        v[i] = mData[i] - v1.mData[i];
    }
    return v;
}

// Overloading scalar multiplication
Vector Vector::operator*(double a) const
{
    Vector v(mSize);
    for (int i = 0; i < mSize; i++)
    {
        v[i] = a * mData[i];
    }
    return v;
}

// Method to calculate norm (with default value p=2.0) corresponding to the Euclidean norm
double Vector::CalculateNorm(double p) const
{
    double norm_val, sum = 0.0;
    for (int i = 0; i < mSize; i++)
    {
        sum += pow(fabs(mData[i]), p);
    }
    norm_val = pow(sum, 1.0 / p);
    return norm_val;
}

// Fortran and MATLAB style friend to get the size of a vector
int length(const Vector &v)
{
    return v.mSize;
}

// Overloading the output stream insertion << operator
std::ostream &operator<<(std::ostream &output, const Vector &v)
{
    for (int i = 0; i < v.mSize; i++)
    {
        output << v.mData[i] << std::endl;
    }
    return output;
}