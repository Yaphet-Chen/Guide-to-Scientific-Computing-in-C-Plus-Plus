/*---------------------------------------------------------------------------*\
 * @File        : SummationOfSeries.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : Program to sum Pi using  Gottfried Wilhelm Leibniz formula:
 *                          Pi = 4 * Sum_n ( (-1)**n/(2*n+1) )
 * @version 0.1
 * @Date        : 2018-10-14
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

/* However, merely giving each process a similar amount of work is no guarantee of a
successful parallel algorithm if the combined computational load of parallel processes
is much more than that of the sequential program, or if communication dominates the program.
 * Load balancing: giving the processes the same amount of work.
 * Parallel speedup: S_p = T_1/T_p, the ratio of the time it takes to run the code sequentially
                     to time it takes to run on p processes.
 * Parallel efficiency: scales parallel speedup by p, E_p = T_1/(pT_p) = S_p/p, generally in the
                        range from 0 to 1 with 1 being the ideal value.
 * Super-linear speedup: E_p > 1, normally arises when a given problem has memory constraints
                         when run on a small numbers of processes
 **/

#include <mpi.h>
#include <cmath>
#include <iostream>

int main(int argc, char *argv[])
{
    MPI::Init(argc, argv);
    int max_n = 1000;
    double sum = 0;

    int num_procs = MPI::COMM_WORLD.Get_size();
    int rank = MPI::COMM_WORLD.Get_rank();
    // Distribute in such a way as to interleave processor contributions
    for (int n = rank; n < max_n; n += num_procs)
    {
        double temp = 1.0 / (2.0 * ((double)(n)) + 1.0);
        if (n % 2 == 0) // n is even
        {
            sum += temp;
        }
        else
        {
            // n is odd
            sum -= temp;
        }
    }

    double global_sum;
    MPI::COMM_WORLD.Reduce(&sum, &global_sum, 1, MPI::DOUBLE, MPI::SUM, 0);
    if (rank == 0)
    {
        std::cout << "Pi is about " << 4.0 * global_sum << " with error " << 4.0 * global_sum - M_PI << "\n";
    }

    MPI::Finalize();
    return 0;
}