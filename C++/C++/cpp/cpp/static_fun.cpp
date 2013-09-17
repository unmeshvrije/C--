#include<iostream>
using namespace std;

class a
{
  int x;
  static int cnt;		//static variable of class (represents property of class)
				//static variable is not auto-incremented
public:

    a ()
  {
    x = ++cnt;
  }
  void putdata ()
  {
    cout << "\n\t\tx=" << x;	// member function outputting private variable
  }

  static void showcnt (void)	//static functions can access  only static members
  {
    cout << "\n\t\t" << cnt << "th object is created.";
  }

};

int a::cnt;	//we've to declare static variable like this ??????

// cnt is the variable of 'a' class.

int
main ()
{
  a::showcnt ();   //static var will have value '0' initially.
  a a1;
  a::showcnt ();
  a1.putdata ();
  a a2;
  a::showcnt ();
  a2.putdata ();
  a a3;
  a::showcnt ();
  a3.putdata ();
  return 0;
}
