/*---------------------------------------------------------------------------*\
 * @File        : AccessPrivileges.cpp
 * @Author      : Yipei Chen
 * @Email       : ychendh@connect.ust.hk
 * @Brief       : Demonstrate the concept of Access Privileges
 * @version 0.1
 * @Date        : 2018-10-05
 * 
 * @copyright Copyright (c) 2018
 * 
\*---------------------------------------------------------------------------*/

#include <string>
class ExampleClass
{
    double member1; // Default is private

  public: // Class members are accessible to everyone
    std::string member2;

  private: // Class members are only accessible to other class members, unless friend is used
    int member3;

  public:
    int member4;

  protected: // Class members are accessible to other class members, to derived classes, and to friends
    double member5;
};