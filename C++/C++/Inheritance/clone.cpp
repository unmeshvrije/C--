#include <iostream>
using namespace std;

class Man
{
   public:
   float height;
  Man(){cout << "Man::CTOR" << endl;}
   virtual Man *clone()
   {
   cout << "Cloning Man..."<< endl;
      return new Man(*this);
   }
};


class Robot : public Man
{
   public:
   Robot()
   {
     cout << "Robot::CTOR" << endl;
   }
   Robot *clone()
   {
   cout << "Cloning Robot..."<< endl;
      return new Robot(*this);
   }
};

int main()
{
   /*
   Man Hritik;
   Hritik.height = 6.2;

   Man *Dummy;
   Dummy = Hritik.clone();
  cout << "Dummy = " <<Dummy->height;
   cout << endl;
   */

   Robot RaOne;
   RaOne.height = 6.8;
   Robot *SRK;
   SRK = RaOne.clone();
   cout << "SRK = " << SRK->height;
   cout << endl;
  
/*
  Man *ptr = new Robot;
  Man *Krish = ptr->clone();
*/
/*
ptr-> clone will call Robot's clone
(as ptr is allocated memory of type
Robot)
But This object is cloned and
it contains both Man's part and 
Robot's part.

Hence Derived class ptr (Robot's ptr)
cannot point to it.
Thus we need ptr to Man's class here.

Robot *Krish = ptr->clone;
this statement is erroneous;
*/ 
    Robot *Stark = new Robot;
    Robot *Thor = Stark->clone();
   return 0;
}
