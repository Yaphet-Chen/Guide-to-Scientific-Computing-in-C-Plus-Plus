/*---------------------------------------------------------------------------*\
 * @File        : BoundaryConditions.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : Implementation of Boundary Conditions class
 * @version 0.1
 * @Date        : 2018-10-15
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/
#include <cassert>
#include "BoundaryConditions.hpp"

// The default constructor should be overridden to set these variables to the value “false” in the absence of any other instruction.
BoundaryConditions::BoundaryConditions()
{
    mLhsBcIsDirichlet = false;
    mRhsBcIsDirichlet = false;
    mLhsBcIsNeumann = false;
    mRhsBcIsNeumann = false;
}

void BoundaryConditions::SetLhsDirichletBc(double lhsValue)
{
    assert(!mLhsBcIsNeumann);
    mLhsBcIsDirichlet = true;
    mLhsBcValue = lhsValue;
}

void BoundaryConditions::SetRhsDirichletBc(double rhsValue)
{
    assert(!mRhsBcIsNeumann);
    mRhsBcIsDirichlet = true;
    mRhsBcValue = rhsValue;
}

void BoundaryConditions::SetLhsNeumannBc(double lhsDerivValue)
{
    assert(!mLhsBcIsDirichlet);
    mLhsBcIsNeumann = true;
    mLhsBcValue = lhsDerivValue;
}

void BoundaryConditions::SetRhsNeumannBc(double rhsDerivValue)
{
    assert(!mRhsBcIsDirichlet);
    mRhsBcIsNeumann = true;
    mRhsBcValue = rhsDerivValue;
}