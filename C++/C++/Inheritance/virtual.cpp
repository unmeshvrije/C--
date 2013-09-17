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

int main()
{
  Shape *ptr = new Circle;
  ptr->Display(); 
//Dynamic call dispatch
   return 0;
}
