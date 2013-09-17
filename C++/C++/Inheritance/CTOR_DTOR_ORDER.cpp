#include <iostream>
using namespace std;

class A
{
   public:
   A() {cout << "A::CTOR" << endl;}
   ~A() {cout << "A::DTOR" << endl;}
};

class B: A
{
   public:
   B() {cout << "B::CTOR" << endl;}
   ~B() {cout << "B::DTOR" << endl;}
};

class C: B
{
   public:
   C() {cout << "C::CTOR" << endl;}
   ~C() {cout << "C::DTOR" << endl;}
};

int main()
{
  C c1;// A, B, C CTOR
  {
     B b1; // A, B CTOR
  }
  // B , A DTOR

  c1.~C();  // C , B , A DTOR (!)
  
}// C, B ,A DTOR
