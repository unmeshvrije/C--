#include<iostream>
using namespace std;

class a
{
  int x;

public:

	/* c++ doesn't support default constructor internally
		WE have to write it. */ 	
  
  a ()			//default constructor
  {
    x = 10;
  }

  a (int x)
  {
    a::x = x;
  }
  void putdata ()
  {
    cout << "\n\t\tx=" << x;
    getchar ();
  }

};


int
main ()
{
  a a1; // constructor is written for this situation
  a1.putdata ();

  a1 =5;	   //constructor is written for this situation
  a1.putdata ();

  a a2(15);
  a2.putdata ();
 
  return 0;
}
