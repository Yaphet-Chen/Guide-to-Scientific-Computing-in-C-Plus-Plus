/*---------------------------------------------------------------------------*\
 * @Brief       : Dynamic Allocation of Memory for Arrays
 * 
 * @File        : DynamicAllocation.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Date        : 2018-09-29
\*---------------------------------------------------------------------------*/

#include <iostream>

int main(int argc, char *argv[])
{
    /*++++++++++++++++++++++++++++++++++++ Vectors +++++++++++++++++++++++++++++++++++++++*/
    double *x;
    double *y;

    x = new double[10];
    y = new double[10];

    for (int i = 0; i < 10; i++)
    {
        x[i] = ((double)(i));
        y[i] = 2.0 * x[i];
    }

    std::cout << x << "\n";     // x stores the address of the first element of the array.
    std::cout << &x[0] << "\n"; // Prints the same value
    for (int i = 1; i < 10; i++)
    {
        std::cout << &x[i] << "\n";
    }

    delete[] x; // Always be sure to free any memory allocated when it is no longer required
    delete[] y;

    /*++++++++++++++++++++++++++++++++++++ Matrices +++++++++++++++++++++++++++++++++++++++*/
    int rows = 5, cols = 3;
    double **A;
    /* A is an array of pointers
    1. Each A[i] is a pointer, and contains the address of A[i][0]
    2. A contains the address of the pointer A[0] */
    A = new double *[rows];
    for (int i = 0; i < rows; i++)
    {
        A[i] = new double[cols]; // The matrix created is same as double A[5][3];
    }
    // Deallocate memory dynamically allocated for a matrix
    for (int i = 0; i < rows; i++)
    {
        delete[] A[i]; // Delete any memory dynamically allocated, particularly memory allocated inside loops
    }
    delete[] A;

    /*++++++++++++++++++++++++++++++++ Irregularly Sized Matrices +++++++++++++++++++++++++++++++++++*/
    int **B;
    B = new int *[1000];
    for (int i = 0; i < 1000; i++)
    {
        B[i] = new int[i + 1];
    }
    for (int i = 0; i < 1000; i++)
    {
        delete[] B[i];
    }
    delete[] B;

    return 0;
}