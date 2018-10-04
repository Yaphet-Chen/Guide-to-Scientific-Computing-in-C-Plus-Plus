/*---------------------------------------------------------------------------*\
 * @File        : DefaultFunctionArguments.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : Default Values for Function Arguments
 * @version 0.1
 * @Date        : 2018-10-04
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

#include <cmath>
#include <iostream>

// Sets a default tolerance for the solution, and a default maximum number of iterations.
void CalculateCubeRoot(double &x, double K, double tolerance = 1.0e-6, int maxIterations = 100);
int main(int argc, char *argv[])
{
    double x = 1.0;
    double K = 12.0;

    // Calculate cube root using default values
    CalculateCubeRoot(x, K);

    // Calculate cube root using a tolerance of 0.001 and the
    // default maximum number of iterations
    double tolerance = 0.001;
    CalculateCubeRoot(x, K, tolerance);

    // Calculate cube root using a tolerance of 0.001 and a
    // maximum number of iterations of 50
    int maxIterations = 50;
    CalculateCubeRoot(x, K, tolerance, maxIterations);

    return 0;
}

/*---------------------------------------------------------------------------*\
 * @Brief       : Uses the Newton–Raphson technique for calculating the cube root of a given number K
 * 
 * @Param       : x - Cube root
 * @Param       : K 
 * @Param       : tolerance - default 1.0e-6
 * @Param       : maxIterations - default 100
\*---------------------------------------------------------------------------*/
void CalculateCubeRoot(double &x, double K, double tolerance, int maxIterations)
{
    int iterations = 0;
    double residual = x * x * x - K;
    while ((fabs(residual) > tolerance) && (iterations < maxIterations))
    {
        x = x - (pow(x, 3.0) - K) / (3.0 * pow(x, 2.0));
        residual = x * x * x - K;
        iterations++;
    }
    std::cout << "the cube root of K = " << K << " is " << x << "\n";
}