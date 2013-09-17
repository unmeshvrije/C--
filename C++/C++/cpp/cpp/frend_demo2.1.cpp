#include<iostream>
using namespace std;

class c1
{
  int x;
//public:
private:
    c1 ()//constructor
  {
    x = 10;
  }
  friend void fun ();
};

class c2
{
  int y;
//public:
private:
   c2 ()//constructor
  {
    y = 20;
  }
  friend void fun ();
};

void
fun ()//function in which we are declaring objects of both the classes
{
  c1 o1;
  c2 o2;
  cout << o1.x << o2.y << endl;
}

int
main ()
{
  fun ();//function having declarations & 'cout' statements for classes
  return 0;
}
