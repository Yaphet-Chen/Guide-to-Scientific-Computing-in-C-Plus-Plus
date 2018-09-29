/*---------------------------------------------------------------------------*\
 * @Brief       : Reading from the file
 * 
 * @File        : ReadingFile.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Date        : 2018-09-29
\*---------------------------------------------------------------------------*/

#include <cassert>
#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    double x[100], y[100];
    std::ifstream read_file("../Chapter 3 - File Input and Output/Sample.dat"); // Declare an input stream variable read_file, and then specify the file Sample.dat that we wish to read.
    assert(read_file.is_open());                                                // Ensures that Sample.dat is on disk in the correct location and with the correct access privileges

    int i = 0;
    while (!read_file.eof()) // The input stream variable read_file.eof() takes the value true when the end of the file is reached
    {
        read_file >> x[i] >> y[i];
        i++;
    }

    // Rewind a file so that we can read a file starting from the beginning again
    read_file.clear();
    read_file.seekg(std::ios::beg);
    while (!read_file.eof())
    {
        read_file >> x[i] >> y[i];
        i++;
    }

    read_file.close();
    return 0;
}