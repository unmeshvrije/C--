#include<iostream>
using namespace std;

class c1
{
private:
  int x;
public:
int u;
    c1 ()          //constructor
  {
    x = 10;
    u=50;
  }
  void fun1 ()                  
  {
    cout << "\n" << x;
  }
      /*two inline functions of class*/
  int square ()
  {
    return x * x;
  }
};

class c2
{
private:
  int y;
public:
    c2 ()
  {
    y = 20;
  }

//c1 is the friend of c2  
  friend class c1;
   
  void fun2 ()
  {
    cout << "\n" << y;
  }

  void getc1 (c1 & temp)       //fun of c2 accessing all the funs of c1 (c1's obj is passed)
  {
    temp.fun1 ();
    //temp is the references variable
    // containing val of o1
    cout << "\n\t" <<"Class c1's public variable u= "<< temp.u <<"\n\t\t"<< temp.square ();
  }

};

int
main ()
{
  c1 o1;
  c2 o2;

  o2.fun2 ();			
  //object of c2 accessing its own data

//c2's object  should be able to access c1's any public data or functions
  o2.getc1 (o1);	
  //calling fun which contains 
  //call to c1's allfuns 
  //by passing c1's obj i.e. o1
  return 0;
}
