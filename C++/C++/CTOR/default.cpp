#include <iostream>
using namespace std;

class Dog
{
   int age;
   public:
   Dog()
   {
      cout << "Dog created" << endl;
      age = 1;
   }
   /*Dog (int age = 3)
   {
      cout << "Dog::Dog(int)" << endl;
      this->age = age;
      cout << "this =";
      cout << this << endl;
   }*/
   void SetAge(int a)
   {
      age = a;
   }  
   int GetAge()
   {
      return age;
   }
};

int main()
{
  /*int i;
  cout << "i = " << i << endl;
*/
/*
  int i =35;
  cout << i << endl;
  cout << hex << i << endl;
  cout << oct << i << endl;
  cout << dec << i << endl;
*/ 
  /*Dog Sheru(5);
  cout << "Sheru's address = " << &Sheru << endl;
  */
  //Dog Gennie(7);
 /*
Dog Gennie; Try to create object
	      Try to locate constructor
(If there are two constructors:
1.Default
2.Parameterized CTOR with default arg
)
 Dog Gennie(); Declaration of function
	OR Prototype of function

Dog Gennie(5);
	Try to locate parameterized CTOR;
*/

  /*cout << "Sheru is " << Sheru.GetAge()
  << "years old" << endl;*/
  
cout << "Gennie is " << Gennie.GetAge()
  << "years old" << endl;

  //  Gennie();

  /*cout << "Setting age as 8 " << endl;
  Gennie.SetAge(8);
  cout << "Gennie is " << Gennie.GetAge()
  << "years old" << endl;
*/
  return 0;
}

Dog Gennie()
{
   cout << "Nasty function" << endl;
}
