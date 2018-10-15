/*---------------------------------------------------------------------------*\
 * @File        : PointToPoint.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : Point-to-Point Communication
 *                Point-to-Point communication is not symmetric: one process sends while another receives.
 * @version 0.1
 * @Date        : 2018-10-15
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

/* Message passing is the main feature of MPI.
Send a single message between processes, one process sends while another process receives.
These two functions are called Send and Recv. Their function prototypes are:*/

// void Comm::Send(const void *buf, int count, const Datatype &datatype, int dest, int tag) const
// void Comm::Recv(void *buf, int count, const Datatype &datatype, int source, int tag) const

/* Data on the current process are assumed to be in contiguous memory (as an array of count variables),
but buf may be a pointer to a single variable. Note the const keyword next to the buffer argument:
MPI is making a guarantee not to alter your data during the message sending.

An integer count that gives the number of items in the message.

The datatype field tells the system what the type of the data is (so that the correct number of bytes are sent
in the correct format).

The dest of the Send method give the destination process number (this is the rank of the process we wish to send to).

The message tag can be any nonnegative integer value and its purpose is to allow the user to easily identify
the context of a message. Negative tag values are reserved by the library for special values such as MPI::ANY_TAG. */

#include <iostream>
#include <mpi.h>

int main(int argc, char *argv[])
{
    MPI::Init(argc, argv);
    int tag = 30;
    if (MPI::COMM_WORLD.Get_rank() == 0)
    {
        // Specific send code for process 0
        double send_buffer[2] = {100.0, 200.0};
        MPI::COMM_WORLD.Send(send_buffer, 2, MPI::DOUBLE, 1, tag);
    }
    if (MPI::COMM_WORLD.Get_rank() == 1)
    {
        // Specific receive code for process 1
        double recv_buffer[2] = {0.0, 0.0};
        /* The receiver is allowed to use wild-cards for either the source of the message, or the message tag, or both.
         * MPI::ANY_SOURCE is useful if we wish to receive all the results of one phase of computation before moving on
         to the next phase. Messages sent with the next tag can then be queued until the receiving process is ready for them.
         * MPI::ANY_TAG is useful if we know which process is sending the data, but do not know what the tag will be.
 
         * MPI::ANY_TAG and MPI::ANY_SOURCE are C++ names for these wild-card values. Many codes use the interchangeable
         C names: MPI_ANY_TAG and MPI_ANY_SOURCE.
         **/
        MPI::COMM_WORLD.Recv(recv_buffer, 2, MPI::DOUBLE, MPI::ANY_SOURCE, MPI::ANY_TAG);
        /* There is no MPI type for strings because std::string is a C++ class rather than a plain data-type.
         * Classes can readily be transferred by packing the raw data into a message at one end and unpacking it
           into a waiting class at the other end.
         * C++ names: MPI::BOOL, MPI::CHAR, MPI::INT and MPI::DOUBLE.
         * C names: MPI_BOOL, MPI_CHAR, MPI_INT and MPI_DOUBLE.
         **/
        std::cout << recv_buffer[0] << "\n";
        std::cout << recv_buffer[1] << "\n";
    }
    MPI::Finalize();
    return 0;
}

/* Both Send and Recv functions are known as blocking functions because they do not
allow the execution of the program to continue until it is safe to do so.

The default Send is a compromise between the safety of waiting to be sure that
a message has been delivered and the efficiency of getting on with other tasks after
sending the message immediately.

The other send functions have similar function prototypes, but slightly different names. 

 * Send: not only guarantees that it will not change the contents of the data buffer, but that
         any subsequent changes to the data buffer will not affect the message that is being sent.

 * Ssend: very safest, but possibly most inefficient, means of sending a message is to use a blocking
          synchronous send which guarantees not to continue until the message has been delivered.

 * Bsend: the buffered send, allows the program to continue when safe, but this may happen faster
          since the message is copied to a separate buffer. This buffer must be supplied and configured by the user.

 * Isend: immediate send, the most efficient means of sending a message which returns control to the program
          immediately, whether the message has been delivered, buffered or not yet acted on. The Isend command
          gives back a handle (called an MPI::Request) which has a Wait method: this method instructs execution
          to “wait here” until the message has been sent.

 * Ibsend: compatible combinations of an immediate send that can make use of a user-supplied buffer
           using the buffered non-blocking send.
 **/