#include <iostream>
#include <cstdlib> // The functions convert these arrays of characters to the appropriate variable types require the header file cstdlib

int main(int argc, char *argv[])
{
    std::cout << "Number of command line arguments = "
              << argc << "\n";
    for (int i = 0; i < argc; i++)
    {
        std::cout << "Argument " << i << " = " << argv[i];
        std::cout << "\n";
    }

    std::string program_name = argv[0];
    int number_of_nodes = atoi(argv[1]);
    double conductivity = atof(argv[2]);
    std::cout << "Program name = " << program_name << "\n";
    std::cout << "Number of nodes = " << number_of_nodes << "\n";
    std::cout << "Conductivity = " << conductivity << "\n";

    return 0;
}
// Enter the following at the command line: ./CommandLineCode 100 5.0