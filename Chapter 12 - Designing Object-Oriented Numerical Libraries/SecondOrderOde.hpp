/*---------------------------------------------------------------------------*\
 * @File        : SecondOrderOde.hpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : Specify the ordinary differential equation
 *                1. specify the coefficients on the left-hand side
 *                2. the function on the right-hand side
 *                3. the interval on which the equation is valid
 * @version 0.1
 * @Date        : 2018-10-15
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

#ifndef SECONDORDERODEHEADERDEF
#define SECONDORDERODEHEADERDEF

class SecondOrderOde
{
    // The boundary value ODE class is able to access the coefficients etc. of this equation
    friend class BvpOde;

  private:
    // Coefficients on LHS of ODE
    double mCoeffOfUxx;
    double mCoeffOfUx;
    double mCoeffOfU;
    // Function on RHS of ODE
    double (*mpRhsFunc)(double x);

    // Interval for domain
    double mXmin;
    double mXmax;

  public:
    SecondOrderOde(double coeffUxx, double coeffUx, double coeffU,
                   double (*righthandSide)(double), double xMinimum, double xMaximum)
    {
        mCoeffOfUxx = coeffUxx;
        mCoeffOfUx = coeffUx;
        mCoeffOfU = coeffU;
        mpRhsFunc = righthandSide;
        mXmin = xMinimum;
        mXmax = xMaximum;
    }
};

#endif