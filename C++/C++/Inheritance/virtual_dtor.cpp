#include <iostream>
using namespace std;

class A // Devil
{
   public:
   A(){cout << "A::CTOR" << endl;}
   virtual ~A()
   {
     cout << "A::DTOR" << endl;
   }
};

// B is parrot (it has life of devil)
class B : public A
{
   public:
   B(){cout << "B::CTOR" << endl;}
   ~B(){cout << "B::DTOR" << endl;}
};

int main()
{
   A* ptr = new B;
   delete ptr;

   return 0;
}
