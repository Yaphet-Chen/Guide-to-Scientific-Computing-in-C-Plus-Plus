/*---------------------------------------------------------------------------*\
 * @File        : Vector.hpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : Declaration of Vector class
 * @version 0.1
 * @Date        : 2018-10-14
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

#ifndef VECTORHEADERDEF
#define VECTORHEADERDEF

#include <iostream>
/* The Vector and Matrix classes will include
 * 1. Constructors and destructors that handle memory management.
 * 2. Overload the assignment, addition, subtraction and multiplication operators, including checks that the vectors and matrices are of the correct size, which allow us to write code such as “u = A * v;” 
 * 3. The square bracket operator will be overloaded to provide a check that the index of the array lies within the correct range
 * 4. The round bracket operator will be overloaded to allow the entries of the vector or matrix to be accessed using MATLAB style notation, indexing from 1 rather than from zero.
 **/

class Vector
{
private:
  double *mData; // Data stored in vector
  int mSize;     // Size of vector, not allow the user to change this variable through any method

public:
  Vector(); // Non-implemented default constructor to avoid implicitly constructed
  Vector(const Vector &otherVector);
  Vector(int size);
  ~Vector();
  int GetSize() const;
  void SetUniRand(double lower, double upper);                            // Set uniform random entities
  double &operator[](int i);                                              // Zero-based indexing
  double Read(int i) const;                                               // Read-only zero-based indexing
  double &operator()(int i);                                              // One-based indexing
  Vector &operator=(const Vector &otherVector);                           // Assignment
  Vector operator+() const;                                               // Unary +
  Vector operator-() const;                                               // Unary -
  Vector operator+(const Vector &v1) const;                               // Binary +
  Vector operator-(const Vector &v1) const;                               // Binary -
  Vector operator*(double a) const;                                       // Scalar multiplication
  double CalculateNorm(double p = 2.0) const;                             // P-norm method (with default value p=2)
  friend int length(const Vector &v);                                     // Declare length function as a friend
  friend std::ostream &operator<<(std::ostream &output, const Vector &v); // Insertion <<
};

// Prototype signature of friend function
int length(const Vector &v);
std::ostream &operator<<(std::ostream &output, const Vector &v);

#endif