
/**********************Built in type  to   user defined type*********************************/

#include<iostream>
using namespace std;

class year
{
  int yy;

public:
    year (){cout <<endl <<"Default Constructor...."; }
    ~year (){cout <<endl <<"Default Destructor...."; }
    
  year (int t)
  {
    cout <<endl <<"Param Cosntructor.....";
    yy = t;
  }
  void display ()
  {
    cout << "\n  yy=" << yy;
  }
};


int
main ()
{
  int x = 4;
  // x is built-in type	     (int)
  // y1 is user defined type (year)
//  year y1 = x;//assigning variable to object
  

  year y2;
  
  y2 = x;
  
  // y2 = year temp_obj(x);
    
  //year y2,y3;
  //y1.display ();
  y2.display();
  
/*
  y2 = 8;			//internally causes a constructor "year(int)" to run
  y2.display ();
  
  y3=x;			//this will also cause constructor year(int) to run
  y3.display();
*/
  return 0;
}
