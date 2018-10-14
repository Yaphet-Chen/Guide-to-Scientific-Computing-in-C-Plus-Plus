/*---------------------------------------------------------------------------*\
 * @File        : MpiHelloWorld.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : Essential MPI information
 * @version 0.1
 * @Date        : 2018-10-14
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

/* A program intended for a distributed memory architecture can run on a shared memory architecture.
 * In this case, the individual parts of the parallel program will have separate memory spaces within
   the shared memory system (so that they cannot directly access each others’ memory), but will be able
   to communicate via the memory system. Communication is therefore much faster than over a network.

 * You can even run distributed memory programs on a computer with a single processor.
   All the parallel processes will be run as what are known as individual threads, and will communicate
   via the memory system with the operating system responsible for context switching between the threads. 

 * Process: a part of a parallel program that may be executed independently of the other parts,
            provided that data can be communicated through MPI calls when required.
            A process can be thought of as a component of the program that can be executed on one of the processors.
            If a code has p processes, then each process is given a rank which is a unique integer in the range 0 ≤ rank < p.

 * MPI is actually a set of standards for performing distributed computing and there are various implementations.
 * The MPI-1 standard documents the primary core of MPI (basic point-to-point and collective communication)
 * The MPI-2 standard adds other useful but advanced features such as parallel file access (through the input
   and output operations provided by MPIIO) and remote memory access (one-sided communication).

 * The most commonly used are the MPICH and Open MPI implementations.
   The Open MPI library implementation is currently available from major Linux distribution repositories
   and is therefore easy to install on Linux systems. It can be used either on a stand-alone system (shared-memory)
   or across standard Ethernet using the secure shell ssh protocol.
 **/

#include <iostream>
#include <mpi.h> // MPI, as a third-party library, is not part of the standard C++ distribution.

int main(int argc, char *argv[])
{
    // All MPI calls must lie between MPI::Init and MPI::Finalize.
    MPI::Init(argc, argv); // Start the parallel part of the code

    /* The COMM_WORLD object represents a communications group involving all the processes
    running the current calculation. It is possible to split this communication group up into
    smaller groups so that subsets of the processes can share private data. */
    int num_procs = MPI::COMM_WORLD.Get_size(); // Access the number of processes taking part in the program execution
    int rank = MPI::COMM_WORLD.Get_rank();      // Identify the process which is executing a given statement
    std::cout << "Hello world from process " << rank << " of " << num_procs << "\n";

    /* Finalize is a function in the MPI namespace, Get_size is a method of the communication object COMM_WORLD.
    Some C++ programmers opt for the plain C functions MPI_Init, MPI_Get_size, etc.
    Both versions are valid in C++ programs and can even be mixed. */
    MPI::Finalize(); // Stop the parallel part of the code, closing any remote connections and terminating all processes.

    return 0;
}

/* mpiCC, mpic++ or mpicxx are wrapper compiler automatically adds the correct compiler flags when it calls the actual compiler.
 * Use mpirun or mpiexec to run in parallel.
 * To run the program locally, use the “number of processes” -np flag.
 * To run the program across a network, you can give a list of machines in a host file,
   or alternatively list the machine names on the command-line.
 * If you are running your program on a large cluster or a supercomputer, then it is likely
   that the program will be launched from a script via a queueing system. In this case,
   the locations of the processors available to you will be determined by the job queue manager.
 * MPI implementations vary in how they return console input from the individual processes
   to the console from which the program was launched. Even when flush is called on the cout stream
   it may still be the case that the MPI machinery is buffering output.
 **/

/* mpiCC -o MpiHelloWorld MpiHelloWorld.cpp
 * mpirun -np 2 ./MpiHelloWorld
 * mpirun -host remote1.org,localhost,remote2.org ./MpiHelloWorld
 **/
