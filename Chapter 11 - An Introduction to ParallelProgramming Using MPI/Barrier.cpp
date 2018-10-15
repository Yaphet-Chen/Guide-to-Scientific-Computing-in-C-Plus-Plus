/*---------------------------------------------------------------------------*\
 * @File        : Barrier.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : The simplest collective method: Barrier
 * @version 0.1
 * @Date        : 2018-10-15
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

/* These collective calls have the advantage that they can be highly tuned in an MPI implementation
to fit the local architecture. If a supercomputer consists of several multicore computers connected by Ethernet,
then the broadcast algorithm can be tuned to minimise the number of Ethernet messages while possibly increasing
the number of faster messages between cores in the same machine. */

#include <iostream>
#include <mpi.h>

int main(int argc, char *argv[])
{
    MPI::Init(argc, argv);
    std::cout << "Processes may arrive at any time\n";
    std::cout.flush();
    /* Barrier: every process should wait here until all processes are ready to proceed.
    Barriers are useful when you are timing certain parts of the code, printing out information
    to the console, or debugging the code.*/
    MPI::COMM_WORLD.Barrier();
    std::cout << "All processes continue together\n";
    std::cout.flush();
    MPI::Finalize();
    return 0;
}