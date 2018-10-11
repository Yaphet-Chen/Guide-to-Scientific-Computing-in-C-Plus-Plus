/*---------------------------------------------------------------------------*\
 * @File        : Point2d.hpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : A Brief Survey of the Standard Template Library - Sets
 * @version 0.1
 * @Date        : 2018-10-11
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

#ifndef POINT2DDEF
#define POINT2DDEF

class Point2d
{
  public:
    int x, y;
    Point2d(int a, int b);
    bool operator<(const Point2d &other) const;
};

Point2d::Point2d(int a, int b)
{
    x = a;
    y = b;
}

/* It is only possible to make an efficient set implementation if the elements of the set can be ordered. 
As the items in a set have to be comparable, we need to overloaded < operator that allows us to order points in two dimensions. */
bool Point2d::operator<(const Point2d &other) const
{
    if (x < other.x)
    {
        return true;
    }
    else if (x > other.x)
    {
        return false;
    }
    else if (y < other.y)
    {
        // x == other.x
        return true;
    }
    else
    {
        // x == other.x and
        // y >= other.y
        return false;
    }
}

#endif