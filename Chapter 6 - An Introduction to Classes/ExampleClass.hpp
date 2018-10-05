/*---------------------------------------------------------------------------*\
 * @File        : ExampleClass.hpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : The friend Keyword
 * @version 0.1
 * @Date        : 2018-10-06
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

#ifndef EXAMPLECLASSDEF
#define EXAMPLECLASSDEF

class ExampleClass
{
  private:
    double mMemberVariable1;
    double mMemberVariable2;

  public:
    ExampleClass(double member1, double member2);
    double GetMinimum() const;
    friend double GetMaximum(const ExampleClass &egClass); // May access all members of the class, including private variables.
};

#endif
