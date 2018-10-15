/*---------------------------------------------------------------------------*\
 * @File        : CombinedSendRecv_Chain.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : Message passing between processes in a chain using combined send-receive.
 * @version 0.1
 * @Date        : 2018-10-15
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

#include <iostream>
#include <mpi.h>

int main(int argc, char *argv[])
{
    MPI::Init(argc, argv);
    int tag = 30;
    int rank = MPI::COMM_WORLD.Get_rank();
    int num_procs = MPI::COMM_WORLD.Get_size();

    int right_rank = rank + 1;
    if (rank == num_procs - 1) // Top-most sends nowhere
    {
        /* MPI provides a special process name MPI::PROC_NULL which means
        that this process does not participate with a send and/or receive */
        right_rank = MPI::PROC_NULL;
    }

    int left_rank = rank - 1;
    if (rank == 0) // Bottom-most receives nothing
    {
        left_rank = MPI::PROC_NULL;
    }

    int recv_data = 999; // This will be unchanged on proc 0
    // Communicate 0->1->2... Final process sends nowhere
    MPI::COMM_WORLD.Sendrecv(&rank, 1, MPI::INT, right_rank, tag,
                             &recv_data, 1, MPI::INT, left_rank, MPI::ANY_TAG);
    // As with the Recv functions, we can use the wild-cards for the source process identity and the received message tag.
    std::cout << "Process " << rank << " received from " << recv_data << "\n";
    MPI::Finalize();
    return 0;
}