#include<iostream>
using namespace std;

void swap(int &a, int& b)//'&'indicates call // by reference
{
   int temp = a;
   a = b; // a and b are reference variables
   b = temp;
}
main()
{
   int x =10 ; // initialization
   int y =20 ;
  cout << "\nx = " << x << "   and y = " << y;
   swap(x,y);//call
cout << "\nx = " << x << "   and y = " << y;
}
