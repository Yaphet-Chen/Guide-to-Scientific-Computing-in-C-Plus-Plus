/*---------------------------------------------------------------------------*\
 * @File        : Ch11_Tips.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : Tips: Debugging a Parallel Program
 * @version 0.1
 * @Date        : 2018-10-15
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

/********************* Tip 1: Make an Abstract Program **************************
Write a simplified abstract program which concentrates on the communication, but neglects the
main calculation. This will give you the opportunity to ensure the safe working of
the parallel communication in the absence of details of the particulars.

************************* Tip 3: Intermittent Deadlock **************************
 * Deadlock: all processes are waiting for some event to happen before proceeding
             but no process can supply that event because they are waiting for another process.
 * Intermittent deadlock: the program deadlocks on some runs of the code but runs normally on others.

Perhaps the program runs without encountering problems with some trivial example test input,
but when it is fed with the real-life input it then deadlocks. When intermittent deadlock happens,
it is an indication that the problem is to do with the size or timing of messages.

We make our program less efficient and more likely to deadlock by removing buffering and
asynchronous messages. Once all message passing is synchronous it is likely that the 
intermittent deadlock has become predictable deadlock, allowing us to identify the problem and debug the code.
A program can also be made “more synchronous” by splitting calculation steps up with barriers.

********************** Tip 4: Almost Collective Communication *******************
It is common to treat process zero as a “master process”, and others as “slave processes”.

When debugging parallel code, it is usually a good idea to add barriers in order to
break the program into manageable sections. However, if we were to add barriers into
the slave processes’ block of sending code, this would be a recipe for instant deadlock.
Since all processes except one are executing this code, then any collective communication on
MPI::COMM_WORLD cannot complete. If collective communication is necessary in this code, then
a new communication group including all processes in MPI::COMM_WORLD except rank zero must be created.
**/

#include <iostream>
#include <mpi.h>

int main(int argc, char *argv[])
{
    /********************************** Tip 2: Datatype Mismatch *******************************/
    /* This may be because of mismatches in the size of the data (on most architectures int uses 32 bits
    whereas double uses 64 bits) or it may be due to errors in the conversion of the data.
    Problems where message data types (or sizes) do not match can be hard to see, especially
    when the send and receive components are in separate methods or in separate files. */
    MPI::Init(argc, argv);
    int tag = 30;
    if (MPI::COMM_WORLD.Get_rank() == 0)
    {
        // Specific send code for process 0
        int send_buffer[2] = {100, 200};
        MPI::COMM_WORLD.Send(send_buffer, 2, MPI::INT, 1, tag); // Sent as MPI::INT
    }
    if (MPI::COMM_WORLD.Get_rank() == 1)
    {
        // Specific receive code for process 1
        double recv_buffer[2] = {0.0, 0.0};
        MPI::COMM_WORLD.Recv(recv_buffer, 2, MPI::DOUBLE, MPI::ANY_SOURCE, MPI::ANY_TAG); // Received as MPI::DOUBLE
        std::cout << recv_buffer[0] << "\n";
        std::cout << recv_buffer[1] << "\n";
    }
    MPI::Finalize();
    return 0;
}