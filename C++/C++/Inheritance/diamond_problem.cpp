#include <iostream>
using namespace std;

class A
{
   public:
   int a;
};


class B: virtual public A
{
   public:
   int b;
};

class C: public virtual A
{
   public:
   int c;
};

class D: public B,public C
{
};

int main()
{
   D d;
   d.a = 4;
   return 0;
}
