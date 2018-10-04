/*---------------------------------------------------------------------------*\
 * @File        : FunctionPointers.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : Function Pointers & Newton–Raphson method
 * @version 0.1
 * @Date        : 2018-10-04
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

#include <cmath>
#include <iostream>

double myFunction(double x);
double myOtherFunction(double x);

/*---------------------------------------------------------------------------*\
 * @Brief       : The Newton–Raphson method for solving nonlinear equations
 *                Note that the function as it stands does not check for divergence, so is unsafe to use in some cases.
 * 
 * @Param       : pFunc - a function pointer to the nonlinear function;
 * @Param       : pFuncPrime - a function pointer to the derivative of the nonlinear function; 
 * @Param       : x - an initial guess to the solution;
 * @Return      : double 
\*---------------------------------------------------------------------------*/
double SolveNewton(double (*pFunc)(double), double (*pFuncPrime)(double), double x)
{
    double step;
    do
    {
        step = (*pFunc)(x) / (*pFuncPrime)(x);
        x -= step;
    } while (fabs(step) > 1.0e-5);
    return x;
}

// Function to calculate x that satisfies sqrt(x)=10
double Sqrt10(double x)
{
    return sqrt(x) - 10.0;
}

// Derivative of function to calculate x that satisfies sqrt(x)=10
double Sqrt10Prime(double x)
{
    return 1.0 / (2.0 * sqrt(x));
}

// Function to calculate x that satisfies x*x*x=10
double Cube10(double x)
{
    return x * x * x - 10.0;
}

// Derivative of function to calculate x that satisfies x*x*x=10
double Cube10Prime(double x)
{
    return 3.0 * x * x;
}

int main(int argc, char *argv[])
{
    /* This declaration specifies that the function that this pointer refers to must:
    (i) accept one (and only one) input argument which is a double precision floating point variable;
    (ii) return one double precision floating point variable. */
    double (*p_function)(double x);

    p_function = &myFunction;
    std::cout << p_function(2.0) << "\n";

    p_function = &myOtherFunction;
    std::cout << p_function(2.0) << "\n";

    std::cout << "Root sqrt(x)=10, with guess 1.0 is "
              << SolveNewton(Sqrt10, Sqrt10Prime, 1.0) << "\n";
    std::cout << "Root x ** 3=10, with guess 1.0 is "
              << SolveNewton(Cube10, Cube10Prime, 1.0) << "\n";

    return 0;
}

double myFunction(double x)
{
    return x * x;
}

double myOtherFunction(double x)
{
    return x * x * x;
}
