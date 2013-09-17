#include <iostream>
using namespace std;

class Animal
{
    public:
    void Breath()
    {
  cout << "Animal::Breath()" << endl;
    }
};

class Alien
{
   public:
   void Breath()
   {
cout  << "Alien Breath!!!" << endl;
   }
};

class Man : public Animal
{
    public:
/*    void Breath(int i)
    {
     Animal::Breath();
  cout << "Man::Breath()" << endl;
    }
*/

/*
Above definition hides inherited 
void Breath() function's definition.
Hence we cannot call 
m.Breath() without argument
*/

    void Breath()
    {
  cout << "Man::Breath()" << endl;
     // Animal::Breath();
    }

};

int main()
{
  /*Animal a; 
  a.Breath();*/
  Man m;
  m.Breath();
  //m.Animal::Breath();
//  m.Alien::Breath();
  return 0;
}
