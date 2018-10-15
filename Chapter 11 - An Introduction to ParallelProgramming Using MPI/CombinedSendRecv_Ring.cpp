/*---------------------------------------------------------------------------*\
 * @File        : CombinedSendRecv_Ring.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : Message passing between processes in a ring using combined send-receive.
 * @version 0.1
 * @Date        : 2018-10-15
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

/* Combined send-receive: every process sends a message to another, while also receiving a remote message.
 * Halo data: The local copy of remote neighbouring data
 * Halo exchange: The message passing process
 **/

// void Comm::Sendrecv(const void *sendbuf, int sendcount, const Datatype &sendtype, int dest, int sendtag,
//                     void *recvbuf, int recvcount, const Datatype &recvtype, int source, int recvtag) const

/* Sendrecv are interpreted relative to the local process: if each process is sending to the rank above,
by symmetry, each must be receiving from the rank below.
It is possible to mix the types of messages (both in terms of DataType and the length of the messages). */

#include <iostream>
#include <mpi.h>

int main(int argc, char *argv[])
{
    MPI::Init(argc, argv);
    int tag = 30;
    int rank = MPI::COMM_WORLD.Get_rank();
    int num_procs = MPI::COMM_WORLD.Get_size();
    // Note modular arithmetic, so that 0 has neighbour num_procs-1
    int left_rank = (rank - 1 + num_procs) % num_procs; // left_rank is rank-1
    int right_rank = (rank + 1) % num_procs;
    int recv_data;
    // Closed loop Communicate in a ring ...->0->1->2...
    MPI::COMM_WORLD.Sendrecv(&rank, 1, MPI::INT, right_rank, tag,
                             &recv_data, 1, MPI::INT, left_rank, tag);
    std::cout << "Process " << rank << " received from " << recv_data << "\n";
    MPI::Finalize();
    return 0;
}
