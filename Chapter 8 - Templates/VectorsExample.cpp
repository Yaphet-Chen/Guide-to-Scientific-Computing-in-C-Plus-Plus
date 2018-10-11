/*---------------------------------------------------------------------------*\
 * @File        : VectorsExample.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : A Brief Survey of the Standard Template Library - Vectors
 * @version 0.1
 * @Date        : 2018-10-11
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

/* Containers, such as random-access vectors and sets, are dynamic arrays where the STL is responsible for memory management. 
Other containers that are available in the STL are maps, multimaps, multisets, lists and deques (double-ended queues, pronounced “decks”).

There are also many more algorithms that may be performed on these containers other than those presented here.

The STL vector class is a very useful container because it is an extensible class which has a similar interface to the regular C++ array.
The fact that it is extensible means that its size is not fixed (either at compile time or at the time that it is created)
and that it will grow to accommodate new items as necessary. */

#include <iostream>
#include <vector>    // To use the vector container
#include <algorithm> // To use some algorithms that may be used on STL vectors, such as sorting
#include <string>

int main(int argc, char *argv[])
{
    std::vector<std::string> destinations; // Note that we do not have to state the size of the vector
    destinations.reserve(6);               // Produce efficiency in memory-intensive code because it doesn't have to reallocate any memory later
    destinations.push_back("Paris");       // Appends a copy of this string to the current vector
    destinations.push_back("New York");    // Append another entry to the end of the vector
    destinations.push_back("Singapore");
    std::cout << "Length of vector is " << destinations.size() << "\n"; // Access the number of elements of the vector
    std::cout << "Entries of vector are\n";
    for (int i = 0; i < 3; i++)
    {
        std::cout << destinations[i] << "\n"; // Entries of the vector may be accessed in the same way as for a standard vector
    }

    std::vector<std::string>::const_iterator c; // Access entries of the vector using an iterator
    for (c = destinations.begin(); c != destinations.end(); c++)
    {
        std::cout << *c << "\n"; // Note the use of the overloaded * operator which looks like a pointer de-reference
    }

    destinations.insert(destinations.begin(), "Sydney");     // Add a string to the start of a vector by using the insert and begin method
    destinations.insert(destinations.begin() + 1, "Moscow"); // Add a string to the vector and place it in the second position
    destinations.push_back("Frankfurt");
    std::cout << "Length of vector is " << destinations.size() << "\n";
    std::cout << "Entries of vector are\n";
    for (c = destinations.begin(); c != destinations.end(); c++)
    {
        std::cout << *c << "\n";
    }

    destinations.erase(destinations.begin() + 3, destinations.end()); // Erase all entries of the vector that appear after the third entry
    std::cout << "Length of vector is " << destinations.size() << "\n";
    std::cout << "Entries of vector are\n";
    for (c = destinations.begin(); c != destinations.end(); c++)
    {
        std::cout << *c << "\n";
    }

    sort(destinations.begin(), destinations.end()); // Sort algorithm will sort a vector of strings into alphabetical order
    std::cout << "Length of vector is " << destinations.size() << "\n";
    std::cout << "Entries of vector are\n";
    for (c = destinations.begin(); c != destinations.end(); c++)
    {
        std::cout << *c << "\n";
    }

    return 0;
}