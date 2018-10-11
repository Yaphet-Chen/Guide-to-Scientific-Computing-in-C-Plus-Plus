/*---------------------------------------------------------------------------*\
 * @File        : UsePoint2d.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : A Brief Survey of the Standard Template Library - Sets
 * @version 0.1
 * @Date        : 2018-10-11
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

/* A set is an STL container where new entries are only stored if they are distinct from the entries already stored. 
The STL set is implemented as a tree structure known as a red-black search tree. */
#include <set>
#include <iostream>
#include "Point2d.hpp"

int main(int argc, char *argv[])
{
    std::set<Point2d> points; // We create a set made up of instances of the class Point2d, that is called points
    Point2d origin(0, 0);
    points.insert(origin);
    points.insert(Point2d(-2, 1));
    points.insert(Point2d(-2, -5));
    points.insert(Point2d(0, 0)); // The origin and the point (0, 0) are identical, and so only one is stored

    std::cout << "Number of points in set = " << points.size() << "\n";
    std::set<Point2d>::const_iterator c; // Access entries of the vector using an iterator
    for (c = points.begin(); c != points.end(); c++)
    {
        std::cout << c->x << " " << c->y << "\n";
    }

    return 0;
}