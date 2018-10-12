/*---------------------------------------------------------------------------*\
 * @File        : Exception.hpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : A class to store two pieces of information, and with the 
 *                ability to print this information when required.
 * @version 0.1
 * @Date        : 2018-10-12
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

#ifndef EXCEPTIONDEF
#define EXCEPTIONDEF

#include <string>

class Exception
{
  private:
    std::string mTag, mProblem;

  public:
    Exception(std::string tagString, std::string probString);
    void PrintDebug() const;
};

#endif