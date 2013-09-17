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
	cout << "Man::CTOR" << endl;
        Feelings = f;
	Name = n;
	Property = p;
      }
   protected:
      int Property;
};

class SuperMan : protected Man
{
    private:
      int RealId;

   public:
      int Costume;
      
      SuperMan(int f, int n, int p):Man(f,n,p)
      {
cout << "SuperMan::CTOR" << endl;
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
      // Name
      // Property
};

class SuperChild: public SuperMan
{

   public:
   SuperChild(int f,int n, int p):
   SuperMan(f,n,p)
   {
cout << "SuperChild::CTOR" << endl;
   }
   void Print()
   {
  	cout << setw(15);
  	cout << "Power : ";
	cout << Power << endl;
  	cout << setw(15);
	cout << "Name : ";
	cout << Name << endl;
  	cout << setw(15);
	cout << "Property : ";
	cout << Property <<endl;
   }


};

int main()
{
//   SuperMan Krish(5,6,7);
//   cout << Krish.Name << endl;
   SuperChild Krish2('A','B','C');
   Krish2.Print();
   return 0;
}
