/*---------------------------------------------------------------------------*\
 * @File        : AbstractOdeSolver.hpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : The Abstract Class Pattern
 *                Abstract class: if it contains one or more pure virtual methods.
 *                                Should we mistakenly attempt to create an instance of
 *                                the abstract class we would get a compilation error.
 *                Pure virtual function: completing the declaration of virtual function with = 0
 * @version 0.1
 * @Date        : 2018-10-09
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

#ifndef ABSTRACTODESOLVERDEF
#define ABSTRACTODESOLVERDEF

class AbstractOdeSolver
{
  private:
    double stepSize;
    double initialTime;
    double finalTime;
    double initialValue;

  public:
    void SetStepSize(double h);
    void SetTimeInterval(double t0, double t1);
    void SetInitialValue(double y0);
    virtual double RightHandSide(double y, double t) = 0;
    /* The numerical methods in a class derived from AbstractOdeSolver, will
    be implemented by overriding the virtual function SolveEquation.*/
    virtual double SolveEquation() = 0;
};

#endif