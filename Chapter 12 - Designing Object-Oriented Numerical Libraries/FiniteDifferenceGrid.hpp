/*---------------------------------------------------------------------------*\
 * @File        : FiniteDifferenceGrid.hpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : Define the finite difference grid
 * @version 0.1
 * @Date        : 2018-10-15
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

#ifndef FINITEDIFFERENCEGRIDHEADERDEF
#define FINITEDIFFERENCEGRIDHEADERDEF

#include <vector>
#include "Node.hpp"

class FiniteDifferenceGrid
{
  public:
    // The boundary value ODE class is able to access the nodes
    friend class BvpOde;

  private:
    std::vector<Node> mNodes;

  public:
    FiniteDifferenceGrid(int numNodes, double xMin, double xMax); // Constructor to create a uniform grid
};

#endif