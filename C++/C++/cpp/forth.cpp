#include<iostream>

using namespace std;

class A;  // class declaration
;
class A  //class definition
{
  int a;
  float b;
  
  public:
    void getdata(void)
    {
      //int a;
      cout << "Enter a : ";
      cin >> a;
      cout << "Enter b : ";
      cin >> b;
    }
    
    void putdata(void)
    {
      cout << "a = " <<a;
      cout << "b = " <<b;
    }
    
};




int main()
{
 A obj;
 obj.getdata();
 obj.putdata();
 

}
