#include<iostream>
using namespace std;
class sample
{
  int m;
  void read() //private member fun
  {
    cout << " this is private : enter :";
    cin >> m;
  }
  
  public :
    void update(void);
    void write(void);
};


void sample::update(void)
{
  read();
  cout << "  m = "  << m;
}

// if s1 is object of sample then
main()
{
  sample s1;
//  s1.read(); // wont work
  s1.update();// update is PUBLIC method

}

