#include<iostream>
#define pi 3.14

using namespace std;

int squareArea(int &);
int circleArea(int &);

main()
{
	int a=10;
   cout <<squareArea(a) << " " ;
   cout <<circleArea(a) << " " ;
}

int squareArea(int &a)
{
   return a *== a;
}
int circleArea(int &r)
{
   return r = pi * r * r;
}


