/*---------------------------------------------------------------------------*\
 * @File        : BvpOde.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : Implementation of BvpOde
 * @version 0.1
 * @Date        : 2018-10-16
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include <cassert>
#include "BvpOde.hpp"

BvpOde::BvpOde(SecondOrderOde *pOde, BoundaryConditions *pBcs, int numNodes)
{
    mpOde = pOde;
    mpBconds = pBcs;

    mNumNodes = numNodes;
    mpGrid = new FiniteDifferenceGrid(mNumNodes, pOde->mXmin, pOde->mXmax);

    mpSolVec = new Vector(mNumNodes);
    mpRhsVec = new Vector(mNumNodes);
    mpLhsMat = new Matrix(mNumNodes, mNumNodes);

    mFilename = "ode_output.dat";
    mpLinearSystem = NULL;
}

BvpOde::~BvpOde()
{
    // Deletes memory allocated in constructor
    delete mpGrid;
    delete mpSolVec;
    delete mpRhsVec;
    delete mpLhsMat;

    // Only delete if Solve has been called
    if (mpLinearSystem)
    {
        delete mpLinearSystem;
    }
}

void BvpOde::Solve()
{
    PopulateMatrix();
    PopulateVector();
    ApplyBoundaryConditions();
    mpLinearSystem = new LinearSystem(*mpLhsMat, *mpRhsVec);

    *mpSolVec = mpLinearSystem->Solve();
    WriteSolutionFile();
}

void BvpOde::PopulateMatrix()
{
    for (int i = 1; i < mNumNodes - 1; i++)
    {
        // xm, x and xp are x(i-1), x(i) and x(i+1)
        double xm = mpGrid->mNodes[i - 1].coordinate;
        double x = mpGrid->mNodes[i].coordinate;
        double xp = mpGrid->mNodes[i + 1].coordinate;
        double alpha = 2.0 / (xp - xm) / (x - xm);
        double beta = -2.0 / (xp - x) / (x - xm);
        double gamma = 2.0 / (xp - xm) / (xp - x);
        (*mpLhsMat)(i + 1, i) = (mpOde->mCoeffOfUxx) * alpha - (mpOde->mCoeffOfUx) / (xp - xm);
        (*mpLhsMat)(i + 1, i + 1) = (mpOde->mCoeffOfUxx) * beta + mpOde->mCoeffOfU;
        (*mpLhsMat)(i + 1, i + 2) = (mpOde->mCoeffOfUxx) * gamma + (mpOde->mCoeffOfUx) / (xp - xm);
    }
}

void BvpOde::PopulateVector()
{
    for (int i = 1; i < mNumNodes - 1; i++)
    {
        double x = mpGrid->mNodes[i].coordinate;
        (*mpRhsVec)(i + 1) = mpOde->mpRhsFunc(x);
    }
}
void BvpOde::ApplyBoundaryConditions()
{
    bool left_bc_applied = false;
    bool right_bc_applied = false;
    if (mpBconds->mLhsBcIsDirichlet)
    {
        (*mpLhsMat)(1, 1) = 1.0;
        (*mpRhsVec)(1) = mpBconds->mLhsBcValue;
        left_bc_applied = true;
    }
    if (mpBconds->mRhsBcIsDirichlet)
    {
        (*mpLhsMat)(mNumNodes, mNumNodes) = 1.0;
        (*mpRhsVec)(mNumNodes) = mpBconds->mRhsBcValue;
        right_bc_applied = true;
    }
    if (mpBconds->mLhsBcIsNeumann)
    {
        assert(left_bc_applied == false);
        double h = mpGrid->mNodes[1].coordinate - mpGrid->mNodes[0].coordinate;
        (*mpLhsMat)(1, 1) = -1.0 / h;
        (*mpLhsMat)(1, 2) = 1.0 / h;
        (*mpRhsVec)(1) = mpBconds->mLhsBcValue;
        left_bc_applied = true;
    }
    if (mpBconds->mRhsBcIsNeumann)
    {
        assert(right_bc_applied == false);
        double h = mpGrid->mNodes[mNumNodes - 1].coordinate - mpGrid->mNodes[mNumNodes - 2].coordinate;
        (*mpLhsMat)(mNumNodes, mNumNodes - 1) = -1.0 / h;
        (*mpLhsMat)(mNumNodes, mNumNodes) = 1.0 / h;
        (*mpRhsVec)(mNumNodes) = mpBconds->mRhsBcValue;
        right_bc_applied = true;
    }

    // Check that boundary conditions have been applied on both boundaries
    assert(left_bc_applied);
    assert(right_bc_applied);
}

void BvpOde::WriteSolutionFile()
{
    std::ofstream output_file(mFilename.c_str());
    assert(output_file.is_open());
    for (int i = 0; i < mNumNodes; i++)
    {
        double x = mpGrid->mNodes[i].coordinate;
        output_file << x << " " << (*mpSolVec)(i + 1) << "\n";
    }
    output_file.flush();
    output_file.close();
    std::cout << "Solution written to " << mFilename << "\n";
}