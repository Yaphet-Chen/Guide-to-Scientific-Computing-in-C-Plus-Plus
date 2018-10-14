/*---------------------------------------------------------------------------*\
 * @File        : Broken.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : Tips: Memory Debugging Tools
 * @version 0.1
 * @Date        : 2018-10-14
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

/* Memory leak: If a long-running program repeatedly allocates memory without de-allocating
it, then eventually that program will unnecessarily occupy all the available memory
of the computer. */

/* Memory debugging tool run an executablefile while inspecting all the memory access calls.
 * Electric Fence do this by replacing the usual memory libraries with ones which intercept the calls.
 * Valgrind run the program inside a virtual machine and externally monitor the memory accesses—a slower process,
   but one which does not require recompilation of the program.
 **/

int main(int argc, char *argv[])
{
    double *x = new double[10];
    double *y = new double[10];

    // Error: x[10] is accessed
    // May cause a run-time error
    for (int i = 0; i <= 10; i++)
    {
        x[i] = i;
    }

    // Error: z is not set
    int z;
    if (z == 0)
    {
        y[0] = x[0];
    }

    // Error: x de-allocated twice
    // May cause a run-time error
    delete[] x;
    delete[] x;

    // Error: y still allocated
}
/*
g++ -std=c++11 -g -o Broken Broken.cpp
valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all  ./Broken
*/