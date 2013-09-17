#include<iostream>
using namespace std;

class si
{
  float p, y, r;

public:

    si ()			//default constructor
  {
    p = 1000;
    y = 3;
    r = 4.5;
  }

  si (float pple, float yr, float rate = 5):p(pple),y(yr),r(rate){}
/*  {
    p = pple;
    y = yr;               //this code for constructor is also valid
    r = rate;
  }*/
  void putdata ()
  {
    cout << "\n\t\t" << p << "\t" << y << "\t" << r;
    getchar ();
  }

};


int
main ()
{
  si a1;
  a1.putdata ();
  si a2 (5000, 2, 3.5);		//all the parameters are passed
  a2.putdata ();
  si a3 (4000, 4);		// default parameter for "rate" is used
  a3.putdata ();

  return 0;
}
