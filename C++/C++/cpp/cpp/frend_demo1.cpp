#include<iostream>
using namespace std;

/*****DECLARATION OF ONE CLASS****/
class test
{
  int x, y;
public:
  test () // default constructor
  {
    x = 10;
    y = 20;
  }
  void f1 () // automatically inline
  {
    cout << "\t" << x << "\t" << this->y << endl;
  }
/***********************/
  friend void f2 (test &);/* how to make general function as a friend */
/*********************/
};

void f2 (test &o)/* general function which we want as a friend */
{
  cout << "\n\t" << o.x << "\t" << o.y << endl;
}

/************************************************************/

int
main ()
{
  test obj;//object of test class is created
  
  obj.f1 ();//f1 is the inline function of class test  'obj' is the implicit parameter 
    
  f2(obj);//f2 is general fun 'obj' is the explicit parameter (we have to pass it)
  return 0;
}
