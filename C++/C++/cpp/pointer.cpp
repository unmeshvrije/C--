#include<iostream>

using namespace std;

main()
{
  int *p;
  p = new int(5);
  //*p = 4;5
   //cout << *p;
  for(int i=0;i<5;i++)
  {
    p[i] = i;
    cout << p[i] <<",";
  }
  
  
}
