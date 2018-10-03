/*---------------------------------------------------------------------------*\
 * @File        : FunctionWithPointers.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : 1. Returning Pointer Variables from a Function
 *                2. Use of Pointers as Function Arguments
 * @version 0.1
 * @Date        : 2018-10-03
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

#include <iostream>
#include <cmath>

double **AllocateMatrixMemory(int numRows, int numCols); // Returning Pointer Variables from a Function
void FreeMatrixMemory(int numRows, double **matrix);
void CalculateRealAndImaginary(double r, double theta, double *pReal, double *pImaginary); // Use of Pointers as Function Arguments

int main(int argc, char *argv[])
{
    double **A;
    A = AllocateMatrixMemory(5, 3);
    A[0][1] = 2.0;
    A[4][2] = 4.0;
    FreeMatrixMemory(5, A);

    double r = 3.4;
    double theta = 1.23;
    double x, y;
    CalculateRealAndImaginary(r, theta, &x, &y);
    std::cout << "Real part = " << x << "\n";
    std::cout << "Imaginary part = " << y << "\n";
    std::cout << "Address of x: " << &x << "\n";
    std::cout << "Address of y: " << &y << "\n";

    return 0;
}

// Function to allocate memory for a matrix dynamically
double **AllocateMatrixMemory(int numRows, int numCols)
{
    double **matrix;
    matrix = new double *[numRows];
    for (int i = 0; i < numRows; i++)
    {
        matrix[i] = new double[numCols];
    }
    return matrix;
}

// Function to free memory of a matrix
void FreeMatrixMemory(int numRows, double **matrix)
{
    for (int i = 0; i < numRows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void CalculateRealAndImaginary(double r, double theta, double *pReal, double *pImaginary)
{
    /* We can change the contents of the variable without changing the address through
    de-referencing the pointer, and this will have an effect outside of the function.*/
    *pReal = r * cos(theta);
    *pImaginary = r * sin(theta);

    // Changes to these addresses will not have any effect outside the function as we are working with a copy of these addresses.
    pReal = pImaginary;
    std::cout << "Address of x inside CalculateRealAndImaginary: " << pReal << "\n";
}