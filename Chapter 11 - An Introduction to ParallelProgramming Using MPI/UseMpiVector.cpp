/*---------------------------------------------------------------------------*\
 * @File        : UseMpiVector.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : Test MpiVector Class
 * @version 0.1
 * @Date        : 2018-10-15
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

#include <iostream>
#include <mpi.h>
#include "MpiVector.hpp"

int main(int argc, char *argv[])
{
    MPI::Init(argc, argv);
    MpiVector all_ones(9);
    std::cout << "Local has [" << all_ones.GetLo() << ", " << all_ones.GetHi() << ")\n";
    for (int i = all_ones.GetLo(); i < all_ones.GetHi(); i++)
    {
        all_ones[i] = 1.0;
    }
    assert(fabs(all_ones.CalculateNorm() - 3.0) < 1.0e-6);
    all_ones.UpdateGlobal();
    MPI::Finalize();
    return 0;
}