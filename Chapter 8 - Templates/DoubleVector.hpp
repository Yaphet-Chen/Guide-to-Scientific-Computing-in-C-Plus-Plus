/*---------------------------------------------------------------------------*\
 * @File        : DoubleVector.hpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : Templates to Control Dimensions and Verify Sizes
 * @version 0.1
 * @Date        : 2018-10-09
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

/* Templates, a feature that allows very general code to be written.
One library associated with C++ is the Standard Template Library (STL) */

#ifndef DOUBLEVECTORDEF
#define DOUBLEVECTORDEF

#include <cassert>

/*---------------------------------------------------------------------------*\
 * @Brief       : Templated class：arrays with an additional feature that a check for validity
 *                of the index is performed each time an element of the array is accessed.
 * 
 * @Tparam      : DIM
\*---------------------------------------------------------------------------*/
template <unsigned int DIM>
class DoubleVector
{
private:
  double mData[DIM];

public:
  double &operator[](int index) // Overloading the [] operator
  {
    // Check the index is a valid index before returning the variable requested.
    assert(index < DIM);
    assert(index > -1);
    return (mData[index]);
  }
};

#endif