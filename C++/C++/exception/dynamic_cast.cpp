#include <iostream>
#include <exception>

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


class CastException : public exception
{
  public:
  const char * what()
  {
     return "cast exception";
  }
};

void f(Base *ptr)
{
   try
   {
    Derived *p1 = static_cast<Derived*>(ptr);
    if (NULL == p1)
      throw;
  //   cout << "Static cast failed" << endl;

    Derived *p2 = dynamic_cast<Derived*>(ptr);  
    if (NULL == p2)
      throw new CastException;
      //throw new exception;
     //cout << "Dynamic cast failed" << endl;
    }
    catch(CastException *ce)
    //catch(exception *ce)
    {
       cout << "Something unexpected.." << endl;
//       unexpected();
        cout << ce->what();
    }
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
