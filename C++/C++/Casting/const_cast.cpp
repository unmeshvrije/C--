#include <iostream>
using namespace std;


int main()
{
   const int i = 5;
   cout << "i = " << i << endl;

 int *ptr = const_cast<int*>(&i);
   //int *ptr = (&i);
   *ptr = 10;
//   cout << "After: i = " << i << endl;

   cout << "ptr = " << ptr << endl;
   cout << "*ptr = " << *ptr << endl;
   cout << "&i = " << &i << endl;
   cout << "i = " << i << endl;
   return 0;
}
