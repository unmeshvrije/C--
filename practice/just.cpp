#include<iostream>
using namespace std;

int main()
{
  int n = 5;
  int *p = &n;
  int *q = p;
  cout << p << ": " << *p << endl;
  *q = 10;
  int m = *p;
  cout << m << "," << *p << "." << n << endl;
}
