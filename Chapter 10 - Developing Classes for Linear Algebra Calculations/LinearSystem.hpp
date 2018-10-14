/*---------------------------------------------------------------------------*\
 * @File        : LinearSystem.hpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : Declaration of LinearSystem class
 * @version 0.1
 * @Date        : 2018-10-14
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

#ifndef LINEARSYSTEMHEADERDEF
#define LINEARSYSTEMHEADERDEF

#include "Vector.hpp"
#include "Matrix.hpp"

class LinearSystem
{
private:
  int mSize;   // Size of linear system
  Matrix *mpA; // Matrix for linear system
  Vector *mpb; // Vector for linear system
  // Only allow constructor that specifies matrix and vector to be used. Copy constructor is private.
  LinearSystem(const LinearSystem &otherLinearSystem){};

public:
  LinearSystem(); // Non-implemented default constructor to avoid implicitly constructed
  LinearSystem(const Matrix &A, const Vector &b);
  ~LinearSystem();        // Destructor frees memory allocated
  virtual Vector Solve(); // Method for solving system
};

#endif