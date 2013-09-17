#include <iostream>
#include <typeinfo>
#include <cstring>
using namespace std;


template <typename Generic>
Generic Min(Generic a, Generic b)
{
   if (
     typeid(Generic) == typeid(char*)
     )
     {
     //  cout << "typeid pass" << endl;
        int iRet = strcmp(a,b);
	if(iRet < 0)
	  return a;
	return b;
     }
   else
   {
     if (a < b)
       return a;
     
     return b;
   }
}

int main()
{
  int a = 4, b = 6;
  float c = 3.34, d = 7.545;
  char e = 'E', f = 'F';
  char str1[] = "abcd";
  char str2[] = "abce";

//This causes template instantiation.
   cout << Min<char*>(str1,str2);
   cout << endl;
/*  cout << "Min of integers = ";
  cout << Min<int>(a,b);

  cout << endl;
  cout << "Min of floats = " << Min<float>(c,d);
  cout << endl;
  cout << "Min of chars = " << Min<char>(e,f);
  cout << endl;*/
  return 0;
}
