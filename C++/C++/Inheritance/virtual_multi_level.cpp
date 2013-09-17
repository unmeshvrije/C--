#include <iostream>
using namespace std;

class Shape
{
   public:
   virtual void Display()
   {
     cout << "Shape::Display" <<endl;
   }
};

class Circle:public Shape
{
   public:
   void Display()
   {
   cout << "Circle::Display" << endl;
   }
};

class Ellipse:public Circle
{
   public:
   void Display()
   {
  cout << "Ellipse::Display" << endl;
   }
};

int main()
{
/*  Shape *ptr = new Circle;
  ptr->Display(); */
//Dynamic call dispatch
   Ellipse e;
   e.Display();
   
   Circle *ptr= new Ellipse();
   ptr->Display();
   
   Shape *ptr2 = new Ellipse();
   ptr2->Display();

   return 0;
}
