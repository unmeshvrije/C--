#include <iostream>
#include "point.h"

using namespace std;

class Pointer
{
  private:
   Point *ptr;
 
  public:
  Pointer(){}
  Pointer(int x, int y)
  {
     ptr = new Point(x,y);
  }
  Pointer(Point* pp)
  { 
      ptr = pp;
  }

  ~Pointer()
  {
     delete ptr;
  }
  Point* operator->()
  {
     return ptr;
  }

  Point operator *()
  {
     return *ptr;
  }
   
};

int main()
{
 //int i = 5;
//  int *p = &i;

//  Point P1(5,6); 
  Pointer p(5,6);
  cout << p->x;
  cout << p->y << endl;
  cout << (*p).x;
  cout << (*p).y << endl;
  return 0;
}
