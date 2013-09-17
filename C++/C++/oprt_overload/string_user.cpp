#include <iostream>
#include "string.h"
using namespace std;

int main()
{

   String s1("Ram", 3);
   cout << s1.GetString() << endl;

   // Calls default CTOR
   String s4;

   // Calls PARAM CTOR
   String s2("Rao",3);
   cout << s2.GetString() << endl;

   // Calls Copy constructor 
   String s3 = s1;
   cout << s3.GetString() << endl;

   // Calls operator = function
   s4 = s2;
   cout << s4.GetString() << endl;
/*
   //
   //	To test cascadation of =
   //	operators
   //
   String s5,s6,s7,s8;
   s5 = s6 = s7 = s8 = s1;
 
   cout << s5.GetString() << endl;
   cout << s6.GetString() << endl;
   cout << s7.GetString() << endl;
   cout << s8.GetString() << endl;

   //
   //	String Re-Assignment
   //	Means that s5 already has 
   //	string "ram", we are assiging
   //	rao (in s2)
   //
   s5 = s2;
   cout << s5.GetString() << endl;
*/
  
   /*String s9 = s1 + s2;
   cout << endl << "Back to main :s9 is " << endl;
   cout << s9.GetString() << endl;
*/

/*   String s10;
   s10 = s1 + s2;
   cout << "s10" << endl;
   cout << s10.GetString() << endl;

   String s11;
   // Will not be supported properly
   s11 = s1 + s2 + s2;
   cout << "s11" << endl;
   cout << s11.GetString() << endl;
*/
  String s12("Raj", 3);
  s12 += s2;
  cout << "s12: " << endl;
  cout << s12 << endl;

  cout <<"s12[1] ="<< s12[1] << endl;
   s12[1] = 'Z';
  cout << "After:" << endl;
  cout << s12 << endl;
/*
  String s13;
  cin >> s13;
  cout << s13;
*/
//  operator << (cout, s12)

  /*
if (s1 == s3)
    cout << "same" << endl;
*/
  return 0;
}
