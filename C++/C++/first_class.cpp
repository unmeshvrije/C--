#include <iostream>
#include <cstring>
using namespace std;

class Man
{
   protected:
   float Earning;
   double Property;// Land, home

   private:
   char Feelings[20];
   char Nature[20];

   public:
   float weight;
   float height;
   char Name[20];

   void breath();
   //void talk();
   //void walk();
   void sleep();
   void die();
   //void read();
   //void write();
   void SetValues()
   {
    Earning = 5000000;
    Property = 342345;
    strcpy(Name, "Hritik");
    strcpy(Nature, "jolly");
    weight = 70.4;
    height = 6.2;
   }

   void PrintValues()
   {
cout << "Earning= " << Earning << endl;
cout << "Nature= " << Nature << endl;
cout << "Property= " << Property << endl;
   }

};


int main()
{
   Man Hritik;
   Hritik.SetValues();
cout << "Weight = "<<Hritik.weight << endl;
cout << "Height = "<<Hritik.height << endl;
cout << "Name = "<<Hritik.Name << endl;
  Hritik.PrintValues();
//cout << "earning= "<<Hritik.Earning<< endl;
   return 0;
}
