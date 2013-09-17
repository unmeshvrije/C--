#include<iostream>
using namespace std;

/**friend class example**/
class c1
{
private:
  int x;

public:
  int y;
  
    c1 ()
  {
    x = 10;
    y = 20;
  }
  void fun1 ()
  {
    cout << "\n" << x << "\t" << y;
  }

//  friend void c2::getc1(c1 &);// does not work
   friend class c2;
};

class c2
{
private:
  int z;
public:
  int w;
    c2 ()
  {
    z = 30;
    w = 40;
  }
//c1's function  is the friend of c2  
  void fun2 ()
  {
    cout << "\n" << z << "\t" << w << endl;
  }

  void getc1 (c1 &temp)//o1
  // without object of c1 class we
  // can't call its method
  {
    //temp.fun1 ();
    cout << " y= "<<temp.y << endl;
    cout << " x= "<<temp.x << endl;
  }
};

int
main ()
{
  c1 o1;
  c2 o2;
    
  o2.fun2 ();
  cout<<o2.y<<endl;
  //object of c2 accessing its own data

//c2's object  should be able 
//to access c1's data
  o2.getc1 (o1);
 //calling fun which contains 
 //call to c1's fun 
//by passing c1's obj i.e. o1
  return 0;
}
