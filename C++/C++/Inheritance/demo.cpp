#include <iostream>
using namespace std;

class Base {

public:
   int x;
   Base(){x = 1; y = 2;} 

protected:
   int y;
};


class Derived : private Base {

protected:
   int x;

public:
   Derived(){/*x = 5; y = 6;*/}
   int y;
   void Print()
   {
      cout << "x =" << x << endl;
      cout << "y =" << y << endl;
   }
};

int main()
{
  Derived d;
  d.Print();
}
