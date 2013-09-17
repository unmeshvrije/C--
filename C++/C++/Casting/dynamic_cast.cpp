#include <iostream>
using namespace std;

class Base
{
   public:
   virtual void fun() {cout << "Base::fun()" << endl;}
};

class Derived : public Base
{
   public:
   void fun() {cout << "Derived::fun()" << endl;}
};
/*
void TestCast(Base *ptr)
{
   if (NULL != dynamic_cast<Base*>(ptr))
     cout << "DYN_CAST: ptr is of Base type" << endl;
   else
     cout << "DYN_CAST: ptr is NOT of Base type";

   if (NULL != dynamic_cast<Derived*>(ptr))
     cout << "DYN_CAST: ptr is of Derived type" << endl;
   else
     cout << "DYN_CAST: ptr is NOT of Derived type";

   if (NULL != static_cast<Base*>(ptr))
     cout << "STATIC_CAST: ptr is of Base type" << endl;
   else
     cout << "STATIC_CAST: ptr is NOT of Base type" << endl;

   if (NULL != static_cast<Derived*>(ptr))
     cout << "STATIC_CAST: ptr is of Derived type" << endl;
   else
     cout << "sTATIC-CAST: ptr is NOT of Derived type" << endl;

}
*/
void f(Base *ptr)
{
    Derived *p1 = static_cast<Derived*>(ptr);
    if (NULL == p1)
     cout << "Static cast failed" << endl;

    Derived *p2 = dynamic_cast<Derived*>(ptr);  
    if (NULL == p2)
     cout << "Dynamic cast failed" << endl;
}

int main()
{
    Base *ptr = new Derived();
   Derived *ptr2 = new Derived();

    Base b;
    f(&b);

    //Derived *ptr3 = static_cast<Derived*>(ptr);
 /*
   Derived *ptr3 = dynamic_cast<Derived*>(ptr);
    if (NULL == ptr3)
      cout <<"Fail" << endl;
*/



//    Derived *ptr = new Base();

//    cout << "Test Base *ptr which has Derived type mem:" << endl;
  //  TestCast(ptr);
  //  cout << "Test Derived *ptr which has Derived type mem:" << endl;
//    TestCast(ptr2);
}
