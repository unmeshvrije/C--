#include<iostream>

//Syntax of reference variable
//data_type & reference_name = variable_name

using namespace std;
main()
{
  int x ;
  x = 10;
  int &y = x; // reference should always have
   // other variable as initializer
cout << "\nx = " << x << "   and y = " << y;
y = 5;
cout << "\nx = " << x << "   and y = " << y;
x = 15;
cout << "\nx = " << x << "   and y = " << y;

//Lvalue : Location (address) of an expression
//Rvalue : VAlue of expression
//e.g. -
//  int a,b;
//a=4;  // rvalue 4 is stored in Lvalue of a
// b = a;//rvalue of a is stored in lvalue of b


   int &z = 50;
   cout << endl << z;
}
