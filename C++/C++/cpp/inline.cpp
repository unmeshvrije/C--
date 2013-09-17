#include<iostream>
using namespace std;

#define SQUARE(x) (x*x)

double cube(double a)
{
  return (a*a*a);
}

main()
{
  double a;
  cout << "  Enter a  : ";
  cin >> a;
  cout <<endl << "  cube of a = " << cube(a) 
<< endl << "square =" << SQUARE(a);
}
