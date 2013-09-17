#include <iostream>
using namespace std;


namespace  Naive
{
   int i;
   int j;
}

int i;

int main()
{
   int i = 10;
   Naive::i = 6;
 cout << " Naive i = " << Naive::i << endl;
 cout << " Local i = " << i << endl;
  ::i = 5;
 cout << " Global i = " << ::i << endl;
   return 0;
}
