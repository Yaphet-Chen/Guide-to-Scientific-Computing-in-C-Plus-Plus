/*---------------------------------------------------------------------------*\
 * @File        : BoundaryConditions.hpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : Specity Boundary Conditions
 * @version 0.1
 * @Date        : 2018-10-15
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

#ifndef BOUNDARYCONDITIONSHEADERDEF
#define BOUNDARYCONDITIONSHEADERDEF

class BoundaryConditions
{
  public:
    friend class BvpOde;

  private:
    bool mLhsBcIsDirichlet;
    bool mRhsBcIsDirichlet;
    bool mLhsBcIsNeumann;
    bool mRhsBcIsNeumann;
    double mLhsBcValue;
    double mRhsBcValue;

  public:
    BoundaryConditions();
    void SetLhsDirichletBc(double lhsValue);
    void SetRhsDirichletBc(double rhsValue);
    void SetLhsNeumannBc(double lhsDerivValue);
    void SetRhsNeumannBc(double rhsDerivValue);
};

#endif