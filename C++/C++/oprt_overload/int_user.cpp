#include <iostream>
#include "integer.h"
using namespace std;


int main()
{
   Integer I(4);
   Integer J(4);
   Integer K;
   cout << "I = " << I << endl;
   cout << "J = " << J << endl;
   K = I++;
   cout << "K = " << K << endl;
   cout << "I = " << I << endl;

   Integer L;
   L = ++I;
   cout << "L = " << L << endl;
   cout << "I = " << I << endl;
}
