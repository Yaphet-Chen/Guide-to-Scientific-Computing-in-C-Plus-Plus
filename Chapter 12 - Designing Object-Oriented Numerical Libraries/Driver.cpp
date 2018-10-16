/*---------------------------------------------------------------------------*\
 * @File        : Driver.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : Testing model problems 1&2
 * @version 0.1
 * @Date        : 2018-10-16
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

#include <cmath>
#include <string>
#include "BvpOde.hpp"

double model_prob_1_rhs(double x) { return -1.0; }
double model_prob_2_rhs(double x) { return 34.0 * sin(x); }

int main(int argc, char *argv[])
{
    SecondOrderOde ode_mp1(1.0, 0.0, 0.0, model_prob_1_rhs, 0.0, 1.0);
    BoundaryConditions bc_mp1;
    bc_mp1.SetLhsDirichletBc(0.0);
    bc_mp1.SetRhsDirichletBc(0.0);
    BvpOde bvpode_mp1(&ode_mp1, &bc_mp1, 101);
    bvpode_mp1.SetFilename("model_problem_results1.dat");
    bvpode_mp1.Solve();

    SecondOrderOde ode_mp2(1.0, 3.0, -4.0, model_prob_2_rhs, 0.0, M_PI);
    BoundaryConditions bc_mp2;
    bc_mp2.SetLhsNeumannBc(-5.0);
    bc_mp2.SetRhsDirichletBc(4.0);
    BvpOde bvpode_mp2(&ode_mp2, &bc_mp2, 1001);
    bvpode_mp2.SetFilename("model_problem_results2.dat");
    bvpode_mp2.Solve();
    return 0;
}