/*---------------------------------------------------------------------------*\
 * @File        : Exception.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : Implementation of Exception class
 * @version 0.1
 * @Date        : 2018-10-12
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

#include <iostream>
#include "Exception.hpp"

Exception::Exception(std::string tagString, std::string probString)
{
    mTag = tagString;
    mProblem = probString;
}

void Exception::PrintDebug() const
{
    std::cerr << " ** Error (" << mTag << ") ** \n"; // One-word summary of the problem type
    std::cerr << "Problem: " << mProblem << "\n\n";  // More lengthy description of the error
}