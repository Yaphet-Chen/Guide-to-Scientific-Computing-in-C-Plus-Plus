/*---------------------------------------------------------------------------*\
 * @File        : Matrix.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : Implementation of Matrix class
 * @version 0.1
 * @Date        : 2018-10-14
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

#include <cmath>
#include <cassert>
#include <random>
#include <iostream>
#include <iomanip>
#include "Matrix.hpp"
#include "Vector.hpp"

/*---------------------------------------------------------------------------*\
 * @Brief       : Overwritten copy constructor
 *                Allocate memory for new matrix, and copy entries into this matrix
 * @Param       : otherMatrix 
\*---------------------------------------------------------------------------*/
Matrix::Matrix(const Matrix &otherMatrix)
{
    mNumRows = otherMatrix.mNumRows;
    mNumCols = otherMatrix.mNumCols;
    mData = new double *[mNumRows];
    for (int i = 0; i < mNumRows; i++)
    {
        mData[i] = new double[mNumCols];
    }
    for (int i = 0; i < mNumRows; i++)
    {
        for (int j = 0; j < mNumCols; j++)
        {
            mData[i][j] = otherMatrix.mData[i][j];
        }
    }
}

/*---------------------------------------------------------------------------*\
 * @Brief       : Construct a new Matrix
 *                Allocates memory, and initialises entries to zero
 * @Param       : numRows 
 * @Param       : numCols 
\*---------------------------------------------------------------------------*/
Matrix::Matrix(int numRows, int numCols)
{
    assert(numRows > 0);
    assert(numCols > 0);
    mNumRows = numRows;
    mNumCols = numCols;
    mData = new double *[mNumRows];
    for (int i = 0; i < mNumRows; i++)
    {
        mData[i] = new double[mNumCols];
    }
    for (int i = 0; i < mNumRows; i++)
    {
        for (int j = 0; j < mNumCols; j++)
        {
            mData[i][j] = 0.0;
        }
    }
}

// Overwritten destructor to correctly free memory
Matrix::~Matrix()
{
    for (int i = 0; i < mNumRows; i++)
    {
        delete[] mData[i];
    }
    delete[] mData;
}

// Set entities from uniform random distribution
void Matrix::SetUniRand(double lower, double upper)
{
    assert(lower < upper);
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(lower, upper);
    for (int i = 0; i < mNumRows; i++)
    {
        for (int j = 0; j < mNumCols; j++)
        {
            mData[i][j] = distribution(generator);
        }
    }
}

// Method to get number of rows of matrix
int Matrix::GetNumberOfRows() const
{
    return mNumRows;
}

// Method to get number of columns of matrix
int Matrix::GetNumberOfColumns() const
{
    return mNumCols;
}

/*---------------------------------------------------------------------------*\
 * @Brief       : Overloading the round brackets
 *                Note that this uses ‘one-based’ indexing, and a check on the validity of the index
 * @Param       : i 
 * @Param       : j 
 * @Return      : double& 
\*---------------------------------------------------------------------------*/
double &Matrix::operator()(int i, int j)
{
    assert(i > 0);
    assert(i < mNumRows + 1);
    assert(j > 0);
    assert(j < mNumCols + 1);
    return mData[i - 1][j - 1];
}

// Overloading the assignment operator
Matrix &Matrix::operator=(const Matrix &otherMatrix)
{
    assert(mNumRows = otherMatrix.mNumRows);
    assert(mNumCols = otherMatrix.mNumCols);
    for (int i = 0; i < mNumRows; i++)
    {
        for (int j = 0; j < mNumCols; j++)
        {
            mData[i][j] = otherMatrix.mData[i][j];
        }
    }
    return *this;
}

// Overloading the unary + operator
Matrix Matrix::operator+() const
{
    Matrix mat(mNumRows, mNumCols);
    for (int i = 0; i < mNumRows; i++)
    {
        for (int j = 0; j < mNumCols; j++)
        {
            mat(i + 1, j + 1) = mData[i][j];
        }
    }
    return mat;
}

// Overloading the unary - operator
Matrix Matrix::operator-() const
{
    Matrix mat(mNumRows, mNumCols);
    for (int i = 0; i < mNumRows; i++)
    {
        for (int j = 0; j < mNumCols; j++)
        {
            mat(i + 1, j + 1) = -mData[i][j];
        }
    }
    return mat;
}

// Overloading the binary + operator
Matrix Matrix::operator+(const Matrix &m1) const
{
    assert(mNumRows == m1.mNumRows);
    assert(mNumCols == m1.mNumCols);
    Matrix mat(mNumRows, mNumCols);
    for (int i = 0; i < mNumRows; i++)
    {
        for (int j = 0; j < mNumCols; j++)
        {
            mat(i + 1, j + 1) = mData[i][j] + m1.mData[i][j];
        }
    }
    return mat;
}

// Overloading the binary - operator
Matrix Matrix::operator-(const Matrix &m1) const
{
    assert(mNumRows == m1.mNumRows);
    assert(mNumCols == m1.mNumCols);
    Matrix mat(mNumRows, mNumCols);
    for (int i = 0; i < mNumRows; i++)
    {
        for (int j = 0; j < mNumCols; j++)
        {
            mat(i + 1, j + 1) = mData[i][j] - m1.mData[i][j];
        }
    }
    return mat;
}

// Overloading scalar multiplication
Matrix Matrix::operator*(double a) const
{
    Matrix mat(mNumRows, mNumCols);
    for (int i = 0; i < mNumRows; i++)
    {
        for (int j = 0; j < mNumCols; j++)
        {
            mat(i + 1, j + 1) = a * mData[i][j];
        }
    }
    return mat;
}

// Overloading matrix multiplied by a vector
Vector operator*(const Matrix &m, const Vector &v)
{
    int original_vector_size = v.GetSize();
    assert(m.GetNumberOfColumns() == original_vector_size);
    int new_vector_length = m.GetNumberOfRows();
    Vector new_vector(new_vector_length);

    for (int i = 0; i < new_vector_length; i++)
    {
        for (int j = 0; j < original_vector_size; j++)
        {
            new_vector[i] += m.mData[i][j] * v.Read(j);
        }
    }

    return new_vector;
}

// Overloading vector multiplied by a matrix
Vector operator*(const Vector &v, const Matrix &m)
{
    int original_vector_size = v.GetSize();
    assert(m.GetNumberOfRows() == original_vector_size);
    int new_vector_length = m.GetNumberOfColumns();
    Vector new_vector(new_vector_length);

    for (int i = 0; i < new_vector_length; i++)
    {
        for (int j = 0; j < original_vector_size; j++)
        {
            new_vector[i] += v.Read(j) * m.mData[j][i];
        }
    }

    return new_vector;
}

// Calculate determinant of square matrix recursively
double Matrix::CalculateDeterminant() const
{
    assert(mNumRows == mNumCols);
    double determinant = 0.0;

    if (mNumRows == 1)
    {
        determinant = mData[0][0];
    }
    else
    {
        // More than one entry of matrix
        for (int i_outer = 0; i_outer < mNumRows; i_outer++)
        {
            Matrix sub_matrix(mNumRows - 1, mNumRows - 1);
            for (int i = 0; i < mNumRows - 1; i++)
            {
                for (int j = 0; j < i_outer; j++)
                {
                    sub_matrix(i + 1, j + 1) = mData[i + 1][j];
                }
                for (int j = i_outer; j < mNumRows - 1; j++)
                {
                    sub_matrix(i + 1, j + 1) = mData[i + 1][j + 1];
                }
            }
            double sub_matrix_determinant = sub_matrix.CalculateDeterminant();
            determinant += pow(-1.0, i_outer) * mData[0][i_outer] * sub_matrix_determinant;
        }
    }
    return determinant;
}

// Overloading the output stream insertion << operator
std::ostream &operator<<(std::ostream &output, const Matrix &mat)
{
    for (int i = 0; i < mat.mNumRows; i++)
    {
        for (int j = 0; j < mat.mNumCols; j++)
        {
            output << "\t" << std::setw(8) << mat.mData[i][j];
        }
        output << std::endl;
    }
    return output;
}