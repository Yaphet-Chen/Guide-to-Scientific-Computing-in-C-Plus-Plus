/*---------------------------------------------------------------------------*\
 * @File        : Matrix.hpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : Declaration of Matrix class
 * @version 0.1
 * @Date        : 2018-10-14
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

#ifndef MATRIXHEADERDEF
#define MATRIXHEADERDEF

#include <iostream>
#include "Vector.hpp"

class Matrix
{
private:
  double **mData;         // Entries of matrix
  int mNumRows, mNumCols; // Dimensions

public:
  Matrix(); // Non-implemented default constructor to avoid implicitly constructed
  Matrix(const Matrix &otherMatrix);
  Matrix(int numRows, int numCols);
  ~Matrix();
  void SetUniRand(double lower, double upper);
  int GetNumberOfRows() const;
  int GetNumberOfColumns() const;
  double &operator()(int i, int j);             // One-based indexing
  Matrix &operator=(const Matrix &otherMatrix); // Overloaded assignment operator
  Matrix operator+() const;                     // Unary +
  Matrix operator-() const;                     // Unary -
  Matrix operator+(const Matrix &m1) const;     // Binary +
  Matrix operator-(const Matrix &m1) const;     // Binary -
  Matrix operator*(double a) const;             // Scalar multiplication
  double CalculateDeterminant() const;
  // Declare vector multiplication friendship
  friend Vector operator*(const Matrix &m, const Vector &v);
  friend Vector operator*(const Vector &v, const Matrix &m);
  friend std::ostream &operator<<(std::ostream &output, const Matrix &mat); // Insertion <<
};

// Prototype signatures for friend operators
Vector operator*(const Matrix &m, const Vector &v);
Vector operator*(const Vector &v, const Matrix &m);
std::ostream &operator<<(std::ostream &output, const Matrix &mat);

#endif