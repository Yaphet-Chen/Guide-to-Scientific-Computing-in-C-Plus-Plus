/*---------------------------------------------------------------------------*\
 * @File        : ArraysFunctions.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : Send arrays to functions
 * @version 0.1
 * @Date        : 2018-10-03
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

#include <iostream>
#include <cmath>

/* Note that we do not have to specify the size of the first index of an array in
the function prototype. This size is computed by the compiler. It may be included
if desired, but this will be ignored when the code is compiled. */
void DoSomething1(double u[], double A[][10], double B[10][10]); // Send arrays whose size is known at compile time
void DoSomething2(double *u, double **A);                        // Arrays whose size has been dynamically allocated

int main(int argc, char *argv[])
{
    double u1[5], A1[10][10], B1[10][10];

    DoSomething1(u1, A1, B1);

    // This will print the values allocated in the function DoSomething1
    std::cout << u1[2] << "\n";
    std::cout << A1[2][3] << "\n";
    std::cout << B1[3][3] << "\n";

    double *u2 = new double[10];
    double **A2 = new double *[10];
    for (int i = 0; i < 10; i++)
    {
        A2[i] = new double[10];
    }

    DoSomething2(u2, A2);

    // This will print the values allocated in the function DoSomething2
    std::cout << u2[2] << "\n";
    std::cout << A2[2][3] << "\n";

    delete[] u2;
    for (int i = 0; i < 10; i++)
    {
        delete[] A2[i];
    }
    delete[] A2;

    return 0;
}

void DoSomething1(double u[], double A[][10], double B[10][10])
{
    u[2] = 1.0;
    A[2][3] = 4.0;
    B[3][3] = -90.6;
}

void DoSomething2(double *u, double **A)
{
    u[2] = 2.0;
    A[2][3] = 5.0;
}