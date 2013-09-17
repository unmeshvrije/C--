#include<iostream>

using namespace std;

char * allocateMemory();
main()
{
  char *str;
  str = allocateMemory();
  cout << str;
  delete str;
  str= "     ";
  cout<< str;
}

char *allocateMemory()
{
  str = "memory allocation test";
  return str;
}
