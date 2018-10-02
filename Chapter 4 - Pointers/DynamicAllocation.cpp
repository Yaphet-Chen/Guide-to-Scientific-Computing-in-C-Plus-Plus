/*---------------------------------------------------------------------------*\
 * @Brief       : Dynamic Allocation of Memory for Arrays & Tips: Pointers
 * 
 * @File        : DynamicAllocation.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Date        : 2018-09-29
\*---------------------------------------------------------------------------*/

#include <iostream>
#include <cassert>

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
    int N = 1000; // Matrix size
    B = new int *[N];
    /*++++++++++++++++++++++++++++++++ Tip 2: Safe Dynamic Allocation +++++++++++++++++++++++++++++++*/
    /* There may be circumstancesunder which it is not possible to allocate memory
    1. The number of items in an array has been set with a negative argument
    2. There is not enough physical memory available to the program.
    Setting the number of elements in an array to a negative number is easier than you might think.
    1. If the size of a problem is configured via an input file, then a size may easily be mistyped.
    2. overflow error: If a number is assigned to an integer that is larger than the maximum value that
    can be stored by that integer, then the integer value stored may actually be a negative number.
    The default behaviour is to throw an exception when a memory error is encountered and an exception could terminate your program. */
    assert(B != NULL);
    for (int i = 0; i < N; i++)
    {
        B[i] = new int[i + 1];
        assert(B[i] != NULL);
    }

    /*+++++++++++++++++++++++++++++ Tip 3: Every new Has a delete ++++++++++++++++++++++++++++++++++++*/
    /* There is no automatic garbage collection for memory which is no longer accessible. The problem
    may arise when memory is allocated inside functions, but not freed before the function ends.
    There are several ways around this issue. 
    1. Ensure that every new in your program is matched with a delete somewhere else.
    2. Make sure that inaccessible or unnecessary memory is freed up is to run your program through a memory debugger.
    3. Use shared pointers. These are an advanced language feature which allow memory to be automatically de-allocated
    once there is no longer any other part of the program which can access it. */
    for (int i = 0; i < N; i++)
    {
        delete[] B[i];
    }
    delete[] B;

    return 0;
}