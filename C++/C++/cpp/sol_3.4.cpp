#include<iostream>
#define pi 3.14

using namespace std;

int squareArea(int &);
double circleArea(int &);

main()
{
	int a=7;
   cout <<squareArea(a) << " " ;
   cout <<circleArea(a) << " " ;
}

int squareArea(int &a)
{
   return a *= a;
}
double circleArea(int &r)
{
   double s = (double) r;
   s = pi * (double)r * (double)r;
   return s;
}


