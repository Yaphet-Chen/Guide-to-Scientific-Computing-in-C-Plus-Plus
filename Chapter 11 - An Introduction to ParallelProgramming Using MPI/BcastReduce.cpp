/*---------------------------------------------------------------------------*\
 * @File        : BcastReduce.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : Broadcast and Reduce
 * @version 0.1
 * @Date        : 2018-10-15
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

/* The collective operations broadcast and reduce are primarily one-to-many and many-to-one operations.
 * Broadcast: data from one process are shared with all other processes in the communication group.
 * Reduction: all the data is concentrated to a single process.
 * Allreduce: a many-to-many reduction operation, which may be thought of as a reduction operation
              followed by a broadcast to all processes.
 **/

/* This reduction operation is likely to be of one of a standard set available for numerical data
(MPI::MAX, MPI::MIN, MPI::SUM, and MPI::PROD). There are other predefined reduction operations available
including some bit-wise operations, and there is also opportunity to define extra operations. */

// void Comm::Bcast(void *buffer, int count, const MPI::Datatype &datatype, int root) const
// void Comm::Reduce(const void *sendbuf, void *recvbuf, int count, const MPI::Datatype &datatype, const MPI::Op &op, int root) const

#include <stdlib.h> // srand, rand
#include <time.h>   // time
#include <iostream>
#include <mpi.h>

int main(int argc, char *argv[])
{
    MPI::Init(argc, argv);
    int dice[3] = {0, 0, 0};
    if (MPI::COMM_WORLD.Get_rank() == 0) // Proc 0 sets the dice (#sides)
    {
        srand(time(NULL)); // Initialize random seed
        for (int i = 0; i < 3; i++)
        {
            dice[i] = (rand() % 6) + 1;
        }
    }
    MPI::COMM_WORLD.Bcast(dice, 3, MPI::INT, 0); // Proc 0 broadcasts
    dice[0] += MPI::COMM_WORLD.Get_rank();       // Every process adds their rank to dice[0]
    // On Proc 0: max = dice[0]+MPI::COMM_WORLD.Get_size()-1
    int max;
    MPI::COMM_WORLD.Reduce(dice, &max, 1, MPI::INT, MPI::MAX, 0); // Reduce the first value to get the maximum
    if (MPI::COMM_WORLD.Get_rank() == 0)
    {
        std::cout << max << std::endl;
        std::cout << max - dice[0] << std::endl;
    }
    MPI::Finalize();
    return 0;
}