/*---------------------------------------------------------------------------*\
 * @File        : ExampleClass.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : The friend Keyword
 * @version 0.1
 * @Date        : 2018-10-06
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

#include "ExampleClass.hpp"

// Constructor to set private members
ExampleClass::ExampleClass(double member1, double member2)
{
    mMemberVariable1 = member1;
    mMemberVariable2 = member2;
}
// GetMinimum is a member method
double ExampleClass::GetMinimum() const
{
    if (mMemberVariable1 < mMemberVariable2)
    {
        return mMemberVariable1;
    }
    else
    {
        // mMemberVariable1 >= mMemberVariable2
        return mMemberVariable2;
    }
}

// GetMaximum is a friend function
double GetMaximum(const ExampleClass &egClass) // Not a member of the class, we do not include ExampleClass::
{
    if (egClass.mMemberVariable1 >
        egClass.mMemberVariable2)
    {
        return egClass.mMemberVariable1;
    }
    else
    {
        // egClass.Var1 <= egClass.Var2
        return egClass.mMemberVariable2;
    }
}
