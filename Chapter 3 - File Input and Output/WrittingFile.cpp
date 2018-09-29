/*---------------------------------------------------------------------------*\
 * @Brief       : Writting to file & Tips: Controlling Output Format
 * 
 * @File        : WrittingFile.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Date        : 2018-09-29
\*---------------------------------------------------------------------------*/

#include <cassert>
#include <iostream>
#include <fstream> // Writing to, or reading from, file requires the additional header file fstream.

int main(int argc, char *argv[])
{
    double x[3] = {0.0, 1.0, 0.0};
    double y[3] = {0.0, 0.0, 1.0};

    /* i> Will create a new file, if this file does not already exist.
      ii> If this file does exist, will delete the original file and write a new file with the same name. */
    std::ofstream write_output1("Output.dat");                // Declare an output stream variable write_output1, and also specify the filename “Output.dat”.
    std::ofstream write_output2("Output.dat", std::ios::app); // Append data to the end of this file.

    /* If the file cannot be opened
    1. Perhaps we did not have permission to write to that file, like /etc/Output.dat
    2. A directory we have specified does not exist
    then writing to the ofstream may cause no error even though writing to the file is not possible. */
    assert(write_output1.is_open()); // Checks that the file has been successfully opened
    assert(write_output2.is_open());
    for (int i = 0; i < 3; i++)
    {
        write_output1 << x[i] << " " << y[i] << "\n";
        write_output2 << x[i] << " " << y[i] << "\n";
    }

    /* Output to file is also buffered: closing the file handle flushes the buffer.
    1. Prevent another part of the program reads a file which is still being written to
    2. Prevents the file being corrupted by mistakenly attempting to write further data.
    3. Flush a buffer without closing the file handle: write_output.flush(); */
    write_output1.close(); // Close the file handle
    write_output2.close();

    /*++++++++++++++++++++++++ Setting the Precision of the Output ++++++++++++++++++++++*/
    double z = 1.8364238;

    std::ofstream write_output("Output.dat", std::ios::app);
    assert(write_output.is_open());

    write_output.precision(3); // 3 significant figures
    write_output << z << "\n";

    write_output.precision(5); // 5 significant figures
    write_output << z << "\n";

    write_output.precision(10); // 10 significant figures
    write_output << z << "\n";  // The variable x is only given to eight significant figures

    write_output.close();

    /*++++++++++++++++++++++++++ Setting the Format of the Output ++++++++++++++++++++++++*/
    std::ofstream write_file("OutputFormatted.dat");
    write_file.setf(std::ios::scientific); // Output in scientific format.
    write_file.setf(std::ios::showpos);    // Always showing a + or − sign.
    /* In this case the precision specified is 
    1. The number of digits after the decimal point
    2. When scientific format is used zeros are added after the decimal point to ensure that all output is of exactly the same width.*/
    write_file.precision(13);

    double x0 = 3.4, y0 = 0.0000855, z0 = 984.424;
    // Write numbers as +x.<13digits>e+00 (width 20)
    write_file << x0 << " " << y0 << " " << z0 << "\n";
    write_file.close();

    return 0;
}