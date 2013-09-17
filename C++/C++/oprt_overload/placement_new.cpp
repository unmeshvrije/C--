#include <iostream>
#include "point.h"

using namespace std;

ostream& operator << (ostream &out, Point &P)
{
  out << "(" << P.x << "," << P.y << ")";
}

int main()
{
  char MySpace[80];
  Point p(3,5);
  cout << p << endl;

  Point *q = new Point(234,567);
  cout << *q << endl;
  delete q;

  Point *ptr;
  
  char *move = MySpace;

  for (
  	int i = 0; 
	i < 10 ;
	++i, move += sizeof(Point)
  	)
{
    cout << "i = " << i << endl;
    new (move)Point(i,i);
/*
=> operator new (sizeof(Point), move)
*/
}

ptr = (Point*)MySpace;

for (int i = 0; i < 10; ++i)
  cout << ptr[i];

cout << endl;

  //MySpace
  return 0;
}
