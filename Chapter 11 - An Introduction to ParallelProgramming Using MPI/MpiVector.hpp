/*---------------------------------------------------------------------------*\
 * @File        : MpiVector.hpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : Bare-bones class for Parallel Linear Algebra
 * @version 0.1
 * @Date        : 2018-10-15
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

/**
 * Scatter: one-to-many operation with one process being responsible for sending the message to all other processors.
            Unlike the broadcast operation, where the same entries of data (of size count) are sent to all processes,
            the first count elements are send to the first process, the next count to the next and so on.
 * Scatterv: scatter for variable sized data (where the count size can be different for different destinations)
 * Gather: many-to-one operation with each process contributing some data to the result. The difference is that the
           data is not reduced but rather it is concatenated. If each process contributes count elements of data,
           then the gathering process must have space to store count multiplied by num_procs elements. 
 * Gatherv: variable-sized data version of the gather, which the numbers of elements contributed per process may be different.
 * Allgather: the result of the gather ends up on all the processes involved in the communication. It may be thought of
              as a regular Gather operation followed by a broadcast.
 * Allgatherv: variable-sized data version of the Allgather.
 **/

// void Comm::Scatter(const void *sendbuf, int sendcount, const MPI::Datatype &sendtype,
//                    void *recvbuf, int recvcount, const MPI::Datatype &recvtype, int root) const

// void Comm::Gather(const void *sendbuf, int sendcount, const MPI::Datatype &sendtype,
//                   void *recvbuf, int recvcount, const MPI::Datatype &recvtype, int root) const

// void Comm::Allgather(void *send_data, int send_count, MPI_Datatype send_datatype,
//                      void *recv_data, int recv_count, MPI_Datatype recv_datatype, MPI_Comm communicator) const

// void Comm::Allgatherv(const void *sendbuf, int sendcount, const MPI::Datatype &sendtype,
//                       void *recvbuf, const int recvcounts[], const int displs[], const MPI::Datatype &recvtype) const

/* There are a few standard ways of getting data to file from a parallel program:
1. concentration, where one process does all the writing, as suggested above;
2. round-robin where processes take it in turns to open and close the same file;
3. parallel file libraries such as MPI’s MPIIO; and separate files where each process writes data to
   different places to be re-assembled later. 
The choice of output method is largely dependent on the data structure and size. */

#include <mpi.h>
#include <cmath>
#include <cassert>

class MpiVector
{
  private:
    int mLo, mHi, mSize;
    double *mData;
    double *mGlobalData;

  public:
    MpiVector(int vecSize)
    {
        int num_procs = MPI::COMM_WORLD.Get_size();
        int rank = MPI::COMM_WORLD.Get_rank();
        int ideal_local_size = vecSize / num_procs;

        assert(ideal_local_size > 0);
        mLo = ideal_local_size * rank;
        mHi = ideal_local_size * (rank + 1);

        // Top processor picks up extras
        if (rank == num_procs - 1)
        {
            mHi = vecSize;
        }
        assert(mHi > mLo);
        mData = new double[mHi - mLo];
        mGlobalData = new double[vecSize];
        mSize = vecSize;
    }
    ~MpiVector()
    {
        delete[] mData;
        delete[] mGlobalData;
    }

    double &operator[](int globalIndex)
    {
        // Make sure that this on the local vector
        assert(mLo <= globalIndex && globalIndex < mHi);
        return mData[globalIndex - mLo];
    }
    int GetHi()
    {
        return mHi;
    }
    int GetLo()
    {
        return mLo;
    }
    double CalculateNorm() const
    {
        double local_sum = 0.0;
        for (int i = 0; i < mHi - mLo; i++)
        {
            local_sum += mData[i] * mData[i];
        }
        double global_sum;
        MPI::COMM_WORLD.Allreduce(&local_sum, &global_sum, 1, MPI::DOUBLE, MPI::SUM);
        return sqrt(global_sum);
    }
    void UpdateGlobal()
    {
        int num_procs = MPI::COMM_WORLD.Get_size();
        int num_per_proc[num_procs];
        int local_size = mHi - mLo;
        MPI::COMM_WORLD.Allgather(&local_size, 1, MPI::INT, num_per_proc, 1, MPI::INT);
        int lows_per_proc[num_procs];
        MPI::COMM_WORLD.Allgather(&mLo, 1, MPI::INT, lows_per_proc, 1, MPI::INT);
        MPI::COMM_WORLD.Allgatherv(mData, local_size, MPI::DOUBLE, mGlobalData, num_per_proc, lows_per_proc, MPI::DOUBLE);
    }
};