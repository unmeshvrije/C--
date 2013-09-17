#include <iostream>
#include <iomanip>
using namespace std;

class Man
{
   private:
      int Feelings;
   public:
      int Name;
      Man(int f, int n, int p)
      {
        Feelings = f;
	Name = n;
	Property = p;
      }
   protected:
      int Property;
};

class SuperMan : public Man
{
    private:
      int RealId;

   public:
      int Costume;
      
      SuperMan(int f, int n, int p):Man(f,n,p)
      {
         RealId = 1;
	 Costume = 2;
	 Power = 3;
      }

      void Print()
      {
  	cout << setw(15);
	cout << "RealIdentity : ";
	cout << RealId << endl;
  	cout << setw(15);
	cout << "Costume : ";
	cout << Costume << endl;
  	cout << setw(15);
  	cout << "Power : ";
	cout << Power << endl;
  	cout << setw(15);
	cout << "Name : ";
	cout << Name << endl;
  	cout << setw(15);
	cout << "Property : ";
	cout << Property <<endl;
 // cout << "Feelings:" << Feelings;
      }

   protected:
      int Power;
};

int main()
{
   SuperMan Krish(5,6,7);
   cout << Krish.Name << endl;
//   cout << Krish.Property << endl;
 //  Krish.Print();
   return 0;
}
