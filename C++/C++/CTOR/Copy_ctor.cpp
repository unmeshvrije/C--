#include <iostream>
#include "integer.h"
using namespace std;

int main()
{
   Integer I;
   cout << "I = " << I.GetValue() << endl;

   Integer J(5);
   J.SetValue(10,'A');
   cout << " J = "<< J.GetValue() << endl;
   cout << " JChar = "<< J.GetChar() << endl;

   Integer K(J);
   cout << "K = " << K.GetValue() << endl;
   cout << "KChar = " << K.GetChar() << endl;
   return 0;
}
