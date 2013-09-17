#include<iostream>
#include<cstdio>
using namespace std;

/**PRIOR DECLARARION OF THE CLASS**/
class c2; //since we are using c2 in declaration of the fun() as a friend
//FORWARD REFERENCE OF class c2

class c1
{
  int x;
  //  You can declare friend
  //  either in private or 
  //  in public section.
  friend void fun (c1&,c2&);
public:
  c1 ()//constructor
  {
    x = 10;
  }
/********************************/
~c1()
{
cout<<"destroyed....\n";
getchar();
}

/********************************/
};


class c2
{
  int y;
  friend void fun (c1&, c2&);
public:
   c2 ()//constructor
  {
    y = 20;
  }
};


void
fun (c1& o1,c2& o2)//function in which we are just printing private vars of both the classes
{//so it should be friend of both classes
  cout << o1.x << o2.y;
}

int
main ()
{
  c1 o1;
  c2 o2;
  fun (o1,o2);//function to which we are passing objects of both the classes
  return 0;
}
