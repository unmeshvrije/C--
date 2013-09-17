#include <iostream>
#include "string.h"
using namespace std;

int main()
{

   String s1("Ram", 3);
   cout << s1.GetString();

   String s2(s1);
   cout << s2.GetString();
   return 0;
}
