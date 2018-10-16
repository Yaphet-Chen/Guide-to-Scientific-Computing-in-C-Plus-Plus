/*---------------------------------------------------------------------------*\
 * @File        : FiniteDifferenceGrid.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : Implementation of FiniteDifferenceGrid Class
 * @version 0.1
 * @Date        : 2018-10-15
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

#include <cassert>
#include "FiniteDifferenceGrid.hpp"
#include "Node.hpp"

FiniteDifferenceGrid::FiniteDifferenceGrid(int numNodes, double xMin, double xMax)
{
    double stepsize = (xMax - xMin) / ((double)(numNodes - 1));
    for (int i = 0; i < numNodes; i++)
    {
        Node node;
        node.coordinate = xMin + i * stepsize;
        mNodes.push_back(node);
    }
    assert(((int) mNodes.size()) == numNodes);
}