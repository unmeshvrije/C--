#include <iostream>
#include <cstring>
using namespace std;

class Dog
{
   char name[20];
   public:
   Dog(const char *name)
   {
     strcpy(this->name, name);
     cout << this->name  << " took birth" << endl;
   }
   ~Dog() {cout << this->name << " died" << endl;}
};

void fun()
{
   Dog Max("Max");
}


int main()
{
   Dog Sheru("Sheru");
   fun();
   return 0;
}
